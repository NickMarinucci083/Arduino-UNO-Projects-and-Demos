#include <LiquidCrystal.h> //Set up LCD

int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

const int sensor = A0;
int sensorVal = 0;

byte Large_PictureA[] = { //Create the custom images
  B00000,
  B00000,
  B00001,
  B00010,
  B00100,
  B10100,
  B01100,
  B00100
};

byte Large_PictureB[] = {
  B00000,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
  B10001,
  B00000
};

byte Large_PictureC[] = {
  B00000,
  B00000,
  B10000,
  B01000,
  B00100,
  B00101,
  B00110,
  B00100
};

byte Large_PictureD[] = {
  B01100,
  B10100,
  B00100,
  B00010,
  B00001,
  B00000,
  B00000,
  B00000
};

byte Large_PictureE[] = {
  B00100,
  B10101,
  B01110,
  B00000,
  B11111,
  B00000,
  B00000,
  B00000
};

byte Large_PictureE2[] = {
  B00100,
  B00100,
  B10001,
  B01110,
  B11111,
  B00000,
  B00000,
  B00000
};

byte Large_PictureF[] = {
  B00110,
  B00101,
  B00100,
  B01000,
  B10000,
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
  lcd.createChar(4, Large_PictureE);
  lcd.createChar(5, Large_PictureF);
  lcd.createChar(6, Large_PictureE2);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorVal = analogRead (sensor); //Get "pat the cat" sensor working
  
if (sensorVal > 200) { //If sensor is triggered
  lcd.setCursor (0, 0); //Print the word "meow" next to cat face and refresh image due to lcd.clear being used
  lcd.print ("Virtual");
  lcd.setCursor (0, 1);
  lcd.print ("Cat");
  lcd.setCursor (10, 1);
  lcd.write (byte (6));
  lcd.setCursor (12, 0);
  lcd.print ("meow");
  delay (1000);
} else {
  lcd.clear(); //Otherwise, keep refreshing image with only cat face, no meow
  lcd.setCursor (0, 0);
  lcd.print ("Virtual");
  lcd.setCursor (0, 1);
  lcd.print ("Cat");
  lcd.setCursor (9, 0);
  lcd.write (byte(0));
  lcd.setCursor (10, 0);
  lcd.write (byte(1));
  lcd.setCursor (11, 0);
  lcd.write (byte(2));
  lcd.setCursor (9, 1);
  lcd.write (byte(3));
  lcd.setCursor (10, 1);
  lcd.write (byte (4));
  lcd.setCursor (11, 1);
  lcd.write (byte(5));
  delay (1000);
  }
}