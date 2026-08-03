const int A = 10;
const int B = 11;
int speed = 0;

void setup() {
  // put your setup code here, to run once:
 pinMode (A, OUTPUT);
 pinMode (B, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 for(speed=0;speed<=255;speed++)
 {
 analogWrite(A, speed);
 delay(15);
 }

 for(speed=255;speed>=0;speed--)
 {
 analogWrite(B, speed);
 delay(15);
 }

 for(speed=0;speed<=255;speed++)
 {
 analogWrite(B, speed);
 delay(15);
 }

 for(speed=255;speed>=0;speed--)
 {
 analogWrite(A, speed);
 delay(15);
 }
}
