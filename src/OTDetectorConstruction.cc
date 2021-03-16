#include "OTDetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

OTDetectorConstruction::OTDetectorConstruction()
: G4VUserDetectorConstruction()
{
}

OTDetectorConstruction::~OTDetectorConstruction()
{
}

G4VPhysicalVolume* OTDetectorConstruction::Construct()
{  
  G4NistManager* nist = G4NistManager::Instance();


  // -----------------------------------------------------
  // World

  G4Material* world_mat = nist -> FindOrBuildMaterial("G4_AIR");

  G4Box* solidWorld = new G4Box("World", 5.*cm, 5.*cm, 5.*cm);
  
  G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, world_mat, "World"); 
                                   
  G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World", 0, false, 0, true);     


  // -----------------------------------------------------
  // Detector

  G4double Temperature = 293.15 *kelvin;
  
  G4double Ardensity = 0.00166201 *g/cm3;
  G4double Methanedensity = 0.000668 *g/cm3;
  G4double P10density = 0.0015617 *g/cm3;
  
  G4Material *ArGas = new G4Material("ArgonGas", 18, 39.948*g/mole, Ardensity, kStateGas, Temperature);

  G4Material* methane = nist -> FindOrBuildMaterial("G4_METHANE");
  G4Material *MethaneGas = new G4Material("matMethaneGas", Methanedensity, methane, kStateGas, Temperature);

  G4Material *p10 = nullptr;
  p10 = new G4Material("matP10", P10density, 2, kStateGas, Temperature);
  p10 -> AddMaterial(ArGas, 0.9 *perCent);
  p10 -> AddMaterial(MethaneGas, 0.1 *perCent);


  G4Box* solidDetector = new G4Box("Detector", 5.*cm, 5.*cm, 5.*cm);
      
  G4LogicalVolume* logicDetector = new G4LogicalVolume(solidDetector, p10, "Detector");
                                   
  new G4PVPlacement(0, G4ThreeVector(), logicDetector, "Detector", logicWorld, false, 1, true);

  return physWorld;
}
