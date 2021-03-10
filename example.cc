#include "globals.hh"
#include <time.h>

#include "G4RunManager.hh"
#include "G4VisExecutive.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"

#include "QGSP_BERT.hh"
#include "OTDetectorConstruction.hh"
#include "OTPrimaryGeneratorAction.hh"
#include "OTRunAction.hh"
#include "OTEventAction.hh"
#include "OTSteppingAction.hh"
#include "track.hh"

#include "physicslist.hh" //user physics list
#include "modularplist.hh" // modular physics list


int main(int argc, char** argv)
{
  
  G4RunManager* runManager = new G4RunManager;

  G4VModularPhysicsList* plist = new modularplist();
  runManager -> SetUserInitialization(plist);
  runManager -> SetUserInitialization(new OTDetectorConstruction());
  runManager -> SetUserAction(new OTPrimaryGeneratorAction());
  if (argc != 1)
    runManager -> SetUserAction(new OTRunAction(argv[1]));
  else
    runManager -> SetUserAction(new OTRunAction());

  runManager -> SetUserAction(new OTEventAction());
  runManager -> SetUserAction(new track());
  runManager -> SetUserAction(new OTSteppingAction());
  runManager -> Initialize();
  
  G4VisManager* visManager = new G4VisExecutive;
  visManager -> Initialize();

  G4UImanager* UImanager = G4UImanager::GetUIpointer();
  if (argc != 1) 
  {
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager -> ApplyCommand(command+fileName);
  }
  else 
  {
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    UImanager -> ApplyCommand("/control/execute vis.mac");
    UImanager -> ApplyCommand("/run/beamOn 10000");
    ui -> SessionStart();
    delete ui;
  }

  delete visManager;
  delete runManager;

  return 0;
}
