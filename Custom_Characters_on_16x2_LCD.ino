#include <LiquidCrystal.h>

int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

byte Picture1[] = { //Controlling the 5x7 dot matrix pixels on the LCD individually
  B01110,
  B10001, //Lock
  B10001,
  B11111,
  B11111,
  B11011,
  B11011,
  B11111
};

byte Picture2[] = {
  B00001,
  B00011, //Musical note
  B00101,
  B01001,
  B01011,
  B11011,
  B11000,
  B00000
};

byte Picture3[] = {
  B00000,
  B10001, //Happy face
  B00100,
  B00000,
  B11111,
  B10001,
  B11011,
  B01110
};

byte Picture4[] = {
  B00100,
  B01110, //Bell
  B01010,
  B01010,
  B11011,
  B11111,
  B00000,
  B00100
};

byte Picture5[] = {
  B00001,
  B00011, //Speaker symbol
  B00111,
  B11111,
  B11111,
  B00111,
  B00011,
  B00001
};

byte Picture6[] = {
  B11111,
  B10101, //Minecraft creeper
  B11111,
  B11111,
  B11111,
  B01110,
  B01010,
  B11011
};

byte Picture7[] = {
  B00000,
  B01010, //Smiley face
  B00000,
  B10001,
  B01110,
  B00000,
  B00000,
  B00000
};

byte Large_PictureA[] = {
  B01110,
  B00000,
  B01110,
  B01010,
  B01110,
  B00010,
  B00100,
  B00000
};

byte Large_PictureB[] = {
  B01110,
  B00000,
  B01110,
  B01010,
  B01110,
  B01000,
  B00100,
  B00000
};

byte Large_PictureC[] = {
  B01110,
  B01001,
  B00100,
  B00110,
  B00101,
  B00100,
  B01000,
  B00000
};

byte Large_PictureD[] = {
  B01110,
  B10010,
  B00100,
  B01100,
  B10100,
  B00100,
  B00010,
  B00000
};

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.home();
  lcd.print("Custom fonts:");
  lcd.createChar(0, Picture1);
  lcd.createChar(1, Picture2);
  lcd.createChar(2, Picture3);
  lcd.createChar(3, Picture4);
  lcd.createChar(4, Picture5);
  lcd.createChar(5, Picture6);
  lcd.createChar(6, Picture7);
  lcd.createChar(7, Large_PictureA);
  lcd.createChar(8, Large_PictureB);
  lcd.createChar(9, Large_PictureC);
  lcd.createChar(10, Large_PictureD);
}

void loop() {
  // put your main code here, to run repeatedly:
 lcd.setCursor (0, 1); lcd.write(byte(0));
 lcd.setCursor (2, 1); lcd.write(byte(1));
 lcd.setCursor(4, 1);  lcd.write(byte(2));
 lcd.setCursor(6, 1);  lcd.write(byte(3));
 lcd.setCursor(8, 1);  lcd.write(byte(4));
 lcd.setCursor(10, 1); lcd.write(byte(5));
 lcd.setCursor(12, 1); lcd.write(byte(6));
 lcd.setCursor (14, 0);lcd.write(byte(7));
 lcd.setCursor (15, 0);lcd.write(byte(8));
 lcd.setCursor (14, 1);lcd.write(byte(9));
 lcd.setCursor (15, 1);lcd.write(byte(10));
}
