
void root2txt(int ee)
{
  double k = 0.812258;
  double b = 2.58919;

  //200keV
  TFile *ff1;
  ff1 = TFile::Open(TString::Format("../../../../exp_data/2019_rawdata/rootfile/12C_%dkeV.root",ee).Data());
  
  TH1D* hh = (TH1D*)ff1->Get("h1");

  ofstream ffo;
  ffo.open(TString::Format("../../../../exp_data/2019_%dkeV.txt",ee).Data());

  for(int i=1600;i<3600;++i){
    ffo << i << " " << b+k*hh->GetBinCenter(i+1) << " " << hh->GetBinContent(i+1) << endl;
  }

  ffo.close();
}
