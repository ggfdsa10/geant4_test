#include "track.hh"
#include "OTEventAction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"

#include "G4EventManager.hh"

track::track()
: G4UserTrackingAction()
{
}

track::~track()
{
}


void track::PreUserTrackingAction(const G4Track* t)
{
  G4int parentID = t -> GetParentID();
  
  G4double energy = t -> GetKineticEnergy();


  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

  G4int eventID = G4RunManager::GetRunManager() -> GetCurrentEvent() -> GetEventID();
  
  OTEventAction *eventAction = (OTEventAction *) G4EventManager::GetEventManager() -> GetUserEventAction();
  if (parentID == 1)
    {
      analysisManager -> FillNtupleIColumn(0, eventID);
      analysisManager -> FillNtupleDColumn(1, energy);
      analysisManager -> AddNtupleRow();
      eventAction -> GenerateElectron(parentID);
      
    }
}
