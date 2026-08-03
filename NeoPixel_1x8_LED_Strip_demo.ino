#include <Adafruit_NeoPixel.h>

#define PIN 2 // Connect DI pin of grid to pin 2 of Arduino
#define NUMPIXELS 8

int LED;
int R, G, B;

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//                      ^          ^          ^            ^
//               Amount of    The pin      Color format  Data trasfer
//               LED's on    DI of strip   GRB or RGB    rate, either
//               the strip   is connected               800KHz or 400KHz

void setup() {
  strip.begin();
  strip.setBrightness(255);
  strip.clear();

  Serial.begin(9600);
}

void loop() {

  R = random(0, 255);
  G = random(0, 255);
  B = random(0, 255);

  Serial.print(String("R = ") + R + String(", "));
  Serial.print(String("G = ") + G + String(", "));
  Serial.println(String("B = ") + B);

  strip.setBrightness(255);

  for (int LED = 0; LED < NUMPIXELS; LED++) {

    strip.setPixelColor(LED, strip.Color(R, G, B));
    strip.show();
    delay(500);

  }

  // Fade out color
  for (int brightness = 255; brightness >= 1; brightness--) {
    strip.setBrightness(brightness);
    strip.show();
    delay(10);
  }

}