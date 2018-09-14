#ifndef __GRETINA_H
#define __GRETINA_H

#include "Riostream.h"
#include "Rtypes.h"

#include "TObject.h"
#include "TString.h"
#include "TVector3.h"
#include "TMath.h"
#include "TRandom1.h"
#include "TClass.h"

#include <vector>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "Defines.h"
#include "colors.h"

using std::vector;
using std::cout;  using std::endl;
using std::swap;

class g3Waveform : public TObject {

 public:
  vector<Short_t> raw;
  vector<Float_t> pz;
  
 public:
  void Clear();
  Int_t LEDLevel(Int_t index, Int_t thresh, Int_t filterK);
  Int_t LED(Int_t index, Int_t thresh, Int_t filterK);
  Float_t CFD(Int_t startSample);
  Float_t BL(Int_t start, Int_t end);
  Int_t Look4Pileup();
  void calcPZ(Float_t base, Float_t tau);
  Float_t simpleE();
  Float_t riseTime(Float_t fLow, Float_t fHigh);
  Double_t computeChiSquare(Int_t startIndex, Int_t nPoints,
			    Double_t tau, Double_t nStart, Double_t baseline);
  Double_t LSFitExpo(Int_t startIndex, Int_t nPoints,
		     Double_t nStart, Double_t tau,
		     Double_t &nStartFit, Double_t &baselineFit,
		     Double_t &nStartFitError,
		     Double_t &baselineFitError);
  Double_t LSFitLinear(Int_t startIndex, Int_t nPoints,
		       Double_t &slopeFit, Double_t &offsetFit);
  Float_t baseline2Flatten(Float_t tau, Int_t startIndexBase,
			   Int_t lengthBase, Int_t startIndexTop,
			   Int_t lengthTop, Float_t smallStep);
  
  ClassDef(g3Waveform, 1);
};

class g3ChannelEvent : public TObject {

 public:
  UShort_t hdr0, hdr1, hdr7;
  Int_t ID;
  Int_t segNum;
  Float_t eRaw, eCal;
  /* These are for event history, available in firmware 2.00_006f and beyond. */
  Float_t eCalPO, prevE1, prevE2;
  UShort_t deltaT1, deltaT2;
  UShort_t PZrollover;

  Float_t eCalc;
  Float_t calcTime;
  long long int timestamp;
  long long int CFDtimestamp;
  Float_t baseline;
  Float_t riseTime;
  g3Waveform wf;

 public:
  Int_t module() { return (hdr1 >> 4); }
  Int_t boardID() { return (hdr0 >> 11); }
  Int_t chanID() { return (hdr1 & 0xf); }
  Int_t tracelength() { return (((hdr0 & 0x7ff)*2) - 14); }
  Int_t chnNum() { return (ID%40); }
  Bool_t sign() { return (hdr7 & 0x0100); }
  Int_t pileUp() { return ((hdr7 & 0x8000) >> 15); }    

 public:

  ClassDef(g3ChannelEvent, 3);
};

class g3CrystalEvent : public TObject {
 
 public:
  Int_t crystalNum, quadNum, module;
  Int_t runNumber;
  Float_t dopplerSeg, dopplerCrystal;
  Int_t traceLength;
  Float_t segSum, segSumTimed, segSumTimed2;
  vector<g3ChannelEvent> chn;

 public:
  void OrderChannels();
  Float_t cc1();
  Float_t cc2();
  Float_t cc3();
  Float_t cc4();
  Float_t cc1Raw();
  Float_t cc2Raw();
  Float_t cc3Raw();
  Float_t cc4Raw();
  Float_t cc1Calc();
  Float_t cc2Calc();
  Float_t cc3Calc();
  Float_t cc4Calc();
  Float_t segSumRaw();
  Float_t segSumRawThresh(Float_t thresh);
  Float_t segSumRawTimed(Float_t minT, Float_t maxT);
  Float_t segSumRawThreshTimed(Float_t thresh, Float_t minT, Float_t maxT);
  Int_t segsHit(Float_t thresh);
  Float_t segSumCalc();
  Float_t segSumCalcThresh(Float_t thresh);
  Int_t segsHitCalc(Float_t thresh);
  Float_t maxSegE();
  Float_t maxSegECalc();
  Int_t maxSegNum();
  Int_t secondSegNum();
  Int_t maxSegNumCalc();
  Int_t deepRingHit(Float_t thresh);
  long long int LEDLow();
  long long int LEDHigh();
  UInt_t crystalBuild();
  long long int LEDRange();

 private:
  ClassDef(g3CrystalEvent, 2);
};

class g3OUT : public TObject {

 public:
  vector <g3CrystalEvent> xtals;

 public:
  g3OUT() { ; }
  ~g3OUT() { ; }
  void Reset();
  UInt_t crystalMult();
  Float_t calorimeterE();

 private:
  ClassDef(g3OUT, 1);
};

/*--------------------------------------------------------*/
/*---    GRETINA MODE 2 - DECOMPOSED DATA STRUCTURE    ---*/
/*--------------------------------------------------------*/

/* \class g2IntPt
   \brief Class containing the information relevant to a single gamma-ray interaction point resulting from
   signal decomposition (mode2 data).

   This class defines a single interaction point in a given GRETINA crystal.  It includes all relevant 
   parameters --> energy, position and segment number.
*/

