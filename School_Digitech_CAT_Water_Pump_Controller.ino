#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int tankPump = 7;
const int riverPump = 4;

#define buttonA 5
#define buttonB 6

const int tankSensor = A2;
const int farmSensor = A1;

const int tankMax = 260;
const int tankMin = 420;
const int farmMin = 560;
const int farmMax = 280;

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, -1);

int tank;
int farm;
int waterLevel;

void setup() {
  // put your setup code here, to run once:
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  display.display();
  delay(3000);
  display.clearDisplay();
  display.display();
  display.setTextColor(WHITE);
  display.setTextSize(1);

  pinMode(tankPump, OUTPUT);
  pinMode(riverPump, OUTPUT);
  digitalWrite(tankPump, LOW);
  digitalWrite(riverPump, LOW);

  pinMode(buttonA, INPUT_PULLUP);
  pinMode(buttonB, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  tank = analogRead(tankSensor);
  farm = analogRead(farmSensor);

  waterLevel = map(tank, tankMin, tankMax, 0, 126);
  
  display.setCursor(35, 46);
  display.print("Water level");
  display.drawRect(0, 54, 128, 10, WHITE);
  display.fillRect(1, 55, 126, 8, BLACK);
  display.fillRect(1, 55, waterLevel, 8, WHITE);
  display.display();
  
  delay(50);

  if (waterLevel < 120) {digitalWrite(riverPump, HIGH);}
  if (waterLevel > 115) {digitalWrite(riverPump, LOW);}
  Serial.println(waterLevel);

  /*if (digitalRead(buttonA) == LOW) {
    digitalWrite(riverPump, HIGH);
  } else {
    digitalWrite(riverPump, LOW);
  }
  if (digitalRead(buttonB) == LOW) {
    digitalWrite(tankPump, HIGH);
  } else {
    digitalWrite(tankPump, LOW);
  }*/
}