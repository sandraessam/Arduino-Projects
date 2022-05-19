/*
   -- Temp_Hum Proj --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_CLOUD

#include <RemoteXY.h>
#include <EEPROM.h>
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "DHT.h" 

#define DHT_PIN 2
#define DHT_TYPE DHT22
#define TFT_DC 9
#define TFT_CS 53
#define TFT_RST 8
#define TFT_MISO 50
#define TFT_MOSI 51
#define TFT_CLK 52

DHT dht(DHT_PIN,DHT_TYPE);
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);
float maxt=0.0;
float maxh=0.0;
float mint=0.0;
float minh=0.0;
float PrevMaxt=130.0;
float PrevMaxh=200.0;
float PrevMint=-50.0;
float PrevMinh=-1.0;
float PrevTemp=0.0;
float PrevHum=0.0;
float PrevBat=110.0;
uint8_t flag=0;
uint8_t on_off=0;
// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "TEdata1"
#define REMOTEXY_WIFI_PASSWORD "171611ss"
#define REMOTEXY_CLOUD_SERVER "cloud.remotexy.com"
#define REMOTEXY_CLOUD_PORT 6376
#define REMOTEXY_CLOUD_TOKEN "bb93eed9f9dcaa70fc08f4adb85191e1"


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 294 bytes
  { 255,1,0,77,0,31,1,16,162,0,129,0,5,7,18,6,31,84,101,109,
  112,58,32,40,0,67,4,28,8,20,5,2,26,11,129,0,54,7,18,6,
  31,67,194,176,32,41,0,129,0,5,14,24,6,31,77,97,120,84,58,32,
  40,32,0,67,4,28,15,20,5,2,26,11,129,0,54,15,10,6,31,67,
  194,176,32,41,0,129,0,5,40,18,6,31,77,97,120,72,58,32,40,0,
  67,4,29,40,20,5,2,26,11,129,0,56,40,10,6,31,37,32,41,0,
  129,0,5,54,18,6,31,72,117,109,58,32,40,32,0,67,4,29,54,20,
  5,2,26,11,129,0,57,54,10,6,31,37,32,41,0,2,1,76,6,22,
  11,1,26,31,31,79,78,0,79,70,70,0,129,0,5,21,21,6,31,77,
  105,110,84,58,32,40,32,0,67,4,28,22,20,5,2,26,11,129,0,53,
  22,10,6,31,67,194,176,32,41,0,129,0,5,47,24,6,31,77,105,110,
  72,58,32,40,0,67,4,29,47,20,5,2,26,11,129,0,57,47,10,6,
  31,37,32,41,0,129,0,4,30,22,6,24,66,97,116,116,101,114,121,58,
  32,40,0,67,4,32,31,20,5,2,26,11,129,0,56,40,10,6,31,37,
  32,41,0,129,0,55,30,10,6,24,37,32,41,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 

    // output variables
  char text_temp[11];  // string UTF8 end zero 
  char text_maxt[11];  // string UTF8 end zero 
  char text_maxh[11];  // string UTF8 end zero 
  char text_hum[11];  // string UTF8 end zero 
  char text_mint[11];  // string UTF8 end zero 
  char text_minh[11];  // string UTF8 end zero 
  char text_bat[11];  // string UTF8 end zero 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_SWITCH_1 12
#define PIN_SWITCH_2 13


void setup() 
{
  RemoteXY_Init (); 
  tft.begin();        // Intialize TFT
  tft.setRotation(3);     // Rotate TFT to show words in 480*320
  tft.fillScreen(ILI9341_BLACK);    // background Black
  tft.setTextColor(ILI9341_WHITE);
  pinMode (PIN_SWITCH_1, OUTPUT);
  pinMode (PIN_SWITCH_2, OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(A6,INPUT);
  pinMode(A7,INPUT);
  pinMode(A8,INPUT);
  pinMode(A9,INPUT);
  pinMode(4,OUTPUT); //relay pump
  pinMode(5,OUTPUT); //relay fan
  pinMode(6,OUTPUT); //relay Water pump
  
  EEPROM.get(10,maxt);
  EEPROM.get(15,maxh);
  EEPROM.get(20,mint);
  EEPROM.get(25,minh);
 if(isnan(maxt)){
      maxt=0.0;
    } 
 if(isnan(maxh)){
      maxh=0.0;
    } 
 if(isnan(mint)){
      mint=0.0;
    } 
 if(isnan(minh)){
      minh=0.0;
    }
 // TODO you setup code
}

void loop() 
{ 
  RemoteXY_Handler ();
  int Circuit=digitalRead(A8); //Switch for Circuit on 1 ,off 0
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
  if(digitalRead(PIN_SWITCH_1)==HIGH || Circuit==HIGH){
  flag=1;  
  float hum=dht.readHumidity();
  float temp=dht.readTemperature();
  float battery=digitalRead(A9);
  battery=(battery/1.040)*100;
  dtostrf(temp,0,1,RemoteXY.text_temp);
  dtostrf(hum,0,1,RemoteXY.text_hum);
  dtostrf(maxt,0,1,RemoteXY.text_maxt);
  dtostrf(maxh,0,1,RemoteXY.text_maxh);
  dtostrf(mint,0,1,RemoteXY.text_mint);
  dtostrf(minh,0,1,RemoteXY.text_minh);
  dtostrf(battery,0,1,RemoteXY.text_bat);
  
  int val=digitalRead(A0); //Switch for increasing max temp by 0.5
  int val1=digitalRead(A1); //Switch for decreasing max temp by 0.5
  int val2=digitalRead(A2); //Switch for increasing max humidity by 0.5
  int val3=digitalRead(A3); //Switch for decreasing max humidity by 0.5
  int val4=digitalRead(A4); //Switch for increasing min temp by 0.5
  int val5=digitalRead(A5); //Switch for decreasing min temp by 0.5
  int val6=digitalRead(A6); //Switch for increasing min humidity by 0.5
  int val7=digitalRead(A7); //Switch for increasing min humidity by 0.5
  
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
    EEPROM.put(15,maxh);
  }
  if(val4 == HIGH){
    delay(250);
    mint+=0.5;
    EEPROM.put(20,mint);
  }
  if(val5 == HIGH){
    delay(250);
    mint-=0.5;
    EEPROM.put(20,mint);
  }
  if(val6 == HIGH){
    delay(250);
    minh+=0.5;
    EEPROM.put(25,minh);
  }
  if(val7 == HIGH){
    delay(250);
    minh-=0.5;
    EEPROM.put(25,minh);
  }
  //tft.fillScreen(ILI9341_BLACK);
  tft.setTextSize(3);
  tft.setCursor(0,10);
  tft.print("Temperature: ");
  if (isnan(temp)){
    tft.setTextSize(2);
    tft.setCursor(250,10);
    tft.setTextColor(ILI9341_BLACK);
    tft.print(PrevTemp);
    tft.setCursor(250,10);
    tft.setTextColor(ILI9341_WHITE);
    tft.print("Error");
  }
  else if(PrevTemp!=temp){
    tft.setTextSize(2);
    tft.setCursor(250,10);
    tft.setTextColor(ILI9341_BLACK);
    tft.print(PrevTemp);
    tft.setCursor(250,10);
    tft.setTextColor(ILI9341_WHITE);
    tft.print(temp);
    tft.setCursor(320,10);
    tft.print(" c");
    PrevTemp=temp;
  }
  tft.setTextSize(3);
  tft.setCursor(0,60);
  tft.print("MAX T: ");
  if(PrevMaxt!=maxt){
  tft.setTextSize(2);
  tft.setCursor(250,60);
  tft.setTextColor(ILI9341_BLACK);
  tft.print(PrevMaxt);
  tft.setCursor(250,60);
  tft.setTextColor(ILI9341_WHITE);
  tft.print(maxt);
  tft.setCursor(320,60);
  tft.print(" c");
  PrevMaxt=maxt;}
  tft.setTextSize(3);
  tft.setCursor(0,110);
  tft.print("MIN T: ");
  if(PrevMint!=mint){
  tft.setTextSize(2);
  tft.setCursor(250,110);
  tft.setTextColor(ILI9341_BLACK);
  tft.print(PrevMint);
   tft.setCursor(250,110);
  tft.setTextColor(ILI9341_WHITE);
  tft.print(mint);
  tft.setCursor(320,110);
  tft.print(" c");
  PrevMint=mint;}
  tft.setTextSize(3);
  tft.setCursor(0,150);
  tft.print("Battery: ");
  if(PrevBat!=battery){
  tft.setTextSize(2);
  tft.setCursor(250,150);
  tft.setTextColor(ILI9341_BLACK);
  tft.print(PrevBat);
  tft.setCursor(250,150);
  tft.setTextColor(ILI9341_WHITE);
  tft.print(battery);
  tft.setCursor(320,150);
  tft.print(" %");
  PrevBat=battery;}
  tft.setTextSize(3);
  tft.setCursor(0,200);
  tft.print("MAX H: ");
  if(PrevMaxh!=maxh){
  tft.setTextSize(2);
  tft.setCursor(250,200);
  tft.setTextColor(ILI9341_BLACK);
  tft.print(PrevMaxh);
  tft.setCursor(250,200);
  tft.setTextColor(ILI9341_WHITE);
  tft.print(maxh);
  tft.setCursor(320,200);
  tft.print(" %");
  PrevMaxh=maxh;}
  tft.setTextSize(3);
  tft.setCursor(0,250);
  tft.print("MIN H: ");
  if(PrevMinh!=minh){
  tft.setTextSize(2);
  tft.setCursor(250,250);
  tft.setTextColor(ILI9341_BLACK);
  tft.print(PrevMinh);
  tft.setCursor(250,250);
  tft.setTextColor(ILI9341_WHITE);
  tft.print(minh);
  tft.setCursor(320,250);
  tft.print(" %");
  PrevMinh=minh;}
  tft.setTextSize(3);
  tft.setCursor(0,290);
  tft.print("Humidity: ");
  if (isnan(hum)){
  tft.setTextSize(2);
  tft.setCursor(250,290);
  tft.setTextColor(ILI9341_BLACK);
  tft.print(PrevHum);
  tft.setCursor(250,290);
  tft.setTextColor(ILI9341_WHITE);
  tft.print("Error");
  }
  else  if(PrevHum!=hum){
    tft.setTextSize(2);
    tft.setCursor(250,290);
    tft.setTextColor(ILI9341_BLACK);
    tft.print(PrevHum);
    tft.setCursor(250,290);
    tft.setTextColor(ILI9341_WHITE);
    tft.print(hum);
    tft.setCursor(320,290);
    tft.print(" %");
    PrevHum=hum;
  }
  //display.update();
  if (temp<maxt){
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
  }
  else if(temp<mint){
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }
  else{
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }
if (hum<minh){
    digitalWrite(6,HIGH);
  }
 else{
   digitalWrite(6,LOW);
 }

  }
else{
   if(flag==1){
     tft.fillScreen(ILI9341_BLACK);
     PrevMaxt=130.0;
     PrevMaxh=200.0;
     PrevMint=-50.0;
     PrevMinh=-1.0;
     PrevTemp=0.0;
     PrevHum=0.0;
     PrevBat=110.0;
     flag=0;
   }
}
}
