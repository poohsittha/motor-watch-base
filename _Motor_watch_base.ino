const int speedPin = 9;
const int directionPin1 = 8;
const int directionPin2 = 7;
const int buttonPin = 6; // Assuming the button is connected to pin 2
bool motorRunning = false;

void setup() {
  pinMode(speedPin, OUTPUT);
  pinMode(directionPin1, OUTPUT);
  pinMode(directionPin2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Enable internal pull-up resistor for the button
}

void loop() {
  // Check if the button is pressed
  if (digitalRead(buttonPin) == LOW) {
    // If the button is pressed, toggle the motor state
    motorRunning = !motorRunning;
    // Delay to debounce the button press
    delay(1000);
  }

  // If the motor is running, control its speed
  if (motorRunning) {
    speedControl();
  } else {
    // If the motor is not running, turn it off
    digitalWrite(directionPin1, LOW);
    digitalWrite(directionPin2, LOW);
  }
}

void speedControl() {
  digitalWrite(directionPin1, HIGH);
  digitalWrite(directionPin2, LOW);

  for (int i = 0; i < 2; i++) {
    analogWrite(speedPin, i);
    delay(200);
  }

  for (int i = 2; i >= 0; i--) {
    analogWrite(speedPin, i);
    delay(200);
  }

  digitalWrite(directionPin1, LOW);
  digitalWrite(directionPin2, LOW);
}
