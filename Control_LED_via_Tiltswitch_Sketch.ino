int led = 8; //LED connected to pin 8
int tilt = 13; //Tilt switch connected to pin 13
int tiltvalue = 0; //Value of the tiltswitch (High or low)

void setup() {
  // put your setup code here, to run once:
pinMode (led, OUTPUT); //LED as output
pinMode (tilt, INPUT_PULLUP); //Tiltswitch as input with a pullup resistor
}

void loop() {
  // put your main code here, to run repeatedly:
tiltvalue = digitalRead (tilt); //Make the "tiltvalue" variable equal to the value of the tiltswitch pin
digitalWrite (led, tiltvalue); //Make the led the same as the value of the "tiltvalue" variable
delay (50); //Wait 50ms (To "debounce" the tiltswitch)
}
