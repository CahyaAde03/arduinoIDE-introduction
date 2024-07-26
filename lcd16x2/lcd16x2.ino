#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  String text = "Mata kuliah Mikrokontroler 2023 ";
  int textLength = text.length();
  int lcdWidth = 16;

  while (true) {
    for (int i = 0; i < textLength + lcdWidth; i++) {
      lcd.clear();
      int startPos = i;
      int endPos = i + lcdWidth;

      if (endPos > textLength) {
        int overflow = endPos - textLength;
        startPos -= overflow;
        endPos = textLength;
      }

      String displayText = text.substring(startPos, endPos);
      lcd.setCursor(0, 0);
      lcd.print(displayText);

      delay(300);
    }
  }
}
