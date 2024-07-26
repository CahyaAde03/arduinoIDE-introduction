// pin 2 sebagai input dan pin 8 sebagai output
const int pinButton = 2;
const int pinLED = 8;
const int A = 7;

void setup() {
  pinMode(pinButton, INPUT);
  pinMode(pinLED, OUTPUT);
  pinMode(A,OUTPUT);
// aktifkan pull-up resistor
  digitalWrite(pinButton, HIGH);
}

void loop() {
  if(digitalRead(pinButton) == LOW){
    digitalWrite(pinLED, HIGH);
    digitalWrite(A,HIGH);
  }else{
    digitalWrite(pinLED, LOW);
    digitalWrite(A,LOW);
  }
}
