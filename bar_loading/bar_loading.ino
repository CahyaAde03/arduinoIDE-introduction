#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Alamat I2C LCD 16x2: 0x27

void setup() {
  lcd.init();
  lcd.backlight();  
  String loadingText = "Loading.........";
  int textLength = loadingText.length();

  for (int i = 0; i < textLength; ++i) {
    lcd.setCursor(i, 0);
    lcd.print(loadingText[i]);
    delay(200); 
  }

  delay(1000); 
  lcd.clear();  
}

void loop() {
  
}
