
void draw_cali(int ee)
{
  double a, b, c;

  ifstream ffi;
  ffi.open(TString::Format("../../../exp_data/2020_%dkeV.txt",ee).Data());

  double adcmin = 3300;
  double adcmax = 6300;
  int binnum = 3000;

  double p0 = 1.22342;
  double p1 = 0.429543;

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
  cc->SaveAs(TString::Format("2020_%dkeV.pdf",ee));
}
