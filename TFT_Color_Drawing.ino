#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>

#define BROWN    0x5960  //Brown
#define RED      0xF800  // Red
#define GREEN    0x07E0  // Green
#define BLUE     0x001F  // Blue
#define MAGENTA  0xF81F  // Magenta
#define YELLOW   0xFFE0  // Yellowreen
#define CYAN     0x07FF  // Cyan
#define WHITE    0xFFFF  // White
#define BLACK    0x0000  // Black
#define GREY     0x8410  //Grey

// Define pins for touchscreen
#define YP A1 //ADC
#define XM A2 //ADC
#define YM 7  //IO
#define XP 6  //IO

// Touchscreen calibration values
#define TS_LEFT 955
#define TS_RT 145
#define TS_TOP 940
#define TS_BOT 180

// Pressure thresholds
#define MINPRESSURE 100
#define MAXPRESSURE 1000

unsigned int color = BLACK;
int thickness = 0;

int x;
int y;

MCUFRIEND_kbv tft;
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

void setup() {
  analogReference(EXTERNAL);
  unsigned int ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
  drawMenu();
  drawPXmenu();
  drawClear();
  clearScreen();
  drawTopBorder();
  drawBottomBorder();
  x = 495;
  y = 335;
  tft.setTextSize(1);
  tft.setTextColor(BLACK);
}

void loop() {
  // put your main code here, to run repeatedly:
  TSPoint p = ts.getPoint();

  // Restore pinMode after reading touchscreen (required for MCUFRIEND)
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  checkButtons();
  keepBorders();

  x = map(p.y, TS_LEFT, TS_RT, 0, 492);
  y = map(p.x, TS_BOT, TS_TOP, 0, 320);

  if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
    if (thickness >= 1) {
    tft.fillCircle(x, y, thickness, color);
    }
  }

}


void drawMenu() {
  tft.fillRect(0, 0, 50, 40, BROWN);
  tft.fillRect(0, 40, 50, 40, RED);
  tft.fillRect(0, 80, 50, 80, GREEN);
  tft.fillRect(0, 120, 50, 120,BLUE);
  tft.fillRect(0, 160, 50, 160, MAGENTA);
  tft.fillRect(0, 200, 50, 200, YELLOW);
  tft.fillRect(0, 240, 50, 240, CYAN);
  tft.fillRect(0, 280, 50, 280, WHITE);
  tft.fillRect(430, 40, 50, 40, WHITE);
  tft.drawRect(435, 45, 40, 30, BLACK);
  tft.setTextColor(BLACK);
  tft.setCursor(440, 50);
  tft.print("ERASE");
}

void drawPXmenu() {
  tft.fillRect(430, 80, 50, 40, GREY);
  tft.drawRect(431, 81, 48, 38, BLACK);
  tft.setTextColor(BLACK);
  tft.setCursor(442, 87);
  tft.print("1 PX");
  tft.fillRect(430, 120, 50, 40, GREY);
  tft.drawRect(431, 121, 48, 38, BLACK);
  tft.setCursor(442, 127);
  tft.print("3 PX");
  tft.fillRect(430, 160, 50, 40, GREY);
  tft.drawRect(431, 161, 48, 38, BLACK);
  tft.setCursor(442, 167);
  tft.print("5 PX");
  tft.fillRect(430, 200, 50, 40, GREY);
  tft.drawRect(431, 201, 48, 38, BLACK);
  tft.setCursor(442, 207);
  tft.print("7 PX");
  tft.fillRect(430, 240, 50, 40, GREY);
  tft.drawRect(431, 241, 48, 38, BLACK);
  tft.setCursor(442, 247);
  tft.print("9 PX");
  tft.fillRect(430, 280, 50, 40, GREY);
  tft.drawRect(431, 281, 48, 38, BLACK);
  tft.setCursor(439, 287);
  tft.print("11 PX");
}

void clearScreen() {
  tft.fillRect(50, 10, 380, 300, BLACK);
}

