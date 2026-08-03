#include <Adafruit_GFX.h> //Display libraries
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>
#include <Fonts/FreeSans18pt7b.h> //Font libraries (Memory suckers)
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSans9pt7b.h>

#define WHITE    0xFFFF  // White
#define BLACK    0x0000  // Black
#define GREY     0x0841  // Grey

// Define pins for touchscreen
#define YP A1 //ADC
#define XM A2 //ADC
#define YM 7  //IO
#define XP 6  //IO

// Touchscreen calibration values
#define TS_LEFT 955
#define TS_RT 145
#define TS_TOP 940
#define TS_BOT 180

// Pressure thresholds
#define MINPRESSURE 200
#define MAXPRESSURE 1000

int x; //TS values
int y;

int hours = 12;
int minutes = 0;
int seconds = 0;
int day = 0; //0 = monday, 1 = tuesday, 2 = wednesday, 3 = thursday, 4 = friday, 5 = saturday, 6 = sunday
int date = 1;
int month = 1; //1 = Jan, 2 = Feb, 3 = March, 4 = April, 5 = May, 6 = June, 7 = July, 8 = Aug, 9 = Sept, 10 = Oct, 11 = Nov, 12 = Dec
bool timeMode = false; //false = 24 hour time, true = 12 hour time
//Time keeping adjustment variable - lower if clock falls behind time, raise if clock goes ahead of time
float time = 998.09;

bool spaceMove; //Variables for rest of sketch
bool space_move;
int lastMinute = -1;
int lastDay = -1;
bool nightMode = false; //Display color setting
int nightColor = WHITE;
bool hourset = false;
bool lastNightMode = true;
bool clockRunning = true; //Controls wether clock runs or not
bool exitMenu = false;
int displayHour;
unsigned long previousMicros = 0;

MCUFRIEND_kbv tft;

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

const char* days[] = { //Day display words
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
};

const char* daysShortened[] = {
  "Mon",
  "Tue",
  "Wed",
  "Thur",
  "Fri",
  "Sat",
  "Sun"
};

void setup() {
  analogReference(EXTERNAL); //Connect 5V to AREF pin for touchscreen to work properly
  unsigned int ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1); //Landscape
  tft.fillScreen(BLACK);
  tft.setTextColor(WHITE);
  tft.setFont(&FreeSans18pt7b);
  displayStart(); //Display start screen for 10 seconds
  delay(10000);
  tft.fillScreen(BLACK); //Clear screen
}

void loop() { //A NON-BLOCKING time function is used here, no delay(1000); garbage
  getTouchCoordinates();

  if (x >= 400 && x <= 480) { //If night mode button is pressed, toggle between
    if (y >= 200 && y <= 260) {//making screen dark or light
      nightMode = !nightMode;
    }

    if (y >= 260 && y <= 320) { //If settings pressed, stop the clock and do menu loop
      clockRunning = false;
      displayMenu();
    }
  }

  if (nightMode == true) {tft.setTextColor(GREY); nightColor = GREY;} //If button is pressed, toggle between light and dark screen
  else {tft.setTextColor(WHITE); nightColor = WHITE;}

  unsigned long currentMicros = micros(); //Set currentMicros to the micros() system clock

  if (clockRunning && (currentMicros - previousMicros) >= (time * 1000.0)) { //Timeleeping logic (only done when clockRunning is true)
    previousMicros += (unsigned long)(time * 1000.0); //When clockRunning is false, seconds do not increment

    seconds++; //Increment seconds

    if (seconds >= 60) { //Reset seconds when it gets to 60 and increment minutes
      seconds = 0;
      minutes++;
    }
    if (minutes >= 60) { //Do the same for minutes and increment hours
      minutes = 0;
      hours++;
    }
    if (hours >= 24) { //When hours gets to 24 (time is primarily kept as 24H in this program)
      hours = 0;       //reset it and increment day and date.
      day++;
      date++;
    }
    if (day >= 7) { //When the day gets to 7 (a week) reset it.
      day = 0;
    }

    doMonthLogic(); //Does the individual month logic.

    if (minutes != lastMinute) { //Only update the display when the time changes (every minute)
      displayTime();             //otherwise it makes the display strobe and glitch every times the loop runs
      lastMinute = minutes;
    }

    if (day != lastDay) {
      display_day_and_date();
      lastDay = day;
    }
  }

  if (nightMode != lastNightMode) { //Refresh screen when night mode changes to new display color
    drawButtons();
    displayTime();
    display_day_and_date();
    lastNightMode = nightMode;
  }
}

void displayTime() {
  tft.fillRect(0, 0, 480, 160, BLACK); //Erase the previous time
  tft.setTextColor(nightColor); //Ensure time is written in the right color
  tft.setFont(&FreeSans18pt7b);

  tft.setTextSize(5);
  tft.setCursor(20, 137); //Top half of screen

  displayHour = hours; //Display the time - if 12H is selected, convert 24H time (how time is kept in this program)
  if (timeMode) {      //into 12 hour time and then display that instead
    if (displayHour == 0) displayHour = 12;
    else if (displayHour > 12) displayHour -= 12;
  }

  char timeStr[6]; //Prepare the time string and display it
  sprintf(timeStr, "%02d:%02d", displayHour, minutes);
  tft.print(timeStr);
}

