const int buzzerPin = 3; // Atur pin buzzer ke pin 3 atau pin lain yang sesuai

void setup() {
  pinMode(buzzerPin, OUTPUT); // Mengatur pin buzzer sebagai OUTPUT
}

void loop() {
  // Untuk menghidupkan buzzer, Anda dapat mengirimkan sinyal HIGH ke pin buzzer
  digitalWrite(buzzerPin, HIGH);
  delay(100); // Tahan selama 1 detik
  
  // Untuk mematikan buzzer, Anda dapat mengirimkan sinyal LOW ke pin buzzer
  digitalWrite(buzzerPin, LOW);
  delay(10000); // Tahan selama 1 detik
}
