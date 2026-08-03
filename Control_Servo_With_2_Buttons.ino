#include <ezButton.h> //The button library
#include <Servo.h> //The servo library

const int BUTTON_PINA = 2; // Increment button
const int BUTTON_PINB = 3; // Decrement button
int servoAngle = 90;

ezButton buttonA(BUTTON_PINA);  // create ezButton object that attaches to BUTTON_PIN
ezButton buttonB(BUTTON_PINB); //Create another one
Servo myservo; //Create a servo object for the servo on pin 6

void setup() {
  buttonA.setDebounceTime(20); // set debounce time to 20 milliseconds
  buttonB.setDebounceTime(20);
  myservo.attach(6); //Servo attached to pin 6
  myservo.write (90); //Make it initally go to 90 degrees
}

void loop() {
  buttonA.loop(); // MUST call the loop() function first
  buttonB.loop();

  if(buttonA.isReleased()) { //If the increment button is pressed:
   servoAngle = (servoAngle+5); //Set servo angle to servo angle plus 5
   myservo.write(servoAngle); //Write it to the servo
  }

  if(buttonB.isReleased()) { //If the decrement button is pressed:
   servoAngle = (servoAngle-5); //Set servo angle to servo angle minus 5
   myservo.write(servoAngle); //Write it to the servo
  }  
}