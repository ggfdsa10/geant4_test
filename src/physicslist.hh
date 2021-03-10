#ifndef PHYSICSLIST_HH
#define PHYSICSLIST_HH

#include "G4VUserPhysicsList.hh"
#include "G4ProcessManager.hh"
#include "G4ParticleDefinition.hh"
#include "G4StepLimiter.hh"
#include "G4SystemOfUnits.hh"
#include "G4CoulombScattering.hh"

#include "G4Electron.hh"
#include "G4Positron.hh"
#include "G4eMultipleScattering.hh"
#include "G4eIonisation.hh"
#include "G4eBremsstrahlung.hh"

#include "G4MuonMinus.hh"
#include "G4MuMultipleScattering.hh"
#include "G4MuIonisation.hh"
#include "G4MuBremsstrahlung.hh"
#include "G4MuPairProduction.hh"

#include "G4Gamma.hh"

#include "G4GenericIon.hh"
#include "G4ionIonisation.hh"

class physicslist : public G4VUserPhysicsList
{
public:
  physicslist();
  virtual ~physicslist();


  void ConstructParticle();
  void ConstructProcess(); 
  void SetCuts();

};

#endif
