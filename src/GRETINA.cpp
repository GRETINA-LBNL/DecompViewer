#include "GRETINA.h"

ClassImp(g1GammaEvent);
ClassImp(g1OUT);

/**************************************************************/
/* g3CrystalEvent Class Functions *****************************/
/**************************************************************/

/*! Puts channels from a mode3 crystal event in numerical order
    within the vector chn<g3ChannelEvent>

    \return No return value -- directly alters class structures
*/

void g3CrystalEvent::OrderChannels() {
  g3ChannelEvent temp;
  Bool_t finished = 0;
  while (!finished) {
    finished = 1;
    for (UInt_t ui=0; ui<chn.size()-1; ui++) {
      if (chn[ui].chnNum() > chn[ui].chnNum()) {
	temp = chn[ui];
	chn[ui] = chn[ui+1];
	chn[ui+1] = temp;
	finished = 0;
      }
    }
  }
}

/**************************************************************/

/*! Extracts the calibrated first central contact energy from mode3
    data (CC1 --> electronics channel 9 for a given crystal) 

    \return Returns the float value of the calibrated CC1 energy
*/

Float_t g3CrystalEvent::cc1() { 
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].chnNum() == 9) { return chn[ui].eCal; }
  }
  return -1.0;
}

/**************************************************************/

/*! Extracts the calibrated first central contact energy from mode3
    data (CC2 --> electronics channel 19 for a given crystal) 

    \return Returns the float value of the calibrated CC2 energy
*/

Float_t g3CrystalEvent::cc2() { 
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].chnNum() == 19) { return chn[ui].eCal; }
  }
  return -1.0;
}

/**************************************************************/

/*! Extracts the calibrated first central contact energy from mode3
    data (CC3 --> electronics channel 29 for a given crystal) 

    \return Returns the float value of the calibrated CC3 energy
*/

Float_t g3CrystalEvent::cc3() { 
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].chnNum() == 29) { return chn[ui].eCal; }
  }
  return -1.0;
}

/**************************************************************/

/*! Extracts the calibrated first central contact energy from mode3
    data (CC4 --> electronics channel 39 for a given crystal) 

    \return Returns the float value of the calibrated CC4 energy
*/

Float_t g3CrystalEvent::cc4() { 
 for (UInt_t ui=0; ui<chn.size(); ui++) {
   if (chn[ui].chnNum() == 39) { return chn[ui].eCal; }
  }
  return -1.0;
}

/**************************************************************/

/*! Extracts the uncalibrated first central contact energy from mode3
    data (CC1 --> electronics channel 9 for a given crystal) 

    \return Returns the float value of the raw (uncalibrated) CC1 energy
*/

Float_t g3CrystalEvent::cc1Raw() { 
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].chnNum() == 9) { return chn[ui].eRaw; }
  }
  return -1.0;
}

/**************************************************************/

/*! Extracts the uncalibrated first central contact energy from mode3
    data (CC2 --> electronics channel 19 for a given crystal) 

    \return Returns the float value of the raw (uncalibrated) CC2 energy
*/

Float_t g3CrystalEvent::cc2Raw() { 
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].chnNum() == 19) { return chn[ui].eRaw; }
  }
  return -1.0;
}

/**************************************************************/

/*! Extracts the uncalibrated first central contact energy from mode3
    data (CC3 --> electronics channel 29 for a given crystal) 

    \return Returns the float value of the raw (uncalibrated) CC3 energy
*/

Float_t g3CrystalEvent::cc3Raw() { 
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].chnNum() == 29) { return chn[ui].eRaw; }
  }
  return -1.0;
}

/**************************************************************/

/*! Extracts the uncalibrated first central contact energy from mode3
    data (CC4 --> electronics channel 39 for a given crystal) 

    \return Returns the float value of the raw (uncalibrated) CC4 energy
*/

Float_t g3CrystalEvent::cc4Raw() { 
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].chnNum() == 39) { return chn[ui].eRaw; }
  }
  return -1.0;
}

/**************************************************************/

/*! Extracts the first central contact energy calculated from the waveform
    in  mode3 data (CC1 --> electronics channel 9 for a given crystal) 

    \return Returns the float value of the waveform calculated CC1 energy
*/

Float_t g3CrystalEvent::cc1Calc() { 
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].chnNum() == 9) { return chn[ui].eCalc; }
  }
  return -1.0; 
}

