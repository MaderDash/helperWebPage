/*
Photocell tester.
  Reads an analog input on pin A2, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).

  This example code is in the public domain.
 Date:           03-09-2022
 By              Maderdash.

*/

#define photoCell A2  
#define ledPin 13

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // Setting up the pins for reading and writing.
  pinMode(photoCell, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the input on analog pin A2:
  int sensorValue = analogRead(photoCell);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
  if (voltage >= 2.5) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

}