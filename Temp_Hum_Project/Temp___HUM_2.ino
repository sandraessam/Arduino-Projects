/* 
   -- New project -- 
    
   This source code of graphical user interface  
   has been generated automatically by RemoteXY editor. 
   To compile this code using RemoteXY library 2.3.3 or later version  
   download by link http://remotexy.com/en/library/ 
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                    
     - for ANDROID 4.1.1 or later version; 
     - for iOS 1.2.1 or later version; 
     
   This source code is free software; you can redistribute it and/or 
   modify it under the terms of the GNU Lesser General Public 
   License as published by the Free Software Foundation; either 
   version 2.1 of the License, or (at your option) any later version.     
*/ 

////////////////////////////////////////////// 
//        RemoteXY include library          // 
////////////////////////////////////////////// 

// RemoteXY select connection mode and include library  
#define REMOTEXY_MODE__ETHERNET_LIB
#include <Ethernet.h> 
/* Ethernet shield used pins: 10(SS) */ 
#include <SPI.h> 
/* SPI interface used pins: 11(MOSI), 12(MISO), 13(SCK) */ 

#include <RemoteXY.h> 

// RemoteXY connection settings  
#define REMOTEXY_ETHERNET_MAC "DE:AD:BE:EF:EF:ED" 
#define REMOTEXY_SERVER_PORT 6377 


// RemoteXY configurate   
#pragma pack(push, 1) 

uint8_t RemoteXY_CONF[] =   // 138 bytes
  { 255,2,0,25,0,131,0,16,179,0,66,129,61,10,29,4,38,26,66,193,
  30,10,31,4,189,26,129,0,3,2,18,6,173,84,101,109,112,101,114,97,
  116,117,114,101,32,58,0,129,0,4,24,35,6,173,72,117,109,105,100,105,
  116,121,32,37,58,0,129,0,56,17,10,6,173,48,194,176,67,0,67,4,
  52,2,20,5,2,26,11,67,4,51,25,20,5,2,26,11,2,1,9,46,
  22,11,2,26,31,31,79,78,0,79,70,70,0,2,1,69,46,22,11,36,
  26,31,31,79,78,0,79,70,70,0,66,129,38,34,48,4,133,26 };
   
// this structure defines all the variables of your control interface  
struct { 

    // input variable
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
  uint8_t switch_2; // =1 if switch ON and =0 if OFF 

    // output variable
  signed char level_temp_up; // =0..100 level position 
  signed char level_temp_down; // =0..100 level position 
  signed char level_hum; // =0..100 level position 
  char text_temp[11];  // string UTF8 end zero 
  char text_hum[11];  // string UTF8 end zero 

    // other variable
  unsigned char connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop) 

///////////////////////////////////////////// 
//           END RemoteXY include          // 
///////////////////////////////////////////// 
#include <DHT.h> 
#define DHTPIN 2 
DHT dht(DHTPIN, DHT11);

#define PIN_SWITCH_1 A0
#define PIN_SWITCH_2 A1




void setup()  
{ 
  RemoteXY_Init ();  
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT); 
  pinMode (PIN_SWITCH_1, OUTPUT);
  pinMode (PIN_SWITCH_2, OUTPUT);
   
  // TODO you setup code 
   
} 

void loop()  
{  
  RemoteXY_Handler (); 
   
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_2, (RemoteXY.switch_2==0)?LOW:HIGH);
   
  // TODO you loop code 
  // use the RemoteXY structure for data transfer 

  float temp = dht.readTemperature();   
  float hum = dht.readHumidity(); 
  dtostrf(temp, 0, 1, RemoteXY.text_temp); 
  dtostrf(hum, 0, 1, RemoteXY.text_hum); 
   
  if (temp<0) { 
    RemoteXY.level_temp_up = 0; 
    RemoteXY.level_temp_down = min (-temp*2,100); 

  } 
  else if (temp>0) { 
    RemoteXY.level_temp_up = min(temp*2,100); 
    RemoteXY.level_temp_down = 0; 
  } 
  else { 
    RemoteXY.level_temp_up = 0; 
    RemoteXY.level_temp_down = 0; 
  } 
  RemoteXY.level_hum = hum;


int maxHum = 70;
int maxTemp = 22;
/*int maxHum1 = 68;
int maxTemp1 = 20;*/


  if(hum >= maxHum ) {
      digitalWrite(A4, HIGH);
      
  } else if(hum < maxHum ){
     digitalWrite(A4, LOW);
      
  }

  if(temp >= maxTemp ) {
      digitalWrite(A5, HIGH);
      
  } else if(temp < maxTemp ){
     digitalWrite(A5, LOW);
      
  }
 delay(2000); 

}

