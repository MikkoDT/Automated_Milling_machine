const int buttonPin = 10;    // Push button
const int motorPin = 8;      // Motor relay control

// Linear actuator control pins
const int relayPower = 24;

const int actuator1Fwd = 32;
const int actuator1Rev = 30;

const int actuator2Fwd = 28;
const int actuator2Rev = 26;

// Timing values
unsigned long runDuration = 20UL * 60UL * 1000UL;  // 20 minutes
unsigned long actuator1Time = 10UL * 1000UL;       // 10 seconds
unsigned long actuator2Time = 3UL * 1000UL;        // 3 seconds

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(motorPin, OUTPUT);

  pinMode(relayPower, OUTPUT);

  pinMode(actuator1Fwd, OUTPUT);
  pinMode(actuator1Rev, OUTPUT);

  pinMode(actuator2Fwd, OUTPUT);
  pinMode(actuator2Rev, OUTPUT);

  // Initialize all OFF
  digitalWrite(motorPin, LOW);
  digitalWrite(relayPower, LOW);

  digitalWrite(actuator1Fwd, LOW);
  digitalWrite(actuator1Rev, LOW);

  digitalWrite(actuator2Fwd, LOW);
  digitalWrite(actuator2Rev, LOW);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    delay(200); // debounce

    // Step 1: Run motor
    digitalWrite(motorPin, HIGH);
    delay(runDuration);
    digitalWrite(motorPin, LOW);

    // Step 2: Enable relay power
    digitalWrite(relayPower, HIGH);

    // Step 3: Linear actuator 1 forward
    digitalWrite(actuator1Fwd, HIGH);
    digitalWrite(actuator1Rev, LOW);
    delay(actuator1Time);
    digitalWrite(actuator1Fwd, LOW);

    // Step 4: Linear actuator 2 reverse
    digitalWrite(actuator2Fwd, LOW);
    digitalWrite(actuator2Rev, HIGH);
    delay(actuator2Time);
    digitalWrite(actuator2Rev, LOW);

    // Done
    while (true); // Halt system after one cycle
  }
}
