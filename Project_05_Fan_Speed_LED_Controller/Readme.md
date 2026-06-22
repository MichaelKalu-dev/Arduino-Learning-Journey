# Project 05 — Fan Speed LED Controller (Potentiometer-Based System)

## Overview

This project simulates a fan speed controller using a potentiometer and three LEDs.

The potentiometer is used as an input device to select different speed levels, and the LEDs visually represent the selected mode.

This project builds on previous work involving analog input, state machines, and digital output control.

---

## System Behavior

The system divides potentiometer readings into four ranges:

- 0 – 255   → OFF (all LEDs OFF)
- 256 – 511 → LOW speed (Red LED ON)
- 512 – 767 → MEDIUM speed (Red + Blue LEDs ON)
- 768 – 1023 → HIGH speed (Red + Blue + Green LEDs ON)

---

## Components Used

- Arduino Uno
- 1 × Potentiometer
- 3 × LEDs (Red, Blue, Green)
- 3 × Resistors (220Ω or 330Ω)
- Breadboard
- Jumper wires

---

## How It Works

1. The potentiometer produces an analog signal (0–1023).
2. Arduino reads the value using `analogRead()`.
3. The value is classified into one of four ranges.
4. Each range corresponds to a fan speed mode.
5. LEDs represent the current mode visually.

---

## Key Concepts Learned

- Analog input using `analogRead()`
- Range-based decision making
- State representation using `enum`
- Digital output control using `digitalWrite()`
- Debugging hardware connection issues

---

## Wiring Summary

- Potentiometer middle pin → A0
- Potentiometer sides → 5V and GND
- Red LED → Pin 10
- Blue LED → Pin 11
- Green LED → Pin 12
- All LEDs connected with resistors to GND

---

## Outcome

The system successfully demonstrates how analog input can be used to control multiple digital outputs in different states.

This project simulates real-world fan speed control behavior using LEDs as indicators.