/**************************************************************/

/*! Extracts the first central contact energy calculated from the waveform
    in  mode3 data (CC2 --> electronics channel 19 for a given crystal) 

    \return Returns the float value of the waveform calculated CC2 energy
*/

Float_t g3CrystalEvent::cc2Calc() { 
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].chnNum() == 19) { return chn[ui].eCalc; }
  }
  return -1.0;  
}

/**************************************************************/

/*! Extracts the first central contact energy calculated from the waveform
    in  mode3 data (CC3 --> electronics channel 29 for a given crystal) 

    \return Returns the float value of the waveform calculated CC3 energy
*/

Float_t g3CrystalEvent::cc3Calc() { 
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].chnNum() == 29) { return chn[ui].eCalc; }
  }
  return -1.0;  
}

/**************************************************************/

/*! Extracts the first central contact energy calculated from the waveform
    in  mode3 data (CC4 --> electronics channel 39 for a given crystal) 

    \return Returns the float value of the waveform calculated CC4 energy
*/

Float_t g3CrystalEvent::cc4Calc() { 
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].chnNum() == 39) { return chn[ui].eCalc; }
  }
  return -1.0;  
}

/**************************************************************/

/*! Calculates a raw (NOT Dino corrected) segment sum for the crystal, 
    with no threshold on the segments included

    \return Returns the float value of the raw segment sum for
            the crystal 
*/

Float_t g3CrystalEvent::segSumRaw() {
  return segSumRawThresh(0.0);
}

/**************************************************************/

/*! Calculates a raw (NOT Dino corrected) segment sum for the crystal,
    including segments that are above a threshold value

    \param thresh The float energy threshold; any segments below
           this value are not included in the sum
    \return Returns the float value of the raw segment sum for the crystal
*/

Float_t g3CrystalEvent::segSumRawThresh(Float_t thresh) {
  Float_t segSum = 0;
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].eCal > thresh && chn[ui].segNum < 36) {
      segSum += chn[ui].eCal;
    }
  }
  return segSum;
}

/**************************************************************/

Float_t g3CrystalEvent::segSumRawTimed(Float_t minT, Float_t maxT) {
  Float_t segSum = 0;
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].segNum < 36) {
      if (chn[ui].calcTime > minT &&
	  chn[ui].calcTime > maxT) {
	segSum += chn[ui].eCal;
      }
    }
  }
  return segSum;
}

/**************************************************************/

Float_t g3CrystalEvent::segSumRawThreshTimed(Float_t thresh, Float_t minT, Float_t maxT) {
  Float_t segSum = 0;
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].eCal > thresh && chn[ui].segNum < 36) {
      if (chn[ui].calcTime > minT &&
	  chn[ui].calcTime > maxT) {
	segSum += chn[ui].eCal;
      }
    }
  }
  return segSum;
}

/**************************************************************/

/*! Determines the number of segments hit in the crystal above a given
    energy threshold

    \param thresh The float energy threshold -- segments with energy
           depositions above threshold are counted as hit
    \return Returns integer value of the number of segments hit above 
            the energy threshold
*/

Int_t g3CrystalEvent::segsHit(Float_t thresh) {
  Int_t hit = 0;
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].eCal > thresh && chn[ui].segNum < 36) {
      hit++;
    }
  }
  return hit;
}

/**************************************************************/

Float_t g3CrystalEvent::segSumCalc() {
  Float_t segSum = 0.;
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].segNum < 36) {
      segSum += chn[ui].eCalc;
    }
  }
  return segSum;
}

/**************************************************************/

Float_t g3CrystalEvent::segSumCalcThresh(Float_t thresh) {
  Float_t segSum = 0.;
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].segNum < 36 && chn[ui].eCalc < thresh) {
      segSum += chn[ui].eCalc;
    }
  }
  return segSum;
}

/**************************************************************/

Int_t g3CrystalEvent::segsHitCalc(Float_t thresh) {
  Int_t hit = 0;
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].eCalc > thresh && chn[ui].segNum < 36) {
      hit++;
    }
  }
  return hit;
}

/**************************************************************/

Float_t g3CrystalEvent::maxSegE() {
  Float_t maxE = 0.;  Int_t max = -1;
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].eCal > maxE && chn[ui].segNum < 36) {
      max = ui;
      maxE = chn[ui].eCal;
    }
  }
  return maxE;
}

