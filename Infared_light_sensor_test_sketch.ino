const int sensorPin = A0;
int Infared_sensorVal = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Use serial monitor
}

void loop() {
  // put your main code here, to run repeatedly:
 Infared_sensorVal = analogRead (sensorPin);

 if (Infared_sensorVal < 500) { //Change the number here to adjust the sensitivity of your sensor
  Serial.println ("Obstacle detected");
 } else {
  Serial.println ("Sensor clear");
 }
}
