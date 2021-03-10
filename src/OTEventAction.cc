#include "OTEventAction.hh"

OTEventAction::OTEventAction()
: G4UserEventAction()
{
}

OTEventAction::~OTEventAction()
{
}

void OTEventAction::BeginOfEventAction(const G4Event*)
{
  generate = 0.;
 
}

void OTEventAction::EndOfEventAction(const G4Event*)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

  analysisManager -> FillNtupleIColumn(1, 0, generate);
  analysisManager -> AddNtupleRow(1);
}
