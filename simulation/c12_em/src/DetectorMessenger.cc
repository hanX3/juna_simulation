#include "DetectorMessenger.hh"
#include "DetectorConstruction.hh"

#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
DetectorMessenger::DetectorMessenger(DetectorConstruction *det)
: G4UImessenger(),
  detectorConstruction(det)
{
  directory = new G4UIdirectory("/juna/");
  directory->SetGuidance("UI commands specific to this example.");

  detDirectory = new G4UIdirectory("/juna/det/");
  detDirectory->SetGuidance("Detector construction control");

  stepMaxCmd = new G4UIcmdWithADoubleAndUnit("/juna/det/stepMax", this);
  stepMaxCmd->SetGuidance("Define a step max");
  stepMaxCmd->SetParameterName("stepMax", false);
  stepMaxCmd->SetUnitCategory("Length");
  stepMaxCmd->AvailableForStates(G4State_Idle);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
DetectorMessenger::~DetectorMessenger()
{
  delete stepMaxCmd;
  delete directory;
  delete detDirectory;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void DetectorMessenger::SetNewValue(G4UIcommand* command, G4String newValue)
{
  if(command == stepMaxCmd){
    G4cout << "!!!!<<<<<<<<<<<   stepMax  " << stepMaxCmd->GetNewDoubleValue(newValue) << G4endl;
    detectorConstruction->SetMaxStep(stepMaxCmd->GetNewDoubleValue(newValue));
  }
}
