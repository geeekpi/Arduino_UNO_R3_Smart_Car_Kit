// Line Tracking Module Pinout
#define LEFT_TRACK_SENSOR A0
#define RIGHT_TRACK_SENSOR A1

// Motor Control Pinout
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

// Threshold for line detection
const int THRESHOLD = 400; // Adjust this value according to your sensor readings

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);

  // Initialize motor control pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // Read sensor values
  int leftSensorValue = analogRead(LEFT_TRACK_SENSOR);
  int rightSensorValue = analogRead(RIGHT_TRACK_SENSOR);

  // Debugging: print sensor values
  Serial.print("Left Sensor: ");
  Serial.print(leftSensorValue);
  Serial.print(" | Right Sensor: ");
  Serial.println(rightSensorValue);

  // Line tracking logic
  if (leftSensorValue < THRESHOLD && rightSensorValue < THRESHOLD) {
    // Both sensors detect the line - move forward
    go();
  } else if (leftSensorValue < THRESHOLD && rightSensorValue >= THRESHOLD) {
    // Left sensor detects the line - turn right
    turnRight();
  } else if (leftSensorValue >= THRESHOLD && rightSensorValue < THRESHOLD) {
    // Right sensor detects the line - turn left
    turnLeft();
  } else {
    // No line detected - stop
    stopCar();
  }
}

// Motor control functions
void go() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

