#define led1 3;
#define led2 4;
void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  Serial.print("Lampu LED: ");

}

void loop() {
   Serial.println("Lampu ON");
   digitalWrite(3,HIGH);
   delay(5000);

   Serial.println("Lampu OFF");
   digitalWrite(3,LOW);
   delay(5000);

  
}
