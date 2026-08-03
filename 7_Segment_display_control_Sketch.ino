const int a = 1; //Segment a connected to pin 1
const int b = 2; //Segment b connected to pin 2
const int c = 3; //Segment c connected to pin 3
const int d = 4; //Segment d connected to pin 4
const int e = 5; //Segment e connected to pin 5
const int f = 6; //Segment f connected to pin 6
const int g = 7; //Segment g connected to pin 7

void setup() {
  // put your setup code here, to run once:
pinMode (a, OUTPUT); //Configures pins to output
pinMode (b, OUTPUT);
pinMode (c, OUTPUT);
pinMode (d, OUTPUT);
pinMode (e, OUTPUT);
pinMode (f, OUTPUT);
pinMode (g, OUTPUT);
digitalWrite (a, LOW); //Makes all segments initially low
digitalWrite (b, LOW);
digitalWrite (c, LOW);
digitalWrite (d, LOW);
digitalWrite (e, LOW);
digitalWrite (f, LOW);
digitalWrite (g, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
display0(); //Display the numbers in order
display1();
display2();
display3();
display4();
display5();
display6();
display7();
display8();
display9();
}

//0 = a,b,c,d,e,f
void display0() {
  digitalWrite (a, HIGH);
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, HIGH);
  digitalWrite (e, HIGH);
  digitalWrite (f, HIGH);
  delay (1000);
  digitalWrite (a, LOW);
  digitalWrite (b, LOW);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  digitalWrite (e, LOW);
  digitalWrite (f, LOW);
}
//1 = b,c
void display1() {
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  delay (1000);
  digitalWrite (b, LOW);
  digitalWrite (c, LOW);
}
//2 = a,b,d,e,g
void display2() {
  digitalWrite (a, HIGH);
  digitalWrite (b, HIGH);
  digitalWrite (d, HIGH);
  digitalWrite (e, HIGH);
  digitalWrite (g, HIGH);
  delay (1000);
  digitalWrite (a, LOW);
  digitalWrite (b, LOW);
  digitalWrite (d, LOW);
  digitalWrite (e, LOW);
  digitalWrite (g, LOW);
}
//3 = a,b,c,d,g
void display3() {
  digitalWrite (a, HIGH);
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, HIGH);
  digitalWrite (g, HIGH);
  delay (1000);
  digitalWrite (a, LOW);
  digitalWrite (b, LOW);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  digitalWrite (g, LOW);
}
//4 = b,c,f,g
void display4() {
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (f, HIGH);
  digitalWrite (g, HIGH);
  delay (1000);
  digitalWrite (b, LOW);
  digitalWrite (c, LOW);
  digitalWrite (f, LOW);
  digitalWrite (g, LOW);
}
//5 = a,c,d,f,g
void display5() {
  digitalWrite (a, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, HIGH);
  digitalWrite (f, HIGH);
  digitalWrite (g, HIGH);
  delay (1000);
  digitalWrite (a, LOW);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  digitalWrite (f, LOW);
  digitalWrite (g, LOW);
}
//6 = a,c,d,e,f,g
void display6() {
  digitalWrite (a, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, HIGH);
  digitalWrite (e, HIGH);
  digitalWrite (f, HIGH);
  digitalWrite (g, HIGH);
  delay (1000);
  digitalWrite (a, LOW);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  digitalWrite (e, LOW);
  digitalWrite (f, LOW);
  digitalWrite (g, LOW);
}
//7 = a,b,c
void display7() {
  digitalWrite (a, HIGH);
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  delay (1000);
  digitalWrite (a, LOW);
  digitalWrite (b, LOW);
  digitalWrite (c, LOW);
}
//8 = a,b,c,d,e,f,g
void display8() {
  digitalWrite (a, HIGH);
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, HIGH);
  digitalWrite (e, HIGH);
  digitalWrite (f, HIGH);
  digitalWrite (g, HIGH);
  delay (1000);
  digitalWrite (a, LOW);
  digitalWrite (b, LOW);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  digitalWrite (e, LOW);
  digitalWrite (f, LOW);
  digitalWrite (g, LOW);
}
//9 = a,b,e,d,f,g
void display9() {
  digitalWrite (a, HIGH);
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, HIGH);
  digitalWrite (f, HIGH);
  digitalWrite (g, HIGH);
  delay (1000);
  digitalWrite (a, LOW);
  digitalWrite (b, LOW);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  digitalWrite (f, LOW);
  digitalWrite (g, LOW);
}