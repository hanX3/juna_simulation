{
  gROOT->ProcessLine(".!rm -f ../../../../../../result/2019/320keV/chi2_fall_part.dat");

  gROOT->ProcessLine(".L analysis.cpp");
  gROOT->ProcessLine("analysis(317.1)");
  gROOT->ProcessLine("analysis(317.2)");
  gROOT->ProcessLine("analysis(317.3)");
  gROOT->ProcessLine("analysis(317.4)");
  gROOT->ProcessLine("analysis(317.5)");
  gROOT->ProcessLine("analysis(317.6)");
  gROOT->ProcessLine("analysis(317.7)");
  gROOT->ProcessLine("analysis(317.8)");
  gROOT->ProcessLine("analysis(317.9)");
  gROOT->ProcessLine("analysis(318.0)");
  gROOT->ProcessLine("analysis(318.1)");
  gROOT->ProcessLine("analysis(318.2)");
  gROOT->ProcessLine("analysis(318.3)");
  gROOT->ProcessLine("analysis(318.4)");
  gROOT->ProcessLine("analysis(318.5)");
  gROOT->ProcessLine("analysis(318.6)");
  gROOT->ProcessLine("analysis(318.7)");
  gROOT->ProcessLine("analysis(318.8)");
  gROOT->ProcessLine("analysis(318.9)");
  gROOT->ProcessLine("analysis(319.0)");
  gROOT->ProcessLine("analysis(319.1)");
  gROOT->ProcessLine("analysis(319.2)");
  gROOT->ProcessLine("analysis(319.3)");
  gROOT->ProcessLine("analysis(319.4)");
  gROOT->ProcessLine("analysis(319.5)");
  gROOT->ProcessLine("analysis(319.6)");
  gROOT->ProcessLine("analysis(319.7)");
  gROOT->ProcessLine("analysis(319.8)");

  gROOT->ProcessLine(".q");
}
