#include <LiquidCrystal.h> //Use "Liquid crystal.h" library
#include <ezButton.h>

const int APin= 11; //Set the digital 2 to A pin
const int BPin= 12; //Set the digital 3 to B pin
const int SPin= 13 ;//Set the digital 4 to S pin
unsigned char encoderVal = 0; //Encoder value from 0-255
int direction = LOW; //LOW = Reverse, HIGH = Forward
int speed = 0;

int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7; //rs on to, en on 11, d0 on 0, etc
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //Order of LCD pins clarified with order of pins on previous line

const int fanFoward = 10; //"A" pin of DC fan module connected to pin 10
const int fanReverse = 9; //B" pin of DC fan module connected to pin 9

ezButton button(13); //Rotary encoder button on pin 13

void setup()
{
 pinMode(APin, INPUT);//initialize the A pin as input
 pinMode(BPin, INPUT);//initialize the B pin as input
 pinMode(SPin, INPUT);//initialize the S pin as input
 pinMode (fanFoward, OUTPUT); //Fan pins as a output
 pinMode (fanReverse, OUTPUT);
 button.setDebounceTime(20); //Button debounce time is 20ms
 lcd.begin (16, 2); //Start the 16x2 LCD
 lcd.setCursor (4, 0); //Practicing a start-up routine on LCD
 lcd.print ("ARDUINO");
 lcd.setCursor (1, 1);
 lcd.print("www.adeept.com");
 delay (2000);
 lcd.clear();
 lcd.setCursor (3, 0);
 lcd.print ("Loading...");
 delay (1000);
 lcd.clear();
 lcd.setCursor (0, 0); //Cursor to home position
 lcd.print ("Speed:"); //Print "Speed"
 lcd.setCursor (0, 1); //Cursor to start of second row
 lcd.print ("Direction:"); //Print "Direction"
 lcd.setCursor (8, 0); //Cursor to column 8, first row
 lcd.print ("/10"); //Print "/10"
}


void loop()
{ button.loop(); //Set up the button

 int change = getRotaryEncoder(); //Get the encoder value from "int getRotaryEncoder(void)" function
 encoderVal = encoderVal - change;

 if(button.isPressed()) { //If encoder is pushed down, 
    direction = !direction; //Toggle direction
    encoderVal = 0; //Set encoderVal to 0
    analogWrite (fanFoward, 0); //Turn fan off completely
    analogWrite (fanReverse, 0);
  }
 
 speed = map (encoderVal, 0, 50, 0, 10); //Speed variable is a scaled version of the encoderVal variable
 lcd.setCursor (6, 0); //Set LCD cursor to 6th comumn, first row
 lcd.print (speed); //Print the speed
 
 if (speed <= 9) { //If speed is below or equal to 9, keep that area on the LCD clear
  lcd.setCursor(7, 0); //(If this is not here, LCD will print a 0 and ruin the number)
  lcd.print (" "); //Prints a space to make LCD character blank
 }

 if (encoderVal >= 51) { //Prevent speed going above 10
  encoderVal = 50;
 }

 if (direction == HIGH) { //If direction is high, write the fan speed to pin 10
 analogWrite (fanFoward, (speed*25));
 lcd.setCursor (10, 1); //and print to LCD "Back"
 lcd.print ("Back  ");
 } else {
 analogWrite (fanReverse, (speed*25)); //If direction is LOW, write the fan speed to pin 9
 lcd.setCursor (10, 1); //and print ot LCD "Foward"
 lcd.print ("Foward");
 }
}


int getRotaryEncoder(void) //The rotary encoder reading function that returns the value of encoder as an integer (int)
{
 static int oldA = HIGH; //set the oldA as HIGH
 static int oldB = HIGH; //set the oldB as HIGH
 int result = 0;
 int newA = digitalRead(APin); //read the value of APin to newA
 int newB = digitalRead(BPin); //read the value of BPin to newB
 if (newA != oldA || newB != oldB)//if the value of APin or the BPin has changed
 {
 if (oldA == HIGH && newA == LOW)// something has changed
 {
 result = (oldB * 2 - 1);
 }
 }
 oldA = newA;
 oldB = newB;
 return result;
} 