#include <ezButton.h>

const int buttona = 4;
const int buttonb = 5;
const int leda = 10;
const int ledb = 11;
int ledstatea = LOW;
int ledstateb = LOW;

ezButton button(buttona);
//ezButton button(buttonb);

void setup() {
  pinMode(leda, OUTPUT);
  pinMode (ledb, OUTPUT);
  button.setDebounceTime(20);
  button.setDebounceTime(20);
}

void loop() {
  button.loop();

  if(button.isPressed()) {
    ledstatea = !ledstatea;
    digitalWrite(leda, ledstatea);

  }
}