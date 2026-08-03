const int trig_pin = 2; //Trigger conencted to pin 9
const int echo_pin = 3; //Echo connected to pin 8
const int buzzer = 6; //Buzzer on pin 6
const int blue = 9; //Blue of RGB LED connected to pin 9
const int red = 10; //Red of RGB LED connected to pin 9
const int green = 11; //Green of RGB LED connected to pin 9
float timing = 0.0; //Float to store "timing" variable
float distance = 0.0; //Float to store "distance" variable
int buzzertone = 0; //Holds the tone of the piezo
int redval = 0; //Holds the value of the red integer
int greenval = 0; //Holds the value of the green integer
int blueval = 0; //Holds the value of the blue integer

void setup()
{
   pinMode(echo_pin, INPUT); //Echo as input
   pinMode(trig_pin, OUTPUT); //Trigger as output
}

void loop()
{
  triggerSound(); //Triggers the "ping" from ultrasonic distance sensor
  
  timing = pulseIn(echo_pin, HIGH); //Timing variable is equal to how long the "echo" pulse is
  distance = (((timing / 29) / 2) - 1); //Calculate distance from that time
  
  buzzertone = map (distance, 0, 50, 0, 800); //Scale the buzzer tone from half a meter to a 0 - 800 Hrz tone
  tone (buzzer, buzzertone*2); //Write it to the buzzer

  redval = map (distance, 0, 50, 0, 255); //Colour values equal to a scaled down version of the 50cm ultrasonic input
  analogWrite (red, redval); //Red val as it is
  greenval = map (distance, 0, 50, 0, 255);
  analogWrite (green, (!greenval)); //Greenval opposite to the redval
  blueval = map (distance, 0, 50, 0, 255);
  analogWrite (blue, blueval*1.1); //Blueval as it is but times 1.1
  delay (100); //Wait a bit in between to avoid arduino board from "crashing:
}

void triggerSound() {

  //The trigger sequence
  digitalWrite (trig_pin, LOW); //The ultrasonic distance sensor requires the trigger pin to go high
  delay (2);
  digitalWrite (trig_pin, HIGH); //for 2 ms and then low for 10 ms which triggers the device reliably.
  delay (10);
  digitalWrite (trig_pin, LOW);
}