/**************************************************************/

Float_t g3CrystalEvent::maxSegECalc() {
  Float_t maxE = 0.;  Int_t max = -1;
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].eCalc > maxE && chn[ui].segNum < 36) {
      max = ui;
      maxE = chn[ui].eCalc;
    }
  }
  return maxE;
}

/**************************************************************/

Int_t g3CrystalEvent::maxSegNum() {
  Float_t maxE = 0.;  Int_t max = -1;
 
  for (Int_t u=0; u<chn.size(); u++) {
    if (chn[u].eCal > maxE && chn[u].segNum < 36) {
      max = u;
      maxE = chn[u].eCal;
    }
  }

  return chn[max].segNum;
}

/**************************************************************/

Int_t g3CrystalEvent::secondSegNum() {
  Float_t maxE = 0.;  Int_t max = -1;
  
  for (Int_t u=0; u<chn.size(); u++) {
    if (chn[u].eCal > maxE && chn[u].segNum < 36 && chn[u].eCal != maxSegE()) {
      max = u;
      maxE = chn[u].eCal;
    }
  }

  return chn[max].segNum;
}

/**************************************************************/

Int_t g3CrystalEvent::maxSegNumCalc() {
  Float_t maxE = 0.;  UInt_t max = -1;
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].eCalc > maxE && chn[ui].segNum < 36) {
      max = ui;
      maxE = chn[ui].eCalc;
    }
  }
  return chn[max].segNum;
}

/**************************************************************/

Int_t g3CrystalEvent::deepRingHit(Float_t thresh) {
  Int_t deep = -1;
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (chn[ui].segNum < 6 && chn[ui].eCal > thresh && deep < 1) {
      deep = 1; 
    } else if (chn[ui].segNum < 12 && chn[ui].segNum > 5 && 
	       chn[ui].eCal > thresh && deep < 2) {
      deep = 2;
    } else if (chn[ui].segNum < 18 && chn[ui].segNum > 11 && 
	       chn[ui].eCal > thresh && deep < 3) {
      deep = 3;
    } else if (chn[ui].segNum < 24 && chn[ui].segNum > 17 && 
	       chn[ui].eCal > thresh && deep < 4) {
      deep = 4;
    } else if (chn[ui].segNum < 30 && chn[ui].segNum > 23 && 
	       chn[ui].eCal > thresh && deep < 5) {
      deep = 5;
    } else if (chn[ui].segNum < 36 && chn[ui].segNum > 29 && 
	       chn[ui].eCal > thresh && deep < 1) {
      deep = 6;
    }
  }
  return deep;
}

/**************************************************************/

long long int g3CrystalEvent::LEDLow() {
  long long int ledLow = -1;
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (ledLow == -1) { ledLow = chn[ui].timestamp; }
    if (ledLow > chn[ui].timestamp) {
      ledLow = chn[ui].timestamp;
    }
  }
  return ledLow;
}

/**************************************************************/

long long int g3CrystalEvent::LEDHigh() {
  long long int ledHigh = 0;
  for (UInt_t ui=0; ui<chn.size(); ui++) {
    if (ledHigh < chn[ui].timestamp) {
      ledHigh = chn[ui].timestamp;
    }
  }
  return ledHigh;
}

/**************************************************************/

UInt_t g3CrystalEvent::crystalBuild() { return chn.size(); }

/**************************************************************/

/*! Function calculates the difference between the high and low 
    LED timestamps for channel events within the mode3 crystal event,
    essentially the 'width' of the event for the crystal

    \return Returns the difference between the first and last LED
            timestamps as a long long int
*/

long long int g3CrystalEvent::LEDRange() {
  return (LEDHigh() - LEDLow());
}

/**************************************************************/
/* g3OUT Class Functions **************************************/
/**************************************************************/

/*! Resets the mode3 output class -- clears channel vector

    \return No return value -- clears data structures in class
            directly
*/

void g3OUT::Reset() {
  UInt_t crystals = crystalMult();
  for (UInt_t ui=0; ui<crystals; ui++) {
    xtals[ui].chn.clear();
  }
  xtals.clear();
}

/**************************************************************/

/*! Extracts the number of crystals hit within a mode3 event, namely
    the size of the xtals vector

    \return Returns the unsigned integer value of the size of the
            xtals array
*/

