#include <LiquidCrystal.h> //Use "Liquid crystal.h" library

int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7; //rs on to, en on 11, d0 on 0, etc
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //Create LCD object

void setup() {
  lcd.begin(16, 2); //Turn display on, tells arduino there is 16 colums and 2 rows on this particular display
  lcd.setCursor(1, 0); //Set the cursor to column 1, row 0
  lcd.print("Hello, world!!"); //Print to LCD "Hello, world"
}

void loop() {
  lcd.setCursor(7, 1); //Set cursor to column 7, row 1
  lcd.print(millis() / 1000); //Print to LCD the arduino system clock, divided by 1000
}