/*
This code assumes you program your ATMEGA328P microcontroller on you Arduino UNO board, then take the chip out and set it up on a breadboard, 
as usual with the 16MHz crystal and 22pF load caps on either side, Vcc, AVcc connected to breadboard +5V bus, GND pins to GND bus, adding a reset
button on reset pin with a pullup resistor, and LOTS of capacitors around the chip Vcc and GND pins to prevent chip randomly glitching.
(1000 μF as close as possible to chip Vcc and GND, another 1000 μF on the breadboard power buses, and a small 4.7 μF capacitor between GND and 
the chip's RESET connection so on power up, it auto resets.)
These bypass caps are actually important, without them the game WILL, NOT IF, WILL glitch and freeze up.
Then connect a button to pin 9 and GND, with an optional 0.1 μF between the button, if it glitches with button bounce.
Connect a HC'SR04 sensor as usual with power pins, then connect trigger to pin 12, and echo to pin 13. (Optional - 
connect a LED to pin 13 to show sensor is active, it will blink when game is running [use 3.3K series resisor])
Connect the SH1106 OLED as usual, with power and the I2C pins to A5 and A4 as usual, then connect a PASSIVE buzzer to 
pin 10 of chip, through a transistor and the flyback diode across the buzzer.
Ensure the sensor is to the left of the display so it plays better directionwise.
Build and layout the components on the breadboards as shown on the character image:
(One small breadboard, no power rails and one large breadboard, with power rails on both sides)
---ENSURE BUZZER IS THE PASSIVE TYPE, USING AN ACTIVE BUZZER WILL CAUSE DAMAGE---
---USE THE RIGHT 16MHz CRYSTAL, DON'T USE ANY OTHER VALUE OR TIMING WILL BE OFF---



    _____________________
    |                   |                THE HANDHELD DISTANCE GAME BUILD ON 2 BREADBOARDS:
    |                   |__________________________________________________________________________________________
    |                   |______________________________________________|_____|_____________________________________|
____|-| ULTRASONIC    --|--                          ____ []BUZZER TRANSISTOR|   16MHZ /\   ()  ()            /\/\ |<-RESISTOR
|   | |  SENSOR       --|--   __________________    /    \             |     |    OSC  \/    ()              ()    |<-POWER LED
|___| |-              --|--  |                  |  (BUZZER)     _____  |     |   ______________________     _____  |
    | |-  () /\/\     --|--  |   SH1106 OLED    |   \____/     |     | |     |  |   ATMEGA328P CHIP    |   |_____| |<-POWER SWITCH
____| |-  POWER       --|--  |   1.3", 128X64   |          [_] | ( ) | |     |  |______________________|   () ()   |<-DECOUPLING CAPS
|   | |-  LED +       --|--  |       I2C        |              |_____| |     |               ()            ______  |
|___| |   RESISTOR    --|--  |__________________|         RESET AND START BUTTONS                         |______| |,_LM7805 REGULATOR
    |-|                 |______________________________________________|_____|_____________________________________|
    |                   |______________________________________________|_____|_____________________________________|
    |                   |ATTACH BREADBOARDS WITH 4-HOLE WIDE        2 ELASTIC BANDS HERE HOLD
    |___________________|FLAT JUMPER WIRES BRIDGING THE BOARDS      A 9V BATTERY UNDERNEATH       () = DECOUPLING CAPS AROUND CHIP VCC AND AVCC PINS

*/

