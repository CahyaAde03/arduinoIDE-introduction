#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  lcd.init();
  lcd.backlight();

}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("rangkaian");

  lcd.setCursor(0, 1);
  lcd.print("mikrokontroler");
  delay(2000);
  lcd.clear();
  delay(200);
 

}
