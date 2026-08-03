#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>

#define WHITE    0xFFFF  // White
#define BLACK    0x0000  // Black

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
#define MINPRESSURE 200
#define MAXPRESSURE 1000

int x;
int y;

MCUFRIEND_kbv tft;
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(2000000); //Fast baud rate so drawing is easy
  Serial.println("Touch screen to see coordinates");
  const unsigned int ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
  tft.fillScreen(BLACK);
  tft.setCursor(10, 10);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("Touch screen test");
}

void loop() {
  // put your main code here, to run repeatedly:
  TSPoint p = ts.getPoint();

  // Restore pinMode after reading touchscreen (required for MCUFRIEND)
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);


  x = map(p.y, TS_LEFT, TS_RT, 0, 492);
  y = map(p.x, TS_BOT, TS_TOP, 0, 320);

  if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
    // Map touchscreen coordinates to screen coordinates
    tft.fillCircle(x, y, 2, WHITE);
    
    Serial.print("Raw x = ");
    Serial.print(p.x);
    Serial.print("  ");
    Serial.print("Raw y = ");
    Serial.print(p.y);
    Serial.print(" | ");
    Serial.print("Coordinate x = ");
    Serial.print(x);
    Serial.print("  ");
    Serial.print("Coordinate y = ");
    Serial.print(y);
    Serial.print("    ");
    Serial.print("Pressure = ");
    Serial.println(p.z);
  }
}