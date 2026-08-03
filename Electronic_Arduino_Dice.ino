/* Quick schematic of the way the Led's are wired: symbols matching are leds wired in parralel is a led

()              []


{}      O       {}


[]              ()


() leds connected to pin 2
[] leds connected to pin 3
{} leds connected to pin 4
O (center led) connected to pin 5
A tilt switch connected to pin 13 and ground

*/

#include <ezButton.h> //Use the button debouncing library for the tilt switch

const int leftdiagonalLeds = 2; //The pins the Led's are connected to
const int rightdiagonalLeds = 3;
const int middleLeds = 4;
const int middleLed = 5;
int allLeds; //All the leds
int number = 0; //The number the dice will show
int slowdownTime = 0; //Slow down time

ezButton shakeSensor(13); //Tilt switch connected to pin 13

void setup() {
  // put your setup code here, to run once:

  for (allLeds=2; allLeds<=5; allLeds++) { //Set all leds as output and make them initally low
  pinMode (allLeds, OUTPUT);
  digitalWrite (allLeds, LOW);
 }
 shakeSensor.setDebounceTime(10); //Debounce the tilt switch
}

void loop() {
  // put your main code here, to run repeatedly:
  shakeSensor.loop();
  
  if (shakeSensor.isReleased() /*(triggered)*/) { //If the tilt switch is shaken, 
    clearLeds(); //Turn all the leds off (refer to functions at end of program)
    randomSeed(micros()); //Seed the random number generator
    number = random (1, 7); //Pick a random number between 1-6 (Never goes to 7)

    for (slowdownTime = 0; slowdownTime <= 40; slowdownTime++) { //slowly increment the slowdownTime from 60ms
      clearLeds(); //Display randomly chosen dice numbers, then slow down
      display6();
      delay (slowdownTime * 2);
      clearLeds();
      display1();
      delay (slowdownTime * 2);
      clearLeds();
      display5();
      delay (slowdownTime * 2);
    } //At end of for loop, retreive the number chosen before by the
  }   //random number generator and display the corrensponding dice spots.

  if (number == 1) { //When the number is generated, if it is a certain number, light the following leds
    clearLeds();
    display1();
  }
  if (number == 2) {
    clearLeds();
    display2();
  }
  if (number == 3) {
    clearLeds();
    display3();
  }
  if (number == 4) {
    clearLeds();
    display4();
  }
  if (number == 5) {
    clearLeds();
    display5();
  }
  if (number == 6) {
    clearLeds();
    display6();
  }
}

void display1() { //The leds that need to be lit to display certain numbers on a dice pattern
  digitalWrite (middleLed, HIGH);
}

void display2() {
  digitalWrite (leftdiagonalLeds, HIGH);
}

void display3() {
  digitalWrite (middleLed, HIGH);
  digitalWrite (leftdiagonalLeds, HIGH);
}

void display4() {
  digitalWrite (leftdiagonalLeds, HIGH);
  digitalWrite (rightdiagonalLeds, HIGH);
}

void display5() {
  digitalWrite (leftdiagonalLeds, HIGH);
  digitalWrite (rightdiagonalLeds, HIGH);
  digitalWrite (middleLed, HIGH);
}

void display6() {
  digitalWrite (leftdiagonalLeds, HIGH);
  digitalWrite (rightdiagonalLeds, HIGH);
  digitalWrite (middleLeds, HIGH);
}

void clearLeds() { //Turns all leds off
  for (allLeds=2; allLeds<=5; allLeds++) {
    digitalWrite (allLeds, LOW);
 }
}