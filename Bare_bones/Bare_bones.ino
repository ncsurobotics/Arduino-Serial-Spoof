/*
  Serial Call and Response
  Language: Wiring/Arduino


  created January 2018
  by Jake Keller
  modified February 2018
  by Jake Keller
*/

void setup() {
  // start serial port at 57600 bps:
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  // Wait for input from seawolf
  while(Serial.available() <= 0) {
    // send 0xFF (simulated as a series of bytes due to terminal restraints)
    Serial.write(0x46); // ASCII "F"
    Serial.write(0x46); // ASCII "F"
    Serial.write(0x20); // ASCII (space)
    delay(500);
  }
  // when a byte is received check if it is "0x00"
  // (simulated w/ "0" ASCII character from keyboard)
  if(Serial.read() == 0x30){
    Serial.write(0x46); // ASCII "F"
    Serial.write(0x30); // ASCII "0"
    Serial.write(0x20); // ASCII (space)
  }

  
  // Do it again
}


