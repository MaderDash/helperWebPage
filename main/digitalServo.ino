/*
Date :              03-09-22
By                  Maderdash
Connect two 10 k resistors to pin A2
Then we connect a switch to each one.

GND---[10k]---PIN_A2---[10k]---5V
--\---[switch]------\-----[switch]--\

*/

#include <Servo.h>                // We add a library to oiur code.

Servo myServo;                    // We create a servo named myServo

#define sence_pin A2              //The pin we want to read the value on.
int analog_reading   = 0;         //This will be the raw value gatherd from the pin.
int angle            = 0;         // This will be the angle that we want to move the servo to.

void setup() {
  myServo.attach(9);              //Assighning the servo to pin 9.
  Serial.begin(9600);             //Starting the serial
}

void loop() {
  // Read the pin.
  analog_reading = analogRead(sence_pin); 
  //Print the value of the pin.
  Serial.print("sencePIN ");
  Serial.print(analog_reading);
  //Change the value to an angle from 0- 180 deg.
  angle = map(analog_reading, 0, 1024, 0, 180);
  //Print the angle we are useing now.
  Serial.print(", angle: ");
  Serial.println(angle);
  //Send the angle to the servo.
  myServo.write(angle);
  delay(15);
}
