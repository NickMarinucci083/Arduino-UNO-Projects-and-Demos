//Connect I2C Display as normal, channel A is ADC0, Channel B is ADC1, etc.
//Voltage is then displayed on OLED with a voltage source or 0-5v connected between a channel and GND

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define I2C_Address 0x3c
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define channelA A0
#define channelB A1
#define channelC A2
#define channelD A3

float voltageA = 0.00;
float voltageB = 0.00;
float voltageC = 0.00;
float voltageD = 0.00;

// ---------- READ ANALOG WITH AVERAGING ----------
int stableAnalogRead(int pin) {
  analogRead(pin);          // throw away first reading (ADC settle)
  delayMicroseconds(50);

  long sum = 0;
  const int samples = 20;

  for (int i = 0; i < samples; i++) {
    sum += analogRead(pin);
    delayMicroseconds(50);  // helps stabilize floating inputs
  }

  return sum / samples;
}

void setup() {
  display.begin(I2C_Address, true);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(2);
}

void loop() {

  int readingA = stableAnalogRead(channelA);
  int readingB = stableAnalogRead(channelB);
  int readingC = stableAnalogRead(channelC);
  int readingD = stableAnalogRead(channelD);

  voltageA = readingA * (5.0 / 1023.0);
  voltageB = readingB * (5.0 / 1023.0);
  voltageC = readingC * (5.0 / 1023.0);
  voltageD = readingD * (5.0 / 1023.0);

  char bufferA[10];
  dtostrf(voltageA, 4, 2, bufferA);

  char bufferB[10];
  dtostrf(voltageB, 4, 2, bufferB);

  char bufferC[10];
  dtostrf(voltageC, 4, 2, bufferC);

  char bufferD[10];
  dtostrf(voltageD, 4, 2, bufferD);

  display.clearDisplay();
  display.setCursor(0, 0);

  display.print("chA ");
  display.print(bufferA);
  display.println(" V");

  display.print("chB ");
  display.print(bufferB);
  display.println(" V");

  display.print("chC ");
  display.print(bufferC);
  display.println(" V");

  display.print("chD ");
  display.print(bufferD);
  display.println(" V");

  display.display();

  delay(200);
}