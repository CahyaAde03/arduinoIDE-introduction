const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int fadeDelay = 10; // Waktu jeda antara setiap perubahan warna
const int steps = 3000;    // Jumlah langkah per perubahan warna

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Animasi perpindahan mulus
  for (int step = 0; step < steps; step++) {
    float t = float(step) / steps;
    int r = int(255 * (1 + sin(2 * PI * t)) / 2);
    int g = int(255 * (1 + sin(2 * PI * (t - 1/3.0)) / 2));
    int b = int(255 * (1 + sin(2 * PI * (t - 2/3.0)) / 2));

    analogWrite(redPin, r);
    analogWrite(greenPin, g);
    analogWrite(bluePin, b);
    delay(fadeDelay);
  }
}
