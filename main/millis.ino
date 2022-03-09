/*
  Blink without Delay

  Turns on and off a light emitting diodes (LED) connected to a digital pin,
  without using the delay() function. This means that other code can run at the
  same time without being interrupted by the LED code.
  We can blink 2 leds at different intervals soing this.

  The circuit:
  - Leds conected to pins 3 and 4.[ be sure to use resistors.


  created 07-08-21
  by Maderdash

*/

// constants won't change. Used here to set a pin number:
const int redLed             =  3;              // the number of the redLED pin
const int greenLed           =  4;              // the number of the greenLED pin
// Variables will change:
int redLedState              = LOW;             // ledState used to set the redLED
int greenLedState            = LOW;             // ledState used to set the greenLED
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long redPreviousMillis = 0;            // will store last time redLED was updated
unsigned long greenPreviousMillis = 0;          // will store last time greenLED was updated
// constants won't change:
const long redInterval       = 1000;            // interval at which to blink redLed (milliseconds)
const long greenInterval     = 200;             // interval at which to blink greenLed (milliseconds)
void setup() {
  // set the digital pin as output:
  pinMode(redLed, OUTPUT);                      //Setting the pin to send a signal OUT
  pinMode(greenLed, OUTPUT);                    //Setting the pin to send a signal OUT
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();
  // The red led code is below this line.
  if (currentMillis - redPreviousMillis >= redInterval) {
    // save the last time you blinked the LED
    redPreviousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (redLedState == LOW) {
      redLedState = HIGH;
    } else {
      redLedState = LOW;
    }
    // set the LED with the ledState of the variable:
    digitalWrite(redLed, redLedState);
  }
  //The green code is below this line.
  if (currentMillis - greenPreviousMillis >= greenInterval) {
    // save the last time you blinked the greenLED
    greenPreviousMillis = currentMillis;
    if (greenLedState == LOW) {
      greenLedState = HIGH;
    } else {
      greenLedState = LOW;
    }
    digitalWrite(greenLed, greenLedState);
  }
}