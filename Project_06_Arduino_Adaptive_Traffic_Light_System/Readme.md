# 🚦 Arduino Adaptive Traffic Light System (Project 06)

This project simulates a real-world traffic light controller using an Arduino.  
It includes pedestrian control and adaptive timing based on traffic conditions using a potentiometer.

---

## 🧠 Features

- Standard traffic light cycle (Red → Yellow → Green)
- Pedestrian request button system
- Pedestrian crossing sequence with blinking warning
- Adaptive green light timing based on traffic density
- Traffic density controlled via potentiometer

---

## 🔧 Components Used

- Arduino Uno
- 4 LEDs (Red, Yellow, Green, Blue)
- 1 Push Button
- 1 Potentiometer
- Resistors (220Ω recommended)
- Breadboard and jumper wires

---

## 🚦 System Behavior

### Traffic Cycle

- Red → fixed 5 seconds
- Yellow → 2 seconds
- Green → variable (based on traffic density)

---

### Traffic Density (Potentiometer)

| Range | Traffic Level | Green Duration |
|------|--------------|---------------|
| 0–341 | Low traffic  | 5 seconds     |
| 342–682 | Medium traffic | 10 seconds |
| 683–1023 | High traffic | 15 seconds |

Potentiometer is sampled only before entering the green state.

---

### Pedestrian System

- Button press stores a pedestrian request
- System completes current cycle before responding
- Pedestrian sequence:
  - Yellow blinking warning
  - Blue walk signal (5 seconds)
  - Final blinking warning before returning to normal cycle

