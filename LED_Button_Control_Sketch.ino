const int BUTTON = 2; //Pin the button is connected to
const int LED = 9; //Pin the LED is connected to
int BUTTONstate = 0; //Stores the state of the button

void  setup()
{
  pinMode(BUTTON, INPUT_PULLUP); //Configures the button pin to a input with a internal pullup resistor
  pinMode(LED, OUTPUT); //Configures the LED pin to an output
}

void  loop()
{
  BUTTONstate = digitalRead(BUTTON); //Make the BUTTONstate variable equal to the state of the button pin
  if (BUTTONstate == HIGH) //If the BUTTONstate variable is high,
  {
    digitalWrite(LED, LOW); //Turn the LED on
  } 
  else{
    digitalWrite(LED, HIGH); //Else, keep it off
  }
}