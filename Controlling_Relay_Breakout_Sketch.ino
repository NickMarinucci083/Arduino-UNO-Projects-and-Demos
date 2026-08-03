int relaySignal = 8; //Relaysignal pin connected to digital pin 8

void setup() {
  // put your setup code here, to run once:
pinMode (relaySignal, OUTPUT); //Relaysignal as a output
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite (relaySignal, HIGH); //Turn the relay on
delay (1000); //Wait a second
digitalWrite (relaySignal, LOW); //Turn the relay off
delay (1000); //Wait a second
}
