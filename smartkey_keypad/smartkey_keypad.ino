#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Sesuaikan dengan alamat LCD I2C Anda
const int led2= 10;
const int led1= 11;
const int relay=12;

char password[4] = "123";  // Tidak perlu null-terminator karena sudah 3 karakter
char enteredPassword[4];  // Tidak perlu null-terminator karena sudah 3 karakter
int passwordIndex = 0;

const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  pinMode(led1, OUTPUT);
  pinMode(relay,OUTPUT);
  pinMode(led2, OUTPUT);
  lcd.print("   Smart Key   ");
  lcd.setCursor(0, 1);
  lcd.print("Password = ");
  digitalWrite(relay,HIGH);
}

void loop() {
  char customKey = customKeypad.getKey();
  
  if (customKey) {
    if (customKey == '#') {
      checkPassword();
    } else {
      enteredPassword[passwordIndex++] = customKey;
      lcd.print('*');  // Tampilkan karakter '*' untuk setiap input
      if (passwordIndex == 3) {
        checkPassword();
      }
    }
  }
}

void checkPassword() {
  lcd.clear();
  lcd.print("Checking...");
  delay(1000);

  // Bandingkan password yang dimasukkan dengan password yang benar
  if (strcmp(enteredPassword, password) == 0) {
    lcd.clear();
    lcd.print("Password Benar");
    digitalWrite(led1, HIGH);
    digitalWrite(relay,LOW);
    digitalWrite(led2, LOW);
    delay(2000);
    lcd.clear();
    lcd.print("Password = ");
    digitalWrite(led1, LOW);
  } else {
    lcd.clear();
    lcd.print("Password Salah");
    digitalWrite(led2, HIGH);
    digitalWrite(relay,HIGH);
    delay(2000);
    lcd.clear();
    lcd.print("Password = ");
    digitalWrite(led2, LOW);
  }
  
  // Reset variabel password
  memset(enteredPassword, 0, sizeof(enteredPassword));
  passwordIndex = 0;
  lcd.clear();
  lcd.print("Password = ");
}
