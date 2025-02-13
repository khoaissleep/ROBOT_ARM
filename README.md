# Robot Arm Project

## Introduction
This project involves building and controlling a robot arm using three stepper motors (28BYJ-48) and one servo motor (MG996) on the Arduino Mega 2560 platform. The robot arm performs a series of movements such as rotating the arm, picking up objects, and releasing them in a repetitive cycle. This project can be applied to automation tasks, robotics, and educational purposes.

## Main Components
- **3 Stepper Motors (28BYJ-48)**: Control the rotation and vertical movement of the robot arm.
- **1 Servo Motor (MG996)**: Controls the gripper mechanism of the robot.
- **Arduino Mega 2560**: The main controller for motors and input/output devices.

## Hardware Configuration
- **Stepper Motors (28BYJ-48)** are connected to the control pins of the Arduino Mega (IN1, IN2, IN3, IN4 for each motor).
- **Servo Motor (MG996)** is connected to the A1 pin on the Arduino Mega.

## Motion Description
In the `loop()` section of the code, the robot performs the following actions:

1. **Pick Up Object**:
   - Stepper motors 1 and 3 move the arm down.
   - Stepper motor 2 rotates the arm to the correct position.
   - Servo rotates to 90 degrees to open the gripper.

2. **Lift Object**:
   - The arm lifts up using stepper motors 1 and 3.
   - Stepper motor 2 rotates back to the initial position.

3. **Release Object**:
   - The arm moves down again using stepper motors 1 and 3.
   - The servo opens the gripper to release the object.

## Code Details
### Stepper Motor Functions
- **step1_forward**: Rotates stepper motor 1 (left side) clockwise.
- **step1_backward**: Rotates stepper motor 1 (left side) counterclockwise.
- **step2_forward**: Rotates stepper motor 2 (bottom) clockwise (rotates the arm left/right).
- **step2_backward**: Rotates stepper motor 2 (bottom) counterclockwise.
- **step3_forward**: Rotates stepper motor 3 (right side) clockwise.
- **step3_backward**: Rotates stepper motor 3 (right side) counterclockwise.

### Servo Motor Function
- **servorun**: Controls the servo motor to open and close the gripper. The servo rotates to 90 degrees to open and returns to 0 degrees to close the gripper.

## Loop Sequence
```cpp
void loop() {
  // Lower the arm to pick up an object
  step1_forward();
  step3_forward();

  // Rotate the arm
  step2_forward();

  // Pick up the object
  servorun();

  // Lift the arm
  step1_backward();
  step3_backward();

  // Rotate back to the initial position
  step2_backward();

  // Lower the arm to release the object
  step1_forward();
  step3_forward();

  // Release the object
  servorun();
}
```

## Installation and Usage
### Software Requirements:
- **Arduino IDE**: To program the Arduino Mega 2560.
- **Servo Library**: To control the servo motor.
- **Stepper Library**: To control the stepper motors.

### Setup Instructions:
1. Open the Arduino IDE and upload the source code to the Arduino Mega 2560.
2. Connect the motors and servo to the following pins:
   - Stepper Motor 1 (28BYJ-48): Pins 2, 3, 4, 5.
   - Stepper Motor 2 (28BYJ-48): Pins 6, 7, 8, 9.
   - Stepper Motor 3 (28BYJ-48): Pins 10, 11, 12, 13.
   - Servo: Pin A1.
3. Install the `Stepper` and `Servo` libraries from the Arduino Library Manager.

## Conclusion
This project demonstrates a robot arm capable of performing basic tasks such as picking up and releasing objects. It applies stepper and servo motor control in robotic systems and automation.