void display_day_and_date() {
  tft.fillRect(0, 160, 385, 160, BLACK);
  tft.setTextColor(nightColor);
  tft.setFont(&FreeSans18pt7b); //Set appropriate color, font and position

  tft.setCursor(10, 220);
  tft.setTextSize(2);
  tft.print(days[day]); //Show the actual word day from the days[] array, not a number from 1-7

  tft.setCursor(10, 300);
  tft.print(date); //Then print the date and month, with a "/" in the middle
  tft.print("/");
  tft.print(month);
}

void drawButtons() {
  tft.fillRect(385, 199, 95, 60, nightColor); //Draws the "settings" "night mode" buttons
  tft.drawRect(390, 204, 85, 50, BLACK);

  tft.fillRect(385, 259, 95, 60, nightColor);
  tft.drawRect(390, 264, 85, 50, BLACK);

  tft.setTextSize(NULL);
  tft.setFont(&FreeSans12pt7b); //Draws the text
  tft.setTextColor(BLACK);
  tft.setCursor(404, 225);
  tft.print("Night");
  tft.setCursor(402, 246);
  tft.print("mode");
  tft.setCursor(413, 287);
  tft.print("Set");
  tft.setCursor(413, 308);
  tft.print("info");
}

void doMonthLogic() {
  //Resets the day and increments the month on the right month
  if ((month == 1 || month == 3 || month == 5 || month == 7 || //For 31 day months
     month == 8 || month == 10) && date > 31) {
      date = 1;
      month++;
  }
  else if ((month == 4 || month == 6 || month == 9 || month == 11) && date > 30) { //For 30 day months
    date = 1;
    month++;
  }
  else if (month == 2 && date > 28) { //For febuary (28 days, no leap year adjustment)
    date = 1;
    month++;
  }
  else if (month == 12 && date > 31) { //When it gets to december 31, reset back to january
    date = 1;
    month = 1;
  }
}

void getTouchCoordinates() {
  TSPoint p = ts.getPoint(); //Get coordinates

  pinMode(XM, OUTPUT); //Restore pins back to output
  pinMode(YP, OUTPUT);

  x = map(p.y, TS_LEFT, TS_RT, 0, 480);
  y = map(p.x, TS_BOT, TS_TOP, 0, 320);
}

