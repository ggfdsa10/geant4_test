#include "OTRunAction.hh"

OTRunAction::OTRunAction()
: G4UserRunAction()
{
  fName = "data";
}

OTRunAction::OTRunAction(const char *name)
: G4UserRunAction()
{
  fName = name;
}

OTRunAction::~OTRunAction()
{
  delete G4AnalysisManager::Instance();
}

void OTRunAction::BeginOfRunAction(const G4Run*)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager -> OpenFile(fName);

  analysisManager -> CreateNtuple("electron_energy", "electron_energy");
  analysisManager -> CreateNtupleIColumn("eventID");
  analysisManager -> CreateNtupleDColumn("energy");
  analysisManager -> FinishNtuple();

  analysisManager -> CreateNtuple("generate_electron", "generate_electron");
  analysisManager -> CreateNtupleIColumn("generate_count");
  analysisManager -> FinishNtuple();
}

void OTRunAction::EndOfRunAction(const G4Run*)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager -> Write();
  analysisManager -> CloseFile();
}
