#ifndef OTEVENTACTION_HH
#define OTEVENTACTION_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "globals.hh"
#include "g4root.hh"

class OTEventAction : public G4UserEventAction
{
  public:
    OTEventAction();
    virtual ~OTEventAction();

    // method from the base class
    virtual void BeginOfEventAction(const G4Event *);
    virtual void EndOfEventAction(const G4Event *);

    void GenerateElectron(G4double count) { generate += count; }


  private:
    G4double generate;

	      
	      
};

#endif
