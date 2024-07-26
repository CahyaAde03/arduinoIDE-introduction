
// I am connecting two servos to a jostick where each servo will represent one axis of Joystick's movement

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo2;

int pos = 0;    // variable to store the servo position
int joyX = 0;   //Analog pin to which the joystick (X) is connected
int joyY = 1;   //Analog pin to which the joystick (Y) is connected

void setup() {
  
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);
}

void loop() {
    int valX = analogRead(joyX); //Read the joystick X value (value between 0 and 1023)
    int valY = analogRead(joyY); //Read the joystick Y value (value between 0 and 1023)

    valX = map(valX, 1023, 0, 0, 360); //Scale the joystick X value to use it with the servo
    valY = map(valY, 1023, 0, 0, 360); //Scale the joystick X value to use it with the servo

    //Sets the servo position according to the scaled values.
    myservo.write(valY);   // will move vertical Servo
    myservo2.write(valX);  // will move horizontal servo

    delay(5);


 
}
