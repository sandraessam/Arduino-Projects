#include <Adafruit_ssd1306syp.h>
#include "DHT.h" 

#define DHT_PIN 2
#define DHT_TYPE DHT22
DHT dht(DHT_PIN,DHT_TYPE);
Adafruit_ssd1306syp display(SDA,SCL);
float maxt=0.0;
float maxh=0.0;
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  display.initialize();
  EEPROM.get(10,maxt);
  EEPROM.get(15,maxh);
}

void loop() {
  // put your main code here, to run repeatedly:
  float hum=dht.readHumidity();
  float temp=dht.readTemperature();
  int val=digitalRead(A0);
  int val1=digitalRead(A1);
  int val2=digitalRead(A2);
  int val3=digitalRead(A3);
  if (val == HIGH){
    delay(250);
    maxt+=0.5;
    EEPROM.put(10,maxt);
  }
  if (val1 == HIGH){
    delay(250);
    maxt-=0.5;
    EEPROM.put(10,maxt);
  }
  if (val2 == HIGH){
    delay(250);
    maxh+=0.5;
    EEPROM.put(15,maxh);
  }
  if (val3 == HIGH){
    delay(250);
    maxh-=0.5;
    EEPROM.put(10,maxh);
  }
  display.clear();
  display.setTextSize(1);
  display.setCursor(0,4);
  display.print("Temperature: ");
  if (isnan(temp)){
    display.setTextSize(1);
    display.print("Error");
  }
  else{
    display.setTextSize(1);
    display.print(temp);
    display.println(" c");
  }
  display.setTextSize(1);
  display.setCursor(0,20);
  display.print("MAX T: ");
  display.print(maxt);
  display.print(" c");
  display.setTextSize(1);
  display.setCursor(0,40);
  display.print(maxh);
  display.print("70.00");
  display.print(" %");
  display.setTextSize(1);
  display.setCursor(0,55);
  display.print("Humidity: ");
  if (isnan(hum)){
    display.setTextSize(1);
    display.print("Error");
    digitalWrite(5,HIGH);
  }
  else{
    display.setTextSize(1);
    display.print(hum);
    display.println(" %");
  }
  display.update();
  if (temp>=maxt){
    digitalWrite(4,HIGH);
  }
  else{
    digitalWrite(4,LOW);
  }
  if (hum>=maxh){
    digitalWrite(5,HIGH);
  }
  else{
    digitalWrite(5,LOW);
  }
}
