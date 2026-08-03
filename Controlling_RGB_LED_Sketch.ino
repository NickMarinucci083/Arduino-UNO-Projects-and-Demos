int redPin = 11; //Red connected to digital pin 11
int greenPin = 10; //Red connected to digital pin 10
int bluePin = 9; //Red connected to digital pin 9
void setup()
{
 pinMode(redPin, OUTPUT); //Red as otput
 pinMode(greenPin, OUTPUT); //Green as output
 pinMode(bluePin, OUTPUT); //Blue as output
}
void loop()
{
 color (255, 0, 0); //Red
 delay (1000); //Wait one second
 color (0,255, 0); //Green
 delay (1000); //Wait one second
 color (0, 0, 255); //Blue
 delay (1000); //Wait one second
 color(255,255,0); //Yellow
 delay(1000); //Wait one second
 color(0,255,255); //Cyan
 delay(1000); //Wait one second
 color(255,0,255); //Magenta
 delay(1000); //Wait one second
 color (255,255,255); //White
 delay(1000); //Wait one second
 color(0,0,0); //Off
 delay(2000); //Wait one second
}

void color (int red, int green, int blue) //1st numeral red integer, 2nd numeral as green integer and 3rd numeral as blue integer
{
 analogWrite (redPin, 255-red); //analogwrite red to red integer
 analogWrite (greenPin, 255-green); //analogwrite green to green integer
 analogWrite (bluePin, 255-blue); //analogwrite blue to blue integer
} 