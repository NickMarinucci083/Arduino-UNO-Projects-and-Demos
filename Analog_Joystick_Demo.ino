#define buttonPIN 2 //Pins the x and y of analog joystick is connected to.
#define xPIN A0
#define yPIN A1

int raw_x = 0;
int raw_y = 0;
int x = 0;
int y = 0;

bool push = false;

int direction = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(500000); //Fast baud rate so long prints work nicely
  pinMode(buttonPIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  raw_x = analogRead(xPIN);
  raw_y = analogRead(yPIN);

  if (digitalRead(buttonPIN) == HIGH) {push = false;}
  else {push = true;} //Button pulls pin low when pressed, active low logic

  x = map(raw_x, 0, 1023, -100, 100);
  y = map(raw_y, 0, 1023, -100, 100);

  printValues();

  delay(10);
}

void printValues() {
  Serial.print("X = ");
  Serial.print(x);
  Serial.print(" | ");
  Serial.print("Y = ");
  Serial.print(y);
  Serial.print(" | Pushed = ");

  if (push == true) {Serial.print("Yes");}
  else {Serial.print("No");}

  Serial.print(" | Direction: ");

  if (abs(x) < 30 && abs(y) < 30) { //Maths work to calculate direction
    direction = 0; // center
  }
  else if (x < -30) {
    direction = 1; // left
  }
  else if (x > 30) {
    direction = 2; // right
  }
  else if (y > 30) {
    direction = 3; // up
  }
  else if (y < -30) {
    direction = 4; // down
  }

  if (direction == 2) {Serial.println("Up");}
  else if (direction == 1) {Serial.println("Down");}
  else if (direction == 3) {Serial.println("Left");}
  else if (direction == 4) {Serial.println("Right");}
  else if (direction == 0) {Serial.println("Centered");}
  else {Serial.print("Error");}
}