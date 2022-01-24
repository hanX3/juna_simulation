// change simulation bin

#include <stdio.h>
#include <dirent.h>

//data path
string rawdata = "../../../../";
string rootfilepath = "../../../../rootfile/2020/";
string expdata = "../../../../exp_data/";

//exp adc range
//3300-6300 3000 bin 2020 exp
double adcmin = 3300;
double adcmax = 6300;
int binnum = 3000;

//set cali par
double p0 = 1.22342;
double p1 = 0.429543;

bool getfilename(string dirpath, vector<TString>  &vfiles)
{
  struct dirent *ptr;
  DIR *dir;
  dir=opendir(dirpath.c_str());
  while((ptr=readdir(dir))!=NULL){
    if(ptr->d_name[0] == '.')
      continue;

    //printf("%s  %d\n", ptr->d_name, (int)strlen(ptr->d_name));
    vfiles.push_back(ptr->d_name);
  }

  closedir(dir);

  return true;
}

//main
void getrootfile(int beam_energy, double sim_energy)
{
  gROOT->SetBatch(1);

  //data path
  stringstream ss;
  ss.str("");
  ss << rawdata << "fit_exp_" << beam_energy << "keV/em_" << setiosflags(ios::fixed) << setprecision(1) << sim_energy << "/data/";
  string datapath(ss.str());
  cout << ss.str() << endl;
  ss.str("");
  ss << rootfilepath << "proton_" << sim_energy << "keV.root";
  cout << ss.str() << endl;
  TFile *fo = new TFile(ss.str().c_str(), "RECREATE");

  gStyle->SetOptStat(0);

  //read exp data
  ifstream fi;
  ss.str("");
  ss << expdata << "2020_" << beam_energy << "keV.txt";
  cout << ss.str() << endl;
  fi.open(ss.str().c_str());

  TH1D *h1 = new TH1D("h1", "h1", binnum, p0+adcmin*p1, p0+adcmax*p1);

  double a;
  double b;
  double c;

  int ii = 1;
  while(1)
  {
    fi >> a >> b >> c;
    if(!fi.good())  break;
    h1->SetBinContent(ii, c);
    ii++;
  }

  //simulation data
  vector<TString> v_filename;
  vector<string> v_rootfile;
  getfilename(datapath, v_filename);
  for(int i=0;i<(int)v_filename.size();i++){
    Size_t len = v_filename[i].Length();
    if(len<10)
      continue;

    TString strhead(v_filename[i](0, 6));
    TString strtail(v_filename[i](len-4, 4));
    //cout << strhead << "  " << strtail << endl;

    if(strhead.CompareTo("energy")==0 && strtail.CompareTo("root")==0){
      v_rootfile.push_back(v_filename[i].Data());
    }
  }

  TChain *chain = new TChain("tree");
  ss.str("");
  for(int i=0;i<v_rootfile.size();i++){
     ss.str("");
     ss << datapath << v_rootfile[i];
     chain->Add(ss.str().c_str());
  }

  TH1D *hsim_1 = new TH1D("hsim_1", "", binnum, p0+p1*adcmin, p0+p1*adcmax);
  hsim_1->GetXaxis()->SetTitle("Gamma Energy [keV]");
  hsim_1->GetYaxis()->SetTitle("Counts");
  ss.str("");
  ss << "sim energy " << sim_energy << " keV";
  hsim_1->SetTitle(ss.str().c_str());
  chain->Draw("energy0>>hsim_1", "energy0>10.", "");

  TH1D *hsim_2 = new TH1D("hsim_2", "", 2.*binnum, p0+p1*adcmin, p0+p1*adcmax);
  hsim_2->GetXaxis()->SetTitle("Gamma Energy [keV]");
  hsim_2->GetYaxis()->SetTitle("Counts");
  ss.str("");
  ss << "sim energy " << sim_energy << " keV";
  hsim_2->SetTitle(ss.str().c_str());
  chain->Draw("energy0>>hsim_2", "energy0>10.", "");

  TH1D *hsim_3 = new TH1D("hsim_3", "", 3.*binnum, p0+p1*adcmin, p0+p1*adcmax);
  hsim_3->GetXaxis()->SetTitle("Gamma Energy [keV]");
  hsim_3->GetYaxis()->SetTitle("Counts");
  ss.str("");
  ss << "sim energy " << sim_energy << " keV";
  hsim_3->SetTitle(ss.str().c_str());
  chain->Draw("energy0>>hsim_3", "energy0>10.", "");

  TH1D *hsim_4 = new TH1D("hsim_4", "", 4.*binnum, p0+p1*adcmin, p0+p1*adcmax);
  hsim_4->GetXaxis()->SetTitle("Gamma Energy [keV]");
  hsim_4->GetYaxis()->SetTitle("Counts");
  ss.str("");
  ss << "sim energy " << sim_energy << " keV";
  hsim_4->SetTitle(ss.str().c_str());
  chain->Draw("energy0>>hsim_4", "energy0>10.", "");

  h1->SetLineColor(1);
  h1->SetTitle("Exp");
  h1->SetLineWidth(2);
  h1->GetXaxis()->SetTitle("Gamma Energy [keV]");
  h1->GetYaxis()->SetTitle("Counts");
  hsim_1->SetLineColor(1);
  hsim_2->SetLineColor(1);
  hsim_3->SetLineColor(1);
  hsim_4->SetLineColor(1);

  fo->cd();
  h1->Write();
  hsim_1->Write();
  hsim_2->Write();
  hsim_3->Write();
  hsim_4->Write();
  fo->Close();
}
