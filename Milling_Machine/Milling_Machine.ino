const int buttonPin = 50;    // Push button connected to GND
const int motorPin = 8;      // Motor relay control pin

// Linear Actuator Pins
const int relayPowerPin = 24; // Powers actuator relays
const int act1ForwardPin = 32;
const int act1ReversePin = 30;
const int act2ForwardPin = 28;
const int act2ReversePin = 26;

// Adjustable durations
unsigned long motorDuration1 = 60UL * 60UL * 1000UL;  // 20 mins for first run
unsigned long motorDuration2 = 10UL * 60UL * 1000UL;  // 20 mins for second run

unsigned long act1ExtendTime = 16UL * 1000UL;         // 10 seconds
unsigned long act2RetractTime = 6UL * 1000UL;         // 6 seconds

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(motorPin, OUTPUT);
  
  pinMode(relayPowerPin, OUTPUT);
  pinMode(act1ForwardPin, OUTPUT);
  pinMode(act1ReversePin, OUTPUT);
  pinMode(act2ForwardPin, OUTPUT);
  pinMode(act2ReversePin, OUTPUT);

  digitalWrite(motorPin, LOW);
  digitalWrite(relayPowerPin, LOW);
  digitalWrite(act1ForwardPin, LOW);
  digitalWrite(act1ReversePin, LOW);
  digitalWrite(act2ForwardPin, LOW);
  digitalWrite(act2ReversePin, LOW);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    delay(200); // Debounce

    // Step 1: Motor runs (1st time)
    digitalWrite(motorPin, HIGH);
    delay(motorDuration1);
    digitalWrite(motorPin, LOW);

    // Step 2: Enable power to relay module
    digitalWrite(relayPowerPin, HIGH);

    // Step 3: Extend Actuator 1 (forward)
    digitalWrite(act1ForwardPin, HIGH);
    delay(act1ExtendTime);
    digitalWrite(act1ForwardPin, LOW);

    delay(500); // Small delay between actuator operations

    // Step 4: Retract Actuator 2 (reverse)
    digitalWrite(act2ReversePin, HIGH);
    delay(act2RetractTime);
    digitalWrite(act2ReversePin, LOW);

    delay(500); // Optional delay before second motor run

    // Step 6: Motor runs again (2nd time)
    digitalWrite(motorPin, HIGH);
    delay(motorDuration2);
    digitalWrite(motorPin, LOW);

    // Step 7: Turn off relay power
    digitalWrite(relayPowerPin, LOW);

    // End of process
    while (true); // Freeze program to avoid re-trigger
  }
}
