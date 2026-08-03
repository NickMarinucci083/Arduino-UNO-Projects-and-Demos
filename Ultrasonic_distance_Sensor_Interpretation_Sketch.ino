#include <LiquidCrystal.h> //Use "Liquid crystal.h" library

int rs = 10, en = 11, d0 = 0, d1 = 1, d2 = 2, d3 = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7; //rs on to, en on 11, d0 on 0, etc
LiquidCrystal lcd(rs, en, d0, d1, d2, d3, d4, d5, d6, d7); //Order of LCD pins clarified with order of pins on previous line

const int trig_pin = 9; //Trigger conencted to pin 9
const int echo_pin = 8; //Echo connected to pin 8
float timing = 0.0; //Float to store "timing" variable
float distance = 0.0; //Float to store "distance" variable

void setup()
{
   pinMode(echo_pin, INPUT); //Echo as input
   pinMode(trig_pin, OUTPUT); //Trigger as output
   lcd.begin(16, 2); //Start the 16x2 LCD
   lcd.setCursor (0, 0);
   lcd.print ("Distance:"); //Print "Distance:"
   lcd.setCursor (14, 0);
   lcd.print ("cm"); //Print CM symbol next to that
   lcd.setCursor (0, 1);
   lcd.print ("Distance:"); //Print "Distance" again
   lcd.setCursor (15, 1);
   lcd.print ("M"); //and the "M" symbol
}

void loop()
{
  triggerSound();
  /*pulse in measures the state of how long a pin is in a certain state.
  //Arguments are pulseIn (pin number/name, the state to measure it in);
  //This is measuring how long the echo_pin is high
  //and writes it to the "timing" variable*/
  
  timing = pulseIn(echo_pin, HIGH); //Timing variable is equal to how long the "echo" pulse is
  distance = (((timing / 29) / 2) - 1); //Calculate distance from that time
  
  lcd.setCursor (10, 0);
  lcd.print (distance, 1); //Then next to it, print the distance in CM calculated
  lcd.setCursor (10, 1);
  lcd.print (distance/100); //Print the distance divided by 100 to get a reading in meters
  delay(400); //Wait 100 ms in between so twisted nematic display can display nubmers nicely
}

void triggerSound() {

//The trigger sequence
  digitalWrite (trig_pin, LOW); //The ultrasonic distance sensor requires the trigger pin to go high
  delay (2);
  digitalWrite (trig_pin, HIGH); //for 2 ms and then low for 10 ms which triggers the device reliably.
  delay (10);
  digitalWrite (trig_pin, LOW);
}