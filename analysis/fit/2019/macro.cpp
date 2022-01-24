{
  gROOT->ProcessLine(".L getrootfile_new.cpp");

  gROOT->ProcessLine("getrootfile_new(179.2)");
  gROOT->ProcessLine("getrootfile_new(179.4)");
  gROOT->ProcessLine("getrootfile_new(179.6)");
  gROOT->ProcessLine("getrootfile_new(179.8)");
  gROOT->ProcessLine("getrootfile_new(180.0)");
  gROOT->ProcessLine("getrootfile_new(180.2)");
  gROOT->ProcessLine("getrootfile_new(180.4)");
  gROOT->ProcessLine("getrootfile_new(180.6)");
  
  gROOT->ProcessLine(".q");
}
