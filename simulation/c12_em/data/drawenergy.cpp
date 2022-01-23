{
  auto c1 = new TCanvas("c1", "c1", 0, 0, 480, 360);
  tree->Draw("energy0>>h0(16384,0,4096)", "energy0>10");
  tree->Draw("energy1>>h1(16384,0,4096)", "energy1>10");
  tree->Draw("energy2>>h2(16384,0,4096)", "energy2>10");

  c1->cd();
  c1->SetLogy();
  h0->SetLineColor(1);
  h1->SetLineColor(2);
  h2->SetLineColor(4);
  h0->Draw();

  auto c2 = new TCanvas("c2", "c2", 490, 0, 480, 360);
  c2->cd();
  h1->Draw();

  auto c3 = new TCanvas("c3", "c3", 980, 0, 480, 360);
  c3->cd();
  h2->Draw();

  auto c4 = new TCanvas("c4", "c4", 980, 390, 480, 360);
  c4->cd();
  h0->Draw();
  h1->Draw("same");
  h2->Draw("same");
}
