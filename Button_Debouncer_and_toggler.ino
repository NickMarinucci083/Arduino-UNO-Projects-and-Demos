#include <ezButton.h>

const int BUTTON_PINA = 2; // the number of the pushbutton pin
const int BUTTON_PINB = 3;
const int LED_PINA = 10; // the number of the LED pin
const int LED_PINB = 11;
int ledStateA = LOW;   // the current state of LED and is initally off
int ledStateB = LOW;

ezButton buttonA(BUTTON_PINA);  // create ezButton object that attaches to BUTTON_PIN
ezButton buttonB(BUTTON_PINB);

void setup() {
  pinMode(LED_PINA, OUTPUT);   // set arduino pin to output mode
  pinMode(LED_PINB, OUTPUT);
  buttonA.setDebounceTime(20); // set debounce time to 20 milliseconds
  buttonB.setDebounceTime(20);
}

void loop() {
  buttonA.loop(); // MUST call the loop() function first
  buttonB.loop();

  if(buttonA.isPressed()) {
    ledStateA = !ledStateA; // toggle state of LED
    //(led is now equal to the opposite state of the current led state)
    digitalWrite(LED_PINA, ledStateA); // control LED arccoding to the toggled state

  }

  if(buttonB.isPressed()) {
    ledStateB = !ledStateB; // toggle state of LED
    //(led is now equal to the opposite state of the current led state)
    digitalWrite(LED_PINB, ledStateB); // control LED arccoding to the toggled state

  }  
}