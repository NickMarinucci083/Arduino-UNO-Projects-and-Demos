int Ro = 10, B =  3977; //Nominal resistance 10K, Beta constant
int Rseries = 10;// Series resistor 10K
float To = 298.15; // Nominal Temperature
int Buzzer = 8;
int Led = 9;

 void setup() {
 pinMode (Led, OUTPUT);
 pinMode (Buzzer, OUTPUT);
 Serial.begin(9600);
}
//Tc
void loop() {

  /*Read analog outputof NTC module,
   i.e the voltage across the thermistor */
  float Vi = analogRead(A0) * (5.0 / 1023.0);
  //Convert voltage measured to resistance value
  //All Resistance are in kilo ohms.
  float R = (Vi * Rseries) / (5 - Vi);
  /*Use R value in steinhart and hart equation
    Calculate temperature value in kelvin*/
  float T =  1 / ((1 / To) + ((log(R / Ro)) / B));
  float Tc = T - 273.15; // Converting kelvin to celsius
  Serial.print(Tc);Serial.println(" °C"); //Prints to serial monitor the temprature and "C" Symbol
  delay (500); //Wait a bit in between

  if (Tc >= 21) { //If temp reaches above 21 degrees
    BuzzerRing(); //Ring buzzer
    digitalWrite (Led, HIGH); //Turn LED on
  } else {
    digitalWrite (Buzzer, LOW); //Else, turn it off
    digitalWrite (Led, LOW); //Turn LED off
  }
}

void BuzzerRing() {
digitalWrite (Buzzer, HIGH); //Turn buzzer on
delay (200); //Wait 200 ms
digitalWrite (Buzzer, LOW); //Turn buzzer off
delay (100); //Wait 100 ms
}