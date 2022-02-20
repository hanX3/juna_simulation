{
  gROOT->ProcessLine(".!rm -f ../../../../../../result/2019/350keV/chi2_fall_part.dat");

  gROOT->ProcessLine(".L analysis.cpp");
  gROOT->ProcessLine("analysis(347.0)");
  gROOT->ProcessLine("analysis(347.1)");
  gROOT->ProcessLine("analysis(347.2)");
  gROOT->ProcessLine("analysis(347.3)");
  gROOT->ProcessLine("analysis(347.4)");
  gROOT->ProcessLine("analysis(347.5)");
  gROOT->ProcessLine("analysis(347.6)");
  gROOT->ProcessLine("analysis(347.7)");
  gROOT->ProcessLine("analysis(347.8)");
  gROOT->ProcessLine("analysis(347.9)");
  gROOT->ProcessLine("analysis(348.0)");
  gROOT->ProcessLine("analysis(348.1)");
  gROOT->ProcessLine("analysis(348.2)");
  gROOT->ProcessLine("analysis(348.3)");
  gROOT->ProcessLine("analysis(348.4)");
  gROOT->ProcessLine("analysis(348.5)");
  gROOT->ProcessLine("analysis(348.6)");
  gROOT->ProcessLine("analysis(348.7)");
  gROOT->ProcessLine("analysis(348.8)");
  gROOT->ProcessLine("analysis(348.9)");
  gROOT->ProcessLine("analysis(349.0)");
  gROOT->ProcessLine("analysis(349.1)");
  gROOT->ProcessLine("analysis(349.2)");
  gROOT->ProcessLine("analysis(349.3)");
  gROOT->ProcessLine("analysis(349.4)");
  gROOT->ProcessLine("analysis(349.5)");

  gROOT->ProcessLine(".q");
}
