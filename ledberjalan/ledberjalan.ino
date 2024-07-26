int ledPins[] = {2, 3, 4, 5, 6, 7};
int numLEDs = 6;
int delayTime = 100; // Waktu jeda antara setiap LED (ms)

void setup() {
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], HIGH); // Hidupkan LED saat ini
    delay(delayTime);
    digitalWrite(ledPins[i], LOW); // Matikan LED saat ini
  }
  
  for (int i = numLEDs - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH); // Hidupkan LED saat ini
    delay(delayTime);
    digitalWrite(ledPins[i], LOW); // Matikan LED saat ini
  }
}
