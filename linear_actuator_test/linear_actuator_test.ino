// Relay Signal Pins
const int forwardPin2 = 30; 
const int reversePin2 = 32;

// Relay Module Power Control
const int relayPower = 24;

void setup() {
  pinMode(forwardPin2, OUTPUT);
  pinMode(reversePin2, OUTPUT);
  pinMode(relayPower, OUTPUT);

  // Turn ON relay module
  digitalWrite(relayPower, HIGH);
  

  // Make sure all directions are OFF first
  digitalWrite(forwardPin2, LOW);
  digitalWrite(reversePin2, LOW);


  digitalWrite(forwardPin2, HIGH);
  delay(10000); // Run time

  // Stop actuator
  digitalWrite(forwardPin2, LOW);
  digitalWrite(reversePin2, LOW);


  // Turn OFF relay module power
  digitalWrite(relayPower, LOW);
}

void loop() {
  // nothing
}
