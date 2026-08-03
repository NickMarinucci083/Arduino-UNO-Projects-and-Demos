/* A relay is connected to pin 8 of the Arduino (Active low relay module) and relay toggles on and off
when correct password is entered in the serial monitor. Incorrect passwards are counted and entering
the wrong password multiple times locks you out for 10 minutes*/

String user_input; //Use string to store a string of letters
String password = "ATMEGA328P"; //Put your custom password here (Capital sensitive)
const int relay = 8; //Active low relay module
int relayState = HIGH;
int wrong_password_count = 0; //Count how many times a incorrect password has been entered

void setup() {
  Serial.begin(4800); //Start serial monitor
  Serial.println("Enter password");
  pinMode (relay, OUTPUT);
  digitalWrite (relay, HIGH); //Active low relay module
}

void loop() {
  if (wrong_password_count == 5) { //If 5 incorrect passwords are counted, 
    Serial.println(); //Enter
    Serial.println("You have entered incorrect passwords too many times, and you are locked out for 20 minutes");
    delay (1200000); //Wait 20 minutes
    Serial.end(); //Stop serial communication
    Serial.begin(4800); //Restart serial communication
    Serial.println("Lockout ended");
    wrong_password_count = 0;
    }

if (Serial.available()) { //Only run if serial buffer isn't overloaded
    
  user_input = Serial.readStringUntil('\n'); // Read until new line

  if (user_input == password) { //If correct password is entered
      wrong_password_count = 0; //Reset wrong password counter
      Serial.print ("Correct password entered, ");
      relayState = !relayState; //Toggle relay
      digitalWrite(relay, relayState);

    if (relayState == HIGH) {
        Serial.println("relay deactivated");
    } else {
        Serial.println ("relay activated");
      }
}  
    else {
    Serial.println ("Incorrect, please try again"); //Otherwise, tell user to try again and
    wrong_password_count = (wrong_password_count + 1); //increment the incorrect password count
  }
}
}