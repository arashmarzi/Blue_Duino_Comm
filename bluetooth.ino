#include <SoftwareSerial.h>
SoftwareSerial mySerial(0,1); // RX, TX

String command = ""; // Stores response of the HC-06 Bluetooth device


void setup() {
  // Open serial communications:
  Serial1.begin(9600);
  Serial1.println("Type AT commands!");
  
  // The HC-06 defaults to 9600 according to the datasheet.
  mySerial.begin(9600);
}

void loop() {
  // Read device output if available.
  if (mySerial.available()) {
    while(mySerial.available()) { // While there is more to be read, keep reading.
      command += (char)mySerial.read();
      Serial1.println(command);
    }
    
    Serial1.println(command);
    command = ""; // No repeats
  }
  
  // Read user input if available.
  if (Serial1.available()){
    delay(10); // The delay is necessary to get this working!
    mySerial.write(Serial.read());
  }

  Serial1.println("a");
}
