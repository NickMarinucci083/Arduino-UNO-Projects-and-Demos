int ledPin = 13; //Sets pin 13 to the pin the LED is connected to

void setup() {
  // put your setup code here, to run once:
pinMode (ledPin, OUTPUT); // configures ledPin to output
Serial.begin(600); //Starts the serial monitor at 600 BPS rate
Serial.println("Setup complete, Starting loop"); //Prints what's in the parentheses to serial monitor
Serial.print("Loading..."); //Prints what's in the parenthesis to the serial monitor
delay(2000); //Waits 2 seconds
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(ledPin, true); // Turns ledPin ON
Serial.println("LED = ON"); //Prints to serial monitor LED = ON
delay(1000); //Waits 1 second
digitalWrite(ledPin, false); //Turns ledPin OFF
Serial.println("LED = OFF"); //Prints ot serial monitor LED = ON
delay(1000); //Waits 1 second
}