class g2IntPt : public TObject {
  
 public:
  Int_t segNum;
  TVector3 xyz;
  TVector3 xyzLab;
  TVector3 xyzLabSeg;
  TVector3 xyzLabCrys;
  Float_t e, segE;
  
 public:
  g2IntPt() { ; }
  ~g2IntPt() { ; }

 public:
  ClassDef(g2IntPt, 1);
};

/* \class g2CrystalEvent
   \brief Class containing the information relevant for mode2 (decomposed data) crystal-level event.

   This class defines a single crystal event for mode2 (decomposed) data from GRETINA.  The
   class includes crystal-level information (such as the fit information from signal decomp and
   the crystal ID etc.), as well as a vector of interaction point information 
   (vector of g2IntPt class objects).
*/

class g2CrystalEvent : public TObject {

 public:
  Int_t crystalID;
  Int_t crystalNum;
  Int_t quadNum;
  long long int timestamp;
  Float_t t0;
  Float_t chiSq;
  Float_t normChiSq;
  Float_t bl;
  Int_t error;
  Float_t cc;
  Float_t ccCurrent, ccPrior1, ccPrior2;
  UShort_t deltaT1, deltaT2;
  Float_t cc1, cc2, cc3, cc4;
  Float_t segSum;
  Float_t doppler;
  Float_t dopplerSeg;
  Float_t dopplerCrystal;
  vector<g2IntPt> intpts;
  vector<Short_t> waveAll;
  
 public:
  g2CrystalEvent() { ; }
  ~g2CrystalEvent() { ; }
  void Reset();
  Int_t numIntPts();
  Int_t numSegHit();
  Int_t segsHitAboveThresh(Float_t thresh);
  Float_t averageIntPtsPerSeg();
  Float_t segSumRaw();
  Float_t segSumRawThresh(Float_t thresh);
  TVector3 maxIntPtXYZ();
  Double_t maxIntPtX() { return maxIntPtXYZ().X(); }
  Double_t maxIntPtY() { return maxIntPtXYZ().Y(); }
  Double_t maxIntPtZ() { return maxIntPtXYZ().Z(); }
  Double_t maxIntPtR() { return maxIntPtXYZ().XYvector().Mod(); }
  TVector3 maxIntPtXYZLab();
  TVector3 maxIntPtXYZLabSeg();
  TVector3 maxIntPtXYZLabCrystal();
  Float_t maxIntPtE();
  Int_t maxIntPtSegNum();
  Float_t maxIntPtSegE();
  Float_t gTheta();
  Float_t gPhi();
  Float_t CosDop();
  Float_t cDoppler(Float_t beta);
  Float_t cDopplerSeg(Float_t beta);
  Float_t cDopplerCrystal(Float_t beta);

 public:
  ClassDef(g2CrystalEvent, 1);
};

class g2OUT : public TObject {

 public:
  Int_t runNumber;
  vector<g2CrystalEvent> xtals;
  
 public:
  g2OUT() { ; }
  ~g2OUT() { ; }
  void Reset();
  Float_t calorimeterDoppler(Float_t beta);
  Float_t calorimeterE(Float_t thresh);
  Float_t calorimeterE();
  UInt_t crystalMult();

 public:
  ClassDef(g2OUT, 1);
};

/*--------------------------------------------------------*/
/*---     GRETINA MODE 1 - TRACKED DATA STRUCTURES     ---*/
/*--------------------------------------------------------*/

struct trackedGamma {
  Float_t esum; /* gamma ray energy */
  Int_t ndet; /* number of interactions */
  Float_t fom; /* figure of merit */
  Short_t tracked; /* tracked == 1 if successful */
  long long int timestamp; /* timestamp of first interaction point */
  Float_t x0, y0, z0, e0; /* first interaction point */
  Float_t x1, y1, z1, e1; /* second interaction point */
  Short_t fCryHit; /* First crystal hit ID */
};

class GTrackEvent : public TObject {
 public:
  vector<trackedGamma> obj; // [mult]

  GTrackEvent() { ; }
  ~GTrackEvent() { ; }
  
  Int_t GetVecSize() { return obj.size(); }

  ClassDef(GTrackEvent, 1);
};

class g1GammaEvent : public TObject {

 public:
  Int_t tracked;
  Float_t FOM;
  Int_t nIntPts;
  Float_t cc;
  Float_t doppler;
  TVector3 xyzLab1, xyzLab2;
  Float_t e1, e2;
  long long int timestamp;
  Float_t t0;

 public:
  g1GammaEvent() { ; }
  ~g1GammaEvent() { ; }
  Float_t gTheta();
  Float_t gPhi();
  /* Polarization functions */
  TVector3 normalVector1();
  TVector3 normalVector2();
  Float_t phiCompton();
  Float_t intPtDistance();
  Float_t scatterAngle();
  Float_t cDoppler(Float_t beta);
  
  ClassDef(g1GammaEvent, 1);

};

class g1OUT : public TObject {
 
 public:
  vector<g1GammaEvent> gammas;

 public:
  g1OUT() { ; }
  ~g1OUT() { ; }
  void Reset();
  Float_t calorimeterE();
  UInt_t gammaMult();

  ClassDef(g1OUT, 1);
};

#endif