void drawClear() {
  tft.fillRect(430, 0, 50, 40, WHITE);
  tft.drawRect(435, 5, 40, 30, BLACK);
  tft.setTextColor(BLACK);
  tft.setCursor(440, 17);
  tft.print("CLEAR");
}

void drawBottomBorder() {
  tft.fillRect(50, 310, 380, 10, BLUE);
  tft.setTextColor(GREEN);
  tft.setCursor(88, 311);
  tft.print("Note: Power from USB for touchscreen to work at best");
}

void drawTopBorder() {
  tft.fillRect(50, 0, 380, 10, BLUE);
  tft.setTextColor(GREEN);
  tft.setCursor(54, 1);
  tft.print("[Adafruit_GFX]       TFT COLOR SKETCHER        [MCUFRIEND.kbv]");
}

void checkButtons() {
  //Detects for button presses on left side of screen
  if (x >= 0 && x < 50) {
  if (y >= 0 && y < 40) {
    color = BROWN;
    drawMenu();
    resetButton();
    tft.fillCircle(25, 18, 5, BLACK);
  } else if (y >= 40 && y < 80) {
    color = RED;
    drawMenu();
    resetButton();
    tft.fillCircle(25, 58, 5, BLACK);
  } else if (y >= 80 && y < 120) {
    color = GREEN;
    drawMenu();
    resetButton();
    tft.fillCircle(25, 98, 5, BLACK);
  } else if (y >= 120 && y < 160) {
    color = BLUE;
    drawMenu();
    resetButton();
    tft.fillCircle(25, 138, 5, BLACK);
  } else if (y >= 160 && y < 200) {
    color = MAGENTA;
    drawMenu();
    resetButton();
    tft.fillCircle(25, 178, 5, BLACK);
  } else if (y >= 200 && y < 240) {
    color = YELLOW;
    drawMenu();
    resetButton();
    tft.fillCircle(25, 218, 5, BLACK);
  } else if (y >= 240 && y < 280) {
    color = CYAN;
    drawMenu();
    resetButton();
    tft.fillCircle(25, 258, 5, BLACK);
  } else if (y >= 280 && y < 320) {
    color = WHITE;
    drawMenu();
    resetButton();
    tft.fillCircle(25, 298, 5, BLACK);
  }
  }
  //Detects for button presses on right side of screen
  if (x >= 430 && x < 480) {
  if (y >= 0 && y < 40) {
    drawClear();
    clearScreen();
    resetButton();
  } else if (y >= 40 && y < 80) {
    color = BLACK;
    drawMenu();
    resetButton();
    tft.fillCircle(455, 65, 5, BLACK);
  } else if (y >= 80 && y < 120) {
    thickness = 1;
    drawPXmenu();
    resetButton();
    tft.fillCircle(455, 105, 5, BLACK);
  } else if (y >= 120 && y < 160) {
    thickness = 3;
    drawPXmenu();
    resetButton();
    tft.fillCircle(455, 145, 5, BLACK);
  } else if (y >= 160 && y < 200) {
    thickness = 5;
    drawPXmenu();
    resetButton();
    tft.fillCircle(455, 185, 5, BLACK);
  } else if (y >= 200 && y < 240) {
    thickness = 7;
    drawPXmenu();
    resetButton();
    tft.fillCircle(455, 225, 5, BLACK);
  } else if (y >= 240 && y < 280) {
    thickness = 9;
    drawPXmenu();
    resetButton();
    tft.fillCircle(455, 265, 5, BLACK);
  } else if (y >= 280 && y < 320) {
    thickness = 11;
    drawPXmenu();
    resetButton();
    tft.fillCircle(455, 305, 5, BLACK);
  }
 }
}

void resetButton() {
  x = 495;
  y = 335;
}

void keepBorders() {
  if (x >= 50 && x <= 430) {
    if (y <= 20){
     drawTopBorder();
    }
  }
  if (x >= 50 && x <= 430) {
    if (y >= 300) {
      drawBottomBorder();
    }
  }
}