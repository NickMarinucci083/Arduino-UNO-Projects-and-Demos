int buzzerPin = 8; //Buzzer connected to pin 8

void setup() {
  // put your setup code here, to run once:
pinMode (buzzerPin, OUTPUT); //Buzzer pin as output
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite (buzzerPin, HIGH); //Turn the buzzer on
 delay (250); //Wait a quarter of a second
 digitalWrite (buzzerPin, LOW); //Turn the buzzer off
 delay (500); //Wait a quarter of a second
}
