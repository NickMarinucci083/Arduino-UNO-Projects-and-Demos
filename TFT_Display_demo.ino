#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>

#define BROWN    0x5960  //Brown
#define RED      0xF800  // Red
#define GREEN    0x07E0  // Green
#define BLUE     0x001F  // Blue
#define MAGENTA  0xF81F  // Magenta
#define YELLOW   0xFFE0  // Yellowreen
#define CYAN     0x07FF  // Cyan
#define WHITE    0xFFFF  // White
#define BLACK    0x0000  // Black
#define GREY     0x8410  //Grey (Uninvertable grey)


MCUFRIEND_kbv tft;

int lines;
int color;
int size;
int blink;
int invert;

void setup() {
  // put your setup code here, to run once:
  unsigned int ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  displaySplashScreen(4000); //Slide through functions
  displayShapes(1000);
  displayLines(15);
  displayPixels(1);
  displayTextDemo();
  displayInvertColors(800);
}

void displaySplashScreen(int time) {
  tft.fillScreen(WHITE); //Displays info and driver of shield, and shows colors
  tft.setTextColor(BLACK);
  tft.setCursor(20, 30);
  tft.setTextSize(3);
  tft.print("3.5 Inch TFT LCD Display");
  tft.setCursor(20, 90);
  tft.print("ILI-");
  tft.print(tft.readID(), HEX);
  tft.print(" driver detected!");
  tft.drawFastHLine(88, 115, 75, RED);
  tft.drawFastHLine(88, 116, 75, RED);
  tft.drawFastHLine(88, 117, 75, RED);
  tft.setTextSize(15);
  tft.setCursor(20, 200);
  tft.setTextColor(RED);
  tft.print("C");
  tft.setTextColor(YELLOW);
  tft.print("O");
  tft.setTextColor(GREEN);
  tft.print("L");
  tft.setTextColor(BLUE);
  tft.print("O");
  tft.setTextColor(BROWN);
  tft.print("R");
  delay(time);
}

void displayShapes(int slidechange) {
  tft.fillScreen(BLACK);

  // RECTANGLE OUTLINES
  tft.drawRect(26, 42, 120, 90, RED);
  tft.drawRect(179, 42, 120, 90, GREEN);
  tft.drawRect(332, 42, 120, 90, BLUE);
  tft.drawRect(26, 187, 120, 90, MAGENTA);
  tft.drawRect(179, 187, 120, 90, CYAN);
  tft.drawRect(332, 187, 120, 90, YELLOW);
  delay(slidechange);

  // RECTANGLE FILLS
  tft.fillRect(26, 42, 120, 90, RED);
  tft.fillRect(179, 42, 120, 90, GREEN);
  tft.fillRect(332, 42, 120, 90, BLUE);
  tft.fillRect(26, 187, 120, 90, MAGENTA);
  tft.fillRect(179, 187, 120, 90, CYAN);
  tft.fillRect(332, 187, 120, 90, YELLOW);
  delay(slidechange);

  tft.fillScreen(BLACK);

  // CIRCLE OUTLINES
  tft.drawCircle(86, 87, 55, RED);
  tft.drawCircle(239, 87, 55, GREEN);
  tft.drawCircle(392, 87, 55, BLUE);
  tft.drawCircle(86, 232, 55, MAGENTA);
  tft.drawCircle(239, 232, 55, CYAN);
  tft.drawCircle(392, 232, 55, YELLOW);
  delay(slidechange);

  // CIRCLE FILLS
  tft.fillCircle(86, 87, 55, RED);
  tft.fillCircle(239, 87, 55, GREEN);
  tft.fillCircle(392, 87, 55, BLUE);
  tft.fillCircle(86, 232, 55, MAGENTA);
  tft.fillCircle(239, 232, 55, CYAN);
  tft.fillCircle(392, 232, 55, YELLOW);
  delay(slidechange);

  tft.fillScreen(BLACK);

  // ELLIPSE OUTLINES
  tft.drawEllipse(86, 87, 60, 40, RED);
  tft.drawEllipse(239, 87, 60, 40, GREEN);
  tft.drawEllipse(392, 87, 60, 40, BLUE);
  tft.drawEllipse(86, 232, 60, 40, MAGENTA);
  tft.drawEllipse(239, 232, 60, 40, CYAN);
  tft.drawEllipse(392, 232, 60, 40, YELLOW);
  delay(slidechange);

  // ELLIPSE FILLS
  tft.fillEllipse(86, 87, 60, 40, RED);
  tft.fillEllipse(239, 87, 60, 40, GREEN);
  tft.fillEllipse(392, 87, 60, 40, BLUE);
  tft.fillEllipse(86, 232, 60, 40, MAGENTA);
  tft.fillEllipse(239, 232, 60, 40, CYAN);
  tft.fillEllipse(392, 232, 60, 40, YELLOW);
  delay(slidechange);

  tft.fillScreen(BLACK);

  // TRIANGLE OUTLINES
  tft.drawTriangle(86, 42, 26, 132, 146, 132, RED);
  tft.drawTriangle(239, 42, 179, 132, 299, 132, GREEN);
  tft.drawTriangle(392, 42, 332, 132, 452, 132, BLUE);
  tft.drawTriangle(86, 187, 26, 277, 146, 277, MAGENTA);
  tft.drawTriangle(239, 187, 179, 277, 299, 277, CYAN);
  tft.drawTriangle(392, 187, 332, 277, 452, 277, YELLOW);
  delay(slidechange);

  // TRIANGLE FILLS
  tft.fillTriangle(86, 42, 26, 132, 146, 132, RED);
  tft.fillTriangle(239, 42, 179, 132, 299, 132, GREEN);
  tft.fillTriangle(392, 42, 332, 132, 452, 132, BLUE);
  tft.fillTriangle(86, 187, 26, 277, 146, 277, MAGENTA);
  tft.fillTriangle(239, 187, 179, 277, 299, 277, CYAN);
  tft.fillTriangle(392, 187, 332, 277, 452, 277, YELLOW);
  delay(slidechange);
}

