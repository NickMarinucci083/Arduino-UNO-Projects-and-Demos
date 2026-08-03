//Reads the internal temp sensor inside the core of the CPU in the ATMeGA328P IC

#include<Adafruit_GFX.h>
#include<Adafruit_SH110X.h>
#include<Wire.h>

Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire, -1);

void setup() {
  Serial.begin(9600);

  display.begin(0x3c, true); //Start I2C data communication with SH1106G OLED display chip
  display.display(); //Display adafruit splashscreen
  delay(1000);
  display.clearDisplay(); //Clear display

  display.setTextSize(7);
  display.setTextColor(SH110X_WHITE);
}

void loop() {
  int reading = readInternalTempADC();
  Serial.print("Core CPU temp: (raw value)");
  Serial.println(reading);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print(reading);
  display.display();

  delay(500);
}

int readInternalTempADC() {
  // Returns raw ADC value of internal temperature sensor (0–1023)
  // Select internal temperature sensor and 1.1V reference
  ADMUX = _BV(REFS1) | _BV(REFS0) | _BV(MUX3);  
  delay(5);               // wait for voltage reference to stabilize
  ADCSRA |= _BV(ADSC);    // start conversion
  while (ADCSRA & _BV(ADSC));  // wait until conversion finishes
  return ADC;             // raw ADC value (0-1023)
}