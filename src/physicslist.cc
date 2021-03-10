#include "physicslist.hh"

physicslist::physicslist() : G4VUserPhysicsList()
{


}

physicslist::~physicslist()
{
  
}

void physicslist::ConstructParticle()
{
  G4Electron::Definition();
  G4Positron::Definition();
  G4MuonMinus::Definition();
  G4Gamma::Definition();
  G4GenericIon::Definition();
}

void physicslist::ConstructProcess()
{

  AddTransportation();
  
  G4ParticleDefinition *electron = G4Electron::Definition();
  G4ProcessManager *emanager = electron -> GetProcessManager();
  
  emanager -> AddProcess(new G4eMultipleScattering(), -1, 1, 1);
  emanager -> AddProcess(new G4eIonisation(), -1, 2, 2);
  emanager -> AddProcess(new G4eBremsstrahlung(), -1, -1, 3);
  emanager -> AddDiscreteProcess(new G4StepLimiter);

  
  G4ParticleDefinition *muon = G4MuonMinus::Definition();
  G4ProcessManager *mmanager = muon -> GetProcessManager();
  
  mmanager -> AddProcess(new G4MuMultipleScattering(), -1, 1, 1);
  mmanager -> AddProcess(new G4MuIonisation(), -1, 2, 2);
  mmanager -> AddProcess(new G4MuBremsstrahlung(), -1, 3, 3);
  mmanager -> AddProcess(new G4MuPairProduction(), -1, 4, 4);
  mmanager -> AddProcess(new G4CoulombScattering(), -1, -1, 5);
  mmanager -> AddDiscreteProcess(new G4StepLimiter);

  G4ParticleDefinition *ion = G4GenericIon::Definition();
  G4ProcessManager *imanager = ion -> GetProcessManager();
  imanager -> AddProcess(new G4ionIonisation(), -1, 1, 1);
}

void physicslist::SetCuts()
{
  defaultCutValue = 1 * nm;
  SetCutsWithDefault();
}

