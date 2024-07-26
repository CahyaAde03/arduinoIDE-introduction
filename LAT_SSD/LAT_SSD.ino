const int pinledA = 2;
const int pinledB = 3;
const int pinledC = 4;
const int pinledD = 5;
const int pinledE = 6;
const int pinledF = 7;
const int pinledG = 8;
const int pinledDP = 9;
void setup() {
  // put your setup code here, to run once:
pinMode(pinledA,OUTPUT);
pinMode(pinledB,OUTPUT);
pinMode(pinledC,OUTPUT);
pinMode(pinledD,OUTPUT);
pinMode(pinledE,OUTPUT);
pinMode(pinledF,OUTPUT);
pinMode(pinledG,OUTPUT);
pinMode(pinledDP,OUTPUT);
}

void loop() {
//keadaan awal ssd mati
digitalWrite(pinledA,HIGH);
digitalWrite(pinledB,HIGH);
digitalWrite(pinledC,HIGH);
digitalWrite(pinledD,HIGH);
digitalWrite(pinledE,HIGH);
digitalWrite(pinledF,HIGH);
digitalWrite(pinledG,HIGH);
digitalWrite(pinledDP,HIGH);
  // membuat angka 0 (semua pinled LOW kecuali pin G)
digitalWrite(pinledA,LOW);
digitalWrite(pinledB,LOW);
digitalWrite(pinledC,LOW);
digitalWrite(pinledD,LOW);
digitalWrite(pinledE,LOW);
digitalWrite(pinledF,LOW);
delay(1000);
//membuat angka 1 (pinledB dan pinled C LOW);
digitalWrite(pinledA,HIGH);
digitalWrite(pinledB,HIGH);
digitalWrite(pinledC,HIGH);
digitalWrite(pinledD,HIGH);
digitalWrite(pinledE,HIGH);
digitalWrite(pinledF,HIGH);
digitalWrite(pinledB,LOW);
digitalWrite(pinledC,LOW);
delay(1000);
//membuat angka 2 (pinledA,B,D,E,G ==LOW)
digitalWrite(pinledB,HIGH);
digitalWrite(pinledC,HIGH);
digitalWrite(pinledA,LOW);
digitalWrite(pinledB,LOW);
digitalWrite(pinledD,LOW);
digitalWrite(pinledE,LOW);
digitalWrite(pinledG,LOW);
delay(1000);
//membuat angka 3 (pinledA,B,C,D,G ==LOW)
digitalWrite(pinledA,HIGH);
digitalWrite(pinledB,HIGH);
digitalWrite(pinledD,HIGH);
digitalWrite(pinledE,HIGH);
digitalWrite(pinledG,HIGH);
digitalWrite(pinledA,LOW);
digitalWrite(pinledB,LOW);
digitalWrite(pinledC,LOW);
digitalWrite(pinledD,LOW);
digitalWrite(pinledG,LOW);
delay(1000); 

}