UInt_t g3OUT::crystalMult() { return xtals.size(); }

/**************************************************************/

Float_t g3OUT::calorimeterE() {
  Float_t sum = 0.;
  for (UInt_t ui=0; ui<crystalMult(); ui++) {
    sum += xtals[ui].cc1();
  }
  return sum;
}

/**************************************************************/
/* g2CrystalEvent Class Functions *****************************/
/**************************************************************/

void g2CrystalEvent::Reset() { 
  intpts.clear();
  crystalNum = -1;  quadNum = -1;
  timestamp = 0;
  t0 = -1.0; chiSq = -1.0;
  bl = -9999; /* 2015-09-20 CMC: added for wf baseline and PZ checks */
  error = -1;
  cc = 0.0; segSum = 0.0;
  ccCurrent = 0.0; ccPrior1 = 0.0; ccPrior2 = 0.0;
  deltaT1 = 0.0; deltaT2 = 0.0;
  doppler = 0.0; dopplerSeg = 0.0; dopplerCrystal = 0.0;
}

/**************************************************************/

Int_t g2CrystalEvent::numIntPts() {  return intpts.size();  }

/**************************************************************/

Int_t g2CrystalEvent::numSegHit() {
  Int_t hit[40] = {0};
  Int_t segsHit = 0;
  for (Int_t i=0; i<intpts.size(); i++) {
    if (hit[intpts[i].segNum] == 0) {
      hit[intpts[i].segNum] = 1;
      segsHit++;
    }
  }
  return segsHit;
}

/**************************************************************/

Int_t g2CrystalEvent::segsHitAboveThresh(Float_t thresh) {
  Int_t hit[40] = {0};
  Int_t segsHit = 0;
  for (Int_t i=0; i<intpts.size(); i++) {
    if (hit[intpts[i].segNum] == 0 && intpts[i].segE > thresh) {
      hit[intpts[i].segNum] = 1;
      segsHit++;
    }
  }
  return segsHit;
}

/**************************************************************/

Float_t g2CrystalEvent::averageIntPtsPerSeg() {
  if (numSegHit() > 0) {
    return ((Float_t)intpts.size() / (Float_t)(numSegHit()));
  } else { return 0.; }
} 

/**************************************************************/

Float_t g2CrystalEvent::segSumRaw() {
  Float_t sum = 0;
  Int_t used[40] = {0};
  for (Int_t i=0; i<intpts.size(); i++) {
    if (used[intpts[i].segNum] == 0) {
      sum += intpts[i].segE;
      used[intpts[i].segNum] = 1;
    }
  }
  return sum;
}

/**************************************************************/

Float_t g2CrystalEvent::segSumRawThresh(Float_t thresh) {
  Float_t sum = 0;
  Int_t used[40] = {0};
  for (Int_t i=0; i<intpts.size(); i++) {
    if (used[intpts[i].segNum] == 0 && intpts[i].segE > thresh) {
      sum += intpts[i].segE;
      used[intpts[i].segNum] = 1;
    }
  }
  return sum;
}

/**************************************************************/

TVector3 g2CrystalEvent::maxIntPtXYZ() {
  Float_t maxE = 0; Int_t max = -1;
  for (Int_t i=0; i<intpts.size(); i++) {
    if (intpts[i].e > maxE) {
      maxE = intpts[i].e;
      max = i;
    }
  }
  if (max > -1) { return intpts[max].xyz; }
  else { return TVector3(0., 0., 0.); }
}

/**************************************************************/

TVector3 g2CrystalEvent::maxIntPtXYZLab() {
  Float_t maxE = 0; Int_t max = -1;
  for (Int_t i=0; i<intpts.size(); i++) {
    if (intpts[i].e > maxE) {
      maxE = intpts[i].e;
      max = i;
    }
  }
  if (max > -1) { return intpts[max].xyzLab; }
  else { return TVector3(0., 0., 0.); }
}

/**************************************************************/

TVector3 g2CrystalEvent::maxIntPtXYZLabSeg() {
  Float_t maxE = 0; Int_t max = -1;
  for (Int_t i=0; i<intpts.size(); i++) {
    if (intpts[i].e > maxE) {
      maxE = intpts[i].e;
      max = i;
    }
  }
  if (max > -1) { return intpts[max].xyzLabSeg; }
  else { return TVector3(0., 0., 0.); }
}

