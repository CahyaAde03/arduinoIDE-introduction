#include <BigNumbers.h>

//YWROBOT

//Compatible with the Arduino IDE 1.0

//Library version:1.1

#include <Wire.h> 

#include <LiquidCrystal_I2C.h>

#include <RunningAverage.h>


RunningAverage myRA(10);
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
const int soilPin = A0;
const int relayPin = 2;
// Variables will change:

int vol = 0;   // counter for the number of button presses
int lastVol = -1;
int samples = 0;
//karakter

byte a[8] = {
  B00011,
  B00100,
  B01010,
  B01000,
  B01010,
  B01001,
  B00100,
  B00011
};
byte b[8] = {
  B11000,
  B00100,
  B01010,
  B00010,
  B01010,
  B10010,
  B00100,
  B11000
};
byte c[8] = {
  B00011,
  B00100,
  B01010,
  B01000,
  B01001,
  B01010,
  B00100,
  B00011
};
byte d[8] = {
  B11000,
  B00100,
  B01010,
  B00010,
  B10010,
  B01010,
  B00100,
  B11000
};
//angka
byte LT[8] = 
{
  B00111,
  B01111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte UB[8] =
{
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000

};

byte RT[8] =
{
  B11100,
  B11110,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111

};

byte LL[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B01111,
  B00111
};

byte LB[8] =
{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111
};

byte LR[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11110,
  B11100
};

byte MB[8] =
{
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};

byte block[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};



void setup(){
  Serial.begin(9600);
  pinMode(soilPin, INPUT);
  pinMode(relayPin, OUTPUT);
  
  digitalWrite(relayPin, HIGH);
  
  lcd.init();
  lcd.backlight(); 
  String loadingText = "Loading....";
  int textLength = loadingText.length();
  for (int i = 0; i < textLength; ++i) {
    lcd.setCursor(i, 0);
    lcd.print(loadingText[i]);
    delay(200); 
  }
  delay(1000); 
  
  lcd.clear();  
  lcd.setCursor(4,0);
  lcd.print("PENYIRAM");
  lcd.setCursor(4,1);
  lcd.print("OTOMATIS");
  delay(2000);
 //karakter
  lcd.createChar(10,a);
  lcd.createChar(11,b);
  lcd.createChar(12,c);
  lcd.createChar(13,d);
 //angka  
  lcd.createChar(0,LT);
  lcd.createChar(1,UB);
  lcd.createChar(2,RT);
  lcd.createChar(3,LL);
  lcd.createChar(4,LB);
  lcd.createChar(5,LR);
  lcd.createChar(6,MB);
  lcd.createChar(7,block);
  // Print a message to the LCD.
  lcd.clear();
  displayNumber();
}

void printNumber(int val){
     int col=5;     
     if( val >= 10){
       printDigits(val/10,col);     
       printDigits(val%10,col+4);
     }
     else{
       printDigits(val,col);
     }
}

void loop(){
   vol = analogRead(soilPin);
   vol = map(vol, 1023, 0, 0, 99); 
    myRA.addValue(vol );
    samples++; 
   if (samples == 300){
    vol = myRA.getAverage();
   }
    if( lastVol != vol ){      
      Serial.println( vol );
       lastVol = vol;
       displayNumber();

    }
    samples = 0;
    myRA.clear();
}

void displayNumber(){
    lcd.clear();
    if( vol >= 20){
      digitalWrite(relayPin,HIGH); 
      lcd.setCursor(0,0);
      lcd.print("Nilai");
      printNumber( vol );
      lcd.print(" %");

      delay(2000);
    }else{
      digitalWrite(relayPin,LOW);
      lcd.setCursor(0,0);
      lcd.print("Nilai");
      printNumber( vol );
      lcd.print(" %");
      delay(2000);
      lcd.clear();


  }
}
void custom0(int x){ 
  lcd.setCursor(x,0); 
  lcd.write(0);  
  lcd.write(1);  
  lcd.write(2);
  lcd.setCursor(x, 1); 
  lcd.write(3);  
  lcd.write(4);  
  lcd.write(5);
}
void custom1(int x){
  lcd.setCursor(x,0);
  lcd.write(1);
  lcd.write(2);
  lcd.print(" ");
  lcd.setCursor(x,1);
  lcd.write(4);
  lcd.write(7);
  lcd.write(4);
}
void custom2(int x){
  lcd.setCursor(x,0);
  lcd.write(6);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(4);
}
void custom3(int x){
  lcd.setCursor(x,0);
  lcd.write(6);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.write(4);
  lcd.write(4);
  lcd.write(5); 
}
void custom4(int x){
  lcd.setCursor(x,0);
  lcd.write(3);
  lcd.write(4);
  lcd.write(7);
  lcd.setCursor(x, 1);
  lcd.print(" ");
  lcd.print(" ");
  lcd.write(7);
}
void custom5(int x){
  lcd.setCursor(x,0);
  lcd.write(3);
  lcd.write(6);
  lcd.write(6);
  lcd.setCursor(x, 1);
  lcd.write(4);
  lcd.write(4);
  lcd.write(5);
}
void custom6(int x){
  lcd.setCursor(x,0);
  lcd.write(0);
  lcd.write(6);
  lcd.write(6);
  lcd.setCursor(x, 1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
}
void custom7(int x){
  lcd.setCursor(x,0);
  lcd.write(1);
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.print(" ");
  lcd.print(" ");
  lcd.write(7);
}
void custom8(int x){
  lcd.setCursor(x,0);
  lcd.write(0);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
}
void custom9(int x){
  lcd.setCursor(x,0);
  lcd.write(0);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 1);
  lcd.print(" ");
  lcd.print(" ");
  lcd.write(7);
}
void printDigits(int digits, int x){
  x+=2;
  switch (digits) {
  case 0:  
    custom0(x);
    break;
  case 1:  
    custom1(x);
    break;
  case 2:  
    custom2(x);
    break;
  case 3:  
    custom3(x);
    break;
  case 4:  
    custom4(x);
    break;
  case 5:  
    custom5(x);
    break;
  case 6:  
    custom6(x);
    break;
  case 7:  
    custom7(x);
    break;
  case 8:  
    custom8(x);
    break;
  case 9:  
    custom9(x);
    break;
  }
}
