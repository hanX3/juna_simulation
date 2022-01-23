{
  gROOT->ProcessLine(".L root2txt.cpp");

  gROOT->ProcessLine("root2txt(180)");
  gROOT->ProcessLine("root2txt(200)");
  gROOT->ProcessLine("root2txt(270)");
  gROOT->ProcessLine("root2txt(290)");
  gROOT->ProcessLine("root2txt(300)");
  gROOT->ProcessLine("root2txt(310)");
  gROOT->ProcessLine("root2txt(320)");
  gROOT->ProcessLine("root2txt(330)");
  gROOT->ProcessLine("root2txt(340)");
  gROOT->ProcessLine("root2txt(350)");
  gROOT->ProcessLine("root2txt(360)");

  gROOT->ProcessLine(".q");
}
