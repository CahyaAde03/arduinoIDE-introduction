const int pinLed = 9;
const int pinPot = A0;
void setup() {
  // put your setup code here, to run once:
pinMode(pinPot, INPUT);
pinMode(pinLed, OUTPUT);
}
int sensor = 0;
int cerah = 0;
void loop() {
  // put your main code here, to run repeatedly:
sensor = analogRead(pinPot);
cerah = map(sensor,0,1023,0,255);
analogWrite(pinLed, cerah);
}
