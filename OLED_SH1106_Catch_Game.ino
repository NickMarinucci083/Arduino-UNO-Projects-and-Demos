const unsigned char skull [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x03, 0xfc, 0x00, 0x03, 
	0xfc, 0x00, 0x66, 0xf6, 0x60, 0x67, 0xfe, 0x60, 0x33, 0xfc, 0xc0, 0x7b, 0xfc, 0xe0, 0x0f, 0xff, 
	0x00, 0x03, 0xfc, 0x00, 0x01, 0xf8, 0x00, 0x00, 0xf0, 0x00, 0x0f, 0x9f, 0x00, 0x0e, 0x07, 0x00, 
	0x0e, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char lives_heart_image [] PROGMEM = {
  0x6c, 0xfe, 0xfe, 0x7c, 0x7c, 0x38, 0x10
};

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include<ezButton.h>

Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire, -1);

#define trig_pin 12
#define echo_pin 13
#define buzzer 10
ezButton play(8);

int spritexvalue = 56; //Start character in the middle of the screen (Character is 8px wide {he eats too much})
int foodyvalue = 0;
int foodxvalue = 1;
float timing = 0.0;
float distance = 0.0;
int distanceRounded = 0;
int score = 0;
int lives = 3;
int wave = 1;
int waveset = 0;
bool isPaused = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  pinMode(echo_pin, INPUT);
  pinMode(trig_pin, OUTPUT);
  play.setDebounceTime(50);
  display.begin(0x3c, false); //Start I2C data communication with SH1106G OLED display chip (no charge pump on the SH1106)
  display.display();
  delay(3000);
  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("Hold sensor across a wall and move left toright to control youravatar on screen.");
  display.setCursor(0, 32);
  display.println("Collect fruit as it  drops, the game gets harder as you play.");
  display.setCursor(13, 57);
  display.print("CLICK TO START!");
  display.display();
  while(digitalRead(9) == HIGH) {delay(1);} //Wait forever until start is pressed
  display.clearDisplay();
  countDown();
}

void loop() { play.loop();

  if (foodyvalue == 1) {
  randomSeed(micros()*analogRead(A3)*analogRead(A2)); //Ensure the place food spawns is completly random
  foodxvalue = random(5, 123); //And food spawns at the right time
  }
  display.fillRect(foodxvalue, foodyvalue, 5, 5, SH110X_WHITE); //Draw food
  foodyvalue = foodyvalue + wave; //Make it move down the screen
  tone (buzzer, 10000, 10);
  if (foodyvalue >= 63) {foodyvalue = 1;}

  detectforhit();
  detectformiss();

  waveset++;
  if (waveset >= 500) {
    wave++;
    display.clearDisplay();
    tone(buzzer, 4000, 1500);
    display.setCursor(17, 25);
    display.setTextSize(2);
    display.print("LEVEL UP");
    display.drawRect(0, 0, 128, 64, SH110X_WHITE);
    display.display();
    delay(1500);
    display.clearDisplay();
    waveset = 0;
    foodyvalue = 1;
    display.setTextSize(1);
  }

  triggerSound();

  timing = pulseIn(echo_pin, HIGH); //Timing variable is equal to how long the "echo" pulse is high
  distance = ((timing / 29) / 2); //Calculate distance from that time
  distanceRounded = round(distance); //Round off distance
  spritexvalue = map(distanceRounded, 5, 205, 2, 126); //Make the distance from 2M in front of sensor move sprite 128 pixels across screen

  //Draw a small triange that moves from left to right as the rotary encoder is turned
  display.fillTriangle((spritexvalue-8), 63, spritexvalue, 50, (spritexvalue+8), 63, SH110X_WHITE);
  display.drawRect(0, 0, 128, 64, SH110X_WHITE); //Draw border
  display.setCursor(2, 2);
  display.print("Score:"); //Show score label
  display.setCursor(37, 2);
  char buffer[4];                  // 3 digits + null terminator
  sprintf(buffer, "%03d", score);  // Format score as 3 digits with leading zeros
  display.print(buffer);
  display.setCursor(85, 2);
  display.print("Wave:");
  display.setCursor(114, 2);
  display.print(wave);
  displayLives();
  display.display(); 
  delay(1);//Refresh screen with new images
  display.clearDisplay();

  if (lives < 1) {
   display.clearDisplay();
   displayYouLose();
   while(digitalRead(9) == HIGH) {delay(1);} //Wait forever until start is pressed)
   display.clearDisplay();
   countDown();
  lives = 3;
  score = 0;
  wave = 1;
  waveset = 0;
  } //Life death function end
} //Main loop end


//Game functions
void triggerSound() {
  digitalWrite (trig_pin, HIGH);
  delay(2);
  digitalWrite (trig_pin, LOW); //Still works slow enough for HC-SR04 sensor to pick up trigger
}

void detectforhit() {
  if ((abs(spritexvalue - foodxvalue) <= 14) && (foodyvalue >= 52)) {//Detect if the spritexvalue is within 16 values of foodxvalue (2x width of sprite)
   score++;
   tone(buzzer, 1000, 200);
   foodyvalue = 64;
  }
}

void detectformiss() {
  if (!(abs(spritexvalue - foodxvalue) <= 14) && (foodyvalue >= 52)) {//Detect if the spritexvalue is within 16 values of foodxvalue (2x width of sprite)
   lives--;
   tone(buzzer, 100, 1000);
   delay(200);
   foodyvalue = 64;
  }
}

void displayLives() {
  if (lives == 3) { //Converts lives value into a graphical image
    display.drawBitmap(56, 2, lives_heart_image, 7, 7, SH110X_WHITE);
    display.drawBitmap(66, 2, lives_heart_image, 7, 7, SH110X_WHITE);
    display.drawBitmap(76, 2, lives_heart_image, 7, 7, SH110X_WHITE);
    display.display();
  }
  if (lives == 2) {
    display.drawBitmap(56, 2, lives_heart_image, 7, 7, SH110X_WHITE);
    display.drawBitmap(66, 2, lives_heart_image, 7, 7, SH110X_WHITE);
    display.display();
  }
  if (lives == 1) {
    display.drawBitmap(56, 2, lives_heart_image, 7, 7, SH110X_WHITE);
    display.display();
  }
}

void displayYouLose() {
  display.setCursor(16, 13);
  display.setTextSize(2);
  display.print("YOU LOSE");
  display.setCursor(15, 33);
  display.setTextSize(1);
  display.print("CLICK TO RESTART");
  display.setTextSize(1);
  display.setCursor(40, 44);
  display.print("Score ");
  display.print(score);
  display.setCursor(40, 54);
  display.print("Wave  ");
  display.print(wave);
  display.drawBitmap(0, 0, skull, 20, 20, SH110X_WHITE);
  display.drawBitmap(108, 0, skull, 20, 20, SH110X_WHITE);
  display.drawBitmap(0, 44, skull, 20, 20, SH110X_WHITE);
  display.drawBitmap(108, 44, skull, 20, 20, SH110X_WHITE);
  display.display();
}

void countDown() {
  display.setTextSize(8);
  for (int countdown = 3; countdown >= 0; countdown--){
  display.setCursor(45, 3);
  display.print(countdown);
  tone(buzzer, 3500, 100);
  display.display();
  delay(1000);
  display.clearDisplay();
  }
  display.setTextSize(1);
}

void gamePaused() {
  display.setTextSize(3);
  display.setCursor(10, 5);
  display.print("Paused");
  display.setTextSize(1);
  display.setCursor(0, 35);
  display.println("Game will resume whensensor is back in    range of 2M");
}