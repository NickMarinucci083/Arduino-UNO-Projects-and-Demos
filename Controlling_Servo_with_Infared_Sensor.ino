#include <LiquidCrystal.h> //Use "Liquid crystal.h" library
#include <Servo.h> //Use servo motor library

int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7; //rs on to, en on 11, d0 on 0, etc
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //Create LCD object
Servo servo;
const int sensor = A0;
unsigned char value = 0;
unsigned char servoAngle = 0;

void setup() {
  lcd.begin(16, 2); //Turn display on, tells arduino there is 16 colums and 2 rows on this particular display
  lcd.print("Servo angle (C):");
  servo.attach(9);
  servo.write(0);
  delay (100);
}

void loop() {
  value = analogRead(sensor); 
  servoAngle = map(value, 0, 255, 0, 180);

 lcd.setCursor (0, 1); //Display and write the servo angle.
 lcd.print(servoAngle);
 servo.write(servoAngle);
 delay (100);
 
 if (value <= 9) { //Keep preceeding "0s" on the display clear
  lcd.setCursor (1, 1);
  lcd.print(" ");
 }

 if (value <= 99) { //and for the 100's place value
  lcd.setCursor (2, 1);
  lcd.print(" ");
 }

}