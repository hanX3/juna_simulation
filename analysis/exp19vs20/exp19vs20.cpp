//data path
string rawdata = "../../../exp_data/";

//exp adc range
double adc_min_2019 = 1600;
double adc_max_2019 = 3600;
int bin_num_2019 = 2000;
double adc_min_2020 = 3300;
double adc_max_2020 = 6300;
int bin_num_2020 = 3000;

//exp cali par
double p0_2019 = 2.58919;
double p1_2019 = 0.812258;
double p0_2020 = 1.22342;
double p1_2020 = 0.429543;

//rise part
double rise_part_start = 2160.;
double rise_part_stop = 2220.;
string fit_func_rise = "pol2";

//scale
double energy_step = 0.5;
double scale_step = 0.1;

//
void exp19vs20(double proton_energy)
{
  stringstream ss;

  ss.str("");
  ss << rawdata << "2019_" << (int)proton_energy << "keV.txt";
  cout << ss.str() << endl;
  ifstream ifs_2019;
  ifs_2019.open(ss.str().c_str());
  
  ss.str("");
  ss << rawdata << "2020_" << (int)proton_energy << "keV.txt";
  cout << ss.str() << endl;
  ifstream ifs_2020;
  ifs_2020.open(ss.str().c_str());

  TH1D *h2019 = new TH1D("h2019", "h2019", bin_num_2019, p0_2019+adc_min_2019*p1_2019, p0_2019+adc_max_2019*p1_2019);
  TH1D *h2020 = new TH1D("h2020", "h2020", bin_num_2020, p0_2020+adc_min_2020*p1_2020, p0_2020+adc_max_2020*p1_2020);
  double a_temp, b_temp, c_temp;
  int ii = 1;
  while(1){
    ifs_2019 >> a_temp >> b_temp >> c_temp;
    if(!ifs_2019.good())  break;
    h2019->SetBinContent(ii, c_temp);
    ii++;
  }
  ifs_2019.close();
  int jj = 1;
  while(1){
    ifs_2020 >> a_temp >> b_temp >> c_temp;
    if(!ifs_2020.good())  break;
    h2020->SetBinContent(jj, c_temp);
    jj++;
  }
  ifs_2020.close();

  TCanvas *cc = new TCanvas("cc", "cc", 0, 0, 1600, 900);
  cc->Divide(3, 2);

  //
  cc->cd(1);
  h2019->SetLineColor(4);
  h2019->GetXaxis()->SetTitle("Gamma Energy [keV]");
  h2019->GetYaxis()->SetTitle("Counts");
  //
  cc->cd(2);
  h2020->SetLineColor(4);
  h2020->GetXaxis()->SetTitle("Gamma Energy [keV]");
  h2020->GetYaxis()->SetTitle("Counts");

  //graph
  double xx_2019[bin_num_2019];
  double yy_2019[bin_num_2019];
  double xx_error_2019[bin_num_2019];
  double yy_error_2019[bin_num_2019];
  for(int i=0;i<bin_num_2019;i++){
    xx_2019[i] = h2019->GetBinCenter(i+1);
    xx_error_2019[i] = 0;
    yy_2019[i] = h2019->GetBinContent(i+1);
    yy_error_2019[i] = sqrt(yy_2019[i]);
  }
  TGraphErrors *gr_exp_2019 = new TGraphErrors(bin_num_2019, xx_2019, yy_2019, xx_error_2019, yy_error_2019);
  gr_exp_2019->SetTitle("2019 exp");
  gr_exp_2019->SetMarkerColor(1);
  gr_exp_2019->SetMarkerStyle(24);
  gr_exp_2019->SetMarkerSize(1);
  cc->cd(1);
  gr_exp_2019->Draw("AP");
  h2019->Draw("same");

  double xx_2020[bin_num_2020];
  double yy_2020[bin_num_2020];
  double xx_error_2020[bin_num_2020];
  double yy_error_2020[bin_num_2020];
  for(int i=0;i<bin_num_2020;i++){
    xx_2020[i] = h2020->GetBinCenter(i+1);
    xx_error_2020[i] = 0;
    yy_2020[i] = h2020->GetBinContent(i+1);
    yy_error_2020[i] = sqrt(yy_2020[i]);
  }
  TGraphErrors *gr_exp_2020 = new TGraphErrors(bin_num_2020, xx_2020, yy_2020, xx_error_2020, yy_error_2020);
  gr_exp_2020->SetTitle("2020 exp");
  gr_exp_2020->SetMarkerColor(1);
  gr_exp_2020->SetMarkerStyle(24);
  gr_exp_2020->SetMarkerSize(1);
  cc->cd(2);
  gr_exp_2020->Draw("AP");
  h2020->Draw("same");

  //fit rise part 2019
  TF1 *tf_rise_2019 = new TF1("tf_rise_2019", fit_func_rise.c_str(), rise_part_start, rise_part_stop);
  gr_exp_2019->Fit("tf_rise_2019", "RQN0");
  TF1 *tf_rise_2020 = new TF1("tf_rise_2020", fit_func_rise.c_str(), rise_part_start, rise_part_stop);
  gr_exp_2020->Fit("tf_rise_2020", "RQN0");
  double scale_mean = 4.;
  double scale_range = 4.;
  cout << "scale_mean  " << scale_mean << endl;
  cout << "scale_range  " << scale_range << endl;

  TGraph *gr_scale = new TGraph();
  int scale_cnt = 0;
  double chi2 = 0.;
  double x_temp;
  double y2019_temp, y2020_temp;
  for(double sca=(scale_mean-scale_range/2.);sca<(scale_mean+scale_range/2.);sca+=scale_step){
    chi2 = 0;
    for(x_temp=rise_part_start;x_temp<rise_part_stop;x_temp+=energy_step){
      y2019_temp = tf_rise_2019->Eval(x_temp);
      y2020_temp = tf_rise_2020->Eval(x_temp);
      chi2 += (y2019_temp/sca-y2020_temp)*(y2019_temp/sca-y2020_temp)/y2020_temp;
    }
    chi2 /= (rise_part_stop-rise_part_start)/energy_step;
    gr_scale->SetPoint(scale_cnt, sca, chi2);
    scale_cnt++;
  }

  cc->cd(3);
  gr_scale->SetTitle("get scale");
  gr_scale->GetXaxis()->SetTitle("scale");
  gr_scale->GetYaxis()->SetTitle("chi2");
  gr_scale->Draw("AP*");

  TF1 *tf_scale = new TF1("tf_scale", "pol6", scale_mean-scale_range/2., scale_mean+scale_range/2.);
  gr_scale->Fit("tf_scale", "R");
  double scale_min = tf_scale->GetMinimumX(scale_mean-scale_range/2., scale_mean+scale_range/2.);
  double chi2_min = tf_scale->GetMinimum(scale_mean-scale_range/2., scale_mean+scale_range/2.);
  ss.str("");
  ss << "scale_min  " << scale_min << "  chi2_min  " << chi2_min;
  TPaveLabel *pp0 = new TPaveLabel(0.3, 0.7, 0.8, 0.8, ss.str().c_str(), "brNDC");
  pp0->Draw();
  pp0->SetTextColor(kRed+3);
  pp0->SetFillColor(kYellow-8);

  //
  cc->cd(4);
  double yy_2019_scaled[bin_num_2019];
  double yy_error_2019_scaled[bin_num_2019];
  for(int i=0;i<bin_num_2019;i++){
    yy_2019_scaled[i] = h2019->GetBinContent(i+1)/scale_min;
    yy_error_2019_scaled[i] = sqrt(yy_2019_scaled[i]);
  }
  TGraphErrors *gr_exp_2019_scaled = new TGraphErrors(bin_num_2019, xx_2019, yy_2019_scaled, xx_error_2019, yy_error_2019_scaled);
  gr_exp_2019_scaled->SetTitle("2019 exp scaled");
  gr_exp_2019_scaled->SetLineColor(2);
  gr_exp_2019_scaled->SetMarkerColor(2);
  gr_exp_2019_scaled->SetMarkerStyle(24);
  gr_exp_2019_scaled->SetMarkerSize(1);
  gr_exp_2019_scaled->Draw("AP");
  
  TGraphErrors *gr_exp_2020_scaled = new TGraphErrors(bin_num_2020, xx_2020, yy_2020, xx_error_2020, yy_error_2020);
  gr_exp_2020_scaled->SetTitle("2020 exp");
  gr_exp_2020_scaled->SetLineColor(4);
  gr_exp_2020_scaled->SetMarkerColor(4);
  gr_exp_2020_scaled->SetMarkerStyle(25);
  gr_exp_2020_scaled->SetMarkerSize(1);
  gr_exp_2020_scaled->Draw("P SAME");

  TLegend *leg = new TLegend(0.12, 0.75, 0.45, 0.85);
  leg->AddEntry(gr_exp_2019_scaled);
  leg->AddEntry(gr_exp_2020_scaled);
  leg->Draw();

  cc->cd(5);
  TGraph *gr_exp_2019_scaled_ = new TGraph(bin_num_2019, xx_2019, yy_2019_scaled);
  gr_exp_2019_scaled_->SetTitle("2019 exp scaled");
  gr_exp_2019_scaled_->SetLineColor(2);
  gr_exp_2019_scaled_->SetMarkerColor(2);
  gr_exp_2019_scaled_->SetMarkerStyle(24);
  gr_exp_2019_scaled_->SetMarkerSize(1);
  gr_exp_2019_scaled_->GetXaxis()->SetRangeUser(2100., 2140.);
  gr_exp_2019_scaled_->GetYaxis()->SetRangeUser(-10., 130.);
  gr_exp_2019_scaled_->Draw("AP");
  
  TGraph *gr_exp_2020_scaled_ = new TGraph(bin_num_2020, xx_2020, yy_2020);
  gr_exp_2020_scaled_->SetTitle("2020 exp");
  gr_exp_2020_scaled_->SetLineColor(4);
  gr_exp_2020_scaled_->SetMarkerColor(4);
  gr_exp_2020_scaled_->SetMarkerStyle(25);
  gr_exp_2020_scaled_->SetMarkerSize(1);
  gr_exp_2020_scaled_->Draw("P SAME");

  TLegend *leg_ = new TLegend(0.12, 0.75, 0.45, 0.85);
  leg_->AddEntry(gr_exp_2019_scaled_);
  leg_->AddEntry(gr_exp_2020_scaled_);
  leg_->Draw();

  cc->cd(6);
  TH1D *h2019_ = (TH1D*)h2019->Clone();
  TH1D *h2020_ = (TH1D*)h2020->Clone();
  h2019_->GetXaxis()->SetRangeUser(1455., 1465.);
  h2019_->SetLineColor(2);
  h2019_->SetLineWidth(2);
  h2019_->Draw();
  h2020_->SetLineColor(4);
  h2020_->SetLineWidth(2);
  h2020_->Scale(766./183.);
  h2020_->Draw("same hist");
  TLegend *leg_2 = new TLegend(0.12, 0.75, 0.45, 0.85);
  leg_2->AddEntry(h2019_);
  leg_2->AddEntry(h2020_);
  leg_2->Draw();

  cc->SaveAs("cc.pdf");
}

