//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: GEMDriftChamberHit.hh,v 1.5 2006-06-29 16:30:55 gunter Exp $
// --------------------------------------------------------------
//
#ifndef GEMDriftChamberHit_h
#define GEMDriftChamberHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"
#include "G4Transform3D.hh"
#include "G4RotationMatrix.hh"

class G4AttDef;
class G4AttValue;

class GEMDriftChamberHit : public G4VHit
{
  public:

      GEMDriftChamberHit();
      GEMDriftChamberHit(G4int z);
      virtual ~GEMDriftChamberHit();
      GEMDriftChamberHit(const GEMDriftChamberHit &right);
      const GEMDriftChamberHit& operator=(const GEMDriftChamberHit &right);
      int operator==(const GEMDriftChamberHit &right) const;

      inline void *operator new(size_t);
      inline void operator delete(void *aHit);

	  inline float x();
	  inline float y();

      virtual void Draw();
      virtual const std::map<G4String,G4AttDef>* GetAttDefs() const;
      virtual std::vector<G4AttValue>* CreateAttValues() const;
      virtual void Print();

  private:
      G4int layerID;
      G4double time;
      G4ThreeVector localPos;
      G4ThreeVector worldPos;

  public:
      inline void SetLayerID(G4int z) { layerID = z; }
      inline G4int GetLayerID() const { return layerID; }
      inline void SetTime(G4double t) { time = t; }
      inline G4double GetTime() const { return time; }
      inline void SetLocalPos(G4ThreeVector xyz) { localPos = xyz; }
      inline G4ThreeVector GetLocalPos() const { return localPos; }
      inline void SetWorldPos(G4ThreeVector xyz) { worldPos = xyz; }
      inline G4ThreeVector GetWorldPos() const { return worldPos; }
};

typedef G4THitsCollection<GEMDriftChamberHit> GEMDriftChamberHitsCollection;

extern G4Allocator<GEMDriftChamberHit> GEMDriftChamberHitAllocator;

inline void* GEMDriftChamberHit::operator new(size_t)
{
  void* aHit;
  aHit = (void*)GEMDriftChamberHitAllocator.MallocSingle();
  return aHit;
}

inline void GEMDriftChamberHit::operator delete(void* aHit)
{
  GEMDriftChamberHitAllocator.FreeSingle((GEMDriftChamberHit*) aHit);
}

#endif


