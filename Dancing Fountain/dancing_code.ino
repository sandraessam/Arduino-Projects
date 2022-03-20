int MOTOR1= 3;
int MOTOR2= 5 ;
int MOTOR3= 10 ;        
int LED1= 4 ;
int LED2= 6 ;
int LED3= 11 ;
int LED4= 2 ;
int LED5= 7 ;
int LED6= 8 ;
int LED7= 9 ;
int digit_sensor = 12; // select the input pin for the potentiometer
int digitValue ;  //  value from the digit input pin

void setup() {
  pinMode (MOTOR1,OUTPUT) ;
  pinMode (MOTOR2,OUTPUT) ;
  pinMode (MOTOR3,OUTPUT) ;
  pinMode (LED1,OUTPUT) ;
  pinMode (LED2,OUTPUT) ;
  pinMode (LED3,OUTPUT) ;
  pinMode (LED4,OUTPUT) ;
  pinMode (LED5,OUTPUT) ;
  pinMode (LED6,OUTPUT) ;
  pinMode (LED7,OUTPUT) ;
  pinMode (digit_sensor, INPUT);
Serial.begin (9600);
}

void loop() {
  digitValue=analogRead(digit_sensor);
  
Serial.println (digitValue, DEC);
if( digitValue>=160 and digitValue<=220 )
 {
  digitalWrite (MOTOR1,LOW) ;
 digitalWrite (MOTOR2,HIGH) ;
 digitalWrite (MOTOR3,LOW) ;
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,LOW) ;
  digitalWrite (LED4,LOW) ;
 digitalWrite (LED5,HIGH) ;
 digitalWrite (LED6,LOW) ;
  digitalWrite (LED7,HIGH) ;
delay (350);
 digitalWrite (MOTOR1,HIGH) ;
 digitalWrite (MOTOR2,LOW) ;
 digitalWrite (MOTOR3,LOW) ;
 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,LOW) ;
  digitalWrite (LED4,HIGH) ;
 digitalWrite (LED5,LOW) ;
 digitalWrite (LED6,LOW) ;
  digitalWrite (LED7,HIGH) ;
delay (350);
 digitalWrite (MOTOR1,LOW) ;
 digitalWrite (MOTOR2,LOW) ;
 digitalWrite (MOTOR3,HIGH) ;
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,HIGH) ;
 digitalWrite (LED4,LOW) ;
 digitalWrite (LED5,LOW) ;
 digitalWrite (LED6,HIGH) ;
  digitalWrite (LED7,LOW) ;

delay (350);
 }
 else if ( digitValue>=220 and digitValue<=250 )
 {
  digitalWrite (MOTOR1,HIGH) ;
 digitalWrite (MOTOR2,LOW) ;
 digitalWrite (MOTOR3,LOW) ;
 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,LOW) ;
delay (350);
 digitalWrite (MOTOR1,LOW) ;
 digitalWrite (MOTOR2,HIGH) ;
 digitalWrite (MOTOR3,LOW) ;
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,LOW) ;
 digitalWrite (LED4,LOW) ;
 digitalWrite (LED5,HIGH) ;
 digitalWrite (LED6,LOW) ;
  digitalWrite (LED7,HIGH) ;
delay (350);
 digitalWrite (MOTOR1,LOW) ;
 digitalWrite (MOTOR2,LOW) ;
 digitalWrite (MOTOR3,HIGH) ;
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,HIGH) ;
 digitalWrite (LED4,LOW) ;
 digitalWrite (LED5,LOW) ;
 digitalWrite (LED6,HIGH) ;
 digitalWrite (LED7,HIGH) ;
delay (350);
digitalWrite (MOTOR1,HIGH) ;
 digitalWrite (MOTOR2,HIGH) ;
 digitalWrite (MOTOR3,LOW) ;
 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,LOW) ;
  digitalWrite (LED4,HIGH) ;
 digitalWrite (LED5,HIGH) ;
 digitalWrite (LED6,LOW) ;
 digitalWrite (LED7,LOW) ;
