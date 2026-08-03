#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define I2C_Address 0x3c
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

String user_input;
int text_size = 1;

void setup() {
  display.begin(I2C_Address, true); //Start I2C data communication with SH1106G OLED display chip
  display.clearDisplay(); //Clear display
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(10, 15);
  display.println("Type some text on"); 
  display.setCursor(20, 25);
  display.print("Serial monitor");   
  display.setCursor(0, 35);
  display.print("to be displayed here.");
  display.display();
  delay(3000);
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("DISPLAY COMMANDS:");
  display.setCursor(0, 10);
  display.setTextSize(1);
  display.print("Clear");
  display.setCursor(0, 20);
  display.print("Invert");
  display.setCursor(0, 30);
  display.print("Noninvert");
  display.setCursor(0, 40);
  display.print("Increase size");
  display.setCursor(0, 50);
  display.print("Decrease size");
  display.display();
  delay(5000);
  display.clearDisplay();
  Serial.begin(9600);
}


void loop() {
  user_input = Serial.readStringUntil('\n'); //Read until new line (enter key is pressed)
  display.setCursor(0, 0);
  display.println(user_input);
  display.display();

  if (user_input == "Clear"){
    display.clearDisplay();
  }
  if (user_input == "Invert"){
    display.clearDisplay();
    display.invertDisplay(true);
  }
  if (user_input == "Noninvert"){
    display.clearDisplay();
    display.invertDisplay(false);
  }
  if (user_input == "Increase size"){
  display.clearDisplay();
  text_size = (text_size+1);
  display.setTextSize(text_size);
  }
  if (user_input == "Decrease size"){
    display.clearDisplay();
    text_size = (text_size-1);
    display.setTextSize(text_size);
  }
}