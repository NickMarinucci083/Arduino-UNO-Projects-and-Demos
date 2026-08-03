/* Relay module signal pin connected to pin 8, trigger and echo pins of HC-SR04 ulrasonic
sound module connected to pins 5 and 6 (echo on pin 5 and trigger on pin 6)*/
const int trig_pin = 6; //Trigger conencted to pin 9
const int echo_pin = 5; //Echo connected to pin 8
const int relay_pin = 8; //Relay signal connected to pin 8 (Active low relay module - bit of a pain in the bum)
float timing = 0.0; //Float to store "timing" variable
float distance = 0.0; //Float to store "distance" variable

void setup()
{
  pinMode(echo_pin, INPUT); //Echo as input
  pinMode(trig_pin, OUTPUT); //Trigger as output
  pinMode (relay_pin, OUTPUT); //Relay as output
}

void loop()
{
  triggerSound();
  timing = pulseIn(echo_pin, HIGH); //Timing variable is equal to how long the "echo" pulse is high
  distance = (((timing / 29) / 2) - 1); //Calculate distance from that time

  if (distance <= 300) { //Something is detected 3 meters away
    digitalWrite (relay_pin, LOW); //Turn relay on
    delay (60000); //Leave it on for 1 minute
  } 
  else {digitalWrite (relay_pin, HIGH);} //Otherwise, keep relay off
}

void triggerSound() {

//The trigger sequence
  digitalWrite (trig_pin, LOW); //The ultrasonic distance sensor requires the trigger pin to go high
  delay (2);
  digitalWrite (trig_pin, HIGH); //for 2 ms and then low for 10 ms which triggers the device reliably.
  delay (10);
  digitalWrite (trig_pin, LOW);
}