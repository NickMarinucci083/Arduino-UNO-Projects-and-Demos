#include <LiquidCrystal.h> //Set up LCD

int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);
int posCount = 0;

byte StickManA[] = {
 B01100,
 B01100,
 B00000,
 B01110,
 B11100,
 B01100,
 B11010,
 B10011,
};

byte StickManB[] = {
 B01100,
 B01100,
 B00000,
 B01100,
 B01100,
 B01100,
 B01100,
 B01110,
};

byte StickManJump[] = {
  B01100,
  B01100,
  B00000,
  B11110,
  B01101,
  B11111,
  B10000,
  B00000,
};

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2); //Create custom characters
  lcd.createChar(0, StickManA);
  lcd.createChar(1, StickManB);
  lcd.createChar(2, StickManJump);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (posCount = 0; posCount <= 15; posCount++) { //Make stickman walk foward
  lcd.setCursor(0, 1);
  lcd.write(byte(0));
  delay (400);
  lcd.setCursor(0, 1);
  lcd.write (byte(1));
  delay (400);
  lcd.scrollDisplayRight(); //Until he reaches the end of the screen
  }

  lcd.clear(); //Then put him in the far left of the top row, in his jump position
  lcd.setCursor(15, 0);
  lcd.write(byte(2));

  for (posCount = 0; posCount <= 14; posCount++) { //And make him jump back to the start of the screen
  lcd.scrollDisplayLeft();
  delay (80);
  }

  lcd.clear(); //Get rid of the second version of himself on the top part of the screen

}