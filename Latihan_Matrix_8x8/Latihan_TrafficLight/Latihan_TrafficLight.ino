const int pinled1 = 11;
const int pinled2 = 12;
const int pinled3 = 13;

void setup() {
  // put your setup code here, to run once
pinMode(pinled1,OUTPUT);
pinMode(pinled2,OUTPUT);
pinMode(pinled3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(pinled1, HIGH);
delay(10000);
digitalWrite(pinled1, LOW);
digitalWrite(pinled2,HIGH);
delay(500);
digitalWrite(pinled2,LOW);
digitalWrite(pinled3, HIGH);
delay(10000);
digitalWrite(pinled3,LOW);
}
