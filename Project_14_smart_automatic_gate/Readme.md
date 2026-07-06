# Project 14 – Smart Automatic Gate System

## 📌 Overview

This project simulates an automatic gate system using an Arduino Uno. An ultrasonic sensor detects an approaching object, a servo motor controls the gate, an LCD provides user feedback, and LEDs indicate the gate's current status.

The objective of this project was to integrate multiple components into a single embedded system while reinforcing concepts such as sensor input, actuator control, state-based logic, and user interface design.

---

## 🎯 Objectives

- Learn to control a servo motor using Arduino.
- Integrate an ultrasonic sensor with a servo motor.
- Display system status on a 16×2 LCD.
- Use LEDs to indicate gate status.
- Practice organizing code using an enumeration (enum).

---

## 🧰 Components Used

- Arduino Uno
- HC-SR04 / Parallax PING))) Ultrasonic Sensor
- SG90 Servo Motor
- 16×2 LCD (Parallel Interface)
- Potentiometer (LCD Contrast)
- Red LED
- Green LED
- Current-limiting resistor(s)
- Breadboard
- Jumper wires

---

## ⚙️ System Behavior

### 🟢 Gate Closed

- Servo positioned at **0°**
- Green LED ON
- Red LED OFF
- LCD displays **"Goodbye"**

### 🔴 Gate Open

When an object is detected within the specified distance:

- Servo rotates to **90°**
- Green LED OFF
- Red LED ON
- LCD displays **"Welcome"**

The system continuously monitors the ultrasonic sensor and updates the gate position accordingly.

---

## 🔄 System Workflow

1. The ultrasonic sensor continuously measures the distance to an approaching object.
2. If the measured distance is within the detection range, the gate opens.
3. The LCD displays a welcome message while the red LED indicates the gate is open.
4. When the object moves outside the detection range, the gate closes.
5. The LCD displays a goodbye message while the green LED indicates the gate is closed.

---

## 🧠 Key Concepts Practiced

- Servo motor control
- Ultrasonic distance measurement
- LCD interfacing
- LED status indication
- Enumeration (`enum`)
- Conditional logic
- Hardware integration
- Embedded system design

---

## 📖 Lessons Learned

Through this project, I learned how different electronic components can work together to create a practical embedded system. I also gained a better understanding of servo motor control and how a single sensor can coordinate multiple outputs such as displays, actuators, and LEDs.

This project reinforced the importance of building systems by integrating smaller concepts learned in previous projects.

---

## 🚀 Future Improvements

Potential enhancements include:

- Automatic closing after a configurable delay.
- Triggering the gate only once per vehicle detection.
- Audible feedback using a buzzer.
- Vehicle counting.
- EEPROM-based settings storage.
- I²C LCD implementation.
- Non-blocking timing using `millis()`.

---

## 📚 Learning Journey

This project is part of my Arduino and Embedded Systems learning series, where each project builds upon previous concepts while introducing new hardware, programming techniques, and system integration challenges.
