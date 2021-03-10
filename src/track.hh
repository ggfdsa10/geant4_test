#ifndef TRACK_HH
#define TRACK_HH

#include "G4UserTrackingAction.hh"
#include "G4Track.hh"
#include "globals.hh"
#include "g4root.hh"

class track : public G4UserTrackingAction
{
public:
  track();
  virtual ~track();

  virtual void PreUserTrackingAction(const G4Track*);

};

#endif
