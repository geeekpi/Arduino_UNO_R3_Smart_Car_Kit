const int led_LF = 2;   // LED in Left Front 
const int led_RF = A2;  // LED in Right front 
const int led_LB = 12;  // LED in Left Back
const int led_RB = 11;  // LED in Right Back


void setup() {
  pinMode(led_LF, OUTPUT);    // setting LED pin output 
  pinMode(led_RF, OUTPUT);
  pinMode(led_LB, OUTPUT);
  pinMode(led_RB, OUTPUT);
}

void loop() {
  digitalWrite(led_LF, HIGH);  //  turn on the LED
  digitalWrite(led_RF, HIGH);  
  digitalWrite(led_LB, HIGH);
  digitalWrite(led_RB, HIGH);
  delay(1000);
  digitalWrite(led_LF, LOW);  // turn off the LED
  digitalWrite(led_RF, LOW);
  digitalWrite(led_LB, LOW);
  digitalWrite(led_RB, LOW);
}