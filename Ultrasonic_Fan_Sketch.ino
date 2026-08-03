const int trig_pin = 9; //Trigger conencted to pin 9
const int echo_pin = 8; //Echo connected to pin 8
const int PWM_fan = 11; //Pin the fan is connected to
float timing = 0.0; //Float to store "timing" variable
float distance = 0.0; //Float to store "distance" variable
int fanspeed = 0;

void setup()
{
   pinMode(echo_pin, INPUT); //Echo as input
   pinMode(trig_pin, OUTPUT); //Trigger as output
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
  
  constrain (fanspeed, 0, 255);
  fanspeed = map (distance, 0, 100, 0, 255);
  analogWrite (PWM_fan, fanspeed);
  delay (10);
}

  void triggerSound() {

  //The trigger sequence
  digitalWrite (trig_pin, LOW); //The ultrasonic distance sensor requires the trigger pin to go high
  delay (2);
  digitalWrite (trig_pin, HIGH); //for 2 ms and then low for 10 ms which triggers the device reliably.
  delay (10);
  digitalWrite (trig_pin, LOW);
}