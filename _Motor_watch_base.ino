const int speedPin = 9;
const int directionPin1 = 8;
const int directionPin2 = 7;
const int buttonPin = 6; 
bool motorRunning = false;

void setup() {
  pinMode(speedPin, OUTPUT);
  pinMode(directionPin1, OUTPUT);
  pinMode(directionPin2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); 
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {    
    motorRunning = !motorRunning;
    delay(1000);
  }

  if (motorRunning) {
    speedControl();
  } else {
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
