#include <stdio.h>
#include <dirent.h>

//exp adc range
double adcmin = 3300;
double adcmax = 6300;
int binnum = 3000;

//set cali par
double p0 = 1.22342;
double p1 = 0.429543;

//background
double bgxmin = 2300.;//keV
double bgxmax = 2400.;//keV

//bin information
int rebinvalue = 1;
string histname = "hsim_1";

//rise part
double risepartstart = 2205.;
double risepartstop = 2235.;
string fitfuncrise = "pol2";

//get scale
string fitfuncscale = "pol6";
double scalestep = 0.01;

//fall part
double fallpartstart = 2237.2;
double fallpartstop = 2241.0;
string fitfuncfall = "pol2";

//main
void analysis(double proton_energy)
{
  gROOT->SetBatch(1);

  std::ofstream ofs;
  ofs.open ("../../../../../../result/2020/320keV/chi2_fall_part.dat", std::ofstream::out | std::ofstream::app);

  //data path
  char filename[1024];
  char savepdf[1024];
  sprintf(filename, "../../../../../../rootfile/2020/proton_%0.1fkeV.root", proton_energy);
  sprintf(savepdf, "../../../../../../result/2020/320keV/fall_part_%0.1f.pdf", proton_energy);
  cout << "filename " << filename << endl;
  cout << "savepdf " << savepdf << endl;

  gStyle->SetOptStat(0);

  //read rootfile

  TFile *fi = TFile::Open(filename);
  fi->ls();
  TH1D *h1 = (TH1D*)fi->Get("h1");
  TH1D *hsim = (TH1D*)fi->Get(histname.c_str());

  TGraph *g1 = new TGraph();

  h1->Rebin(rebinvalue);

  //cali background, exp data
  double bg_exp = 0.;
  TF1 *tfbg = new TF1("tfbg", "pol0", bgxmin, bgxmax);
  h1->Fit("tfbg", "RN0Q");
  bg_exp = tfbg->GetParameter(0);
  //cout << "bg_exp " << bg_exp << endl;

  ////
  cout << "exp bin width " << h1->GetBinWidth(1) << " keV" << endl;

  //analysis
  auto cc = new TCanvas("cc", "cc", 0, 0, 1600, 900);
  cc->Divide(3, 2);

  //
  cc->cd(1);
  h1->SetLineColor(1);
  h1->SetTitle("Exp");
  h1->SetLineWidth(2);
  h1->GetXaxis()->SetTitle("Gamma Energy [keV]");
  h1->GetYaxis()->SetTitle("Counts");
  h1->Draw();
  tfbg->Draw("same");

  //
  cc->cd(2);
  hsim->SetLineColor(1);
  hsim->GetXaxis()->SetRangeUser(2100., 2300);
  hsim->Draw();

  //fit rise part simulation data
  TF1 *tfrisep = new TF1("tfrisep", fitfuncrise.c_str(), risepartstart, risepartstop);
  hsim->Fit("tfrisep", "R");

  //get Scale
  int exprisestartbin = (int)((risepartstart-p0-p1*adcmin)/h1->GetBinWidth(1)+0.5) + 1;
  int exprisestopbin = (int)((risepartstop-p0-p1*adcmin)/h1->GetBinWidth(1)+0.5) + 1;
  //cout << "exprisestartbin  " << exprisestartbin << endl;
  //cout << "exprisestopbin  " << exprisestopbin << endl;

  double scalemean = hsim->GetMaximum()/h1->GetMaximum(); 
  double scalerange = scalemean/2.;
  cout << "scalemean  " << scalemean << endl;
  cout << "scalerange  " << scalerange << endl;

  TGraph *grscale = new TGraph();
  int scalecnt = 0;
  double chi2 = 0.;
  double ytemp = 0.;
  double etemp = 0.;
  for(double sca=(scalemean-scalerange/2.);sca<(scalemean+scalerange/2.);sca+=scalestep){
    chi2 = 0.;
    for(int ii=exprisestartbin;ii<=exprisestopbin;ii++){
      etemp = h1->GetBinCenter(ii);
      ytemp = tfrisep->Eval(etemp);
      ytemp += bg_exp*sca;
      ytemp /= sca;
      chi2 += (ytemp-h1->GetBinContent(ii))*(ytemp-h1->GetBinContent(ii))/h1->GetBinContent(ii);
    }
    chi2 /= (double)(exprisestopbin-exprisestartbin+1.);
    //cout << "sca  " << sca << "  chi2  " << chi2 << endl;
    
    grscale->SetPoint(scalecnt, sca, chi2);
    scalecnt++;
  }

  cc->cd(3);
  grscale->SetTitle("get scale");
  grscale->GetXaxis()->SetTitle("scale");
  grscale->GetYaxis()->SetTitle("chi2");
  grscale->Draw("AP*");
  TF1 *tfscale = new TF1("tfscale", fitfuncscale.c_str(), scalemean-scalerange/2., scalemean+scalerange/2.);
  grscale->Fit("tfscale", "R");

  double scalemin = tfscale->GetMinimumX(scalemean-scalerange/2., scalemean+scalerange/2.);
  double chi2min = tfscale->GetMinimum(scalemean-scalerange/2., scalemean+scalerange/2.);
  //cout << "scalemin  " << scalemin << "  chi2min  " << chi2min << endl;
  stringstream ss;
  ss.str("");
  ss << "scalemin  " << scalemin << "  chi2min  " << chi2min;
  TPaveLabel *pp0 = new TPaveLabel(0.3, 0.7, 0.8, 0.8, ss.str().c_str(), "brNDC");
  pp0->Draw();
  pp0->SetTextColor(kRed+3);
  pp0->SetFillColor(kYellow-8);
  
  //
  cc->cd(4);
  int nexp = h1->GetNbinsX();
  double xx[nexp];
  double yy[nexp];
  double exx[nexp];
  double eyy[nexp];
  for(int i=0;i<nexp;i++){
    xx[i] = h1->GetBinCenter(i+1);
    exx[i] = 0;
    yy[i] = h1->GetBinContent(i+1);
    eyy[i] = std::sqrt(yy[i]);
  }
  int nsim = hsim->GetNbinsX();
  double xxsim[nsim];
  double yysimulatescale[nsim];
  for(int i=0;i<nsim;i++){
    xxsim[i] = hsim->GetBinCenter(i+1);
    yysimulatescale[i] = (double)hsim->GetBinContent(i+1)/scalemin+gRandom->Gaus(bg_exp,1.);
  }
  TGraphErrors *grexp = new TGraphErrors(nexp, xx, yy, exx, eyy);
  grexp->GetXaxis()->SetRangeUser(2150., 2250.);
  grexp->GetYaxis()->SetRangeUser(0., 90.);
  grexp->SetMarkerColor(1);
  grexp->SetMarkerStyle(24);
  grexp->SetMarkerSize(1);
  grexp->Draw("AP");

  TGraph *grsimulationscale = new TGraph(nsim, xxsim, yysimulatescale);
  grsimulationscale->SetMarkerColor(4);
  grsimulationscale->SetMarkerSize(0.5);
  grsimulationscale->SetMarkerStyle(21);
  grsimulationscale->Draw("P same");

  TF1 *tffallp = new TF1("tffallp", fitfuncfall.c_str(), fallpartstart, fallpartstop);
  grsimulationscale->Fit("tffallp", "R", "");

  tfbg->Draw("same");
  
  int expfallstartbin = (int)((fallpartstart-p0-p1*adcmin)/h1->GetBinWidth(1)+0.5) + 1;
  int expfallstopbin = (int)((fallpartstop-p0-p1*adcmin)/h1->GetBinWidth(1)-0.5) + 1;
  //cout << "expfallstartbin " << expfallstartbin << " e " << h1->GetBinCenter(expfallstartbin) << endl;
  //cout << "expfallstopbin " << expfallstopbin << " e " << h1->GetBinCenter(expfallstopbin) << endl;

  chi2 = 0.;
  for(int ii=expfallstartbin;ii<=expfallstopbin;ii++){
    etemp = h1->GetBinCenter(ii);
    ytemp = tffallp->Eval(etemp);
    chi2 += (ytemp-h1->GetBinContent(ii))*(ytemp-h1->GetBinContent(ii))/ytemp;
    cout << " energy " << etemp << " y_expected " << ytemp << " y_observe " << h1->GetBinContent(ii) << " chi2 " << chi2 << endl;
  }
  cout << "chi2  =  " << chi2 << endl;
  ofs << proton_energy << "  " << chi2 << endl;
  ss.str("");
  ss << "chi2  " << chi2;
  TPaveLabel *pp1 = new TPaveLabel(0.2, 0.75, 0.4, 0.8, ss.str().c_str(), "brNDC");
  pp1->Draw();
  pp1->SetTextColor(kRed+3);
  pp1->SetFillColor(kYellow-8);

  cc->cd(5);
  TGraphErrors *gtemp = new TGraphErrors(nexp, xx, yy, exx, eyy);
  gtemp->SetMarkerColor(1);
  gtemp->SetMarkerStyle(24);
  gtemp->SetMarkerSize(1);
  gtemp->GetXaxis()->SetRangeUser(2234., 2244.);
  gtemp->GetYaxis()->SetRangeUser(0., 90.);
  gtemp->Draw("AP");
  grsimulationscale->Draw("P same");
  tffallp->Draw("same");
  tfbg->Draw("same");

  ofs.close();
  cc->SaveAs(savepdf);
}
