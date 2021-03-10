#ifndef MODULARPLIST_HH
#define MODULARPLIST_HH

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4EmLivermorePhysics.hh"


class modularplist : public G4VModularPhysicsList
{
public:
  modularplist();
  virtual~modularplist();

};

#endif
