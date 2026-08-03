/*
Servos work by taking a PWM signal, at 50Hz, (every 20ms), that the high state is high
between 1ms, and 2ms, and map that high time to a angle, etc, high pulse of 1500us will
make servo go to 90 degrees, 1000us will make it 0 degrees, etc.

Example waveform:

.  ______                          ______
. |      |                        |      |
. |      |                        |      |
. |      |                        |      |
._|      |________________________|      |_________________________
.        ^                        ^      ^
.        |________________________|______|
.                     ^               ^
.           20ms 50Hz signal     1-2ms angle signal

*/

#define servoPIN 3

void setup() {
  // put your setup code here, to run once:
  pinMode(servoPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int angle = 0; angle <= 180; angle++) {
    writeToServo(angle);
    delay(5);
  }
  for (int angle = 180; angle >= 0; angle--) {
    writeToServo(angle);
    delay(5);
  }

}

void writeToServo(int angle) {

  int delayPWM = map(angle, 0, 180, 500, 2500);

  digitalWrite(servoPIN, HIGH);
  delayMicroseconds(delayPWM);
  digitalWrite(servoPIN, LOW);
  delayMicroseconds(20000 - delayPWM);

}