# Project 18 – Smart Door Lock System 🔐

## Overview

The Smart Door Lock System is an Arduino-based access control system designed to authenticate users using a 4×4 matrix keypad. The system combines a keypad, LCD, servo motor, and buzzer to create a simple but practical electronic door lock. When the correct four-digit PIN is entered, the servo unlocks the door for a few seconds before automatically locking it again. Incorrect passwords are rejected with both visual and audio feedback.

---

## Features

- 🔑 4-digit PIN authentication
- ⌨️ 4×4 keypad for password entry
- 📺 16×2 LCD user interface
- 🚪 Servo-controlled door lock
- 🔊 Buzzer feedback for successful and failed authentication
- 🔄 Automatic door relocking after a short delay
- 🔁 System resets after each authentication attempt
- 🧠 Password verification using a `for` loop and character arrays

---

## Components Used

- Arduino Uno
- 16×2 LCD
- 4×4 Matrix Keypad
- Servo Motor
- Piezo Buzzer
- Breadboard
- Jumper Wires

---

## Circuit Summary

| Component | Arduino Pins |
|-----------|--------------|
| LCD | RS→9, E→8, D4→3, D5→2, D6→A2, D7→A3 |
| Keypad Rows | 13, 12, 11, 10 |
| Keypad Columns | 7, 6, 5, 4 |
| Servo | A5 |
| Buzzer | A0 |

---

## How It Works

1. The LCD prompts the user to enter a PIN.
2. The user enters a four-digit password using the keypad.
3. Pressing **#** submits the password.
4. The system compares the entered PIN with the stored password.
5. If the password is correct:
   - The LCD displays **Access Granted**.
   - The buzzer sounds briefly.
   - The servo rotates to unlock the door.
   - After a few seconds, the servo returns to the locked position.
6. If the password is incorrect:
   - The LCD displays **Access Denied**.
   - The buzzer sounds to indicate an invalid PIN.
7. The system resets and waits for the next user.

---

## Programming Concepts Demonstrated

- Object-oriented programming with Arduino libraries
- Character arrays
- Two-dimensional arrays
- Boolean variables
- `for` loops
- Conditional statements
- User input processing
- Password validation
- Servo motor control
- LCD interfacing
- Embedded system integration

---

## Applications

This project demonstrates the core principles behind:

- Electronic door locks
- Office access control systems
- Hotel room access systems
- Equipment authentication panels
- Storage room security
- Embedded authentication systems

---

## Future Improvements

- Display `*` instead of entered digits
- Configurable password length
- Password change feature
- Three-attempt lockout
- EEPROM password storage
- RFID authentication
- Fingerprint authentication
- IoT remote monitoring and unlocking
- Event logging with RTC module

---

## Project Information

**Project Number:** 18

**Project Title:** Smart Door Lock System

**Platform:** Arduino Uno

**Programming Language:** Arduino C++

---

## Lessons Learned

This project demonstrates how multiple hardware components can be integrated into a complete embedded system. It emphasizes system design, password authentication, user interaction, debugging, and coordinating several peripherals to solve a real engineering problem.
