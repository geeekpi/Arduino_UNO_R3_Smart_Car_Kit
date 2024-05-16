//DRV8833 Pinout
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

//Ultrasonic sensor
const int trigPin = 6;
const int echoPin = 7;
float duration, distance;

// LED
const int led = 13;

// Line Tracking sensor
#define LFSensor_1 A0
#define LFSensor_2 A1

int sensor[2] = { 0, 0 };


void read_sensor_values() {

  sensor[0] = digitalRead(LFSensor_1);
  sensor[1] = digitalRead(LFSensor_2);
  // Serial.println(sensor[0] +  sensor[1]);
}

void auto_tracking() {
  read_sensor_values();
  if ((sensor[0] == LOW) && (sensor[1] == HIGH)) {
    turnright();
    // delayMicroseconds(5);
  } else if ((sensor[0] == HIGH) && (sensor[1] == LOW)) {
    turnleft();
    // delayMicroseconds(5);
  } else if ((sensor[0] == LOW) && (sensor[1] == LOW)) {
    go();
    // delayMicroseconds(5);
  } else if ((sensor[0] == HIGH) && (sensor[1] == HIGH)) {
    back();
    // delayMicroseconds(5);
  }
}

// Android APP coding
// #define SPINCW '6'
// #define SPINCCW '5'
// #define RIGHT '4'
// #define LEFT '3'
// #define BACK '2'
// #define GO '1'
// #define STOP '0'


// functions
//  go back
void back() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// go front
void go() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// turn left
void turnleft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// turn right
void turnright() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// spinning in clockwise.
void spinCW() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// spinning in counter clockwise.
void spinCCW() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void initCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// stop the car
void stopCar() {
  initCar();
}

float get_distance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2;
  return distance;
}

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(LFSensor_1, INPUT);
  pinMode(LFSensor_2, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  initCar();
}


void loop() {
  // Serial.print("Currnet DISTANCE: ");
  distance = get_distance();
  // Serial.println(distance);
  if (distance > 25) {
    auto_tracking();
  } else if (distance < 15) {
    back();
    // auto_tracking();
  }
  delay(20);
}