void displayLines(int speed) {
  tft.fillScreen(BLACK);
  //Generates vertical and horizontal lines in all colors
  for (lines = 0; lines <= 320; lines = lines+10) {
    tft.drawFastHLine(0, lines, 480, RED);
    delay(speed);
  }
  for (lines = 0; lines <= 320; lines = lines+10) {
    tft.drawFastHLine(0, lines, 480, GREEN);
    delay(speed);
  }
  for (lines = 0; lines <= 320; lines = lines+10) {
    tft.drawFastHLine(0, lines, 480, BLUE);
    delay(speed);
  }
  for (lines = 0; lines <= 320; lines = lines+10) {
    tft.drawFastHLine(0, lines, 480, MAGENTA);
    delay(speed);
  }
  for (lines = 0; lines <= 320; lines = lines+10) {
    tft.drawFastHLine(0, lines, 480, CYAN);
    delay(speed);
  }
  for (lines = 0; lines <= 320; lines = lines+10) {
    tft.drawFastHLine(0, lines, 480, YELLOW);
    delay(speed);
  }
  for (lines = 0; lines <= 320; lines = lines+10) {
    tft.drawFastHLine(0, lines, 480, WHITE);
    delay(speed);
  }

  tft.fillScreen(BLACK);

  for (lines = 0; lines <= 480; lines = lines+10) {
    tft.drawFastVLine(lines, 0, 320, RED);
    delay(speed);
  }
  for (lines = 0; lines <= 480; lines = lines+10) {
    tft.drawFastVLine(lines, 0, 320, GREEN);
    delay(speed);
  }
  for (lines = 0; lines <= 480; lines = lines+10) {
    tft.drawFastVLine(lines, 0, 320, BLUE);
    delay(speed);
  }
  for (lines = 0; lines <= 480; lines = lines+10) {
    tft.drawFastVLine(lines, 0, 320, MAGENTA);
    delay(speed);
  }
  for (lines = 0; lines <= 480; lines = lines+10) {
    tft.drawFastVLine(lines, 0, 320, CYAN);
    delay(speed);
  }
  for (lines = 0; lines <= 480; lines = lines+10) {
    tft.drawFastVLine(lines, 0, 320, YELLOW);
    delay(speed);
  }
  for (lines = 0; lines <= 480; lines = lines+10) {
    tft.drawFastVLine(lines, 0, 320, WHITE);
    delay(speed);
  }
}

