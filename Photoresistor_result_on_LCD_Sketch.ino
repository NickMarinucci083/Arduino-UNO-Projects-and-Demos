#include <LiquidCrystal.h> //Include "Liquid crystal.h" library

int rs = 10, en = 11, d0 = 0, d1 = 1, d2 = 2, d3 = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7; //rs on 10, en on 11, d0 on 0, etc
LiquidCrystal lcd(rs, en, d0, d1, d2, d3, d4, d5, d6, d7); //Order of pins on LCD clarified to order on previous line

int analogPin = A0; //"analogPin" is now the name of the ADC pin A0
int light = 0; //New variable called "Light" and set to 0

void setup() {
  lcd.begin(16, 2); //Turns on display and tell arduino there are 16 columns and 2 rows
  lcd.setCursor (1, 0); //Set cursor to column 1, row 0
  lcd.print ("www.adeept.com"); //Print to LCD "www.adeept.com"
  lcd.setCursor (3, 1); //Set cursor to column 3, row 1
  lcd.print ("Light:"); //Print to LCD "Light:"
}

void loop() {

  light = analogRead (analogPin); //Set the "Light" variable to the value of the "analogPIn"
  lcd.setCursor (10, 1); //Set cursor to column 10, row 1
  lcd.print (light); //Print to LCD the "light" varable value
  delay (700); //Wait 700 ms
}