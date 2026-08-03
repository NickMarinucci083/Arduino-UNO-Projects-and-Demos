#include <SPI.h> //Use the SPI communications protocol library

int wiper_value = 0; //Variable to store wiper value and set it to 0 initally
const int CS = 10;

void setup() {
  pinMode(CS, OUTPUT); //CS pin as output
  SPI.begin(); //Start the SPI library and set appropriate pins to output
}

void loop() {

  digitalWrite(CS, LOW); //Pull CS low
  
  for(wiper_value = 0; wiper_value <= 255; wiper_value++) { //For wiper value being 0 to 255, incrementing

    SPI.transfer(0x00); //Transfer the following data to this adress
    SPI.transfer(wiper_value); //The wiper value
    delay(5); //Wait a bit in between.
  }

  for(wiper_value = 255; wiper_value >= 0; wiper_value--) { //For wiper value being 0 to 255, incrementing

    SPI.transfer(0x00); //Transfer the following data to this adress
    SPI.transfer(wiper_value); //The wiper value
    delay(5); //Wait a bit in between.
  }
  digitalWrite(CS, HIGH); //Pull CS High again

}