# Project 09 - Smart Traffic Light

## Overview

This project expands a standard traffic light controller by introducing traffic awareness using a Parallax PING))) ultrasonic sensor.

Instead of using a fixed green-light duration, the system measures traffic density and dynamically adjusts the green-light time before each green cycle begins.

This simulates a basic adaptive traffic control system.

---

## Components

- Arduino Uno
- Parallax PING))) Ultrasonic Sensor
- Red LED
- Yellow LED
- Green LED
- 3 × 220Ω Resistors
- Breadboard
- Jumper Wires

---

## Wiring

### Ultrasonic Sensor

| PING))) Pin | Arduino Pin |
|------------|------------|
| 5V | 5V |
| GND | GND |
| SIG | Pin 7 |

### LEDs

| LED | Arduino Pin |
|------|------------|
| Red | Pin 8 |
| Yellow | Pin 9 |
| Green | Pin 10 |

---

## Traffic Light Sequence

```text
RED (5 seconds)
↓
YELLOW (2 seconds)
↓
GREEN (variable duration)
↓
YELLOW (2 seconds)
↓
Repeat
```

---

## Traffic Detection Logic

The ultrasonic sensor measures the distance between the sensor and nearby vehicles.

Traffic density is estimated using the measured distance.

| Distance | Traffic Level | Green Time |
|-----------|--------------|------------|
| 0–10 cm | High Traffic | 15 seconds |
| 11–30 cm | Medium Traffic | 10 seconds |
| Above 30 cm | Low Traffic | 5 seconds |

---

## Control Strategy

Traffic is measured once at the end of the first yellow phase.

The selected green duration is then locked and remains unchanged throughout the entire green cycle.

### Decision Flow

```text
Measure Traffic
↓
Determine Traffic Level
↓
Assign Green Duration
↓
Enter GREEN State
↓
Maintain Duration Until Cycle Ends
```

This prevents traffic conditions from changing the green-light timer while the light is already green.

---

## Program Structure

### States

```cpp
RED
YELLOW1
GREEN
YELLOW2
```

### State Flow

```text
RED
↓
YELLOW1
↓
Read Ultrasonic Sensor
↓
Assign Green Time
↓
GREEN
↓
YELLOW2
↓
RED
```

---

## Concepts Practiced

- State Machines
- Enumerations (enum)
- switch Statements
- millis() Timing
- Ultrasonic Sensing
- pulseIn()
- Dynamic Timing
- Sensor-Based Decision Making
- Embedded System Design

---

## Key Lessons Learned

- Sensors can influence system behavior, not just outputs.
- Decisions should be made at clearly defined points in a control cycle.
- Dynamic timing can be implemented without blocking code.
- Separating measurement from execution creates predictable system behavior.
- State machines simplify complex control systems.

---

## Project Outcome

Successfully designed and implemented a smart traffic light system that adapts its green-light duration based on measured traffic conditions.

This project marks the first integration of:

```text
Sensor Input
+
Decision Logic
+
State Machine Control
+
Variable Timing
```

into a single embedded system.

---

## Status

✅ Completed

✅ Tested

✅ Verified

✅ Published
