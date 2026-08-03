#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>

MCUFRIEND_kbv tft;

int x = 0;
int y = 0;

void setup() {
  // put your setup code here, to run once:
  unsigned int ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
  tft.fillScreen(0x0000);

  randomSeed(analogRead(A0)); //Ensure randomness so colors aren't same every time

  for (y = 0; y < 320; y++) {
    for (x = 0; x < 480; x++) {
        tft.drawPixel(x, y, RandomColor());
    }
  }
}

void loop() {}

unsigned int RandomColor() {
  unsigned int red = random(0, 32);    // 5-bit red (0-31)
  unsigned int green = random(0, 64);  // 6-bit green (0-63)
  unsigned int blue = random(0, 32);   // 5-bit blue (0-31)
  
  // Combine the RGB values into a 16-bit RGB565 color format
	//Shift red left by 11 binary bits, and green by 5 bits, blue left alone
	//This generates a direct, 16 bit binary number that can be interpreted
	//as a random RGB565 color

  unsigned int color = (red << 11) | (green << 5) | blue;
  return color; //Return color from function
}