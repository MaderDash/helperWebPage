// Made by Maderdash.
// DATE: 7-6-2021.


//buton pins
uint8_t northSouthButton  = A0;
uint8_t eastWestButton    = A1;
//East West led's/stop lights.
uint8_t greenEast         = A3;
uint8_t yellowEast        = A4;
uint8_t redEast           = A5;
//North South led's/stop lights.
uint8_t greenNorth        = 2;
uint8_t yellowNorth       = 3;
uint8_t redNorth          = 4;
uint8_t i                 = 0;

//Testing array for all IO's.
int testArray[6] = {greenEast, yellowEast, redEast, greenNorth, yellowNorth, redNorth};

//Millis is used rather then delays.
long switchTimer          = 1000;
long startTime            = 0;

//The setup is ran one time setting up pins for In Out.
void setup()
{
  for (int i = 0; i <= 5; i++)
  {
    pinMode(testArray[i], OUTPUT);
  }
  Serial.begin(9600);
  pinMode(northSouthButton, INPUT);
  pinMode(eastWestButton, INPUT);
}

//Loop loops for ever runing code in it.
void loop()
{
  buttonChecker();
  ticker();
  
  //Serial.println(startTime); //This line is to get a serial print out of Millis. 
}

//All of the functions are below this line.//////////
//This function checks the buttons.
void buttonChecker() {
  if (!digitalRead(northSouthButton)) {
    if (i > 6) {
      startTime -= 400;
    }
  }
  if (!digitalRead(eastWestButton)) {
    if (i <= 6) {
      startTime -= 400;
    }
  }
}
//This function counts up every the "switchTimer" varable is reached.
//To make this go faster, you can shorten the Varable.
void ticker() {
  if (millis() >= (startTime + switchTimer)) {
    i++;
    startTime = millis();
  }
  redNorthSouth(i);
  if (i == 15) {
    clearAll();
    i = 0;
  }
}

// In the function below, we call the led function we need to light up in order.
void redNorthSouth(int led) {
  switch (led) {
    case 0:
      greenN();
      redE();
      break;
    case 3:
      yellowN();
      redE();
      break;
    case 5:
      redN();
      redE();
      break;
    case 6:
      greenE();
      redN();
      break;
    case 9:
      yellowE();
      redN();
      break;
    case 11:
      redE();
      redN();
      break;
    default:  break;
  }
}

//Green North and South lights:
void greenN() {
  digitalWrite(redNorth, 0);
  digitalWrite(greenNorth, 1);
  digitalWrite(yellowNorth, 0);
}

//Yellow North-South led's.
void yellowN() {
  digitalWrite(redNorth, 0);
  digitalWrite(greenNorth, 0);
  digitalWrite(yellowNorth, 1);
}

//Red North-South led's.
void redN() {
  digitalWrite(redNorth, 1);
  digitalWrite(greenNorth, 0);
  digitalWrite(yellowNorth, 0);
}

// Green East, and West lights:
void greenE() {
  digitalWrite(redEast, 0);
  digitalWrite(greenEast, 1);
  digitalWrite(yellowEast, 0);
}

//Yellow East-West led.
void yellowE() {
  digitalWrite(redEast, 0);
  digitalWrite(greenEast, 0);
  digitalWrite(yellowEast, 1);
}

//Red East-West led.
void redE() {
  digitalWrite(redEast, 1);
  digitalWrite(greenEast, 0);
  digitalWrite(yellowEast, 0);
}

//Clear all led's.
void clearAll() {
  digitalWrite(redNorth, LOW);
  digitalWrite(yellowNorth, LOW);
  digitalWrite(greenNorth, LOW);
}