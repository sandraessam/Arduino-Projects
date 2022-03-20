
int LED1= 4 ;
int LED2= 6 ;
int LED3= 11 ;
int digit_sensor = 12; // select the input pin for the potentiometer
int digitValue ;  //  value from the digit input pin

void setup() {
  
  pinMode (LED1,OUTPUT) ;
  pinMode (LED2,OUTPUT) ;
  pinMode (LED3,OUTPUT) ;
  pinMode (digit_sensor, INPUT);
Serial.begin (9600);
}

void loop() {
  digitValue=analogRead(digit_sensor);
  
Serial.println (digitValue, DEC);
if( digitValue>=160 and digitValue<=220 )
 {
 
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,LOW) ;
delay (350);
 
 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,LOW) ;
delay (350);

 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,HIGH) ;
delay (350);
 }
 else if ( digitValue>=220 and digitValue<=250 )
 {
 
 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,LOW) ;
delay (350);
 
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,LOW) ;
delay (350);
 
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,HIGH) ;
delay (350);

 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,LOW) ;
delay (350);

 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,HIGH) ;
delay (350);

 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,HIGH) ;
delay (350);
 }
else if ( digitValue>=280 and digitValue<=310 )
 {
  
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,HIGH) ;
delay (350);

 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,LOW) ;
delay (350);
 
 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,HIGH) ;
delay (350);

 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,LOW) ;
delay (350);

 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,HIGH) ;
delay (350);


 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,LOW) ;
delay (350);
}
else if ( digitValue>310 and digitValue<=340 )
 {
 
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,HIGH) ;
delay (350);
 
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,LOW) ;
delay (350);
 
 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,HIGH) ;
delay (350);

 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,LOW) ;
delay (350);

 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,HIGH) ;
delay (350);

 
 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,LOW) ;
delay (350);
}
else if( digitValue>340 and digitValue<370 )
 {

 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,LOW) ;
delay (350);
 
 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,HIGH) ;
delay (350);
 
 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,HIGH) ;
delay (350);
 }
else if( digitValue>370 and digitValue<400 )
 {
  
 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,HIGH) ;
delay (350);
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,LOW) ;
delay (350);
 
 }
}



