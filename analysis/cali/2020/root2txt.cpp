
void root2txt(int ee)
{
  double k = 0.429543;
  double b = 1.22342;

  //200keV
  TFile *ff1;
  ff1 = TFile::Open(TString::Format("../../../exp_data/2020_rawdata/rootfile/c_%dkeV.root",ee).Data());
  
  TH1D* hh = (TH1D*)ff1->Get("h1");

  ofstream ffo;
  ffo.open(TString::Format("../../../exp_data/2020_%dkeV.txt",ee).Data());

  for(int i=3300;i<6300;++i){
    ffo << i << " " << b+k*hh->GetBinCenter(i+1) << " " << hh->GetBinContent(i+1) << endl;
  }

  ffo.close();
}
