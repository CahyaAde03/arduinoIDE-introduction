int sensorPin = A0;
int sensorNilai = 0;
int led = 13;
boolean flag = false;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(led,OUTPUT);

}

void loop() {
  sensorNilai = analogRead(sensorPin);
  Serial.println(sensorNilai);
    delay(1000);
    }
