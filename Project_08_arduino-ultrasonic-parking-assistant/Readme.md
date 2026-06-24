# Project 08 - Ultrasonic Parking Assistant

## Overview

This project uses a Parallax PING))) ultrasonic sensor to measure the distance between the sensor and an object.

Based on the measured distance, the Arduino activates one of three LEDs:

- Green LED: Safe distance
- Yellow LED: Caution
- Red LED: Object too close

This project introduces ultrasonic sensing and demonstrates how sensor data can be used to make decisions and control outputs.

---

## Components

- Arduino Uno
- Parallax PING))) Ultrasonic Sensor
- 3 LEDs
  - Red
  - Yellow
  - Green
- 3 × 220Ω Resistors
- Breadboard
- Jumper Wires

---

## Wiring

### Ultrasonic Sensor

| PING))) Pin | Arduino |
|------------|----------|
| 5V | 5V |
| GND | GND |
| SIG | Pin 7 |

### LEDs

| LED | Arduino Pin |
|------|------------|
| Red | Pin 8 |
| Yellow | Pin 9 |
| Green | Pin 10 |

Each LED is connected in series with a current-limiting resistor.

---

## Logic

The Arduino:

1. Sends a trigger pulse to the ultrasonic sensor.
2. Measures the echo duration using `pulseIn()`.
3. Converts duration to distance in centimeters.
4. Determines the distance zone.
5. Activates the corresponding LED.

### Distance Zones

| Distance | LED |
|-----------|-----|
| 0 - 10 cm | Red |
| 11 - 30 cm | Yellow |
| Above 30 cm | Green |

---

## Concepts Practiced

- Ultrasonic sensing
- Trigger pulse generation
- Echo timing measurement
- `pulseIn()`
- Distance calculation
- Conditional statements (`if`, `else if`, `else`)
- Sensor-driven outputs

---

## Lessons Learned

- Ultrasonic sensors measure time, not distance directly.
- Distance is calculated from echo duration.
- A single signal pin can act as both OUTPUT and INPUT.
- Sensor data can be used to drive system decisions.
- Real-world systems often follow the pattern:

Input → Processing → Output

---

## Status

Completed, tested, and verified.