/**************************************************************/

TVector3 g2CrystalEvent::maxIntPtXYZLabCrystal() {
  Float_t maxE = 0; Int_t max = -1;
  for (Int_t i=0; i<intpts.size(); i++) {
    if (intpts[i].e > maxE) {
      maxE = intpts[i].e;
      max = i;
    }
  }
  if (max > -1) { return intpts[max].xyzLabCrys; }
  else { return TVector3(0., 0., 0.); }
}

/**************************************************************/

Float_t g2CrystalEvent::maxIntPtE() {
  Float_t maxE = 0; Int_t max = -1;
  for (Int_t i=0; i<intpts.size(); i++) {
    if (intpts[i].e > maxE) {
      maxE = intpts[i].e;
      max = i;
    }
  }
  if (max > -1) { return intpts[max].e; }
  else { return 0.; }
}

/**************************************************************/

Int_t g2CrystalEvent::maxIntPtSegNum() {
  Float_t maxE = 0; Int_t max = -1;
  for (Int_t i=0; i<intpts.size(); i++) {
    if (intpts[i].e > maxE) {
      maxE = intpts[i].e;
      max = i;
    }
  }
  if (max > -1) { return intpts[max].segNum; }
  else { return -1; }
}

/**************************************************************/

Float_t g2CrystalEvent::maxIntPtSegE() {
  Float_t maxE = 0; Int_t max = -1;
  for (Int_t i=0; i<intpts.size(); i++) {
    if (intpts[i].e > maxE) {
      maxE = intpts[i].e;
      max = i;
    }
  }
  if (max > -1) { return intpts[max].segE; }
  else { return 0.0; }
}

/**************************************************************/

Float_t g2CrystalEvent::gTheta() {
  if (numIntPts() > 0) {
    return maxIntPtXYZLab().Theta();
  } else { return 0.0; }
}

/**************************************************************/

Float_t g2CrystalEvent::gPhi() {
  if (numIntPts() > 0) {
    if (maxIntPtXYZLab().Phi() < 0) {
      return (maxIntPtXYZLab().Phi() + TMath::TwoPi());
    } else {
      return maxIntPtXYZLab().Phi();
    }
  } else { return 0.0; }
}

/**************************************************************/

Float_t g2CrystalEvent::CosDop() {
  if (numIntPts() > 0) {
    return maxIntPtXYZLab().CosTheta();
  } else {
    return 0.0;
  }
}

/**************************************************************/

Float_t g2CrystalEvent::cDoppler(Float_t beta) {
  if (numIntPts() > 0) {
    Float_t cosDop = maxIntPtXYZLab().CosTheta();
    Float_t gamma = 1/TMath::Sqrt(1. - beta*beta);
    return (gamma*(1. - beta*cosDop));
  } else {
    return 0.0;
  }
}

/**************************************************************/

Float_t g2CrystalEvent::cDopplerSeg(Float_t beta) {
  if (numIntPts() > 0) {
    Float_t cosDop = maxIntPtXYZLabSeg().CosTheta();
    Float_t gamma = 1/TMath::Sqrt(1. - beta*beta);
    return (gamma*(1. - beta*cosDop));
  } else {
    return 0.0;
  }
}

/**************************************************************/

Float_t g2CrystalEvent::cDopplerCrystal(Float_t beta) {
  if (numIntPts() > 0) {
    Float_t cosDop = maxIntPtXYZLabCrystal().CosTheta();
    Float_t gamma = 1/TMath::Sqrt(1. - beta*beta);
    return (gamma*(1. - beta*cosDop));
  } else {
    return 0.0;
  }
}


/**************************************************************/
/* g2OUT Class Functions **************************************/
/**************************************************************/

void g2OUT::Reset() {
  runNumber = -1;
  for (UInt_t ui=0; ui<crystalMult(); ui++) {
    xtals[ui].intpts.clear();
    xtals[ui].waveAll.clear();
  }
  xtals.clear();
}

/**************************************************************/

Float_t g2OUT::calorimeterDoppler(Float_t beta) {
  Float_t maxE = 0;
  Int_t max = -1;
  for (UInt_t ui=0; ui<crystalMult(); ui++) {
    if (xtals[ui].cc > maxE) { maxE = xtals[ui].cc;  max = ui; }
  }
  if (max >= 0) {
    if (beta > 0) {
      return (xtals[max].cDoppler(beta));
    } else { return (xtals[max].doppler); }
  } else { return 0.; }
}

