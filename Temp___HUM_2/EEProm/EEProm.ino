#include <EEPROM.h>
void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  digitalWrite(2,EEPROM.read(10));
  digitalWrite(3,EEPROM.read(11)); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int val=digitalRead(A0);
  int val1=digitalRead(A1);
  if (val ==HIGH){
    delay(400);
    digitalWrite(2,!digitalRead(2));
    EEPROM.write(10,digitalRead(2));
  }
  else if (val1 ==HIGH){
    delay(400);
    digitalWrite(3,!digitalRead(3));
    EEPROM.write(11,digitalRead(3));
  }
   
  
}
