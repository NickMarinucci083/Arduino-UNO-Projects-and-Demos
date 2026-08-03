#include <Servo.h>

int APin= 2;
int BPin= 3;
int SPin= 4 ;
int encoderVal = 90;
Servo myservo;

void setup()
{
 pinMode(APin, INPUT);
 pinMode(BPin, INPUT);
 pinMode(SPin, INPUT);
 myservo.attach(6);
}
void loop()
{
 int change = getRotaryEncoder();
 encoderVal = encoderVal - change;
 if(digitalRead(SPin) == LOW)
 {
 encoderVal = 90; //Put what you want here when the encoder is pushed down
 }
 myservo.write(encoderVal); //The value of the encoder
}
int getRotaryEncoder(void)
{
 static int oldA = HIGH;
 static int oldB = HIGH;
 int result = 0;
 int newA = digitalRead(APin);
 int newB = digitalRead(BPin);
 if (newA != oldA || newB != oldB)
 {
 if (oldA == HIGH && newA == LOW)
 {
 result = (oldB * 2 - 1);
 }
 }
 oldA = newA;
 oldB = newB;
 return result;
} 