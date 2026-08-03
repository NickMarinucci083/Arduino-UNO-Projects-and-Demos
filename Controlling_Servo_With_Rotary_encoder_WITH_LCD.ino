#include <LiquidCrystal.h> //Use "Liquid crystal.h" library
#include <Servo.h> //Use servo motor library

int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7; //rs on to, en on 11, d0 on 0, etc
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //Create LCD object
Servo servo;
const int APin= 11; //Set the digital 2 to A pin
const int BPin= 12; //Set the digital 3 to B pin
const int SPin= 13 ;//Set the digital 4 to S pin
unsigned char encoderVal = 0;

void setup() {
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  lcd.begin(16, 2); //Turn display on, tells arduino there is 16 colums and 2 rows on this particular display
  lcd.setCursor (4, 1);
  lcd.print("Turn angle");
  delay (1000);
  lcd.clear();
  lcd.setCursor(4, 1);
  lcd.print("Push = reset");
  delay (1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Servo angle (C):");
  pinMode(APin, INPUT);//initialize the A pin as input
  pinMode(BPin, INPUT);//initialize the B pin as input
  pinMode(SPin, INPUT);//initialize the S pin as input
  servo.attach(9);
  servo.write(0);
  delay (100);
}

void loop() {
 int change = getRotaryEncoder();
 encoderVal = encoderVal - change;
 if(digitalRead(SPin) == LOW)
 {
 encoderVal = 0;
 }

 lcd.setCursor (0, 1); //Display and write the servo angle.
 lcd.print(encoderVal);
 servo.write(encoderVal);
 
 if (encoderVal <= 9) { //Keep preceeding "0s" on the display clear
  lcd.setCursor (1, 1);
  lcd.print(" ");
 }

 if (encoderVal <= 99) { //and for the 100's place value
  lcd.setCursor (2, 1);
  lcd.print(" ");
 }

 if (encoderVal > 180) { //If a value of over 180 is entered, 
  lcd.setCursor (4, 1);
  lcd.print("Angle limit!"); //Say angle limit reached
 } else {
  lcd.setCursor (4, 1); //Or keep that part of display clear
  lcd.print ("            ");
 }
}








int getRotaryEncoder(void)
{
 static int oldA = HIGH; //set the oldA as HIGH
 static int oldB = HIGH; //set the oldB as HIGH
 int result = 0;
 int newA = digitalRead(APin); //read the value of APin to newA
 int newB = digitalRead(BPin); //read the value of BPin to newB
 if (newA != oldA || newB != oldB)//if the value of APin or the BPin has changed
 {
 if (oldA == HIGH && newA == LOW)// something has changed
 {
 result = (oldB * 2 - 1);
 }
 }
 oldA = newA;
 oldB = newB;
 return result;
}