
void cali_200keV()
{
  TFile *ff;
  ff = TFile::Open("../../../../exp_data/2020_rawdata/rootfile/c_200keV.root");

  TH1D *h1 = (TH1D*)ff->Get("h1");
  auto cc = new TCanvas("cc", "cc", 0, 0, 480, 360);
  cc->cd();
  h1->Draw();

  TF1 *tffit = new TF1("tffit", "[0]+gaus(1)");

  double p[5] = {2601.2, 3393.3, 4099.3, 5121.9, 6083.4};
  double e[5] = {1120.3, 1460.9, 1764.5, 2204.2, 2614.5};
  TF1 *tf[5];
  double par[4*5];
  for(int i=0;i<5;++i){
    tffit->SetParameter(0, 10.);
    tffit->SetParameter(2, p[i]);
    tffit->SetParameter(3, 3.);
    h1->Fit("tffit", "0", "", -10.+p[i], 10.+p[i]);
  
    tf[i] = (TF1*)h1->GetFunction("tffit");
    for(int j=0;j<4;j++){
      par[4*i+j] = tf[i]->GetParameter(j);
      cout << par[4*i+j] << endl;
    }
  }

  auto cc1 = new TCanvas("cc1", "cc1", 0, 0, 480, 360);
  cc1->cd();
  h1->Draw();
  TF1 *tf2[5];
  for(int i=0;i<5;++i){
    tf2[i] = new TF1(TString::Format("tf2%d",i).Data(), "[0]+gaus(1)", -10.+p[i], 10.+p[i]);
    for(int j=0;j<4;++j){
      tf2[i]->SetParameter(j, par[4*i+j]);
      cout << par[4*i+j] << endl;
    }
    tf2[i]->Draw("same");
  }

  cc1->SaveAs("cc1.pdf");

  auto cc2 = new TCanvas("cc2", "cc2", 0, 0, 480, 360);
  cc2->Draw();
  TGraph *gr = new TGraph();
  for(int i=0;i<5;i++){
    gr->SetPoint(i, par[4*i+2], e[i]);
  }
  gr->Draw("AP*");
  gr->Fit("pol1");

  TF1* tff = (TF1*)gr->GetFunction("pol1");
  TPaveLabel *pp = new TPaveLabel(0.15,0.85,0.75,0.95, Form("b = %g, k = %g",tff->GetParameter(0),tff->GetParameter(1)), "brNDC");
  pp->SetTextColor(kRed+3);
  pp->Draw();

  cc2->SaveAs("cc2.pdf");
}
