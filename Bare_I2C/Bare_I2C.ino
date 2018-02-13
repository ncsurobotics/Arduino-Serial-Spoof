/*
  Serial Call and Response
  Language: Wiring/Arduino


  created January 2018
  by Jake Keller
  modified February 2018
  by Jake Keller
*/

#include <Wire.h>

void setup() {
  // join I2C bus (supposedly this is optional for master)
  Wire.begin(0x50);
  // start serial port at 57600 bps:
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  // Wait for input from seawolf
  while(Serial.available() <= 0) {
    Serial.print(" waiting... ");
    delay(1000);
  }
  // 
  char input = Serial.read();
  if(input == 0x61){
    Wire.requestFrom(0x4d, 5);
    
    while (Wire.available()){
        char c = Wire.read();
        Serial.print(c);
    }
  }
  else if(input == 0x62){
    Wire.requestFrom(0x60, 5);
    
    while (Wire.available()){
        char c = Wire.read();
        Serial.print(c);
    }
  }
  else Serial.print("ERROR");

  
  // Do it again
}


