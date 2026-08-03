// Rows      //This assumes led anode's are the rows and led cathode's are the columns
#define R1 9
#define R2 8
#define R3 11
#define R4 10
//Columns
#define C1 7
#define C2 6
#define C3 5
#define C4 4
#define C5 3
#define C6 2
#define C7 1
#define C8 0

int Counter = 0;
int delayTime = 1; //Used to keep image multiplexed long enough between scroll cycles and controls scroll speed


void  setup() {
   pinMode(R1, OUTPUT);
   pinMode(R2, OUTPUT);
   pinMode(R3, OUTPUT);
   pinMode(R4, OUTPUT);
   pinMode(C1, OUTPUT);
   pinMode(C2, OUTPUT);
   pinMode(C3, OUTPUT);
   pinMode(C4, OUTPUT);
   pinMode(C5, OUTPUT);
   pinMode(C6, OUTPUT);
   pinMode(C7, OUTPUT);
   pinMode(C8, OUTPUT);

   allLEDSoff();
}


void loop() {
 for (Counter = 0; Counter <=100; Counter++) { //Start left
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R1, HIGH);
 digitalWrite(C1, LOW);
 digitalWrite(C4, LOW);
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R2, HIGH);
 digitalWrite(C1, LOW);
 digitalWrite(C2, LOW);
 digitalWrite(C4, LOW); 
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R3, HIGH);
 digitalWrite(C1, LOW);
 digitalWrite(C3, LOW);
 digitalWrite(C4, LOW);
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R4, HIGH);
 digitalWrite(C1, LOW);
 digitalWrite(C4, LOW);
 }
 allLEDSoff();
 for (Counter = 0; Counter<=100; Counter++) { //scroll columns right
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R1, HIGH);
 digitalWrite(C2, LOW);
 digitalWrite(C5, LOW);
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R2, HIGH);
 digitalWrite(C2, LOW);
 digitalWrite(C3, LOW);
 digitalWrite(C5, LOW); 
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R3, HIGH);
 digitalWrite(C2, LOW);
 digitalWrite(C4, LOW);
 digitalWrite(C5, LOW);
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R4, HIGH);
 digitalWrite(C2, LOW);
 digitalWrite(C5, LOW);
 } 
 allLEDSoff();
 for (Counter = 0; Counter<=100; Counter++) { //Again
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R1, HIGH);
 digitalWrite(C3, LOW);
 digitalWrite(C6, LOW);
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R2, HIGH);
 digitalWrite(C3, LOW);
 digitalWrite(C4, LOW);
 digitalWrite(C6, LOW); 
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R3, HIGH);
 digitalWrite(C3, LOW);
 digitalWrite(C5, LOW);
 digitalWrite(C6, LOW);
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R4, HIGH);
 digitalWrite(C3, LOW);
 digitalWrite(C6, LOW);
 }
 allLEDSoff();
 for (Counter = 0; Counter <= 100; Counter++) { //Again
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R1, HIGH);
 digitalWrite(C4, LOW);
 digitalWrite(C7, LOW);
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R2, HIGH);
 digitalWrite(C4, LOW);
 digitalWrite(C5, LOW);
 digitalWrite(C7, LOW); 
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R3, HIGH);
 digitalWrite(C4, LOW);
 digitalWrite(C6, LOW);
 digitalWrite(C7, LOW);
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R4, HIGH);
 digitalWrite(C4, LOW);
 digitalWrite(C7, LOW);
 }
 allLEDSoff();
 for (Counter = 0; Counter <= 100; Counter++) { //And again
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R1, HIGH);
 digitalWrite(C5, LOW);
 digitalWrite(C8, LOW);
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R2, HIGH);
 digitalWrite(C5, LOW);
 digitalWrite(C6, LOW);
 digitalWrite(C8, LOW); 
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R3, HIGH);
 digitalWrite(C5, LOW);
 digitalWrite(C7, LOW);
 digitalWrite(C8, LOW);
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R4, HIGH);
 digitalWrite(C5, LOW);
 digitalWrite(C8, LOW);
 }
 for (Counter = 0; Counter <=100; Counter++) { //Now scroll columns left
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R1, HIGH);
 digitalWrite(C4, LOW);
 digitalWrite(C7, LOW);
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R2, HIGH);
 digitalWrite(C4, LOW);
 digitalWrite(C5, LOW);
 digitalWrite(C7, LOW); 
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R3, HIGH);
 digitalWrite(C4, LOW);
 digitalWrite(C6, LOW);
 digitalWrite(C7, LOW);
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R4, HIGH);
 digitalWrite(C4, LOW);
 digitalWrite(C7, LOW);
 }
 allLEDSoff();
 for (Counter = 0; Counter<=100; Counter++) { //Again
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R1, HIGH);
 digitalWrite(C3, LOW);
 digitalWrite(C6, LOW);
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R2, HIGH);
 digitalWrite(C3, LOW);
 digitalWrite(C4, LOW);
 digitalWrite(C6, LOW); 
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R3, HIGH);
 digitalWrite(C3, LOW);
 digitalWrite(C5, LOW);
 digitalWrite(C6, LOW);
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R4, HIGH);
 digitalWrite(C3, LOW);
 digitalWrite(C6, LOW);
 } 
 allLEDSoff();
 for (Counter = 0; Counter<=100; Counter++) { //And image is returned back to start
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R1, HIGH);
 digitalWrite(C2, LOW);
 digitalWrite(C5, LOW);
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R2, HIGH);
 digitalWrite(C2, LOW);
 digitalWrite(C3, LOW);
 digitalWrite(C5, LOW); 
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R3, HIGH);
 digitalWrite(C2, LOW);
 digitalWrite(C4, LOW);
 digitalWrite(C5, LOW);
 delay(delayTime);
 allLEDSoff();
 digitalWrite(R4, HIGH);
 digitalWrite(C2, LOW);
 digitalWrite(C5, LOW);
 }
}

void allLEDSoff() { //Turns all leds off
  digitalWrite(R1,LOW);
  digitalWrite(R2,LOW);
  digitalWrite(R3,LOW);
  digitalWrite(R4,LOW);
  digitalWrite(C1,HIGH);
  digitalWrite(C2,HIGH);
  digitalWrite(C3,HIGH);
  digitalWrite(C4,HIGH);
  digitalWrite(C5,HIGH);
  digitalWrite(C6,HIGH);
  digitalWrite(C7,HIGH);
  digitalWrite(C8,HIGH);
}