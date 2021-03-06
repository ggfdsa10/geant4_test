#include "OTPrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

OTPrimaryGeneratorAction::OTPrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction()
{
  G4int n_particle = 1;
  fParticleGun = new G4ParticleGun(n_particle);

  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4ParticleDefinition* particle
    = particleTable -> FindParticle(particleName = "mu-");

  fParticleGun -> SetParticleDefinition(particle);
  fParticleGun -> SetParticlePosition(G4ThreeVector(-5.*cm,0.,0.));
  fParticleGun -> SetParticleMomentumDirection(G4ThreeVector(1.,0.,0.));
  fParticleGun -> SetParticleEnergy(4.*GeV);
}

OTPrimaryGeneratorAction::~OTPrimaryGeneratorAction()
{
  delete fParticleGun;
}

void OTPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  //this function is called at the begining of each event

  fParticleGun -> GeneratePrimaryVertex(anEvent);
}
