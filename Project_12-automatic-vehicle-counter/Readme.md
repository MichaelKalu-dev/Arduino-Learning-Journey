# Project 12 - Automatic Vehicle Counter

## Overview

This project implements an automatic vehicle counting system using a Parallax PING))) ultrasonic sensor.

The Arduino continuously monitors the distance in front of the sensor. Instead of counting every sensor reading, the system detects the moment a vehicle **enters** the detection zone and increments the vehicle count only once. The total number of detected vehicles is displayed on the Serial Monitor.

This project introduces **event detection (edge detection)**, a fundamental concept in embedded systems.

---

## Components

- Arduino Uno
- Parallax PING))) Ultrasonic Sensor
- Breadboard
- Jumper Wires

---

## Wiring

| Component | Arduino Pin |
|-----------|-------------|
| Ultrasonic Sensor (SIG) | Pin 7 |
| Ultrasonic Sensor (5V) | 5V |
| Ultrasonic Sensor (GND) | GND |

---

## System Operation

The ultrasonic sensor continuously measures the distance to objects in front of it.

When a vehicle moves from outside the detection range into the **10 cm detection zone**, the Arduino:

- Detects the transition.
- Increments the vehicle counter.
- Displays the updated count on the Serial Monitor.

The vehicle is counted **only once**, regardless of how long it remains in front of the sensor.

Once the vehicle leaves the detection zone, the system becomes ready to count the next vehicle.

---

## Detection Logic

```text
No Vehicle
     │
     ▼
Vehicle Enters (Distance ≤ 10 cm)
     │
     ▼
Increment Counter
     │
     ▼
Vehicle Remains
(No Additional Count)
     │
     ▼
Vehicle Leaves
     │
     ▼
Ready for Next Vehicle
```

---

## Detection Condition

The system compares the previous and current distance measurements.

```text
Previous Distance > 10 cm
Current Distance ≤ 10 cm
```

This transition represents a **new vehicle entering** the detection zone.

---

## Concepts Practiced

- Ultrasonic Distance Measurement
- Event (Edge) Detection
- Previous vs Current State Comparison
- Conditional Statements (`if`)
- Variables
- Serial Communication
- Real-Time Monitoring

---

## Skills Developed

This project strengthens the ability to distinguish between a continuous sensor reading and a one-time event.

Skills gained include:

- Detecting transitions instead of continuous conditions.
- Preventing multiple counts from a single object.
- Comparing previous and current sensor values.
- Designing reliable counting systems.

---

## Key Lessons Learned

- Continuous sensor readings should not always trigger repeated actions.
- Comparing previous and current values enables event detection.
- Edge detection is a common technique used in embedded systems, robotics, automation, and industrial control.
- Simple logic can greatly improve the reliability of sensor-based systems.

---

## Applications

This technique can be extended to build:

- Automatic parking counters
- People counting systems
- Conveyor belt product counters
- Entrance monitoring systems
- Production line automation

---

## Project Outcome

Successfully designed and implemented an automatic vehicle counter that detects when a vehicle enters the sensing area and increments the count exactly once.

This project demonstrates how event detection can be used to create reliable counting systems using an ultrasonic sensor.

---

## Future Improvements

Possible enhancements include:

- Displaying the count on an LCD.
- Adding a reset button.
- Saving the count to EEPROM so it is retained after power loss.
- Counting both vehicle entries and exits.
- Integrating the counter with an automatic parking gate.

---

## Status

- ✅ Completed
- ✅ Tested
- ✅ Verified
- ✅ Published
