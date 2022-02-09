#include "JUNAReaction.hh"

#include "TGenPhaseSpace.h"

#include "G4DynamicParticle.hh"
#include "Randomize.hh"
#include "G4ParticleMomentum.hh"
#include "G4IonTable.hh"
#include "G4IonTable.hh"
#include "globals.hh"
#include "G4Proton.hh"
#include "G4Neutron.hh"
#include "G4Gamma.hh"
#include "G4Nucleus.hh"
#include "G4IonTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"

#include "Constants.hh"

JUNAReaction::JUNAReaction(): G4HadronicInteraction()
{

  SetMinEnergy(0. * keV);
  SetMaxEnergy(100. * MeV);
  isBlocked = false;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
JUNAReaction::~JUNAReaction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
G4HadFinalState *JUNAReaction::ApplyYourself(const G4HadProjectile &projectile, G4Nucleus &targetNucleus)
{
  theParticleChange.Clear();
  theParticleChange.SetStatusChange(stopAndKill);

  G4LorentzVector proLonVector = projectile.Get4Momentum();
  G4int targetZ = targetNucleus.GetZ_asInt();
  const G4int targetA = targetNucleus.GetA_asInt();
  const G4int projectA = projectile.GetDefinition()->GetBaryonNumber();

  if(projectA==0);
  else if(projectA==1 && targetA==12){
    G4ParticleDefinition *target = G4IonTable::GetIonTable()->GetIon(targetZ, targetA, 0. * keV);
    G4ParticleDefinition *product0 = G4Gamma::GammaDefinition();
    G4ParticleDefinition *product1 = G4IonTable::GetIonTable()->GetIon(targetZ+1, targetA+1, 0. * keV);
    ReactionKinematic(projectile, target, product0, product1);
  }

  return &theParticleChange;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void JUNAReaction::ReactionKinematic(const G4HadProjectile &projectile, G4ParticleDefinition *targetNucleus, G4ParticleDefinition *product0, G4ParticleDefinition *product1)
{
  G4DynamicParticle* targetDynamic = new G4DynamicParticle(targetNucleus, G4ThreeVector(0., 0., 0.), 0);
  G4LorentzVector proLonVector = projectile.Get4Momentum();//unit MeV
  G4LorentzVector tarLonVector = targetDynamic->Get4Momentum();//unit MeV
  G4LorentzVector compoundLonVector = proLonVector + tarLonVector;//unit MeV

  G4double massProduct0 = product0->GetPDGMass();//unit MeV
  G4double massProduct1 = product1->GetPDGMass();//unit MeV
  G4double mass[2] = {massProduct0/1000., massProduct1/1000.};
  TGenPhaseSpace react;
  TLorentzVector compoundROOTLonVector;
  compoundROOTLonVector.SetPxPyPzE(compoundLonVector.px()/1000., compoundLonVector.py()/1000., compoundLonVector.pz()/1000., compoundLonVector.e()/1000.);
  //lab 2 cm
  //TVector3 boost = compoundROOTLonVector.BoostVector();
  //compoundROOTLonVector.Boost(boost);

  react.SetDecay(compoundROOTLonVector, 2, mass);
  react.Generate();

  G4LorentzVector product0LonVector, product1LonVector;

  TLorentzVector *decay0LonVector = react.GetDecay(0);//GeV
  TLorentzVector *decay1LonVector = react.GetDecay(1);//GeV
  product0LonVector.setPx(decay0LonVector->Px()*1000.);
  product0LonVector.setPy(decay0LonVector->Py()*1000.);
  product0LonVector.setPz(decay0LonVector->Pz()*1000.);
  product0LonVector.setE(decay0LonVector->E()*1000.);
  product1LonVector.setPx(decay1LonVector->Px()*1000.);
  product1LonVector.setPy(decay1LonVector->Py()*1000.);
  product1LonVector.setPz(decay1LonVector->Pz()*1000.);
  product1LonVector.setE(decay1LonVector->E()*1000.);

  G4DynamicParticle *product0Dynamic, *product1Dynamic;
  product0Dynamic = new G4DynamicParticle(product0, product0LonVector);
  product1Dynamic = new G4DynamicParticle(product1, product1LonVector);

  // Add the secondaries to the particle change stack
  // Changes being included in process
  theParticleChange.AddSecondary(product0Dynamic);
  theParticleChange.AddSecondary(product1Dynamic);
}

