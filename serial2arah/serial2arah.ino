String nilai;
int merah = 3;
int kuning = 4;
int hijau = 5;

void setup(){
pinMode(merah,OUTPUT);
pinMode(kuning,OUTPUT);
pinMode(hijau,OUTPUT);
Serial.begin(9600);
Serial.print("Lampu Led = ");
}
void loop(){
  if(Serial.available()>0){
    char nilai = Serial.read();
    switch (nilai){
      case 'A':
      
    Serial.println("Lampu Merah Menyala");
    digitalWrite(merah,HIGH);
    digitalWrite(kuning,LOW);
    digitalWrite(hijau,LOW);
        break;
        
      case 'B':
    Serial.println("Lampu Kuning Menyala");
    digitalWrite(merah,LOW);
    digitalWrite(kuning,HIGH);
    digitalWrite(hijau,LOW);
        break;
        
      case 'C':
    Serial.println("Lampu Hijau Menyala");
    digitalWrite(merah,LOW);
    digitalWrite(kuning,LOW);
    digitalWrite(hijau,HIGH);
        break;
        
      case 'D':
    Serial.println("Semua Kedip");
    digitalWrite(merah,HIGH);
    delay(1000);
    digitalWrite(merah,LOW);
    delay(1000);
    digitalWrite(kuning,HIGH);
    delay(1000);
    digitalWrite(kuning,LOW);
    delay(1000);
    digitalWrite(hijau,HIGH);
    delay(1000);
    digitalWrite(hijau,LOW);
    delay(1000);
        break;
    }
  }
}  
 
  
