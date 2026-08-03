const int trig_pin = 12; //Trigger conencted to pin 9
const int echo_pin = 13; //Echo connected to pin 8
const int alarm = 3; //Alarm pin (passive buzzer or speaker)
const int light = 11; //LED light that flashes on alarm going off
float timing = 0.0; //Float to store "timing" variable
float distance = 0.0; //Float to store "distance" variable
int doorwayWidth = 118; //Width of doorway in CM

void setup() {
   pinMode(echo_pin, INPUT); //Echo as input
   pinMode(trig_pin, OUTPUT); //Trigger as output
   pinMode(alarm, OUTPUT);
   digitalWrite(alarm, LOW);
   pinMode(light, OUTPUT);
   digitalWrite(light, LOW);
}

void loop() {
  triggerSound();
  timing = pulseIn(echo_pin, HIGH); //Timing variable is equal to how long the "echo" pulse is
  distance = (((timing / 29) / 2) - 1); //Calculate distance from that time
  
  if (distance < doorwayWidth) {
   for(int i = 0; i <= 15; i++) {
    tone(alarm, 1000);
    digitalWrite(light, HIGH);
    delay(500);
    tone(alarm, 700);
    digitalWrite(light, LOW);
    delay(500);
   }
  } else {
    noTone(alarm);
  }
}

void triggerSound() {
  digitalWrite (trig_pin, LOW); //The ultrasonic distance sensor requires the trigger pin to go high
  delay (2);
  digitalWrite (trig_pin, HIGH); //for 2 ms and then low for 10 ms which triggers the device reliably.
  delay (10);
  digitalWrite (trig_pin, LOW);
}