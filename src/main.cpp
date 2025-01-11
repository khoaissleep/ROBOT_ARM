
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

// Thời gian delay giữa các bước (điều chỉnh tốc độ động cơ)
int stepDelay = 3;

// Định nghĩa chuỗi bước để quay động cơ
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

// Số bước mỗi vòng quay giảm từ 512 xuống 256 để tăng góc quay
int stepsPerRevolution = 256;

void setup() {

  
  myServo.attach(A1);  // Gắn servo vào chân Analog In A1 (dùng như digital)
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


void step1_xuoi(){
    // Quay cùng chiều kim đồng hồ cho motor 1
  for (int i = 0; i < stepsPerRevolution; i++) { // 256 bước ~ 1 vòng quay rộng hơn
    stepMotor1(i % 8); // Thực hiện từng bước cho motor 1
    delay(stepDelay);
  }
}
void step1_nguoc(){
  // Quay ngược chiều kim đồng hồ cho motor 1
  for (int i = stepsPerRevolution - 1; i >= 0; i--) { // Quay ngược 1 vòng
    stepMotor1(i % 8); // Thực hiện từng bước cho motor 1
    delay(stepDelay);
  }
}



void step2_xuoi(){
    // Quay cùng chiều kim đồng hồ cho motor 2
  for (int i = 0; i < stepsPerRevolution; i++) { // 256 bước ~ 1 vòng quay rộng hơn
    stepMotor2(i % 8); // Thực hiện từng bước cho motor 2
    delay(stepDelay);
  }
}
void step2_nguoc(){
  // Quay ngược chiều kim đồng hồ cho motor 2
  for (int i = stepsPerRevolution - 1; i >= 0; i--) { // Quay ngược 1 vòng
    stepMotor2(i % 8); // Thực hiện từng bước cho motor2
    delay(stepDelay);
  }
}


void step3_xuoi(){
    // Quay cùng chiều kim đồng hồ cho motor 3
  for (int i = 0; i < stepsPerRevolution; i++) { // 256 bước ~ 1 vòng quay rộng hơn
    stepMotor3(i % 8); // Thực hiện từng bước cho motor 3
    delay(stepDelay);
  }
}
void step3_nguoc(){
  // Quay ngược chiều kim đồng hồ cho motor 3
  for (int i = stepsPerRevolution - 1; i >= 0; i--) { // Quay ngược 1 vòng
    stepMotor3(i % 8); // Thực hiện từng bước cho motor 3
    delay(stepDelay);
  }
}

void servorun() {
  myServo.write(90);   // Quay servo đến góc 90 độ
  delay(1000);         // Giữ tại vị trí 90 độ trong 1 giây

  myServo.write(0);    // Quay servo về góc 0 độ
  delay(1000);
}
void loop() {
  // làm cho robot cuối xuống để gắp đồ
  step1_xuoi();
  step3_xuoi();
  // xoay cánh tay
  step2_xuoi();
  // cầm đồ
  servorun();
  // làm cho robot ngẩn đầu lên
  step1_nguoc();
  step3_nguoc();
  // xoay về vị trí cũ
  step2_nguoc();
  
  // làm cho robot cuối xuống để thả đồ
  step1_xuoi();
  step3_xuoi();
  // thả đồ
  servorun();
  

}

// Hàm điều khiển motor 1 - cho phần stepper bên trái
void stepMotor1(int step) {
  digitalWrite(IN1_1, stepSequence[step][0]);
  digitalWrite(IN2_1, stepSequence[step][1]);
  digitalWrite(IN3_1, stepSequence[step][2]);
  digitalWrite(IN4_1, stepSequence[step][3]);
}

// Hàm điều khiển motor 2 cho phần stepper ở dưới robot giúp điều khiển quay trái phải cho robot
void stepMotor2(int step) {
  digitalWrite(IN1_2, stepSequence[step][0]);
  digitalWrite(IN2_2, stepSequence[step][1]);
  digitalWrite(IN3_2, stepSequence[step][2]);
  digitalWrite(IN4_2, stepSequence[step][3]);
}

// Hàm điều khiển motor 3- cho phần stepper bên phải
void stepMotor3(int step) {
  digitalWrite(IN1_3, stepSequence[step][0]);
  digitalWrite(IN2_3, stepSequence[step][1]);
  digitalWrite(IN3_3, stepSequence[step][2]);
  digitalWrite(IN4_3, stepSequence[step][3]);
}

