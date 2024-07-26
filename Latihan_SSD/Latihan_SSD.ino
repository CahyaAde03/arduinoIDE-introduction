//common anoda (LOW) dengan array
const int pinled[8]= {2,3,4,5,6,7,8,9}; //dibuat array
bool digit[10][7] ={ //kondisi led (khusus CA, karna menyala berarti 0
                    {0,0,0,0,0,0,1},
                    {1,0,0,1,1,1,1},
                    {0,0,1,0,0,1,0},
                    {0,0,0,0,1,1,0},
                    {1,0,0,1,1,0,0},
                    {0,1,0,0,1,0,0},
                    {0,1,0,0,0,0,0},
                    {0,0,0,1,1,1,1},
                    {0,0,0,0,0,0,0},
                    {0,0,0,0,1,0,0},
                     };
void setup() {
  // put your setup code here, to run once:
for(int i = 0;i<=7; i++){
  pinMode(pinled[i],OUTPUT); //mendeklare array dari ssd
}
for(int i = 0;i<=7; i++){
  digitalWrite(pinled[i],HIGH);  //keadaan awal ssd mati
}
}
void loop() {
  tampilan(0);
  delay(1000);
  tampilan(1);
  delay(1000);
  tampilan(2);
  delay(1000);
  tampilan(3);
  delay(1000 );
  tampilan(4);
  delay(1000);
  tampilan(5);
  delay(1000);
  tampilan(6);
  delay(1000);
  tampilan(7);
  delay(1000 );
  tampilan(8);
  delay(1000);
  tampilan(9);
  delay(1000);
}
void tampilan(int angka){   //loop untuk memanggil bool digit, angka=variabel yang akan dipanggil
  for(int i = 0; i<=8;i++){
    digitalWrite(pinled[i],digit[angka][i]);
    
  }
}