delay (350);
digitalWrite (MOTOR1,LOW) ;
 digitalWrite (MOTOR2,HIGH) ;
 digitalWrite (MOTOR3,HIGH) ;
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,HIGH) ;
 digitalWrite (LED4,LOW) ;
 digitalWrite (LED5,HIGH) ;
 digitalWrite (LED6,HIGH) ;
  digitalWrite (LED7,LOW) ;
delay (350);
digitalWrite (MOTOR1,HIGH) ;
 digitalWrite (MOTOR2,HIGH) ;
 digitalWrite (MOTOR3,HIGH) ;
 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,HIGH) ;
  digitalWrite (LED4,HIGH) ;
 digitalWrite (LED5,HIGH) ;
 digitalWrite (LED6,HIGH) ;
 digitalWrite (LED7,HIGH) ;

delay (350);
 }
else if ( digitValue>=280 and digitValue<=310 )
 {
  digitalWrite (MOTOR1,LOW) ;
 digitalWrite (MOTOR2,LOW) ;
 digitalWrite (MOTOR3,HIGH) ;
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,HIGH) ;
  digitalWrite (LED4,LOW) ;
 digitalWrite (LED5,LOW) ;
 digitalWrite (LED6,HIGH) ;
  digitalWrite (LED7,HIGH) ;
delay (350);
 digitalWrite (MOTOR1,LOW) ;
 digitalWrite (MOTOR2,HIGH) ;
 digitalWrite (MOTOR3,LOW) ;
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,LOW) ;
 digitalWrite (LED4,LOW) ;
 digitalWrite (LED5,HIGH) ;
 digitalWrite (LED6,LOW) ;
  digitalWrite (LED7,HIGH) ;

 
delay (350);
 digitalWrite (MOTOR1,HIGH) ;
 digitalWrite (MOTOR2,HIGH) ;
 digitalWrite (MOTOR3,HIGH) ;
 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,HIGH) ;
 digitalWrite (LED4,HIGH) ;
 digitalWrite (LED5,HIGH) ;
 digitalWrite (LED6,HIGH) ;
delay (350);
digitalWrite (MOTOR1,LOW) ;
 digitalWrite (MOTOR2,HIGH) ;
 digitalWrite (MOTOR3,LOW) ;
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,LOW) ;
  digitalWrite (LED4,LOW) ;
 digitalWrite (LED5,HIGH) ;
 digitalWrite (LED6,LOW) ;
  digitalWrite (LED7,HIGH) ;

 
delay (350);
digitalWrite (MOTOR1,LOW) ;
 digitalWrite (MOTOR2,HIGH) ;
 digitalWrite (MOTOR3,HIGH) ;
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,HIGH) ;
 digitalWrite (LED4,LOW) ;
 digitalWrite (LED5,HIGH) ;
 digitalWrite (LED6,HIGH) ;
  digitalWrite (LED7,LOW) ;
delay (350);

 digitalWrite (MOTOR1,HIGH) ;
 digitalWrite (MOTOR2,LOW) ;
 digitalWrite (MOTOR3,LOW) ;
 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,LOW) ;
  digitalWrite (LED4,HIGH) ;
 digitalWrite (LED5,LOW) ;
 digitalWrite (LED6,LOW) ;
  digitalWrite (LED7,LOW) ;

delay (350);
}
else if ( digitValue>310 and digitValue<=340 )
 {
  digitalWrite (MOTOR1,LOW) ;
 digitalWrite (MOTOR2,LOW) ;
 digitalWrite (MOTOR3,HIGH) ;
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,HIGH) ;
 digitalWrite (LED4,LOW) ;
 digitalWrite (LED5,LOW) ;
 digitalWrite (LED6,HIGH) ;
  digitalWrite (LED7,LOW) ;

 
delay (350);
digitalWrite (MOTOR1,LOW) ;
digitalWrite (MOTOR2,HIGH) ;
digitalWrite (MOTOR3,LOW) ;
digitalWrite (LED1,LOW) ;
digitalWrite (LED2,HIGH) ;
digitalWrite (LED3,LOW) ;
digitalWrite (LED4,LOW) ;
digitalWrite (LED5,HIGH) ;
digitalWrite (LED6,LOW) ;
 digitalWrite (LED7,LOW) ;

 
