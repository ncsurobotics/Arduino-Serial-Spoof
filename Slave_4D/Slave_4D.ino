// This is spoof of I2C slave code with address 0x4D
// Jake 
// 2/12/2018
// Purpose: emulating seawolf serial board project


#include <Wire.h>

void setup() {
  Wire.begin(0x4d);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
}

void loop() {
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  Wire.write(" 0x4d says Hello "); // respond with message of 6 bytes
  // as expected by master
}
