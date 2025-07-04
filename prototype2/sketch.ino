#include <ESP32Servo.h>

// Joystick 1 (Base + Shoulder)
const int JOY1_X = 35;  // Base rotation
const int JOY1_Y = 34;  // Shoulder movement

// Joystick 2 (Gripper/Elbow)
const int JOY2_X = 33;  // Gripper or Elbow
// Optional: const int JOY2_Y = 25; // For future use

// Servo PWM pins
const int SERVO_BASE     = 12;
const int SERVO_SHOULDER = 13;
const int SERVO_GRIPPER  = 14;

// Servo objects
Servo baseServo;
Servo shoulderServo;
Servo gripperServo;

void setup() {
  Serial.begin(115200);

  // Attach servos
  baseServo.attach(SERVO_BASE, 500, 2400);
  shoulderServo.attach(SERVO_SHOULDER, 500, 2400);
  gripperServo.attach(SERVO_GRIPPER, 500, 2400);
}

void loop() {
  // Read joystick analog values (0 to 4095)
  int baseRaw     = analogRead(JOY1_X);
  int shoulderRaw = analogRead(JOY1_Y);
  int gripperRaw  = analogRead(JOY2_X);

  // Map to servo angles (0 to 180)
  int baseAngle     = map(baseRaw, 0, 4095, 0, 180);
  int shoulderAngle = map(shoulderRaw, 0, 4095, 0, 180);
  int gripperAngle  = map(gripperRaw, 0, 4095, 0, 180);

  // Move servos
  baseServo.write(baseAngle);
  shoulderServo.write(shoulderAngle);
  gripperServo.write(gripperAngle);

  // Optional: Debug output
  Serial.printf("Base: %d, Shoulder: %d, Gripper: %d\n", baseAngle, shoulderAngle, gripperAngle);

  delay(20); // Stability delay
}
