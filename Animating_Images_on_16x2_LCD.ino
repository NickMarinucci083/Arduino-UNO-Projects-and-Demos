#include <LiquidCrystal.h> //Set up LCD

int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

const int sensor = A0;
int sensorVal = 0;

byte Large_PictureA[] = { //Create the custom images
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
  B00000,
  B01110,
  B01001,
  B00100,
  B00010,
  B00001,
  B00000,
  B00000
};

byte Large_PictureD[] = {
  B00000,
  B01110,
  B10010,
  B00100,
  B01000,
  B10000,
  B00000,
  B00000
};

byte Large_PictureA2[] = {
  B01110,
  B00000,
  B01110,
  B01110,
  B00000,
  B00000,
  B00000,
  B00000
};

byte Large_PictureB2[] = {
  B01110,
  B00000,
  B01110,
  B01110,
  B00000,
  B00000,
  B00000,
  B00000
};

byte Large_PictureC2[] = {
  B00000,
  B01110,
  B00011,
  B00001,
  B00000,
  B00000,
  B00000,
  B00000
};

byte Large_PictureD2[] = {
  B00000,
  B01110,
  B11000,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000
};

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.createChar(0, Large_PictureA); //Create the custom images
  lcd.createChar(1, Large_PictureB);
  lcd.createChar(2, Large_PictureC);
  lcd.createChar(3, Large_PictureD);
  lcd.createChar(4, Large_PictureA2);
  lcd.createChar(5, Large_PictureB2);
  lcd.createChar(6, Large_PictureC2);
  lcd.createChar(7, Large_PictureD2);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorVal = analogRead (sensor);
  if (sensorVal > 100) {
  lcd.clear(); //Clear display
  imageA(); //Print image
  lcd.setCursor (1, 0); //Print text
  lcd.print ("I am");
  lcd.setCursor (1, 1);
  lcd.print ("Awake!");
  delay (1000);
  } else {
  lcd.clear(); //Repeat with other image
  imageB();
  lcd.setCursor (1, 0);
  lcd.print ("I am");
  lcd.setCursor (1, 1);
  lcd.print ("Asleep");
  delay (1000);
  }
}


void imageA() {
  lcd.setCursor (10, 0);
  lcd.write (byte(0));
  lcd.setCursor (11, 0);
  lcd.write (byte(1));
  lcd.setCursor (10, 1);
  lcd.write (byte(2));
  lcd.setCursor (11, 1);
  lcd.write (byte(3));
  lcd.setCursor(13, 0);
  lcd.print ("hi!");
}

void imageB() {
  lcd.setCursor (10, 0);
  lcd.write (byte(4));
  lcd.setCursor (11, 0);
  lcd.write (byte(5));
  lcd.setCursor (10, 1);
  lcd.write (byte(6));
  lcd.setCursor (11, 1);
  lcd.write (byte(7));
  lcd.setCursor (13, 0);
  lcd.print ("zzz");
}