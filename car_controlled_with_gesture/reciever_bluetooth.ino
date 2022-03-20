/*this is slave
 هذا الكود للreciever
 */

#include <SoftwareSerial.h>
#include<Wire.h>
SoftwareSerial BTSerial(10, 11); //TX//RX
const int ledPin = 3;
//Motor A
const int motorPin1  = 5;
const int motorPin2  = 6 ; 
//Motor B
const int motorPin3  = 8;
const int motorPin4  = 7;
int state = 0;

void setup()
{
  BTSerial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
    Serial.begin(9600); // Default communication rate of the Bluetooth module
}
void loop()
{
 if(BTSerial.available() > 0)
 { 
    // Checks whether data is comming from the serial port
    state = BTSerial.read(); // Reads the data from the serial port
 }
 
       if (state == 's') //Stationary
      {

        digitalWrite(ledPin, LOW);
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);//STOP
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
        Serial.print('s');
        state = 0;

      

      }
      else
      {

         if (state == 'f') //Forward
        {
          digitalWrite(ledPin, HIGH);
          digitalWrite(motorPin1, LOW);
          digitalWrite(motorPin2, HIGH);//FORWARD
          digitalWrite(motorPin3, HIGH);
          digitalWrite(motorPin4, LOW);
          Serial.print('f');
          state = 0;
        }

        if (state == 'b')//Backward
        {
          digitalWrite(ledPin, LOW);
          digitalWrite(motorPin1, HIGH);
          digitalWrite(motorPin2, LOW);//REVERSE
          digitalWrite(motorPin3, LOW);
          digitalWrite(motorPin4, HIGH);
          Serial.print('b');
          state = 0;


        }

          if (state == 'l') //Left
        {
          digitalWrite(ledPin, HIGH);
          digitalWrite(motorPin1, HIGH);
          digitalWrite(motorPin2, LOW);//LEFT
          digitalWrite(motorPin3, HIGH);
          digitalWrite(motorPin4, LOW);
          Serial.print('l');
          state = 0;

        }

         if (state == 'r') //Right
        {
          digitalWrite(ledPin, HIGH);
          digitalWrite(motorPin1, LOW);
          digitalWrite(motorPin2, HIGH);//RIGHT
          digitalWrite(motorPin3, LOW);
          digitalWrite(motorPin4, HIGH);
          Serial.print('r');
          state = 0;
        }
      }

      delay(333);
    }
  

