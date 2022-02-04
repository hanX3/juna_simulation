{
  gROOT->ProcessLine(".!rm -f ../../../../../../result/2020/330keV/chi2_fall_part.dat");

  gROOT->ProcessLine(".L analysis.cpp");
  gROOT->ProcessLine("analysis(328.2)");
  gROOT->ProcessLine("analysis(328.3)");
  gROOT->ProcessLine("analysis(328.4)");
  gROOT->ProcessLine("analysis(328.5)");
  gROOT->ProcessLine("analysis(328.6)");
  gROOT->ProcessLine("analysis(328.7)");
  gROOT->ProcessLine("analysis(328.8)");
  gROOT->ProcessLine("analysis(328.9)");
  gROOT->ProcessLine("analysis(329.0)");
  gROOT->ProcessLine("analysis(329.1)");
  gROOT->ProcessLine("analysis(329.2)");
  gROOT->ProcessLine("analysis(329.3)");
  gROOT->ProcessLine("analysis(329.4)");
  gROOT->ProcessLine("analysis(329.5)");
  gROOT->ProcessLine("analysis(329.6)");
  gROOT->ProcessLine("analysis(329.7)");
  gROOT->ProcessLine("analysis(329.8)");
  gROOT->ProcessLine("analysis(329.9)");
  gROOT->ProcessLine("analysis(330.0)");
  gROOT->ProcessLine("analysis(330.1)");
  gROOT->ProcessLine("analysis(330.2)");

  gROOT->ProcessLine(".q");
}
