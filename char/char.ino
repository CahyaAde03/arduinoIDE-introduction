#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

byte a[8] = {
  B00000,
  B01010,
  B01010,
  B00000,
  B10001,
  B10001,
  B01110,
  B00000
};
byte b[8] = {
  B00000,
  B01010,
  B01010,
  B00000,
  B01110,
  B10001,
  B10001,
  B00000
};
void setup() {
  lcd.init();
  lcd.backlight();

  // Memindahkan createChar sebelum mencoba untuk mencetaknya
  lcd.createChar(0, a);
  lcd.createChar(1, b);

  displayBinaryChars(); // Menampilkan karakter biner pada inisialisasi
}

void loop() {
  // Loop utama (kosong)
}

void displayBinaryChars() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.write(byte(1));

  delay(2000);
}
