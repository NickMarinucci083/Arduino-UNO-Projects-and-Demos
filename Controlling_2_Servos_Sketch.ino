#include <Servo.h> //Use servo library
int posA = 0; //Position of servos
int posB = 0;

Servo servoA; //Creates a servo motor in library
Servo servoB;

void setup() {
  servoA.attach(5); //Servos connected to pins 5 and 6
  servoB.attach(6);
  servoA.write(0); //Make shure they are at angle 0
  servoB.write(0);
  delay (1000); //Wait for motors to turn to 0 degrees
}

void loop() {
  for (int posA = 0; posA <= 180; posA ++) {  // rotate slowly from 0 degrees to 180 degrees, by one degree
    servoA.write(posA);  // control servo to go to position in variable 'posA'
    delay(10);         // waits 10ms for the servo to reach the position
  }

  for (int posB = 0; posB <= 180; posB ++) {  // rotate slowly from 0 degrees to 180 degrees, by one degree
    // in steps of 1 degree
    servoB.write(posB);  // control servo to go to position in variable 'posB'
    delay(10);         // waits 10ms for the servo to reach the position
  }

  for (int posA = 180; posA >= 0; posA --) {  // rotate from 180 degrees to 0 degrees, by one degree
    servoA.write(posA);                        // control servo to go to position in variable 'posA'
    delay(10);                               // waits 10ms for the servo to reach the position
  }

  for (int posB = 180; posB >= 0; posB --) {  // rotate from 180 degrees to 0 degrees, by one degree
    servoB.write(posB);                        // control servo to go to position in variable 'posB'
    delay(10);                               // waits 10ms for the servo to reach the position
  }
}