void displayPixels(int wait) {
  tft.fillScreen(BLACK);
  //Randomly generates pixels of all colors on screen
  for (int pixels = 0; pixels <= 1000; pixels++) {
    tft.drawPixel(random(0, 480), random(0, 320), RED);
    delay(wait);
  }
  for (int pixels = 0; pixels <= 1000; pixels++) {
    tft.drawPixel(random(0, 480), random(0, 320), GREEN);
    delay(wait);
  }
  for (int pixels = 0; pixels <= 1000; pixels++) {
    tft.drawPixel(random(0, 480), random(0, 320), BLUE);
    delay(wait);
  }
  for (int pixels = 0; pixels <= 1000; pixels++) {
    tft.drawPixel(random(0, 480), random(0, 320), MAGENTA);
    delay(wait);
  }
  for (int pixels = 0; pixels <= 1000; pixels++) {
    tft.drawPixel(random(0, 480), random(0, 320), CYAN);
    delay(wait);
  }
  for (int pixels = 0; pixels <= 1000; pixels++) {
    tft.drawPixel(random(0, 480), random(0, 320), YELLOW);
    delay(wait);
  }
  for (int pixels = 0; pixels <= 1000; pixels++) {
    tft.drawPixel(random(0, 480), random(0, 320), WHITE);
    delay(wait);
  }
}

void displayTextDemo() {
  tft.fillScreen(BLACK);
  //Shows text sizes, colors and blinking text all at once
  tft.setTextColor(WHITE);
  tft.setCursor(0,0);
  for (size = 1; size <= 5; size++) {
    tft.setTextSize(size);
    tft.print("Text size ");
    tft.println(size);
  }

  tft.setCursor(0, 130);
  tft.setTextSize(4);
  for (int number = 1; number <= 6; number++){
    numbertocolor(number);
    tft.println("Text colors");
  }

  tft.setTextSize(3);
  for (blink = 0; blink <=9; blink++) {
    tft.setTextColor(WHITE);
    tft.setCursor(295, 170);
    tft.print("Blinking");
    tft.setCursor(325, 200);
    tft.print("text");
    delay(500);
    tft.setTextColor(BLACK);
    tft.setCursor(295, 170);
    tft.print("Blinking");
    tft.setCursor(325, 200);
    tft.print("text");
    delay(500);
  }
}

void displayInvertColors(int Delay) {
  tft.fillScreen(BLACK);
  //Shows colors, and inverts them a few times to new colors
  tft.fillRect(10, 10, 230, 70, RED);
  tft.fillRect(240, 10, 230, 70, CYAN);
  tft.fillRect(10, 100, 230, 70, GREEN);
  tft.fillRect(240, 100, 230, 70, MAGENTA);
  tft.fillRect(10, 190, 230, 70, BLUE);
  tft.fillRect(240, 190, 230, 70, YELLOW);
  tft.setTextColor(GREY);
  tft.setTextSize(2);
  tft.setCursor(65, 280);
  tft.print("Inverted colors side by side");

  for (invert = 0; invert <= 7; invert++) {
    tft.invertDisplay(true);
    delay(Delay);
    tft.invertDisplay(false);
    delay(Delay);
  }
}

void numbertocolor(int number) {
  //Used to change text color in a for loop
  if (number == 1) {tft.setTextColor(RED);}
  if (number == 2) {tft.setTextColor(GREEN);}
  if (number == 3) {tft.setTextColor(BLUE);}
  if (number == 4) {tft.setTextColor(MAGENTA);}
  if (number == 5) {tft.setTextColor(CYAN);}
  if (number == 6) {tft.setTextColor(YELLOW);}
}