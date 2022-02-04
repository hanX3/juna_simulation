{
  gROOT->ProcessLine(".L getrootfile.cpp");

  //200keV
  gROOT->ProcessLine("getrootfile(200, 199.0)");
  gROOT->ProcessLine("getrootfile(200, 199.1)");
  gROOT->ProcessLine("getrootfile(200, 199.2)");
  gROOT->ProcessLine("getrootfile(200, 199.3)");
  gROOT->ProcessLine("getrootfile(200, 199.4)");
  gROOT->ProcessLine("getrootfile(200, 199.5)");
  gROOT->ProcessLine("getrootfile(200, 199.6)");
  gROOT->ProcessLine("getrootfile(200, 199.7)");
  gROOT->ProcessLine("getrootfile(200, 199.8)");
  gROOT->ProcessLine("getrootfile(200, 199.9)");
  gROOT->ProcessLine("getrootfile(200, 200.0)");
  gROOT->ProcessLine("getrootfile(200, 200.1)");
  gROOT->ProcessLine("getrootfile(200, 200.2)");
  gROOT->ProcessLine("getrootfile(200, 200.3)");
  gROOT->ProcessLine("getrootfile(200, 200.4)");
  gROOT->ProcessLine("getrootfile(200, 200.5)");
  gROOT->ProcessLine("getrootfile(200, 200.6)");
  gROOT->ProcessLine("getrootfile(200, 200.7)");
  gROOT->ProcessLine("getrootfile(200, 200.8)");
  gROOT->ProcessLine("getrootfile(200, 200.9)");
  gROOT->ProcessLine("getrootfile(200, 201.0)");

  gROOT->ProcessLine(".q");
}
