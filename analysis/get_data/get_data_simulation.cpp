
//data path
string path = "../../../rootfile/";
string year = "2020/";

void get_data_simulation(double sim_energy, double scale)
{
  gROOT->SetBatch(1);

  //data path
  stringstream ss;
  ss.str("");
  ss << path << year << "proton_" << setiosflags(ios::fixed) << setprecision(1) << sim_energy << "keV.root";
  string data_path(ss.str());
  cout << ss.str() << endl;
  
  TFile *file_in = TFile::Open(ss.str().c_str());
  if(file_in->IsZombie()){
    cout << "wrong open the file" << endl;
    return;
  }

  ofstream file_out;
  ss.str("");
  ss << "proton_" << setiosflags(ios::fixed) << setprecision(1) << sim_energy << "keV.txt";
  file_out.open(ss.str().c_str());

  TH1D *h1 = (TH1D*)file_in->Get("h1");
  TH1D *hsim_1 = (TH1D*)file_in->Get("hsim_1");

  for(int i=0;i<h1->GetNbinsX();i++){
    file_out << " " << h1->GetBinContent(i+1) << " " << sqrt(h1->GetBinContent(i+1)) << " " << hsim_1->GetBinContent(i+1)/scale << endl;
  }

  file_out.close();
}