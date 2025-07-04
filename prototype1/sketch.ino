#include <ESP32Servo.h>

// Define joystick pins
const int JOY_X = 35;     // Horizontal (X)
const int JOY_Y = 34;     // Vertical (Y)
const int JOY_BTN = 32;   // Button (SEL)

// Servo objects
Servo servo1;  // Base rotation
Servo servo2;  // Shoulder
Servo servo3;  // Gripper or elbow

// State
int currentServo = 0;
bool lastButtonState = HIGH;

void setup() {
  Serial.begin(115200);

  pinMode(JOY_BTN, INPUT_PULLUP);  // internal pull-up

  // Attach servos with pulse width range (can adjust if needed)
  servo1.attach(12, 500, 2400);
  servo2.attach(13, 500, 2400);
  servo3.attach(14, 500, 2400);
}

void loop() {
  // Read joystick positions
  int xValue = analogRead(JOY_X);  // 0–4095
  int yValue = analogRead(JOY_Y);
  int buttonState = digitalRead(JOY_BTN);

  // Map joystick value to angle 0–180
  int angleX = map(xValue, 0, 4095, 0, 180);
  int angleY = map(yValue, 0, 4095, 0, 180);

  // Handle button press (debounced)
  if (buttonState == LOW && lastButtonState == HIGH) {
    currentServo = (currentServo + 1) % 3;
    Serial.print("Switched to Servo ");
    Serial.println(currentServo + 1);
    delay(300);  // Debounce delay
  }
  lastButtonState = buttonState;

  // Control the currently selected servo
  switch (currentServo) {
    case 0:
      servo1.write(angleX);  // X-axis for base
      break;
    case 1:
      servo2.write(angleY);  // Y-axis for shoulder
      break;
    case 2:
      servo3.write((angleX + angleY) / 2);  // Mix for gripper
      break;
  }

  delay(20); // small delay for stability
}