const unsigned char skull [] PROGMEM = { //A skull
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x03, 0xfc, 0x00, 0x03, 
	0xfc, 0x00, 0x66, 0xf6, 0x60, 0x67, 0xfe, 0x60, 0x33, 0xfc, 0xc0, 0x7b, 0xfc, 0xe0, 0x0f, 0xff, 
	0x00, 0x03, 0xfc, 0x00, 0x01, 0xf8, 0x00, 0x00, 0xf0, 0x00, 0x0f, 0x9f, 0x00, 0x0e, 0x07, 0x00, 
	0x0e, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char lives_heart_image [] PROGMEM = { //Heart
  0x6c, 0xfe, 0xfe, 0x7c, 0x7c, 0x38, 0x10
};

const unsigned char sprite [] PROGMEM = { //The basket
  0x00, 0x00, 0x80, 0x01, 0xf8, 0x1f, 0x8f, 0xf1, 0xc0, 0x03, 0xf0, 0x0f, 0xbf, 0xfb, 0xd5, 0x55, 
	0xaa, 0xab, 0xd5, 0x55, 0xea, 0xab, 0x75, 0x56, 0x1e, 0xb8, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00
};

#include <Wire.h>
#include <Adafruit_GFX.h> //Display libraries
#include <Adafruit_SH110X.h>

Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire, -1); //SH1106 OLED used. (wish I had a SSD3306, SH1106's suck)

#define trig_pin 12 //Distance sensor, buzzer (passive) and start button connected here. Button connected to GND on other pin
#define echo_pin 13 //Connect buzzer through a PN2222.
#define buzzer 10
#define start 9

int spritexvalue = 56; //Start character in the middle of the screen (Character is 8px wide {he eats too much})
int foodyvalue = 0; //Food scrolling down screen
int foodxvalue = 1; //Spawn food at a point at top of screen
float timing = 0.0; //Distance sensor handling
float distance = 0.0; //Distance sensor handling
int distanceRounded = 0; //Distance sensor handling
int score = 0; //Player's score
int lives = 3; //Lives
int wave = 1; //Level (wave used as display only had enough space for 4 more letters where this needed to be displayed)
int waveset = 0; //Keep track of where game is
bool pauseRequested = false; //Pause memory

void setup() {
  // put your setup code here, to run once:
  pinMode(start, INPUT_PULLUP); //Get button ready
  pinMode(buzzer, OUTPUT); //Get buzzer ready
  digitalWrite(buzzer, LOW); //Turn it off
  pinMode(echo_pin, INPUT); //Start ultrasonic sensor
  pinMode(trig_pin, OUTPUT);
  display.begin(0x3c, false); //Start I2C data communication with SH1106G OLED display chip
  display.display(); //Display adafruit splashscreen for 3 seconds
  playStartupSound(); //Play start up sound
  delay(3000);
  display.clearDisplay(); //Clear display
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(1);
  display.setCursor(0,0); //Show prompts on how to use game correctly (formatted so println displays it correctly)
  display.println("For best performance,ensure you hold sonaropposite a flat, evenwall, no curtains or doorways. Ensure you have 3M of space oppo-site wall to move.");
  display.setCursor(10, 57);
  display.print("CLICK TO START -->");
  display.display();
  while(digitalRead(9) == HIGH) {delay(1);} //Wait forever until start is pressed
  display.clearDisplay();
  countDown(); //Do the countdown
}

