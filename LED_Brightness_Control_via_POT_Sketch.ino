int ledPin = 9; //LED is connected to pin 9
int value = 0; // Value of the arduino ADC 0
int pinAnalog0 = A0; // Naming pin A0 to pinAnalog0
void setup() {
  // put your setup code here, to run once:
pinMode (ledPin, OUTPUT); //Configures ledPin to output
Serial.begin(9600); //Starts serial monitor to 9600 BPS
}

void loop() {
  // put your main code here, to run repeatedly:
value = analogRead (pinAnalog0); //Set the variable "value" to the value of arduino ADC 0
analogWrite (ledPin, value/4); //Set the pin the LED is connected to to the value of ADC 0 divided by 4
Serial.println(value/4); //Prints to the serial monitor the value of ADC 0 divided by 4
} //Value is divided by 4 as analogWrite only accepts a value between 0 and 255 but the arduino ADC's
  //give a value between 0 and 1024.