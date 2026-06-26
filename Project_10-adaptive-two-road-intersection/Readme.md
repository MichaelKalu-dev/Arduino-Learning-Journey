# Project 10 - Adaptive Two-Road Traffic Intersection

## Overview

This project builds upon the two-road traffic intersection by introducing adaptive traffic control using two Parallax PING))) ultrasonic sensors.

Each road is equipped with its own ultrasonic sensor to detect traffic density. Before a road receives a green light, its sensor measures the traffic level and determines how long the green light should remain active.

This allows each road to receive a green-light duration proportional to its traffic demand, creating a simple adaptive traffic management system.

---

## Components

- Arduino Uno
- 2 × Parallax PING))) Ultrasonic Sensors
- 6 × LEDs
  - Road A: Red, Yellow, Green
  - Road B: Red, Yellow, Green
- 6 × 220Ω Resistors
- Breadboard
- Jumper Wires

---

## Wiring

### Road A

| Component | Arduino Pin |
|----------|-------------|
| Red LED | 13 |
| Yellow LED | 12 |
| Green LED | 11 |
| PING))) Sensor | A0 |

### Road B

| Component | Arduino Pin |
|----------|-------------|
| Red LED | 8 |
| Yellow LED | 9 |
| Green LED | 10 |
| PING))) Sensor | A1 |

---

## Traffic Light Sequence

```text
Road A Green
↓
Road A Yellow
↓
Road B Green
↓
Road B Yellow
↓
Repeat
```

Only one road is permitted to move at any given time.

---

## Traffic Detection Logic

Each road measures its own traffic immediately before entering the green state.

The measured distance determines the green-light duration.

| Distance | Traffic Level | Green Time |
|----------|---------------|------------|
| 0–10 cm | High Traffic | 15 seconds |
| 11–30 cm | Medium Traffic | 10 seconds |
| Above 30 cm | Low Traffic | 5 seconds |

Each road makes its timing decision independently.

---

## Control Strategy

Before Road A receives a green light:

1. Measure traffic on Road A.
2. Calculate the traffic level.
3. Assign `A_greenTime`.
4. Enter the green state.

Before Road B receives a green light:

1. Measure traffic on Road B.
2. Calculate the traffic level.
3. Assign `B_greenTime`.
4. Enter the green state.

Once assigned, the green duration remains fixed until that green phase ends.

---

## State Machine

```text
A_GREEN_B_RED
        ↓
A_YELLOW_B_RED
        ↓
A_RED_B_GREEN
        ↓
A_RED_B_YELLOW
        ↓
Repeat
```

---

## System Flow

```text
Measure Traffic
        ↓
Determine Traffic Density
        ↓
Assign Green Time
        ↓
Execute Traffic Cycle
        ↓
Repeat
```

---

## Concepts Practiced

- Finite State Machines
- Enumerations (enum)
- switch Statements
- millis() Timing
- Ultrasonic Sensors
- pulseIn()
- Dynamic Green-Light Timing
- Multi-Sensor Integration
- Sensor-Based Decision Making
- Embedded System Design

---

## Skills Developed

This project combines multiple embedded-system concepts into a single application.

- Controlling two independent traffic roads.
- Integrating multiple sensors.
- Making independent decisions from multiple inputs.
- Dynamically adjusting system timing.
- Designing scalable state-machine architectures.

---

## Key Lessons Learned

- Multiple sensors can operate within a single state machine.
- Sensor measurements should occur at defined transition points.
- Separating sensing, decision-making, and execution creates predictable system behavior.
- Adaptive systems respond to environmental conditions without changing their core architecture.

---

## Project Outcome

Successfully designed and implemented an adaptive two-road traffic intersection capable of independently adjusting each road's green-light duration based on detected traffic conditions.

This project represents the integration of:

```text
Two Ultrasonic Sensors
+
Two-Road Traffic Control
+
Dynamic Timing
+
State Machine Architecture
+
Adaptive Decision Making
```

into a complete embedded system.

---

## Status

- ✅ Completed
- ✅ Tested
- ✅ Verified
- ✅ Published