void loop() {

  if (pauseRequested == true) { //If paused, display it and stop game until button is pressed to resume game
    display.clearDisplay();
    tone(buzzer, 2500, 500);
    display.setCursor(10, 0);
    display.setTextSize(3);
    display.print("Paused");
    display.setTextSize(1);
    display.setCursor(0, 24);
    display.print(" Sensor too far from");
    display.setCursor(0, 34);
    display.print("wall or hand detected");
    display.setCursor(5, 44);
    display.print(" directly in front!");
    display.setCursor(20, 56);
    display.print("PUSH TO RESUME");
    display.display();
    while (digitalRead(start) == HIGH) {
      delay(1);
    }
    distanceRounded = 100; //Looks unnessesary but leave it.
  }
  pauseRequested = false; //Reset pause variable

  if (foodyvalue == 1) {
  randomSeed(micros()*analogRead(A3)*analogRead(A2)); //Ensure the place food spawns is completly random
  foodxvalue = random(5, 123); //And food spawns at the right time
  }
  display.fillCircle(foodxvalue, foodyvalue, 3, SH110X_WHITE); //Draw food
  foodyvalue = foodyvalue + wave; //Make it move down the screen
  tone (buzzer, 10000, 10); //Add sound during game play (small clicks)
  if (foodyvalue >= 63) {foodyvalue = 1;} //Respawn food when it gets to bottom

  detectforhit(); //Detect for events
  detectformiss();

  display.drawLine(0, 11, map(waveset, 0, 500, 0, 128), 11, SH110X_WHITE); //Draws the next level bar
  display.drawLine(0, 12, map(waveset, 0, 500, 0, 128), 12, SH110X_WHITE);
  waveset++; //Keeps level up to date

  if (waveset >= 500) { //Level up at right time (after 500 loop cycles = every ~1 minute)
    wave++;
    display.clearDisplay(); //Display level up screen
    tone(buzzer, 4000, 1500);
    display.setCursor(17, 25);
    display.setTextSize(2);
    display.print("LEVEL UP");
    display.drawRect(0, 0, 128, 64, SH110X_WHITE);
    display.display();
    delay(1500);
    display.clearDisplay();
    waveset = 0; //Reset waveset
    foodyvalue = 1; //Reset food
    display.setTextSize(1); //Reset text size (don't delete this)
  }

  triggerSound(); //Trigger distance sensor

  timing = pulseIn(echo_pin, HIGH); //Timing variable is equal to how long the "echo" pulse is high
  distance = ((timing / 29) / 2); //Calculate distance from that time
  distanceRounded = round(distance); //Round off distance
  if (distanceRounded <= 5 || (distanceRounded >= 220 && distanceRounded <= 250)) {pauseRequested = true;} //If sensor detects hand in front or gets out of range, pause the game
  spritexvalue = map(distanceRounded, 10, 210, 2, 126); //Make the distance from 2M in front of sensor move sprite 128 pixels across screen

  //Draw a small triange that moves from left to right as the rotary encoder is turned
  display.drawBitmap((spritexvalue-8), 49, sprite, 16, 16, SH110X_WHITE);
  display.drawRect(0, 0, 128, 64, SH110X_WHITE); //Draw border
  display.setCursor(2, 2);
  display.print("Score:"); //Show score label
  display.setCursor(37, 2);
  char buffer[4]; // 3 digits + null terminator
  sprintf(buffer, "%03d", score); // Format score as 3 digits with leading zeros
  display.print(buffer);
  display.setCursor(85, 2); //Show score and wave
  display.print("Wave:");
  display.setCursor(114, 2);
  display.print(wave);
  displayLives();
  display.display(); 
  delay(1); //Refresh screen with new images but delay reduces flickering
  display.clearDisplay();

  if (lives < 1) { //End game when lives gets to 0
   display.clearDisplay();
   displayYouLose(); //Show game over screen
   while(digitalRead(9) == HIGH) {delay(1);} //Wait forever until start is pressed)
   display.clearDisplay();
   countDown();
   lives = 3; //Reset score and all that.
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
  if ((abs(spritexvalue - foodxvalue) <= 10) && (foodyvalue >= 58)) {//Detect if the spritexvalue is within 16 values of foodxvalue (2x width of sprite)
   score++;
   tone(buzzer, 1000, 200);
   foodyvalue = 64;
  }
}

void detectformiss() {
  if (!(abs(spritexvalue - foodxvalue) <= 10) && (foodyvalue >= 58)) {//Detect if the spritexvalue is within 16 values of foodxvalue (2x width of sprite)
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
  display.setCursor(16, 13); //Shows game over screen
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

void countDown() { //Shows numbers 3-0 in middle of screen, in large font, and beeps every time number changes
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


//Used when displaying Adafruit splash screen
void playStartupSound() { //Plays a little tone at start of game.
  tone(buzzer,587,200);delay(350);
  tone(buzzer,784,250);delay(350);
  tone(buzzer,880,200);delay(350);
  tone(buzzer,1175,300);delay(350);
  tone(buzzer,988,250);delay(350);
  tone(buzzer,784,300);delay(350);
  tone(buzzer,587,400);delay(450);
  noTone(buzzer);
}