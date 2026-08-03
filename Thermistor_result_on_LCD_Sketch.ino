#include <LiquidCrystal.h> //Use "LiquidCrystal.h" library

int rs = 10, en = 11, d0 = 0, d1 = 1, d2 = 2, d3 = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7; //rs on 10, en on 11, d0 on 0, etc
LiquidCrystal lcd(rs, en, d0, d1, d2, d3, d4, d5, d6, d7); //Order of pins on LCD clarified to order of pins on previous line

int Ro = 10, B =  3977; //Nominal resistance 10K, Beta constant
int Rseries = 10;// Series resistor 10K
float To = 298.15; // Nominal Temperature

void setup() {
  lcd.begin(16, 2); //Turns on display and tells arduino there are 16 columns and 2 rows on the LCD
  lcd.setCursor (1, 0); //Sets cursor to column 1, row 0
  lcd.print ("www.adeept.com"); //Print to LCD "www.adeept.com"
  lcd.setCursor (3, 1); //Sets cursor to column 2, row 1
  lcd.print ("Temp:"); //Print to LCD "Temp:"
  lcd.setCursor (11, 1); //Sets cursor to column 13, row 1
  lcd.print ("C"); //Print to LCD "C"
}

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

  lcd.setCursor (8, 1); //Set cursor to column 7, row 1
  lcd.print (Tc, 1); //Print to LCD the value of the "Temp" variable
  delay (700); //Wait 700ms (To stop LCD from going crazy trying to
  //display numbers at the fast clock speed of the arduino chip)
}