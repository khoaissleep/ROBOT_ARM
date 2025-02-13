#include <Servo.h>
Servo myServo;
#define IN1_1 2
#define IN2_1 3
#define IN3_1 4
#define IN4_1 5

#define IN1_2 6
#define IN2_2 7
#define IN3_2 8
#define IN4_2 9

#define IN1_3 10
#define IN2_3 11
#define IN3_3 12
#define IN4_3 13

// Delay time between steps (to adjust motor speed)
int stepDelay = 3;

// Step sequence for rotating the motor
int stepSequence[8][4] = {
  {1, 0, 0, 0}, // Step 1
  {1, 1, 0, 0}, // Step 2
  {0, 1, 0, 0}, // Step 3
  {0, 1, 1, 0}, // Step 4
  {0, 0, 1, 0}, // Step 5
  {0, 0, 1, 1}, // Step 6
  {0, 0, 0, 1}, // Step 7
  {1, 0, 0, 1}  // Step 8
};

// Steps per revolution reduced from 512 to 256 for larger rotation angles
int stepsPerRevolution = 256;

void setup() {
  myServo.attach(A1);  // Attach servo to Analog In A1 (used as digital)
  Serial.begin(9600);

  pinMode(IN1_1, OUTPUT);
  pinMode(IN2_1, OUTPUT);
  pinMode(IN3_1, OUTPUT);
  pinMode(IN4_1, OUTPUT);
  
  pinMode(IN1_2, OUTPUT);
  pinMode(IN2_2, OUTPUT);
  pinMode(IN3_2, OUTPUT);
  pinMode(IN4_2, OUTPUT);
  
  pinMode(IN1_3, OUTPUT);
  pinMode(IN2_3, OUTPUT);
  pinMode(IN3_3, OUTPUT);
  pinMode(IN4_3, OUTPUT);
}

void motor1_forward(){
  for (int i = 0; i < stepsPerRevolution; i++) {
    controlMotor1(i % 8); 
    delay(stepDelay);
  }
}
void motor1_backward(){
  for (int i = stepsPerRevolution - 1; i >= 0; i--) {
    controlMotor1(i % 8); 
    delay(stepDelay);
  }
}

void motor2_forward(){
  for (int i = 0; i < stepsPerRevolution; i++) {
    controlMotor2(i % 8);
    delay(stepDelay);
  }
}
void motor2_backward(){
  for (int i = stepsPerRevolution - 1; i >= 0; i--) {
    controlMotor2(i % 8);
    delay(stepDelay);
  }
}

void motor3_forward(){
  for (int i = 0; i < stepsPerRevolution; i++) {
    controlMotor3(i % 8); 
    delay(stepDelay);
  }
}
void motor3_backward(){
  for (int i = stepsPerRevolution - 1; i >= 0; i--) {
    controlMotor3(i % 8);
    delay(stepDelay);
  }
}

void controlServo() {
  myServo.write(90);   // Rotate servo to 90 degrees
  delay(1000);         

  myServo.write(0);    // Rotate servo back to 0 degrees
  delay(1000);
}
void loop() {
  motor1_forward();
  motor3_forward();
  motor2_forward();
  controlServo();
  motor1_backward();
  motor3_backward();
  motor2_backward();
  motor1_forward();
  motor3_forward();
  controlServo();
}

void controlMotor1(int step) {
  digitalWrite(IN1_1, stepSequence[step][0]);
  digitalWrite(IN2_1, stepSequence[step][1]);
  digitalWrite(IN3_1, stepSequence[step][2]);
  digitalWrite(IN4_1, stepSequence[step][3]);
}

void controlMotor2(int step) {
  digitalWrite(IN1_2, stepSequence[step][0]);
  digitalWrite(IN2_2, stepSequence[step][1]);
  digitalWrite(IN3_2, stepSequence[step][2]);
  digitalWrite(IN4_2, stepSequence[step][3]);
}

void controlMotor3(int step) {
  digitalWrite(IN1_3, stepSequence[step][0]);
  digitalWrite(IN2_3, stepSequence[step][1]);
  digitalWrite(IN3_3, stepSequence[step][2]);
  digitalWrite(IN4_3, stepSequence[step][3]);
}
