#include <MCUFRIEND_kbv.h>
#include <Adafruit_GFX.h>

#include <Fonts/FreeMono9pt7b.h> //Also <Fonts/FreeMono12pt7b.h> and <Fonts/FreeMono18pt7b.h>
#include <Fonts/FreeSerif9pt7b.h> //Applys for all fonts, all also come in sizes of 9, 12 and 18
#include <Fonts/FreeSans9pt7b.h> //Only the smallest size of each font is used here, to demonstrate
#include <Fonts/FreeMonoBold9pt7b.h> //all the font shapes without overfilling 32KB memory.
#include <Fonts/FreeSerifBold9pt7b.h> //There are total 8 types of fonts in Adafruit GFX.
#include <Fonts/FreeSansBold9pt7b.h>
#include <Fonts/FreeMonoOblique9pt7b.h>
#include <Fonts/FreeSansOblique9pt7b.h>


#define BLACK   0x0000
#define WHITE   0xFFFF

MCUFRIEND_kbv tft;

/*
  List of fonts in Adafruit GFX:

    &FreeMono9pt7b  &FreeMono12pt7b &FreeMono18pt7b
    &FreeSerif9pt7b &FreeSerif12pt7b &FreeSerif18pt7b
    &FreeSans9pt7b &FreeSans12pt7b &FreeSans18pt7b
    &FreeMonoBold9pt7b &FreeMonoBold12pt7b &FreeMonoBold18pt7b
    &FreeSerifBold9pt7b &FreeSerifBold12pt7b &FreeSerifBold18pt7b
    &FreeSansBold9pt7b &FreeSansBold12pt7b &FreeSansBold18pt7b
    &FreeMonoOblique9pt7b &FreeMonoOblique12pt7b &FreeMonoOblique18pt7b
    &FreeSansOblique9pt7b &FreeSansOblique12pt7b &FreeSansOblique18pt7b

  Change the font by calling tft.setFont();
  and putting a font into the parentheses.
*/

const GFXfont* fonts[] = {
    &FreeMono9pt7b,
    &FreeSerif9pt7b,
    &FreeSans9pt7b,
    &FreeMonoBold9pt7b,
    &FreeSerifBold9pt7b,
    &FreeSansBold9pt7b,
    &FreeMonoOblique9pt7b,
    &FreeSansOblique9pt7b
};

const char* fontNames[] = {
    "Mono 9px",
    "Serif 9px",
    "Sans 9px",
    "MonoBold 9px",
    "SerifBold 9px",
    "SansBold 9px",
    "MonoOblique 9px",
    "SansOblique 9px"
};

void setup() {
  // put your setup code here, to run once:
  unsigned int ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
  tft.fillScreen(BLACK);
  tft.setTextColor(WHITE);
  tft.setCursor(0, 0);
  tft.setTextSize(2);
  tft.print("Font: <Default 2px> ABCD abcd 1234");

  tft.setTextSize(NULL);
  tft.setCursor(0, 32);
  for (int i = 0; i < 8; i++) {
    tft.setFont(fonts[i]);  // Set current font from fonts array
    tft.print("Font: <");
    tft.print(fontNames[i]);  // Print the current font name and a bunch of characters
    tft.println("> ABCD abcd 1234");
  }

  tft.setTextSize(2);
  tft.setFont(NULL);
  tft.setCursor(0, 200);
  tft.print("These fonts are also avaliable in size  12 and 18 px. Any color can be used.    setTextSize() can also be used but it isrecommended to use the different 9, 12  or 18 px font sizes instead of scaling  one size, unless you run out of program memory. Font libraries are memory heavy.");

}

void loop() {}