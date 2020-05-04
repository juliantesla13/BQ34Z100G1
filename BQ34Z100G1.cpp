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
  return w;
}

int BQ34Z100G1::readTTE()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
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

int BQ34Z100G1::readSTE()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
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

int BQ34Z100G1::readAvaliableCap()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x16);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x17);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int high_byte = Wire.read();
  unsigned int w = (high_byte << 8) | low_byte;
  Wire.end();
  return w;
}

int BQ34Z100G1::readStandbyCurrent()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x1c);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x1d);
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
  return w;
}

int BQ34Z100G1::readPassedCharge()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x34);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x35);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int high_byte = Wire.read();
  unsigned int w = (high_byte << 8) | low_byte;
  Wire.end();
  return w;
}

int BQ34Z100G1::readSelfDischargeCurrent()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x38);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x39);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int high_byte = Wire.read();
  unsigned int w = (high_byte << 8) | low_byte;
  Wire.end();
  return w;
}

int BQ34Z100G1::readFLAGS()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x0e);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x0f);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int high_byte = Wire.read();
  unsigned int w = (high_byte << 8) | low_byte;
  Wire.end();
  return w;
}

int BQ34Z100G1::readFullChgCap()
{
  Wire.begin();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x16);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int low_byte = Wire.read();
  Wire.beginTransmission(BQ34Z100);
  Wire.write(0x17);
  Wire.endTransmission();
  Wire.requestFrom(BQ34Z100,1);
  unsigned int high_byte = Wire.read();
  unsigned int w = (high_byte << 8) | low_byte;
  Wire.end();
  return w;
}

int BQ34Z100G1::readChipTemp()
{
  Wire.beginTransmission(BQ34Z100);
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
  Wire.end();
  w = 0.1 * w;          // Each bit is 0.1K, so we have a value in Kelvins
  w = w - 273.15;      // Convert to degrees Celsius
  return w;
}
