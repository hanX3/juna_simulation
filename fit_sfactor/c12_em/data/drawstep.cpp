{
  auto c1 = new TCanvas("c1", "c1", 0, 0, 480, 360);
  tree->Draw("stepLength>>h1(100000, 0, 1.)", "particleName==\"proton\" && detectorName==\"Target\"");

  c1->cd();
  c1->SetLogx();
  c1->SetLogy();
  h1->Draw();
  //c1->SaveAs("step_0.png");
  //c1->SaveAs("step_5.png");
  //c1->SaveAs("step_10.png");
  c1->SaveAs("step_15.png");

  auto c2 = new TCanvas("c2", "c2", 0, 0, 480, 360);
  tree->Draw("eventID>>h2(100000, 0, 100000)", "particleName==\"N13\"");

  c2->cd();
  h2->Draw();
  //c2->SaveAs("N13_0.png");
  //c2->SaveAs("N13_5.png");
  //c2->SaveAs("N13_10.png");
  c2->SaveAs("N13_15.png");
}
