#ifndef BQ34Z100G1_H
#define BQ34Z100G1_H

#include "arduino.h"

class BQ34Z100G1
{

public:
bool isConnected(); 
int readSOC(); // State of Charge, a percent value of the battery's total charge
int readRemainingCapacity(); // The battery's remaining capacity in mAh
int readVoltage();
int readAverageCurrent();
int readTTE();// Time To Empty - The amoutn of time until the battery is empty. 
int readTTF();// Time Till Fully Charged Reading. 
int readSTE();// Time Till Fully Charged Reading. 
int readCycles();// Battery Liftime Cycles
int readSOH();// Battery State of Health
int readAvaliableCap();
int readStandbyCurrent();
int readAvailableEnergy();
int readAveragePower();
int readPassedCharge();
int readSelfDischargeCurrent();
int readFLAGS();
int readFullChgCap();
int readChipTemp();
  };

#endif
