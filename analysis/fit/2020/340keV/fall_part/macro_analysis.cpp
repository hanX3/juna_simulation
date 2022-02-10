{
  gROOT->ProcessLine(".!rm -f ../../../../../../result/2020/340keV/chi2_fall_part.dat");

  gROOT->ProcessLine(".L analysis.cpp");
  gROOT->ProcessLine("analysis(337.6)");
  gROOT->ProcessLine("analysis(337.7)");
  gROOT->ProcessLine("analysis(337.8)");
  gROOT->ProcessLine("analysis(337.9)");
  gROOT->ProcessLine("analysis(338.0)");
  gROOT->ProcessLine("analysis(338.1)");
  gROOT->ProcessLine("analysis(338.2)");
  gROOT->ProcessLine("analysis(338.3)");
  gROOT->ProcessLine("analysis(338.4)");
  gROOT->ProcessLine("analysis(338.5)");
  gROOT->ProcessLine("analysis(338.6)");
  gROOT->ProcessLine("analysis(338.7)");
  gROOT->ProcessLine("analysis(338.8)");
  gROOT->ProcessLine("analysis(338.9)");
  gROOT->ProcessLine("analysis(339.0)");
  gROOT->ProcessLine("analysis(339.1)");
  gROOT->ProcessLine("analysis(339.2)");
  gROOT->ProcessLine("analysis(339.3)");
  gROOT->ProcessLine("analysis(339.4)");
  gROOT->ProcessLine("analysis(339.5)");
  gROOT->ProcessLine("analysis(339.6)");
  gROOT->ProcessLine("analysis(339.7)");
  gROOT->ProcessLine("analysis(339.8)");
  gROOT->ProcessLine("analysis(339.9)");
  gROOT->ProcessLine("analysis(340.0)");
  gROOT->ProcessLine("analysis(340.1)");
  gROOT->ProcessLine("analysis(340.2)");
  gROOT->ProcessLine("analysis(340.3)");

  gROOT->ProcessLine(".q");
}
