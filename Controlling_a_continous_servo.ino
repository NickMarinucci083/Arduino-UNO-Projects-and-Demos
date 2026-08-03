#include <Servo.h> //Use servo library

int pos = 0; //Positiion of servo
int label = 0;

const int callibrate = -5; //Callibrate your servo here, change value until it doesn't move on stop command

Servo servo; //Creates a servo in servo library

void setup() {
  Serial.begin (9600); //Start serial monitor 
  Serial.println("Type [r] to turn right, type [l] to turn left");
  Serial.println("Type [R] to turn right fast, type [L] to turn left fast");
  Serial.println("Type [s] or [S] to stop");
  servo.attach(11); //PWM connected to pin 11, makes it easy to shove servo plug directly into ICSP header instead of using wires.
  servo.write(90 + callibrate); //Set it to middle initally
  delay (1000); //Wait a second for motor to turn there
}

void loop() {
  if (Serial.available() > 0) {
    label = Serial.read();

    if (label == 115  || label == 83) {servo.write(90 + callibrate); Serial.println("stop");}
    
    else if (label == 108) {servo.write(90 + callibrate + 10); Serial.println("left");}

    else if (label == 114) {servo.write(90 + callibrate - 10); Serial.println("right");}

    else if (label == 76) {servo.write(180); Serial.println("left fast");}

    else if (label == 82) {servo.write(0); Serial.println("right fast");}

    else if (label != 115 && label != 108 && label != 114 && label != 83 && label != 76 && label != 82 && label != '\n' && label != '\r') {
      Serial.println("Unknown command, check your spelling"); 
      Serial.println("Commands: R, r, S/s, l, L");
    }
  }
}