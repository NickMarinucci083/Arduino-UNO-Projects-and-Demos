#include <LiquidCrystal.h>

int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);
int positionCounter = 0;
int blinkCounter = 0;
//Custom characters for LCD
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
  lcd.begin(16, 2);
  //Write some text to the LCD
  lcd.createChar(0, Large_PictureA); //Create the custom characters
  lcd.createChar(1, Large_PictureB);
  lcd.createChar(2, Large_PictureC);
  lcd.createChar(3, Large_PictureD);
  lcd.setCursor (4, 0);
  lcd.print ("Arduino");
  lcd.setCursor (0, 1);
  lcd.print ("www.adeept.com");
  lcd.setCursor (14, 0);
  lcd.write (byte(0)); //Print to LCD the custom characters
  lcd.setCursor (15, 0);
  lcd.write (byte(1));
  lcd.setCursor (14, 1);
  lcd.write (byte(2));
  lcd.setCursor (15, 1);
  lcd.write (byte(3));
  delay (2000);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Make text on LCD blink
  for (blinkCounter = 0; blinkCounter <= 5; blinkCounter++) {
  lcd.noDisplay();
  delay (700);
  lcd.display();
  delay (700);
  }
  blinkCounter = 0;


  //Scroll text on LCD left and right
  for(positionCounter = 0; positionCounter <16; positionCounter++){
    lcd.scrollDisplayLeft();
    delay(1000);
  }
  for(positionCounter = 0; positionCounter < 32; positionCounter++){
    lcd.scrollDisplayRight();
    delay(1000);
  }
  for(positionCounter = 0; positionCounter < 16; positionCounter++){
    lcd.scrollDisplayLeft();
    delay(1000);
  }

  //Blink the cursor for a bit
  lcd.blink();
  delay (5000);
  lcd.noBlink();

}