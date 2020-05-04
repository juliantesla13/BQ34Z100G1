#include <Wire.h>                                                                          // Wire library for communicating over I2C
#include <BQ34Z100G1.h>

BQ34Z100G1 t1; 

void setup()
{
  Serial.begin(9600);
    if (t1.isConnected() == false)
  {
    Serial.println("BQ34Z100G1. Please check wiring. Freezing.");
    while (1);
  }
  Serial.println("AHT20 acknowledged.");

}



void loop()
{
 
 Serial.print("Battery State of Charge: ");
 Serial.print(t1.readSOC());
 Serial.println("%");
 
 
 Serial.print("Battery Pack Voltage: ");
 Serial.print(t1.readVoltage());
 Serial.println(" mV");

 
 Serial.print("Time Till Empty: ");
 Serial.print(t1.readTTE());
 Serial.println(" Mins");
 
 
 Serial.print("Time Till Full: ");
 Serial.print(t1.readTTF());
 Serial.println(" Mins");

 
 Serial.print("Battery Cycles: ");
 Serial.print(t1.readCycles());
 Serial.println("");
 
 
 Serial.print("Battery Health Percentage: ");
 Serial.print(t1.readSOH());
 Serial.println("%");
 
 
 Serial.print("Chip Temperature : ");
 Serial.print(t1.readChipTemp());
 Serial.println(" C");


 
 Serial.print("\r\n");
  
 delay(1000);
}
