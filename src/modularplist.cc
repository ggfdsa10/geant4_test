#include "modularplist.hh"

modularplist::modularplist() : G4VModularPhysicsList()
{
  RegisterPhysics(new G4EmStandardPhysics_option4());

}

modularplist::~modularplist()
{

}
