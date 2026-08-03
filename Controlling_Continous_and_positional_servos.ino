#include <Servo.h> //Use servo library

int pos = 0; //Positiion of servo
int command = 0;

const int callibrate = -5; //Callibrate your servo here, change value until it doesn't move on stop command

Servo servoC; //Creates a servo in servo library for continous and positional servos
Servo servoP;

void setup() {
  Serial.begin (9600); //Start serial monitor 
  Serial.println("CONTINUOUS SEVRO COMMANDS:");
  Serial.println("Type [r] to turn right, type [l] to turn left");
  Serial.println("Type [R] to turn right fast, type [L] to turn left fast"); //45-130
  Serial.println("Type [s] or [S] to stop");
  Serial.println("POSITIONAL SERVO COMMANDS:");
  Serial.println("Type any number between 0-9 and servo will point to corresponding number on scale");
  servoC.attach(5);
  servoP.attach(6);
  servoC.write(90 + callibrate); //Set it to middle initally
  servoP.write(145); // Set positional servo outside scale initally
  delay (1000); //Wait a second for motor to turn there
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();

    if (command == 's'  || command == 'S') {servoC.write(90 + callibrate); Serial.println("Stop");}
    
    else if (command == 'l') {servoC.write(90 + callibrate + 10); Serial.println("Left slow");}

    else if (command == 'r') {servoC.write(90 + callibrate - 10); Serial.println("Right slow");}

    else if (command == 'L') {servoC.write(180); Serial.println("Left fast");}

    else if (command == 'R') {servoC.write(0); Serial.println("Right fast");}

    if (command == '1')      { servoP.write(140); Serial.println("Label 1"); }
    else if (command == '2') { servoP.write(130); Serial.println("Label 2"); } 
    else if (command == '3') { servoP.write(119); Serial.println("Label 3"); }
    else if (command == '4') { servoP.write(109); Serial.println("Label 4"); }
    else if (command == '5') { servoP.write(98);  Serial.println("Label 5"); }
    else if (command == '6') { servoP.write(88);  Serial.println("Label 6"); }
    else if (command == '7') { servoP.write(77);  Serial.println("Label 7"); }
    else if (command == '8') { servoP.write(66);  Serial.println("Label 8"); }
    else if (command == '9') { servoP.write(56);  Serial.println("Label 9"); }

  }
}