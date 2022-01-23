{
  gROOT->ProcessLine(".L root2txt.cpp");

  gROOT->ProcessLine("root2txt(200)");
  gROOT->ProcessLine("root2txt(320)");
  gROOT->ProcessLine("root2txt(330)");
  gROOT->ProcessLine("root2txt(340)");

  gROOT->ProcessLine(".q");
}
