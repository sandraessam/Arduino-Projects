/*this is Master
 هذا الكود للtransmitter
 */

#include <SoftwareSerial.h>
#include<Wire.h>

SoftwareSerial BTSerial(10, 11); //TX//RX

int state = 0;
const int MPU_addr = 0x68; // I2C address of the MPU-6050
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
const int trigpin =13;


void setup() 
{
  BTSerial.begin(9600);
  pinMode(trigpin, OUTPUT);
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600); // Default communication rate of the Bluetooth module
  }

  void loop() {

    
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true);
  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();
  Tmp = Wire.read() << 8 | Wire.read();
  GyX = Wire.read() << 8 | Wire.read();
  GyY = Wire.read() << 8 | Wire.read();
  GyZ = Wire.read() << 8 | Wire.read();
  Serial.print("AcX = "); Serial.print(AcX);
  Serial.print(" | AcY = "); Serial.print(AcY);
  Serial.print(" | AcZ = "); Serial.print(AcZ);
  Serial.print(" | Tmp = "); Serial.print(Tmp / 340.00 + 36.53);
  Serial.print(" | GyX = "); Serial.print(GyX);
  Serial.print(" | GyY = "); Serial.print(GyY);
  Serial.print(" | GyZ = "); Serial.println(GyZ);
 

 
 if (AcX < -6000 && -11000)
  {
  
 BTSerial.write('b');
 digitalWrite(trigpin,HIGH);
      
  }
  else if (AcX > 4000 && 6000)
  {
     
   BTSerial.write('f');
  digitalWrite(trigpin,LOW );
  }
  else if (AcY < -7000 && -5000)
  {
   
   BTSerial.write('r');

 digitalWrite(trigpin,HIGH);
  }
  else if (AcY > 5000 && 12000)
  {
     
  BTSerial.write('l');
 digitalWrite(trigpin,HIGH);
  }
  else
  {
     BTSerial.write('s');
   
    digitalWrite(trigpin,LOW);
  
   
  

  }
  delay(333);
}
 
