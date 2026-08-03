#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define I2C_Address 0x3c
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int ADC0 = 0;
int ADC1 = 0;
int ADC2 = 0;
int ADC3 = 0;
//Can't use ADC's 4 and 5 as they are used to connect the I2C display

void setup()   {
  display.begin(I2C_Address, true); //Start I2C data communication with SH1106G OLED display chip
  display.display(); //Display adafruit splashscreen
  delay(3000);
  display.clearDisplay(); //Clear display
}


void loop() {
  ADC0 = analogRead(A0);
  ADC1 = analogRead(A1);
  ADC2 = analogRead(A2);
  ADC3 = analogRead(A3);


  display.setTextSize(2);
  display.setTextColor(SH110X_WHITE);
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("ADC0 = ");
  display.println(ADC0);
  display.print("ADC1 = ");
  display.println(ADC1);
  display.print("ADC2 = ");
  display.println(ADC2);
  display.print("ADC3 = ");
  display.println(ADC3);
  display.display();
}