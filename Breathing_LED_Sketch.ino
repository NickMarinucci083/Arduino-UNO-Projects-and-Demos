int ledPin = 13; //Sets pin 13 to the pin the LED is connected to (Inbuilt pin 13 LED)
int PWMval = 0; //A new variable named PWMval and set to "0"

void setup() {
  // put your setup code here, to run once:
  pinMode (ledPin, OUTPUT); //Sets ledPin to output
}

void loop() {
  // put your main code here, to run repeatedly:
 for (PWMval = 0; PWMval <=255; PWMval++) { //From PWM being 0 to 255, incrementing
  analogWrite (ledPin, PWMval); //Write the value to the ledPin
  delay (3); //Wait 3 ms
 }

 for (PWMval = 255; PWMval >=0; PWMval--) { //From PWM being 255 to 0, decrementing
  analogWrite (ledPin, PWMval); //Write the value to the ledPin
  delay (3); //Wait 3 ms
 }
}
