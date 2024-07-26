const int pinLed1 = 2;
const int pinLed2 = 3;
const int pinLed3 = 4;
const int relayPin = 5;
const int ldrPin = A0;
void setup() {
  Serial.begin(9600);
  pinMode(pinLed1,OUTPUT);
  pinMode(pinLed2,OUTPUT);
  pinMode(pinLed3,OUTPUT);
  pinMode(ldrPin, INPUT);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  int ldrState = analogRead(ldrPin);  

  if(ldrState<=500){
    digitalWrite(pinLed1,HIGH);
    digitalWrite(pinLed2,HIGH);
    digitalWrite(pinLed3,HIGH);
    digitalWrite(relayPin,LOW);
    Serial.println(ldrState);
    Serial.println("LDR tertutup, LED ON");
    delay(1000);
    
    }
  else{
    digitalWrite(pinLed1,LOW);
    digitalWrite(pinLed2,LOW);
    digitalWrite(pinLed3,LOW);
    digitalWrite(relayPin,HIGH);
    Serial.println(ldrState);
    Serial.println("LDR terbuka, LED OFF");
    delay(1000);
    }

}
