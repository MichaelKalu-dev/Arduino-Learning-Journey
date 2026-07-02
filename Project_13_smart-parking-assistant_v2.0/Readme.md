# Project 13 – Smart Parking Assistant 2.0 (LCD Edition)

## 📌 Overview

This project extends my earlier Ultrasonic Parking Assistant by replacing the Serial Monitor with a 16×2 LCD, allowing the system to display real-time distance measurements and parking status directly on the screen. The project combines multiple hardware components into a single embedded system while improving the user interface and user experience.

---

## 🎯 Objectives

- Learn to interface a standard 16×2 LCD with Arduino.
- Display real-time ultrasonic distance measurements.
- Integrate multiple hardware components into one project.
- Implement distance-based decision making.
- Improve LCD performance by minimizing unnecessary screen refreshes.

---

## 🧰 Components Used

- Arduino Uno
- HC-SR04 / Parallax PING))) Ultrasonic Sensor
- 16×2 Standard LCD (Parallel Interface)
- Potentiometer (LCD contrast adjustment)
- Red LED
- Green LED
- Current-limiting resistor(s)
- Breadboard
- Jumper wires

---

## ⚙️ System Behavior

### 🟢 SAFE (> 30 cm)

- Green LED ON
- Red LED OFF
- LCD displays:
  - Distance
  - SAFE

### 🟡 CAUTION (11–30 cm)

- Green LED ON
- Red LED ON
- LCD displays:
  - Distance
  - CAUTION

### 🔴 STOP (≤ 10 cm)

- Red LED ON
- Green LED OFF
- LCD displays:
  - Distance
  - STOP!!!

---

## 🔄 System Workflow

1. The ultrasonic sensor continuously measures the distance to an object.
2. The measured distance is displayed on the first row of the LCD.
3. The system determines the parking status:
   - **SAFE** if the object is more than 30 cm away.
   - **CAUTION** if the object is between 11 cm and 30 cm.
   - **STOP!!!** if the object is 10 cm or closer.
4. The LEDs update to match the current status.
5. The LCD updates only the changing portions of the display to reduce flickering.

---

## 🧠 Key Concepts Practiced

- LCD initialization (`lcd.begin()`)
- Cursor positioning (`lcd.setCursor()`)
- Printing text and variables (`lcd.print()`)
- Ultrasonic distance measurement
- Conditional statements (`if`, `else if`, `else`)
- Hardware integration
- LCD optimization
- State-based output logic

---

## 🔬 Experiments & Observations

During development, I explored the behavior of the LCD by experimenting with:

- Cursor positioning beyond valid rows and columns.
- Character overflow at the edge of the display.
- LCD contrast adjustment using a potentiometer.
- LCD backlight wiring and current limiting.
- The effect of repeatedly calling `lcd.clear()`.
- Clearing only the changing sections of the display to eliminate flickering.

These experiments provided a deeper understanding of how character LCDs operate beyond simply displaying text.

---

## 🚀 Possible Improvements

- Automatic gate control using a servo motor.
- Vehicle counting system.
- Non-blocking timing using `millis()`.
- Audible warning using a buzzer.
- I²C LCD implementation.
- EEPROM-based configuration storage.

---

## 📚 Learning Journey

This project is part of my Arduino and Embedded Systems learning journey, where each project builds upon previous concepts while introducing new hardware, programming techniques, and system integration challenges.
