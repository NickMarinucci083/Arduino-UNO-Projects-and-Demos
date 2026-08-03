#include <Servo.h> //Use servo library

int pos = 0; //Positiion of servo

Servo servoA; //Creates a servo in servo library

void setup() {
  servoA.attach(3); //PWM connected to pin 3
  servoA.write(0); //Set it to 0 degrees initally
  delay (1000); //Wait a second for motor to turn there
}

void loop() {
  for (int pos = 0; pos <= 180; pos ++) {  // rotate slowly from 0 degrees to 180 degrees, by one degree
    servoA.write(pos); // control servo to go to position in variable 'pos'
    delay(20); // waits 20ms for the servo to reach the position
  }
  delay (500);

  for (int pos = 180; pos >= 0; pos --) { // rotate from 180 degrees to 0 degrees, one by one degree
    servoA.write(pos); // control servo to go to position in variable 'pos'
    delay(20); // waits 20ms for the servo to reach the position
  }
  delay (500);
}