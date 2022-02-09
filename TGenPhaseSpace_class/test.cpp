
void test()
{
  TH1D *h1 = new TH1D("h1", "h1", 8192, 0, 4096);
  TH1D *h2 = new TH1D("h2", "h2", 20000, -3.14, 3.14);

  double mom = sqrt(2.*0.938272*0.00034);
  TLorentzVector target(0.0, 0.0, 0.0, 11.1749);
  TLorentzVector beam_lab (0.0, 0.0, 0.0252614, 0.938272);
  cout << beam_lab.Beta () << endl;

  TLorentzVector sum = beam_lab + target;
  cout << sum.Beta() << endl;
  cout << sum.Px() << " " << sum.Py() << " " << sum.Pz() << " " << sum.E() << endl;

  /*
  TVector3 boost = sum.BoostVector();
  cout << boost.X() << " " << boost.Y() << " " << boost.Z() << endl;
  sum.Boost(boost);
  cout << sum.Px() << " " << sum.Py() << " " << sum.Pz() << " " << sum.E() << endl;
  */

  sum = {0., 0., 0., 12.1135};

  double mass1 = 12.1112;
  double mass2 = 0.;
  double masses [2] = {mass1, mass2};
  TGenPhaseSpace event;
  event.SetDecay(sum, 2, masses);

  TLorentzVector *decay1;
  TLorentzVector *decay2;
  for(int i=0;i<10;i++){
    event.Generate();
    decay1 = event.GetDecay(0);
    decay2 = event.GetDecay(1);
    //if((decay2->Theta()-3.14/2)>0.01)
      //continue;

    h1->Fill(decay2->E()*1000000.);
    h2->Fill(decay2->Theta());

    cout << decay2->E()*1000000. << endl;
  }

  TCanvas *c1 = new TCanvas("c1", "c1", 0, 0, 480, 360);
  c1->cd();
  h1->Draw();
  TCanvas *c2 = new TCanvas("c2", "c2", 0, 0, 480, 360);
  c2->cd();
  h2->Draw();

  return ;
}