/**************************************************************/

/*! Determines the calorimeter mode energy for a mode2 event, 
    subject to an energy threshold for inclusion of a given crystal
    energy.  Calculated based on the CC energy values.
    
    \param thresh The float value of the energy threshold that is 
           checked for each crystal to be included in the calorimeter
           sum
    \return Returns the float value of the calorimeter mode energy sum
            for the mode2 event
*/

Float_t g2OUT::calorimeterE(Float_t thresh) {
  Float_t sum = 0.;
  for (UInt_t ui=0; ui<crystalMult(); ui++) {
    if (xtals[ui].cc3 > thresh) { sum += xtals[ui].cc3; }
  }
  return sum;
}

/**************************************************************/

Float_t g2OUT::calorimeterE() {
  return calorimeterE(0.0);
}

/**************************************************************/

UInt_t g2OUT::crystalMult() {
  return xtals.size();
}

/**************************************************************/
/* g1GammaEvent Class Functions *******************************/
/**************************************************************/

Float_t g1GammaEvent::gTheta() {
  return xyzLab1.Theta();
}

/**************************************************************/

Float_t g1GammaEvent::gPhi() {
  if (xyzLab1.Phi() < 0) {
    return (xyzLab1.Phi() + TMath::TwoPi());
  } else {
    return xyzLab1.Phi();
  }
  return 0.0;
}

/**************************************************************/

TVector3 g1GammaEvent::normalVector1() {
  TVector3 xyz;
  xyz.SetXYZ(1.0*xyzLab1.Y(), -1.0*xyzLab1.X(), 0);
  return xyz.Unit();
}

/**************************************************************/

TVector3 g1GammaEvent::normalVector2() {
  TVector3 xyz;
  xyz.SetXYZ((xyzLab1.Y()*(xyzLab2.Z()-xyzLab1.Z())-
	      xyzLab1.Z()*(xyzLab2.Y()-xyzLab1.Y())),
	     (xyzLab1.Z()*(xyzLab2.X()-xyzLab1.X())-
	      xyzLab1.X()*(xyzLab2.Z()-xyzLab1.Z())),
	     (xyzLab1.X()*(xyzLab2.Y()-xyzLab1.Y())-
	      xyzLab1.Y()*(xyzLab2.X()-xyzLab1.X())));	
  return xyz.Unit();
}

/**************************************************************/

Float_t g1GammaEvent::phiCompton() {
  Float_t angle;
  Double_t dotProd = normalVector1().Dot(normalVector2());
  if (normalVector2().Z() > 0) {
    angle = (TMath::ACos(dotProd / 
			 (normalVector1().Mag()*normalVector2().Mag())) + 
	     TMath::Pi()) * TMath::RadToDeg();
  } else if (normalVector2().Z() <= 0) {
    angle = ((TMath::ACos(dotProd / 
			  (normalVector1().Mag()*normalVector2().Mag()))) * 
	     TMath::RadToDeg());
  }
  return angle;
}

/**************************************************************/

Float_t g1GammaEvent::intPtDistance() {
  return ((normalVector2() - normalVector1()).Mag());
}

/**************************************************************/

Float_t g1GammaEvent::scatterAngle() {
  TVector3 delta = normalVector1() - normalVector2();
  Float_t dotProdScat = delta.Dot(normalVector1());
  return (TMath::ACos(dotProdScat / xyzLab1.Mag() * delta.Mag()) * 
	  TMath::RadToDeg());
}

/**************************************************************/

Float_t g1GammaEvent::cDoppler(Float_t beta) {
  Float_t cosDop = xyzLab1.CosTheta();
  Float_t gamma = 1/TMath::Sqrt(1. - beta*beta);
  return (gamma*(1. - beta*cosDop));
}

/**************************************************************/
/* g1OUT Class Functions **************************************/
/**************************************************************/

void g1OUT::Reset() {
  gammas.clear();
}

/**************************************************************/

Float_t g1OUT::calorimeterE() {
  Float_t sum = 0.;
  for (UInt_t ui=0; ui<gammaMult(); ui++) {
    sum += gammas[ui].cc;
  }
  return sum;
}

/**************************************************************/

UInt_t g1OUT::gammaMult() {
  return gammas.size();
}

