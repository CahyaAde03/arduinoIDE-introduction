#include <AccelStepper.h>

const int motorPin1 = 8;  // Pin 1 motor stepper
const int motorPin2 = 9;  // Pin 2 motor stepper
const int motorPin3 = 10; // Pin 3 motor stepper
const int motorPin4 = 11; // Pin 4 motor stepper

AccelStepper stepper(1, motorPin1, motorPin3); // Inisialisasi motor stepper dengan mode full step

void setup() {
  stepper.setMaxSpeed(1000.0);      // Kecepatan maksimum motor stepper (sesuaikan dengan motor Anda)
  stepper.setAcceleration(500.0);    // Percepatan motor stepper (sesuaikan dengan motor Anda)
}

void loop() {
  stepper.runSpeed();  // Motor stepper bergerak dengan kecepatan maksimum
}
 
