#define BQ34Z100 0x55 

#include "BQ34Z100G1.h"
#include <Wire.h>

bool BQ34Z100G1::isConnected()
{
    
    Wire.beginTransmission(BQ34Z100);
    if (Wire.endTransmission() == 0)
        return true;

    delay(1000);

    Wire.beginTransmission(BQ34Z100);
    if (Wire.endTransmission() == 0)
        return true;

    return false;
}
int BQ34Z100G1::readSOC(){
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x02);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  unsigned int w = low_byte;
  Wire.end();
  return w;
  
  }
  
int BQ34Z100G1::readMaxError(){
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x03);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  unsigned int w = low_byte;
  Wire.end();
  return w;
  
  }  

int BQ34Z100G1::readRemainingCapacity() {
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x04);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x05);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int high_byte = Wire.read();
  unsigned int w = (high_byte << 8) | low_byte;
  Wire.end();
  return w;
}


int BQ34Z100G1::readVoltage()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x08);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x09);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int high_byte = Wire.read();
  unsigned int w = (high_byte << 8) | low_byte;
  Wire.end();
  return w;
}

int BQ34Z100G1::readAverageCurrent()
{

  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x0a);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x0b);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int high_byte = Wire.read();
  unsigned int w = (high_byte << 8) | low_byte;
  Wire.end();
  unsigned int a;
  if(w > 0XF000)
  {	  
  a = w ^ 0xFFFF;
  a = -(a + 1);
  return a;}
  
  else {
  a = w;
  return a;    
  }
}

int BQ34Z100G1::readTTE()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0xaa);
  delay(10);
  Wire.write(0x18);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x19);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int high_byte = Wire.read();
  unsigned int w = (high_byte << 8) | low_byte;
  Wire.end();
  return w;
}

int BQ34Z100G1::readTTF()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0xaa);
  delay(10);
  Wire.write(0x1a);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x1b);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int high_byte = Wire.read();
  unsigned int w = (high_byte << 8) | low_byte;
  Wire.end();
  return w;
}

int BQ34Z100G1::readDOD0()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0xaa);
  delay(10);
  Wire.write(0x1e);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x1f);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int high_byte = Wire.read();
  unsigned int w = (high_byte << 8) | low_byte;
  Wire.end();
  return w;
}

int BQ34Z100G1::readCycles()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x2c);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x2d);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int high_byte = Wire.read();
  unsigned int w = (high_byte << 8) | low_byte;
  Wire.end();
  return w;
}

int BQ34Z100G1::readSOH()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x2e);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x2f );
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int high_byte = Wire.read();
  unsigned int w = (high_byte << 8) | low_byte;
  Wire.end();
  return w;
}

int BQ34Z100G1::readFFC()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x06);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x07);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int high_byte = Wire.read();
  unsigned int w = (high_byte << 8) | low_byte;
  Wire.end();
  return w;
}


int BQ34Z100G1::readAvailableEnergy()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);

  Wire.write(0x24);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x25);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int high_byte = Wire.read();
  unsigned int w = (high_byte << 8) | low_byte;
  Wire.end();
  return w;
}

int BQ34Z100G1::readAveragePower()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);

  Wire.write(0x26);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x27);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int high_byte = Wire.read();
  unsigned int w = (high_byte << 8) | low_byte;
  Wire.end();
  unsigned  int a;
  if(w > 0XF000)
  {	  
  a = w ^ 0xFFFF;
  a = -(a + 1);
  return a;}
  
  else {
  a = w;
  return a;    
  }
}

int BQ34Z100G1::readPassedCharge()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  
  Wire.write(0x1C);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x1D);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int high_byte = Wire.read();
  unsigned int w = (high_byte << 8) | low_byte;
  Wire.end();
  return w;
}


bool BQ34Z100G1::CF_Flag()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x0e);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  uint8_t low_byte = Wire.read();
  bool w = bitRead(low_byte,4);
  Wire.end();
  return w;
}

bool BQ34Z100G1::DSG_Flag()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x0e);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  uint8_t low_byte = Wire.read();
  bool w = bitRead(low_byte,0);
  Wire.end();
  return w;
}

bool BQ34Z100G1::CHG_Flag()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x0e);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  uint8_t low_byte = Wire.read();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x0f);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  uint8_t high_byte = Wire.read();
  bool w = bitRead(high_byte,0);
  Wire.end();
  return w;
}

bool BQ34Z100G1::FC_Flag()
{
  Wire.begin(); 
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x0f);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  uint8_t high_byte = Wire.read();
  bool w = bitRead(high_byte,1);
  Wire.end();
  return w;
}

bool BQ34Z100G1::BATLOW_Flag()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x0f);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  uint8_t high_byte = Wire.read();
  bool w = bitRead(high_byte,4);
  Wire.end();
  return w;
}

bool BQ34Z100G1::BATHI_Flag()
{
  Wire.begin();

  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x0f);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  uint8_t high_byte = Wire.read();
  bool w = bitRead(high_byte,5);
  Wire.end();
  return w;
}

bool BQ34Z100G1::OTD_Flag()
{
  Wire.begin();

  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x0f);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  uint8_t high_byte = Wire.read();
  bool w = bitRead(high_byte,6);
  Wire.end();
  return w;
}

bool BQ34Z100G1::OTC_Flag()
{
  Wire.begin();
 
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x0f);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  uint8_t high_byte = Wire.read();
  bool w = bitRead(high_byte,7);
  Wire.end();
  return w;
}


float BQ34Z100G1::readChipTemp()
{
  float a;
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0xaa);
  delay(10);
  Wire.write(0x2a);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x2b);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int high_byte = Wire.read();
  unsigned int w = (high_byte << 8) | low_byte;
  w *= 0.1; // Each bit is 0.1K, so we have a value in Kelvins
  a = w - 273.15; // Convert to degrees Celsius
  Wire.end();
  return a;
}
