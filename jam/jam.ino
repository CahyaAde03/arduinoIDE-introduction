#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long previousMillis = 0;
const long interval = 1000;  // 1 detik
int hours = 0;
int days = 1;  // Dimulai dari hari pertama

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    hours++;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Hari: ");
    lcd.print(days);

    lcd.setCursor(0, 1);
    lcd.print("Jam: ");
    lcd.print(hours);

    if (hours >= 86400) {
      hours = 0;
      days++;
    }
  }
}
