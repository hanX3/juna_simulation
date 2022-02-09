TH1D *h1 = new TH1D("h1", "h1", 160, 2308, 2324);
TH1D *h2 = new TH1D("h2", "h2", 160, 2308, 2324);

void draw()
{
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);

  TFile *f1;
  f1 = TFile::Open("nores.root");
  TTree *tr1 = (TTree*)f1->Get("tree");
  cout << tr1->GetEntries() << endl; 
  double energy_nores;
  tr1->SetBranchAddress("energy0", &energy_nores);
  for(int i=0;i<tr1->GetEntries();i++){
    tr1->GetEntry(i);
    h1->Fill(energy_nores);
  }

  TFile *f2;
  f2 = TFile::Open("withres.root");
  TTree *tr2 = (TTree*)f2->Get("tree");
  cout << tr2->GetEntries() << endl; 
  double energy_withres;
  tr2->SetBranchAddress("energy0", &energy_withres);
  for(int i=0;i<tr2->GetEntries();i++){
    tr2->GetEntry(i);
    h2->Fill(energy_withres);
  }

  TCanvas *c = new TCanvas("c", "c", 0, 0, 600, 960);
  h1->GetXaxis()->SetRangeUser(2311, 2321.9);
  h1->GetXaxis()->SetTitle("E [keV]");
  h1->GetYaxis()->SetTitle("count");
  h1->SetLineColor(2);
  h2->SetLineColor(4);

  c->cd();
  h1->Draw();
  h2->Draw("same");
  c->SaveAs("c1.png");
}
