#include "JUNACrossSection.hh"


JUNACrossSection::JUNACrossSection()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
JUNACrossSection::~JUNACrossSection()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
G4double JUNACrossSection::GetIsoCrossSection(const G4DynamicParticle *aPar, G4int Z, G4int A, const G4Isotope *, const G4Element *, const G4Material *)
{
  G4double crossSection = 0.;
  const G4int aParA = aPar->GetDefinition()->GetBaryonNumber();
  if(aParA==0);
  else if(aParA==1 && Z==6 && A==12){
    G4double ecm = GetEcmValue(aParA, A, aPar->GetKineticEnergy() / MeV);
    G4double sfactor = 0.;
    if(ecm>=0.05 && ecm<=0.4){
      sfactor = 0.000471809 + 0.110481*pow(ecm,1) - 5.06133*pow(ecm,2) + 122.269*pow(ecm,3) - 1654.18*pow(ecm,4) + 13258*pow(ecm,5) - 64040.7*pow(ecm,6) + 182673*pow(ecm,7) - 282948*pow(ecm,8) + 183438*pow(ecm,9);//fit1
      //sfactor = 0.006189 - 0.347591*pow(ecm,1) + 9.95393*pow(ecm,2) - 142.206*pow(ecm,3) + 1115.39*pow(ecm,4) - 4726.65*pow(ecm,5) + 8875.54*pow(ecm,6) + 3396.01*pow(ecm,7) - 38690.9*pow(ecm,8) + 42003.2*pow(ecm,9);//fit 2
    }
    else{
      sfactor = 0.;
    }
    /*
    if(ecm>=0.2 && ecm<0.25){
      sfactor = 0.1849*ecm*ecm-0.01524*ecm+0.006219;
    }
    else if(ecm>=0.25 && ecm<0.3){
      sfactor = 3.505*pow(ecm,3)-2.065*pow(ecm,2)+0.4148*ecm-0.02436;
    }
    else if(ecm>=0.3 && ecm<0.35){
      sfactor = 35.18*pow(ecm,3)-30.75*pow(ecm,2)+9.076*ecm-0.8964;
    }
    else if(ecm>=0.3 && ecm<0.4){
      sfactor = 1.204*pow(10,-16)*exp(84.78*ecm)+1.115*pow(10,-5)*exp(21.63*ecm);
    }
    else{
      crossSection = 0.;
    }
    */
    G4double eta = 0.1575*1.*6*sqrt((1.*12.)/(1.+12.)/ecm);
    crossSection = sfactor*exp(-2.*3.1415926*eta)/ecm * barn;
    crossSection *= 1e10;
  }
  else{
    crossSection = 0.;
  }

  return crossSection;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
G4double JUNACrossSection::GetEcmValue(G4double projectA, G4double targetA, G4double elab)
{
  return targetA/(projectA+targetA)*elab;
}
