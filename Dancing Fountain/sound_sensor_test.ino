
int digit_sensor = 12; // select the input pin for the potentiometer
int digitValue ;  //  value from the digit input pin
void setup () {
pinMode (digit_sensor, INPUT);
Serial.begin (9600);
}
void loop () {
digitValue=analogRead(digit_sensor);
Serial.println (digitValue, DEC);
delay(1000);
}
