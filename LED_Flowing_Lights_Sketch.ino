char ledPins; //Where the 8 LED's are connected (1-8)
int analogPin = A0; //Names the analogPin 0 to "analogPin"
int val = 0; // Creates a new variable called "val" and sets it to 0

void setup() {
  // put your setup code here, to run once:
for(ledPins=1;ledPins<=8;ledPins++) { //For ledPins 1-8, incrementing, 
  pinMode (ledPins, OUTPUT); //Configure them as output
  digitalWrite (ledPins, LOW); //And make them low initially.
  }
}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(analogPin); //Make the value "val" equal to the analogPin
for(ledPins=1;ledPins<=8;ledPins++) { //For the Led's 1-8, incrementing
  digitalWrite (ledPins, HIGH); //Make them high
  delay (val/5); //Wait for as long as the "val" variable divided by 5
  }
val = analogRead(analogPin); //Make the value "val" equal to the analogPin
for(ledPins=1;ledPins<=8;ledPins++) { //For the Led's 1-8, incrementing
  digitalWrite (ledPins, LOW); //Make them low
  delay (val/5); //Wait for as long as the "val" variable divided by 5
  }
}