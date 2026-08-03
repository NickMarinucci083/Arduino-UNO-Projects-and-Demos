#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <Fonts/FreeMono9pt7b.h> //Also <Fonts/FreeMono12pt7b.h> and <Fonts/FreeMono18pt7b.h>
#include <Fonts/FreeSerif9pt7b.h> //Applys for all fonts, all also come in sizes of 9, 12 and 18
#include <Fonts/FreeSans9pt7b.h> //Only the smallest size of each font is used here, to demonstrate
#include <Fonts/FreeMonoBold9pt7b.h> //all the font shapes without overfilling 32KB memory.
#include <Fonts/FreeSerifBold9pt7b.h> //There are total 8 types of fonts in Adafruit GFX.
#include <Fonts/FreeSansBold9pt7b.h>
#include <Fonts/FreeMonoOblique9pt7b.h>
#include <Fonts/FreeSerifBoldItalic9pt7b.h>
#include <Fonts/FreeSansOblique9pt7b.h>

Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire, -1);

void setup() {
  display.begin(0x3c, false);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(1);
  display.setCursor(1, 1);
  display.print("Font demo - Origional");
  
  display.setTextSize(NULL);

  display.setFont(&FreeSans9pt7b);
  display.setCursor(0, 24);
  display.print("Sans");

  display.setFont(&FreeSerif9pt7b);
  display.setCursor(0, 42);
  display.print("Serif");

  display.setFont(&FreeMono9pt7b);
  display.setCursor(0, 59);
  display.print("Mono");

  display.setFont(&FreeSansBold9pt7b);
  display.setCursor(45, 24);
  display.print("Bold");

  display.setFont(&FreeSerifBold9pt7b);
  display.setCursor(40, 42);
  display.print("Bold");

  display.setFont(&FreeMonoBold9pt7b);
  display.setCursor(45, 59);
  display.print("Bold");

  display.setFont(&FreeSansOblique9pt7b);
  display.setCursor(86, 24);
  display.print("Italic");

  display.setFont(&FreeSerifBoldItalic9pt7b);
  display.setCursor(80, 42);
  display.print("Italic");

  display.setFont(&FreeMonoOblique9pt7b);
  display.setCursor(90, 59);
  display.print("Ita");

  display.display();
}

void loop() {
  display.invertDisplay(true);
  delay(3000);
  display.invertDisplay(false);
  delay(3000);
}