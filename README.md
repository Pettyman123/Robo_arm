# 🤖 ESP32 Robot Arm with 2 Joysticks

Control a 3-DOF robot arm using an ESP32 and two analog joysticks. This project uses the [ESP32Servo](https://github.com/jkb-git/ESP32Servo) library to drive three servo motors in real time — no buttons or toggling required.
![image](https://github.com/user-attachments/assets/d585f93e-07d9-4688-a62b-cd53569cfa39)

## 🎮 Features

- Real-time control of 3 servos: base, shoulder, and gripper
- Two analog joysticks for intuitive movement
- No joystick button needed
- Works with Wokwi simulator and real hardware

## 🛠️ Components

- 1 × ESP32 Dev Board  
- 2 × Analog Joysticks  
- 3 × Servo Motors (SG90 or MG90S)  
- Breadboard + jumper wires

## 🔌 Pin Connections

| Component             | ESP32 GPIO |
|----------------------|-------------|
| Joystick 1 X (Base)  | 35          |
| Joystick 1 Y         | 34          |
| Joystick 2 X         | 33          |
| *(Optional)* Joystick 2 Y | 25    |
| Servo 1 (Base)       | 12          |
| Servo 2 (Shoulder)   | 13          |
| Servo 3 (Gripper)    | 14          |

> ⚠️ Use 3.3V for joysticks and 5V for servos. Make sure all GNDs are connected.
