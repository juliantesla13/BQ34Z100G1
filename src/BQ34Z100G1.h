#ifndef BQ34Z100G1_H
#define BQ34Z100G1_H

#include "arduino.h"

class BQ34Z100G1
{

public:
bool isConnected(); // I2C Communication verification  
int readSOC(); // State of Charge, a percent value of the battery's total charge
int readRemainingCapacity(); // The battery's remaining capacity in mAh
int readVoltage(); //Battery pack voltage
int readAverageCurrent(); // Average battery pack current
int readTTE();// Time To Empty - The amoutn of time until the battery is empty. 
int readTTF();// Time Till Fully Charged Reading. 
int readDOD0(); //This read-only command pair returns the time since the last DOD0 update
int readCycles();// Battery Liftime Cycles
int readSOH();// Battery State of Health
int readFFC(); // Full Avaliable Capacity
int readAvailableEnergy(); //Indicate value of the predicted charge or energy remaining in the battery
int readAveragePower(); // Indicate average power of the current discharge
int readPassedCharge();//Indicate the amount of charge passed through the sense resistor since the last IT simulation in mAh
float readChipTemp();// Internal Temp
int readMaxError();// Error in values
bool CF_Flag(); //Condition Flag. True when set
bool DSG_Flag();//Discharging Flag. True when set
bool CHG_Flag();//Charging Allowed. True when set
bool FC_Flag();//Full Charge. True when set
bool BATLOW_Flag();//Battery Low. True when set
bool BATHI_Flag();//Battery High. True when set
bool OTC_Flag();//Overtemperature in Charge condition is detected. True when set
bool OTD_Flag();//Overtemperature in Discharge condition is detected. True when set

  };

#endif