void displayMenu() {
  tft.fillScreen(BLACK); //Clear screen

  tft.setFont(&FreeSans9pt7b); //Display instructions
  tft.setTextSize(NULL);
  tft.setCursor(320, 35);
  tft.print("Input time in 24H");

  tft.setFont(&FreeSans12pt7b); //Display settings
  tft.setTextSize(2);
  tft.setCursor(120, 40);
  tft.print("Settings");

  tft.setCursor(20, 100); //Print the time
  tft.print("Time: ");
  char buffer[6];
  sprintf(buffer, "%02d:%02d", hours, minutes);
  tft.print(buffer);

  tft.setCursor(20, 160); //Print the date and month
  tft.print("Date: ");
  tft.print(date);
  tft.print("/");
  tft.print(month);

  tft.setCursor(20, 220); //Print the worded day
  tft.print("Day: ");
  tft.print(daysShortened[day]);

  tft.setCursor(20, 280); //Print the time mode (12H or 24H) in 0 or 1 display
  tft.print("Format: ");
  tft.print(timeMode);
  
  tft.setFont(&FreeSans9pt7b); //Show that 0 means 24H time and 1 means 12H time
  tft.setTextSize(NULL);
  tft.setCursor(90, 310);
  tft.print("0 = 24 Hour time, 1 = 12 Hour time");

  tft.setCursor(380, 55); //Show that the buttons are touchscreen activated
  tft.setFont(NULL);
  tft.setTextSize(2);
  tft.print("Touch");
  tft.setTextSize(5);

  tft.setCursor(350, 70); //Display the increment and decrement buttons
  tft.print("+  -");
  tft.setCursor(350, 130);
  tft.print("+  -");
  tft.setCursor(350, 190);
  tft.print("+  -");
  tft.setCursor(350, 250);
  tft.print("+  -");

  tft.fillRect(0, 0, 100, 50, nightColor); //Show a "done/exit" button to leave the menu
  tft.setCursor(10, 30);
  tft.setTextSize(NULL);
  tft.setFont(&FreeSans18pt7b);
  tft.setTextColor(BLACK);
  tft.print("Done");

  tft.setFont(&FreeSans12pt7b); //Restore size, font and color settings
  tft.setTextSize(2);
  tft.setTextColor(nightColor);

  for (;;) { //enter a mini loop for the menu code
    getTouchCoordinates(); //The mini loop uses the touchscreen

    if (x >= 0 && x <= 100) { //Done button
      if (y <= 50 && y >= 0) {
        tft.fillScreen(BLACK); //Reset screen
        clockRunning = true; //Start the clock running again
        previousMicros = micros(); //Stop time from incrementing automatically when exiting menu after being in it for more than a minute
        displayTime(); //Redraw the time, date and day
        display_day_and_date();
        drawButtons();
        return; //Get out of the mini loop and go back to running the main loop of the clock running
      }
    }

    if(x >= 350 && x <= 370) { //Time increment
      if (y >= 70 && y <= 90) {
        tft.fillRect(150, 55, 135, 60, BLACK); //Erase previous time
        minutes++;

        if (minutes >= 60) { //Minute logic
        minutes = 0;
        hours++;
        }
        if (hours >= 24) {
        hours = 0;
        }
        
        tft.setCursor(20, 100); //Redraw updated time
        tft.print("Time: ");
        char buffer[6];
        sprintf(buffer, "%02d:%02d", hours, minutes);
        tft.print(buffer);
        delay(50);
      }

      if (y >= 130 && y <= 150) { //Date increment
        tft.fillRect(140, 115, 135, 60, BLACK); //Erase previous date
        date++;

        doMonthLogic(); //Peform the month logic

        tft.setCursor(20, 160); //Redraw date
        tft.print("Date: ");
        tft.print(date);
        tft.print("/");
        tft.print(month);
        delay(50);
      }

      if (y >= 190 && y <= 210) { //Day increment
        tft.fillRect(125, 175, 120, 60, BLACK); //Erase previous day
        day++;
        if (day >= 7) {day = 0;} //Day logic
        tft.setCursor(20, 220); //Redraw updated day
        tft.print("Day: ");
        tft.print(daysShortened[day]); //Worded day, not a number
        delay(50);
      }

      if (y >= 250 && y <= 280) { //Format increment
        tft.fillRect(190, 235, 50, 60, BLACK); //Erae previous number
        timeMode = true; //Set time mode to 12H
        tft.setCursor(20, 280); //Redraw updated format
        tft.print("Format: ");
        tft.print(timeMode);
        delay(50);
      }
    }

    if(x >= 440 && x <= 460) { //Time decrement
      if (y >= 70 && y <= 90) {
        tft.fillRect(150, 55, 135, 60, BLACK); //Erase previous time
        minutes--;
        
        if (minutes < 0) { //Minute logic
          minutes = 59;
          hours--;
        }
        if (hours >= 24) {
        hours = 0;
        }
      
        tft.setCursor(20, 100); //Redraw updated time
        tft.print("Time: ");
        char buffer[6];
        sprintf(buffer, "%02d:%02d", hours, minutes);
        tft.print(buffer);
        delay(50);
      }
    }

    if(x >= 440 && x <= 460) { //Date decrement
      if (y >= 130 && y <= 150) {
        tft.fillRect(140, 115, 135, 60, BLACK); //Erase previous date
        date--;

        doMonthLogic(); //Month logic
        if (date < 1) {date = 1;} //Prevent day from going to negative numbers

        tft.setCursor(20, 160); //Redraw updated date
        tft.print("Date: ");
        tft.print(date);
        tft.print("/");
        tft.print(month);
        delay(50);
      }

      if (y >= 190 && y <= 210) { //Day decrement
        tft.fillRect(125, 175, 120, 60, BLACK); //Erase previous day
        day--;
        if (day < 0) {day = 6;} //Prevent day from going into negative numbers
        tft.setCursor(20, 220); //Redraw updated day
        tft.print("Day: ");
        tft.print(daysShortened[day]);
        delay(50);
      }

      if (y >= 250 && y <= 270) { //Time mode decrement
        tft.fillRect(190, 235, 50, 60, BLACK); //Erase previous format
        timeMode = false; //Set format to 24H time
        tft.setCursor(20, 280); //Redraw updated format
        tft.print("Format: ");
        tft.print(timeMode);
        delay(50);
      }
    }
  }
}

void displayStart() {
  tft.setFont(&FreeSans18pt7b); //Displays "Arduino", "Adeept + www.adeept.com" and the code libraries
  tft.setTextSize(3);           //(Adafruit GFX, MCUFRIEND and Adafruit Touchscreen) as credits
  tft.setCursor(55, 90);
  tft.print("Arduino");
  tft.setTextSize(NULL);
  tft.setCursor(100, 200);
  tft.print("www.adeept.com");
  tft.setCursor(180, 150);
  tft.print("Adeept");

  tft.setFont(&FreeSans9pt7b); //Displays a bit of info about 3.5" TFT LCD shield
  tft.setCursor(30, 240);
  tft.print("3.5'' TFT LCD display with intergrated touch panel");

  tft.setCursor(28, 270);
  tft.print("MCUFRIEND, Adafruit GFX, Adafruit Touchscreen");
  tft.setCursor(25, 300);
  tft.print("Developed 10/11/2025, updates no longer avaliable");
}