# Keypad-Controlled-Access-System-with-Visual-Feedback
![image](https://github.com/user-attachments/assets/3fbbf9a8-c6df-418e-b65b-5dca66583812)

Keypad-Controlled Access System with Visual Feedback
Project Overview
This project implements a secure, keypad-controlled access system using Arduino. It demonstrates the integration of various components to create a functional security system, showcasing principles applicable to industrial automation and access control.
Features

Secure 4-digit passcode entry
Real-time visual feedback via I2C LCD display
LED indicators for access granted (green) and denied (red)
Servo motor actuation simulating door lock mechanism
Serial monitor output for debugging

Components

Arduino board (e.g., Arduino Uno)
4x4 Matrix Keypad
I2C LCD Display (16x2 characters)
Servo Motor
LEDs (1 green, 1 red)
Resistors for LEDs
Jumper wires

Wiring

Keypad: Rows to pins 9, 8, 7, 6; Columns to pins 5, 4, 3, 2
I2C LCD: SDA to A4, SCL to A5
Servo: Signal to pin 10
Green LED: Pin 12 (with appropriate resistor)
Red LED: Pin 13 (with appropriate resistor)

Installation

Clone this repository
Open the .ino file in the Arduino IDE
Install required libraries:

Keypad
Servo
LiquidCrystal_I2C


Upload the code to your Arduino board

Usage

Power on the system
Enter the 4-digit code using the keypad
The LCD will display entered digits and result
Correct code: Green LED lights up, servo rotates (simulating door unlock)
Incorrect code: Red LED lights up

Default passcode: 1234 (modifiable in the code)
Potential Applications and Extensions

Building access control systems
Secure storage units
Integration with larger security systems
Addition of multiple user codes
Logging of access attempts
Time-based access restrictions

Contributing
Contributions to enhance the project are welcome. Please feel free to fork, modify, and make pull requests.
License
MIT License

This README provides a comprehensive overview of your project, including its features, components, setup instructions, and potential applications. It's structured to give viewers on GitHub a clear understanding of what the project does, how to set it up, and its broader implications in security and automation contexts.
