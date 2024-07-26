int red = 7;
int yel = 6;
int gre = 5;
void setup() {
  pinMode(red, OUTPUT);
  pinMode(yel, OUTPUT);
  pinMode(gre, OUTPUT);

}

void loop() {
  digitalWrite(red, HIGH);
  delay(5000);
  digitalWrite(red,LOW);
  digitalWrite(yel,HIGH);
  delay(1000);
  digitalWrite(yel,LOW);
  digitalWrite(gre,HIGH);
  delay(2000);
  digitalWrite(gre,LOW);

}
