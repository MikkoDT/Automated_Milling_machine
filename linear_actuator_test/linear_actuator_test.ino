// Relay Signal Pins
const int forwardPin2 = 32; 
const int reversePin2 = 30;

// Relay Module Power Control
const int relayPower = 24;

void setup() {
  pinMode(forwardPin2, OUTPUT);
  pinMode(reversePin2, OUTPUT);
  pinMode(relayPower, OUTPUT);

  // Turn ON relay module
  digitalWrite(relayPower, HIGH);
  //delay(500); // wait for relay module to power up

  // Make sure all directions are OFF first
  digitalWrite(forwardPin2, LOW);
  digitalWrite(reversePin2, LOW);

  //delay(500); // Optional

  // Activate forward
 
  //digitalWrite(forwardPin2, HIGH);
  //delay(700);

  digitalWrite(forwardPin2, HIGH);
  delay(5000); // Run time

  // Stop actuator
  digitalWrite(forwardPin2, LOW);
  digitalWrite(reversePin2, LOW);

  //delay(500); // Optional delay before full shutdown

  // Turn OFF relay module power
  digitalWrite(relayPower, LOW);
}

void loop() {
  // nothing
}