delay (350);
 digitalWrite (MOTOR1,HIGH) ;
 digitalWrite (MOTOR2,HIGH) ;
 digitalWrite (MOTOR3,HIGH) ;
 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,HIGH) ;
  digitalWrite (LED4,HIGH) ;
 digitalWrite (LED5,HIGH) ;
 digitalWrite (LED6,HIGH) ;
  digitalWrite (LED7,HIGH) ;

delay (350);
digitalWrite (MOTOR1,LOW) ;
 digitalWrite (MOTOR2,HIGH) ;
 digitalWrite (MOTOR3,LOW) ;
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,LOW) ;
 digitalWrite (LED4,LOW) ;
 digitalWrite (LED5,HIGH) ;
 digitalWrite (LED6,LOW) ;
  digitalWrite (LED7,HIGH) ;

delay (350);
digitalWrite (MOTOR1,LOW) ;
 digitalWrite (MOTOR2,HIGH) ;
 digitalWrite (MOTOR3,HIGH) ;
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,HIGH) ;
 digitalWrite (LED4,LOW) ;
 digitalWrite (LED5,HIGH) ;
 digitalWrite (LED6,HIGH) ;
  digitalWrite (LED7,LOW) ;

 
delay (350);

 digitalWrite (MOTOR1,HIGH) ;
 digitalWrite (MOTOR2,LOW) ;
 digitalWrite (MOTOR3,LOW) ;
 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,LOW) ;
 digitalWrite (LED4,HIGH) ;
 digitalWrite (LED5,LOW) ;
 digitalWrite (LED6,LOW) ;
  digitalWrite (LED7,LOW) ;
delay (350);
}
else if( digitValue>340 and digitValue<370 )
 {
  digitalWrite (MOTOR1,LOW) ;
 digitalWrite (MOTOR2,HIGH) ;
 digitalWrite (MOTOR3,LOW) ;
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,LOW) ;
 digitalWrite (LED4,LOW) ;
 digitalWrite (LED5,HIGH) ;
 digitalWrite (LED6,LOW) ;
  digitalWrite (LED7,HIGH) ;

delay (350);
 digitalWrite (MOTOR1,HIGH) ;
 digitalWrite (MOTOR2,LOW) ;
 digitalWrite (MOTOR3,HIGH) ;
 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,HIGH) ;
  digitalWrite (LED4,HIGH) ;
 digitalWrite (LED5,LOW) ;
 digitalWrite (LED6,HIGH) ;
  digitalWrite (LED7,LOW) ;
delay (350);
 digitalWrite (MOTOR1,HIGH) ;
 digitalWrite (MOTOR2,HIGH) ;
 digitalWrite (MOTOR3,HIGH) ;
 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,HIGH) ;
 digitalWrite (LED4,HIGH) ;
 digitalWrite (LED5,LOW) ;
 digitalWrite (LED6,HIGH) ;
 digitalWrite (LED7,HIGH) ;
delay (350);
 }
else if( digitValue>370 and digitValue<400 )
 {
  digitalWrite (MOTOR1,HIGH) ;
 digitalWrite (MOTOR2,HIGH) ;
 digitalWrite (MOTOR3,HIGH) ;
 digitalWrite (LED1,HIGH) ;
 digitalWrite (LED2,HIGH) ;
 digitalWrite (LED3,HIGH) ;
  digitalWrite (LED4,HIGH) ;
 digitalWrite (LED5,HIGH) ;
 digitalWrite (LED6,HIGH) ;
 digitalWrite (LED7,HIGH) ;
delay (350);
 digitalWrite (MOTOR1,LOW) ;
 digitalWrite (MOTOR2,LOW) ;
 digitalWrite (MOTOR3,LOW) ;
 digitalWrite (LED1,LOW) ;
 digitalWrite (LED2,LOW) ;
 digitalWrite (LED3,LOW) ;
 digitalWrite (LED4,LOW) ;
 digitalWrite (LED5,LOW) ;
 digitalWrite (LED6,LOW) ;
  digitalWrite (LED7,LOW) ;

 
 
delay (350);
 
 }
}



