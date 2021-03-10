#include "OTSteppingAction.hh"
#include "OTEventAction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"

#include "G4EventManager.hh"

OTSteppingAction::OTSteppingAction()
: G4UserSteppingAction()
{
}

OTSteppingAction::~OTSteppingAction()
{
}

void OTSteppingAction::UserSteppingAction(const G4Step* step)
{
}
