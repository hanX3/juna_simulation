
void fit()
{
  TGraph *g = new TGraph();
  TCanvas *c = new TCanvas("c", "c", 0, 0, 480, 360);

  ifstream fi;
  fi.open("data1.txt");
  double ecm = 0.;
  double sfactor = 0.;
  int i = 0;
  while(1){
    fi >> ecm >> sfactor;
    if(!fi.good())  break;
    g->SetPoint(i, ecm, sfactor);
    i++;
  }

  c->cd();
  g->Draw();

  TF1 *tf1 = new TF1("tf1", "[0]*TMath::Exp([1]*x)+[2]", 0.1, 0.4);
  //tf1->SetParameters(0.1, 0.5, 0.01);
  tf1->SetParameters(2.2e-08, 38, 0.005);

  TF1 *tf2 = new TF1("tf2", "[0]*TMath::Power([1]-x,[2])+[3]", 0.1, 0.4);
  //tf2->SetParameters(0.1, 2, 0.5);
  //tf2->SetParameters(725., 2.7, -11.7);
  //tf2->SetParameters(95, 1.6, -39, 0.01);
  tf2->SetParameters(150, 1.5, -45, 0.05);

  TF1 *tf3 = new TF1("tf3", "-[0]*x/([1]+x)+[2]", 0.1, 0.4);
  //tf3->SetParameters(0.1, 0.5, 0.01);
  tf3->SetParameters(-20, 52, -0.01);

  g->Fit(tf1, "R");
  g->Fit("pol9", "", "", 0.02, 0.42);
}
