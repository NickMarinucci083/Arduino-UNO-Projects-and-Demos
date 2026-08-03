#include <Adafruit_NeoPixel.h>
//Uses a 16x16 NeoPixel LED matrix, or use individual strips wired progressivly, not serpentine
//Can assemble yourself using 16 1x16 LED strips, or 32 1x8 LED strips
//Wire PROGRESSIVLY, NOT SERPENTINE:

/*
  [# = Neopixel single LED pixel]

  Progressive wiring:                      ________
.                                                 |         /
.    DI (Input)                           DO      |        /
.    -->  # # # # # # # # # # # # # # # # --> -   | \     /
.  ____________________________________________|  |  \   /
. |  DI                                   DO      |   \_/
. |__-->  # # # # # # # # # # # # # # # # --> -   |
.  ____________________________________________|  | USE THIS TYPE
. |  DI                                   DO      | OF WIRING WHEN
. |__-->  # # # # # # # # # # # # # # # # --> -   | MAKING LED MATRIX
  etc...                                   _______| FROM SCRATCH
                                          

  Serpentine wiring:                       ______
.                                                | \     /
.    DI (Input)                          DO      |  \   /
.    --># # # # # # # # # # # # # # # # -->      |   \ /
.                                         |      |   / \
.   DO                                  DI|      |  /   \
.   <--# # # # # # # # # # # # # # # # <--|      | /     \
.   |                                            |
.   |DI                                 DO       | DO NOT USE
.   |--># # # # # # # # # # # # # # # # -->      | THIS TYPE
  etc...                                   ______| OF WIRING
*/

#define PIN 2 // Connect DI pin of grid to pin 2 of Arduino
#define ROWS 16
#define COLS 16
#define NUMPIXELS ROWS * COLS

int R, G, B;
int index;

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

unsigned long pixel_data[ROWS][COLS] = { //Can change data if you want, could display images
  {0x000000,0x101010,0x202020,0x303030,0x404040,0x505050,0x606060,0x707070,0x808080,0x909090,0xA0A0A0,0xB0B0B0,0xC0C0C0,0xD0D0D0,0xE0E0E0,0xF0F0F0},
  {0x000000,0x100010,0x200020,0x300030,0x400040,0x500050,0x600060,0x700070,0x800080,0x900090,0xA000A0,0xB000B0,0xC000C0,0xD000D0,0xE000E0,0xF000F0},
  {0x000000,0x001010,0x002020,0x003030,0x004040,0x005050,0x006060,0x007070,0x008080,0x009090,0x00A0A0,0x00B0B0,0x00C0C0,0x00D0D0,0x00E0E0,0x00F0F0},
  {0x000000,0x101000,0x202000,0x303000,0x404000,0x505000,0x606000,0x707000,0x808000,0x909000,0xA0A000,0xB0B000,0xC0C000,0xD0D000,0xE0E000,0xF0F000},
  {0x000000,0x000010,0x000020,0x000030,0x000040,0x000050,0x000060,0x000070,0x000080,0x000090,0x0000A0,0x0000B0,0x0000C0,0x0000D0,0x0000E0,0x0000F0},
  {0x000000,0x001000,0x002000,0x003000,0x004000,0x005000,0x006000,0x007000,0x008000,0x009000,0x00A000,0x00B000,0x00C000,0x00D000,0x00E000,0x00F000},
  {0x000000,0x100000,0x200000,0x300000,0x400000,0x500000,0x600000,0x700000,0x800000,0x900000,0xA00000,0xB00000,0xC00000,0xD00000,0xE00000,0xF00000},
  {0x000000,0x090400,0x120900,0x1B0D00,0x241200,0x2D1600,0x361B00,0x3F1F00,0x482400,0x512800,0x5A2D00,0x633100,0x6C3600,0x753A00,0x7E3F00,0x874300},
  {0x874300,0x7E3F00,0x753A00,0x6C3600,0x633100,0x5A2D00,0x512800,0x482400,0x3F1F00,0x361B00,0x2D1600,0x241200,0x1B0D00,0x120900,0x090400,0x000000},
  {0xF00000,0xE00000,0xD00000,0xC00000,0xB00000,0xA00000,0x900000,0x800000,0x700000,0x600000,0x500000,0x400000,0x300000,0x200000,0x100000,0x000000},
  {0x00F000,0x00E000,0x00D000,0x00C000,0x00B000,0x00A000,0x009000,0x008000,0x007000,0x006000,0x005000,0x004000,0x003000,0x002000,0x001000,0x000000},
  {0x0000F0,0x0000E0,0x0000D0,0x0000C0,0x0000B0,0x0000A0,0x000090,0x000080,0x000070,0x000060,0x000050,0x000040,0x000030,0x000020,0x000010,0x000000},
  {0xF0F000,0xE0E000,0xD0D000,0xC0C000,0xB0B000,0xA0A000,0x909000,0x808000,0x707000,0x606000,0x505000,0x404000,0x303000,0x202000,0x101000,0x000000},
  {0x00F0F0,0x00E0E0,0x00D0D0,0x00C0C0,0x00B0B0,0x00A0A0,0x009090,0x008080,0x007070,0x006060,0x005050,0x004040,0x003030,0x002020,0x001010,0x000000},
  {0xF000F0,0xE000E0,0xD000D0,0xC000C0,0xB000B0,0xA000A0,0x900090,0x800080,0x700070,0x600060,0x500050,0x400040,0x300030,0x200020,0x100010,0x000000},
  {0xF0F0F0,0xE0E0E0,0xD0D0D0,0xC0C0C0,0xB0B0B0,0xA0A0A0,0x909090,0x808080,0x707070,0x606060,0x505050,0x404040,0x303030,0x202020,0x101010,0x000000}
};

void getRGB(unsigned long color) {
  R = (color >> 16) & 255;
  G = (color >> 8) & 255;
  B = color & 255;
}

void displayGradient(int brightness) {
  for (int x = 0; x < COLS; x++) {
    for (int y = 0; y < ROWS; y++) {

      index = x * ROWS + y;

      unsigned long color = pixel_data[x][y];
      getRGB(color);

      // Apply brightness manually (strip.setBrightness is useless for this)
      strip.setPixelColor(index, strip.Color(
        (R * brightness) / 255, // ChatGPT did the maths here.
        (G * brightness) / 255, // I hate maths.
        (B * brightness) / 255
      ));
    }
  }
}

void displayGradientSetup() {
  for (int x = 0; x < COLS; x++) {
    for (int y = 0; y < ROWS; y++) {

      index = x * ROWS + y;

      unsigned long color = pixel_data[x][y];
      getRGB(color);

      strip.setPixelColor(index, strip.Color(R, G, B));
      
      delay(5);
      strip.show();
    }
  }
}

void setup() {
  strip.begin();
  strip.setBrightness(255);
  strip.clear();
  displayGradientSetup();
}

void loop() {

  // Fade out
  for (int brightness = 255; brightness >= 0; brightness--) {
    displayGradient(brightness);
    strip.show();
    delay(1);
  }

  // Fade in
  for (int brightness = 0; brightness <= 255; brightness++) {
    displayGradient(brightness);
    strip.show();
    delay(1);
  }

}