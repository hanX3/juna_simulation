{
  gROOT->ProcessLine(".!rm -f ../../../../../../result/2020/200keV/chi2_fall_part.dat");

  gROOT->ProcessLine(".L analysis.cpp");
  gROOT->ProcessLine("analysis(198.2)");
  gROOT->ProcessLine("analysis(198.3)");
  gROOT->ProcessLine("analysis(198.4)");
  gROOT->ProcessLine("analysis(198.5)");
  gROOT->ProcessLine("analysis(198.6)");
  gROOT->ProcessLine("analysis(198.7)");
  gROOT->ProcessLine("analysis(198.8)");
  gROOT->ProcessLine("analysis(198.9)");
  gROOT->ProcessLine("analysis(199.0)");
  gROOT->ProcessLine("analysis(199.1)");
  gROOT->ProcessLine("analysis(199.2)");
  gROOT->ProcessLine("analysis(199.3)");
  gROOT->ProcessLine("analysis(199.4)");
  gROOT->ProcessLine("analysis(199.5)");
  gROOT->ProcessLine("analysis(199.6)");
  gROOT->ProcessLine("analysis(199.7)");
  gROOT->ProcessLine("analysis(199.8)");
  gROOT->ProcessLine("analysis(199.9)");
  gROOT->ProcessLine("analysis(200.0)");
  gROOT->ProcessLine("analysis(200.1)");
  gROOT->ProcessLine("analysis(200.2)");
  gROOT->ProcessLine("analysis(200.3)");
  gROOT->ProcessLine("analysis(200.4)");
  gROOT->ProcessLine("analysis(200.5)");
  gROOT->ProcessLine("analysis(200.6)");
  gROOT->ProcessLine("analysis(200.7)");
  gROOT->ProcessLine("analysis(200.8)");
  gROOT->ProcessLine("analysis(200.9)");
  gROOT->ProcessLine("analysis(201.0)");

  gROOT->ProcessLine(".q");
}
