const int led = 11; //Led connected to pin 11
int state = 0; //New var called "state" and set to 0

void setup() {
  pinMode (led, OUTPUT); //Led as output
  Serial.begin (600); //Start serial monitor at 600bps
  Serial.println ("Type 1 to turn pin 11 on or type 2 to turn pin 11 off"); //Print that to serial monitor
}

void loop() {
int state = Serial.parseInt(); //Make state equal to whatever integer is passed through serial port
  if (state == 1) { //If state is "1"
  digitalWrite (led, HIGH); //Turn LED on
  Serial.println  ("LED = ON"); //And print LED = ON
  }
  if (state == 2) { //If state is "2"
  digitalWrite (led, LOW); //Turn LED off
  Serial.println ("LED = OFF"); //And print LED = OFF to serial montitor
  }
}