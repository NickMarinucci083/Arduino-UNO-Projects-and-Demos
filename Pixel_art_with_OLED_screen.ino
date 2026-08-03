/* Connect Sh1106G OLED to SDA and SCL as usual, 
Prepare a breadboard with UP, DOWN, LEFT and right direction buttons.
Also put 2 extra buttons on the side and label them "Erase/Draw" and "Clear"
Then insert a small SPST ot SPDT Switch
Connect one contact of all the buttons (Normally open type) to a common ground bus.
Connect one contact of the switch to the ground bus.
Then connect the other contact of the buttons as shown here:
UP = pin 2
DOWN = pin 3
LEFT = pin 4
RIGHT = pin 5
Erase/Draw = pin 6
Clear = pin 7
Laslty, connect the common pin of the switch to pin 8

Now upload this code to your Arduino UNO

How to use OLED Sketcher:
While the cursor is blinking, you can move the cursor around the screen and erase other pixels
that are aleady on by moving the cursor across them. Care must be taken to move the cursor across
existing lines that are not intended to erase. Flicking the switch will control wether the cursor
moves 1 pixel at a time or 4 pixels at a time, enabling speed to draw long lines without repeatedly
pushing a button 5000 times. When you are in the desired spot, hit the Draw/Erase button and the cursor
will stop flashing. Now you can move the cursor to draw lines/shapes. When done, click the Draw/Erase button
again and you can move the cursor without creating more lines and erase pixels by going over them. Again, 
care must be taken when moving cursor along lines that are not indended to be erased. When your design is 
finished, feel free to take a photo and then hit the "Clear" button to erase display*/

#include <Wire.h> //I2C comminucation library
#include <Adafruit_GFX.h> //OLED graphics library
#include <Adafruit_SH110X.h> //SH1106 OLED Chip driver libary
#include <ezButton.h> //Button debouncer library (I'm too lazy to write the button debounce stuff)

Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire, -1); //(Screen width, Screen height, Data com protocol (I2C), Reset command)

//Create buttons and display objects
ezButton up(2);
ezButton down(3);
ezButton left(4);
ezButton right(5);
ezButton erase (6);
ezButton draw (7);

int x = 64; //Set cursor to middle of screen initially
int y = 32;
bool draw_erase = false; //Set cursor mode to erase initially

void setup() {
  up.setDebounceTime(20);
  down.setDebounceTime(20);
  left.setDebounceTime(20);
  right.setDebounceTime(20);
  erase.setDebounceTime(20);
  draw.setDebounceTime(20);
  pinMode (8, INPUT_PULLUP);
  display.begin(0x3c, true); //Start I2C data communication with SH1106G OLED display chip
  display.display();
  delay(3000);
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(SH110X_WHITE); //Display "pixel art" screen at start
  display.setCursor(20, 0);
  display.println("PIXEL");
  display.setTextSize(2);
  display.setCursor(45, 20);
  display.print("art");
  display.setTextSize(1);
  display.setCursor(5, 40);
  display.print("Adafruit GFX/SH110X       libraries");
  display.display();
  delay(5000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(15, 0);
  display.print("Use up/down/left/");
  display.setCursor(25, 10);
  display.print("right keys to");
  display.setCursor(33, 20);
  display.print("move cursor");
  display.setCursor(0, 35);
  display.print("Blue = Toggle D/E");
  display.setCursor(0, 45);
  display.print("Red = Clear all");
  display.setCursor(0, 55);
  display.print("Switch = Move 1px/8px");
  display.display();
 
  while (
  digitalRead(2)==HIGH&&
  digitalRead(3)==HIGH&&
  digitalRead(4)==HIGH&&
  digitalRead(5)==HIGH&&
  digitalRead(6)==HIGH&&
  digitalRead(7)==HIGH
  ) {} //Wait until any button is pressed

  display.clearDisplay();
}


void loop() { up.loop(); down.loop(); left.loop(); right.loop(); erase.loop(); draw.loop();

  if (down.isPressed() && digitalRead(8) == LOW) { //Move cursor according to buttons being pressed with presision - presision switch is off
    y = (y+1);
  }
  if (up.isPressed() && digitalRead(8) == LOW) {
    y = (y-1);
  }
  if (left.isPressed() && digitalRead(8) == LOW) {
    x = (x-1);
  }
  if (right.isPressed() && digitalRead(8) == LOW) {
    x = (x+1);
  }
  if (draw_erase == true) { //Draw pixels white
    display.drawPixel(x, y, SH110X_WHITE);
    display.display();
  } else {
//If in erase mode, draw pixels in black but flash cursor very fast so user can still see cursor more dimly
    display.drawPixel(x, y, SH110X_WHITE);
    display.display();
    display.drawPixel(x, y, SH110X_BLACK);
    display.display();
  }


  
  if (down.isPressed() && digitalRead(8) == HIGH) { //Move cursor according to buttons being pressed with switch movig cursor quickly
    for (int count=0; count<=2; count++) {
    y = (y+1);
    if (draw_erase == true) {
    display.drawPixel(x, y, SH110X_WHITE);
    display.display();
    } else {
      display.drawPixel(x, y, SH110X_BLACK);
      display.display();
    }
    delay(50);
    }
  }
  if (up.isPressed() && digitalRead(8) == HIGH) {
    for (int count=0; count<=2; count++) {
    y = (y-1);
    if (draw_erase == true) {
    display.drawPixel(x, y, SH110X_WHITE);
    display.display();
    } else {
      display.drawPixel(x, y, SH110X_BLACK);
      display.display();
    }
    delay(50);
    }
  }
  if (left.isPressed() && digitalRead(8) == HIGH) {
    for (int count=0; count<=2; count++) {
    x = (x-1);
    if (draw_erase == true) {
    display.drawPixel(x, y, SH110X_WHITE);
    display.display();
    } else {
      display.drawPixel(x, y, SH110X_BLACK);
      display.display();
    }
    delay(50);
    }
  }
  if (right.isPressed() && digitalRead(8) == HIGH) {
    for (int count=0; count<=2; count++) {
    x = (x+1);
    if (draw_erase == true) {
    display.drawPixel(x, y, SH110X_WHITE);
    display.display();
    } else {
      display.drawPixel(x, y, SH110X_BLACK);
      display.display();
    }
    delay(50);
    }
  }


  if (erase.isPressed()) { //Clear display function
    display.clearDisplay();
  }
  if (draw.isPressed()) { //Toggle draw/erase when draw button is pressed
    draw_erase = !draw_erase;
  }

  if (x < 0) { //Keep cursor from leaving the edges of screen
    x = 0;
    display.drawPixel(x, y, SH110X_WHITE);
    display.display();
  }
  if (x > 128) {
    x = 127;
    display.drawPixel(x, y, SH110X_WHITE);
    display.display();
  }
  if (y < 0) {
    y = 0;
    display.drawPixel(x, y, SH110X_WHITE);
    display.display();
  }
  if (y > 64) {
    y = 63;
    display.drawPixel(x, y, SH110X_WHITE);
    display.display();
  }
}