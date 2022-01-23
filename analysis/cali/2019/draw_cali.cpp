
void draw_cali(int ee)
{
  double a, b, c;

  ifstream ffi;
  ffi.open(TString::Format("../../../exp_data/2019_%dkeV.txt",ee).Data());

  double adcmin = 1600;
  double adcmax = 3600;
  int binnum = 2000;

  double p0 = 2.58919;
  double p1 = 0.812258;

  TH1D *h1 = new TH1D("h1", "h1", binnum, p0+adcmin*p1, p0+adcmax*p1);

  int ii = 1;
  while(1){
    ffi >> a >> b >> c;
    if(!ffi.good())  break;
    h1->SetBinContent(ii, c);
    ii++;
  }

  TCanvas *cc = new TCanvas("cc", "cc", 0, 0, 480, 360);
  cc->cd();
  h1->Draw();
  cc->SaveAs(TString::Format("2019_%dkeV.pdf",ee));
}
