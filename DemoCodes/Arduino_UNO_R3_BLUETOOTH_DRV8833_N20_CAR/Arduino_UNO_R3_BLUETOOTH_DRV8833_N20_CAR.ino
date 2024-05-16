//DRV8833 Pinout
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

// // Ultrasonic sensor
// const int trigPin = 10;
// const int echoPin = 9;
// float duration, distance;

const int led_LF = 2;
const int led_RF = A2;
const int led_LB = 12;
const int led_RB = 11;

// LEFT tracking module
// const int left_Track = A0;
// const int right_Track = A1;

// Android APP coding
#define SPINCW '6'
#define SPINCCW '5'
#define RIGHT '4'
#define LEFT '3'
#define BACK '2'
#define GO '1'
#define STOP '0'

//  turn left
void turnleft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// turn right
void turnright() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// go ahead
void go() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// go back
void back() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// spinning in counter clockwise.
void spinCCW() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// spinning in clockwise.
void spinCW() {
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

// float get_distance() {
//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);

//   duration = pulseIn(echoPin, HIGH);
//   distance = (duration * 0.034) / 2;
//   return distance;
// }


void setup() {
  Serial.begin(9600);
  // Serial.println("Init ultrasonic sensor...");
  // pinMode(trigPin, OUTPUT);
  // pinMode(echoPin, INPUT);
  // delay(50);
  Serial.println("Init ultrasonic sensor...OK!");
  Serial.println("Init DRV8833 driver...");
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  delay(50);
  Serial.println("Init DRV8833 driver...OK!");
  Serial.println("Init LED...");
  pinMode(led_LF, OUTPUT);
  pinMode(led_RF, OUTPUT);
  pinMode(led_LB, OUTPUT);
  pinMode(led_RB, OUTPUT);

  delay(50);
  Serial.println("Init LED...OK!");
  Serial.println("Init Car functions...");
  initCar();
  delay(50);
  digitalWrite(led_LF, HIGH);
  digitalWrite(led_RF, HIGH);
  digitalWrite(led_LB, HIGH);
  digitalWrite(led_RB, HIGH);
  delay(1000);
  digitalWrite(led_LF, LOW);
  digitalWrite(led_RF, LOW);
  digitalWrite(led_LB, LOW);
  digitalWrite(led_RB, LOW);

  Serial.println("Car initializing finished!!!.");
}

char ch;

void loop() {
  // Serial.print("Currnet DISTANCE: ");
  // Serial.println(get_distance());
  if (Serial.available() > 0) {
    ch = Serial.read();

    if (ch == GO) {
      digitalWrite(led_LF, LOW);
      digitalWrite(led_RF, LOW);
      digitalWrite(led_RF, LOW);
      digitalWrite(led_RB, LOW);
      go();
      digitalWrite(led_LF, HIGH);
      digitalWrite(led_RF, HIGH);
    } else if (ch == BACK) {
      digitalWrite(led_LF, LOW);
      digitalWrite(led_RF, LOW);
      digitalWrite(led_RF, LOW);
      digitalWrite(led_RB, LOW);
      back();
      digitalWrite(led_LB, HIGH);
      digitalWrite(led_RB, HIGH);

    } else if (ch == RIGHT) {
      digitalWrite(led_LF, LOW);
      digitalWrite(led_RF, LOW);
      digitalWrite(led_RF, LOW);
      digitalWrite(led_RB, LOW);
      turnright();
      digitalWrite(led_RF, HIGH);
      digitalWrite(led_RB, HIGH);

    } else if (ch == LEFT) {
      digitalWrite(led_LF, LOW);
      digitalWrite(led_RF, LOW);
      digitalWrite(led_RF, LOW);
      digitalWrite(led_RB, LOW);
      turnleft();
      digitalWrite(led_LF, HIGH);
      digitalWrite(led_LB, HIGH);

    } else if (ch == STOP) {
      digitalWrite(led_LF, LOW);
      digitalWrite(led_RF, LOW);
      digitalWrite(led_RF, LOW);
      digitalWrite(led_RB, LOW);
      stopCar();
      digitalWrite(led_LF, LOW);
      digitalWrite(led_LB, LOW);
      digitalWrite(led_RF, LOW);
      digitalWrite(led_RB, LOW);

    } else if (ch == SPINCW) {
      digitalWrite(led_LF, LOW);
      digitalWrite(led_RF, LOW);
      digitalWrite(led_RF, LOW);
      digitalWrite(led_RB, LOW);
      spinCW();
      digitalWrite(led_LF, HIGH);
      digitalWrite(led_RB, HIGH);
    } else if (ch == SPINCCW) {
      digitalWrite(led_LF, LOW);
      digitalWrite(led_RF, LOW);
      digitalWrite(led_RF, LOW);
      digitalWrite(led_RB, LOW);
      spinCCW();
      digitalWrite(led_RF, HIGH);
      digitalWrite(led_LB, HIGH);
    }
  }
}