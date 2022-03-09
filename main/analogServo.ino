#include <Servo.h>;

Servo myServo;
#define potentomiterPin A2
#define servoPin 9

void setup(){
  pinMode(potentomiterPin, INPUT);
  Serial.begin(9600);
  myServo.attach(9);
}

void loop(){
  byte deg = map(analogRead(potentomiterPin), 0, 1023, 0, 180);
  myServo.write(deg)
}