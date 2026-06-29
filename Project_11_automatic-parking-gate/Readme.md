# Project 11 - Automatic Parking Gate System

## Overview

This project implements an automatic parking gate using an ultrasonic sensor and a micro servo motor.

The system continuously monitors the entrance using a Parallax PING))) ultrasonic sensor. When a vehicle is detected within a specified distance, the gate automatically opens by rotating the servo motor while a green LED indicates that entry is permitted.

After a fixed period, the gate automatically closes and the red LED indicates that the entrance is closed, ready for the next vehicle.

---

## Components

- Arduino Uno
- Parallax PING))) Ultrasonic Sensor
- Micro Servo (SG90)
- 2 × LEDs
  - Red LED
  - Green LED
- 2 × 220Ω Resistors
- Breadboard
- Jumper Wires

---

## Wiring

| Component | Arduino Pin |
|----------|-------------|
| Red LED | 13 |
| Green LED | 11 |
| Servo Signal | 9 |
| Ultrasonic Sensor | 7 |

### Servo Connections

| Servo Wire | Arduino |
|------------|----------|
| Brown (GND) | GND |
| Red (VCC) | 5V |
| Orange (Signal) | Pin 9 |

---

## System Operation

The system begins with the parking gate closed.

```text
Gate Closed (0°)
Red LED ON
Green LED OFF
```

The ultrasonic sensor continuously measures the distance to any approaching object.

If an object is detected within **10 cm**, the system performs the following actions:

- Opens the gate to **90°**
- Turns OFF the red LED
- Turns ON the green LED
- Keeps the gate open for **5 seconds**

After the delay, the system returns to monitoring the entrance. If no object is detected, the gate closes and the red LED turns back on.

---

## Control Logic

```text
Measure Distance
        ↓
Distance ≤ 10 cm?
      /     \
    Yes      No
     |        |
Open Gate   Close Gate
Green ON    Red ON
Wait 5 s
     |
Repeat
```

---

## Servo Positions

| Servo Angle | Gate Status |
|--------------|------------|
| 0° | Closed |
| 90° | Open |

---

## Distance Threshold

| Measured Distance | Action |
|-------------------|--------|
| ≤ 10 cm | Open Gate |
| > 10 cm | Keep Gate Closed |

---

## Concepts Practiced

- Servo Motor Control
- Servo Library (`Servo.h`)
- Ultrasonic Distance Measurement
- `pulseIn()`
- Conditional Statements (`if`)
- Digital Outputs
- Mechanical Actuation
- Embedded System Integration

---

## Skills Developed

This project introduced the use of an actuator capable of controlled mechanical movement.

Skills gained include:

- Controlling servo position.
- Integrating sensors with mechanical actuators.
- Designing simple automation systems.
- Combining sensing, decision-making, and physical movement into one embedded application.

---

## Key Lessons Learned

- A servo motor controls **position**, not continuous rotation.
- The `Servo` library simplifies servo control through angle commands.
- Sensors can be used to automate physical systems.
- Embedded systems often combine sensing, processing, and actuation to interact with the real world.

---

## Project Outcome

Successfully designed and implemented an automatic parking gate capable of detecting approaching vehicles, opening the gate automatically, and closing it after a fixed interval.

This project combines:

```text
Ultrasonic Sensor
+
Servo Motor
+
LED Status Indicators
+
Automatic Decision Making
+
Mechanical Movement
```

into a complete embedded automation system.

---

## Future Improvements

Possible enhancements include:

- Using `millis()` instead of `delay()` for non-blocking operation.
- Keeping the gate open until the vehicle has completely passed.
- Adding a buzzer to indicate gate movement.
- Displaying system status on an LCD.

---

## Status

- ✅ Completed
- ✅ Tested
- ✅ Verified
- ✅ Published
