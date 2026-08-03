#include <Servo.h> 

const int trig_pin = 9; //Trigger conencted to pin 9
const int echo_pin = 8; //Echo connected to pin 8
float timing = 0.0; //Float to store "timing" variable
float distance = 0.0; //Float to store "distance" variable
int pos = 0; //Position of servo
Servo myservo; //Create a servo object

void setup()
{
   pinMode(echo_pin, INPUT); //Echo as input
   pinMode(trig_pin, OUTPUT); //Trigger as output
   myservo.attach(3); //Sevo on pin 3
   myservo.write(0); //Set it to "0" degrees
   Serial.begin(9600); //Start the serial monitor
}

void loop()
{
  triggerSound();
  /*pulse in measures the state of how long a pin is in a certain state.
  //Arguments are pulseIn (pin number/name, the state to measure it in);
  //This is measuring how long the echo_pin is high
  //and writes it to the "timing" variable*/
  
  timing = pulseIn(echo_pin, HIGH); //Timing variable is equal to how long the "echo" pulse is
  distance = (((timing / 29) / 2) - 1); //Calculate distance from that time
  pos = map(distance, 0, 100, 0, 180); //Scale the value from 1 meter from sensor to 0-180 degrees angle for servo
  myservo.write (pos); //Write it to the servo motor
  Serial.println(pos); //and the serial monitor for viewing
  delay (10); //Wait a bit in between to avoid overloading motor
}

void triggerSound() {

//The trigger sequence
  digitalWrite (trig_pin, LOW); //The ultrasonic distance sensor requires the trigger pin to go high
  delay (2);
  digitalWrite (trig_pin, HIGH); //for 2 ms and then low for 10 ms which triggers the device reliably.
  delay (10);
  digitalWrite (trig_pin, LOW);
}