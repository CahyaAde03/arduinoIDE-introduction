int trig = 9; 
int echo = 8; 
int red = 10;  
int yellow = 11; 
int green = 12; 

long duration = 0;  
int cm = 0; 
int in = 0; 

void setup()
{
  pinMode(trig, OUTPUT);  
  pinMode(echo, INPUT);  
  pinMode(red, OUTPUT);  
  pinMode(yellow, OUTPUT);  
  pinMode(green, OUTPUT);  
  Serial.begin(9600);  
  Serial.println("Serial Started...");   
}

void loop()
{
  digitalWrite(trig,LOW); 
  digitalWrite(trig,HIGH); 
  digitalWrite(trig,LOW); 
  
  int duration = pulseIn (echo, HIGH);  
  cm = duration*0.034/2;  
  in = duration*0.0133/2; 
  
  Serial.println(in);  
  
  if (in >= 30){ 
    digitalWrite(green, LOW); 
    digitalWrite(yellow, LOW); 
    digitalWrite(red, LOW);  
    digitalWrite(green, HIGH); 
    digitalWrite(yellow, LOW); 
    digitalWrite(red, LOW); 
    
  }
  
   else if (in < 20 && in > 10){ 
    digitalWrite(green, LOW); 
    digitalWrite(yellow, LOW); 
    digitalWrite(red, LOW); 
    digitalWrite(green, LOW); 
    digitalWrite(yellow, HIGH); 
    digitalWrite(red, LOW); 
    
  }
  
   else if (in <= 5 ){ 
    digitalWrite(green, LOW); 
    digitalWrite(yellow, LOW); 
    digitalWrite(red, LOW); 
    digitalWrite(green, LOW); 
    digitalWrite(yellow, LOW); 
    digitalWrite(red, HIGH); 
   
  }
}
