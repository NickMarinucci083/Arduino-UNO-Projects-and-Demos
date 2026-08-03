const int buttonA = 1;
const int buttonB = 2;
const int buttonC = 3;
const int ledA = 4;
const int ledB = 5;
const int ledC = 6;
const int beeper = 8;
int a = 0;
int b = 0;
int c = 0;

void setup() {
  // put your setup code here, to run once:
 pinMode (buttonA, INPUT_PULLUP);
 pinMode (buttonB, INPUT_PULLUP);
 pinMode (buttonC, INPUT_PULLUP);
 pinMode (ledA, OUTPUT);
 pinMode (ledB, OUTPUT);
 pinMode (ledC, OUTPUT);
 pinMode (beeper, OUTPUT);
 digitalWrite (ledA, LOW);
 digitalWrite (ledB, LOW);
 digitalWrite (ledC, LOW);
 digitalWrite (beeper, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
 int a = digitalRead (buttonA);
 int b = digitalRead (buttonB);
 int c = digitalRead (buttonC);

if (a == LOW) {
    digitalWrite(ledA, HIGH);
    tone (beeper, 438);
 } else {
    digitalWrite(ledA, LOW);
    noTone (beeper);
  }

if (b == LOW) {
    digitalWrite(ledB, HIGH);
    tone (beeper, 793);
 } else {
    digitalWrite(ledB, LOW);
    noTone (beeper);
  }

if (c == LOW) {
    digitalWrite(ledC, HIGH);
    tone (beeper, 2160);
 } else {
    digitalWrite(ledC, LOW);
    noTone (beeper);
  }
}