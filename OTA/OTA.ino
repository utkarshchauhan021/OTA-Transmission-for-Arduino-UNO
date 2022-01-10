#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 8); // RX | TX
char mychar;
void setup()
{
  Serial.begin(9600);
  Serial.println("AT");
  mySerial.begin(38400);  // HC-05 default speed in AT command more
  mySerial.println("AT");
}

void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  while (mySerial.available()){
    mychar = mySerial.read();
    Serial.print(mychar);
  }
  // Keep reading from Arduino Serial Monitor and send to HC-05
  while (Serial.available()){
    mychar = Serial.read();
    Serial.print(mychar);
    mySerial.print(mychar);
    
}
}
