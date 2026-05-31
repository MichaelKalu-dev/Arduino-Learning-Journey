# Project 03 - Button Controlled Traffic Light System

## Overview
This project is a traffic light simulation using Arduino where a push button is used to trigger a pedestrian request. When the button is pressed, the system modifies the normal traffic cycle by introducing a blinking yellow phase and an extended red light to allow safe crossing.

---

## Components Used
- Arduino Uno
- 3 LEDs (Red, Yellow, Green)
- 3 Resistors (220Ω recommended)
- Push button
- Breadboard
- Jumper wires

---

## How It Works
- The system runs a normal traffic light cycle:
  - Red → Red+Yellow → Green → Yellow → Red
- A push button is used to send a pedestrian request.
- When the request is detected:
  - Yellow blinks 3 times
  - Red light duration is extended
  - System resets request after handling

---

## Key Learning Outcomes
- Understanding INPUT_PULLUP configuration
- Button state detection (HIGH/LOW logic inversion)
- Use of boolean flags for event handling
- State-based system thinking
- Basic traffic light sequencing logic
- Introduction to loop-based repetition (for loops)

---

## Wiring Summary
- LEDs connected to digital pins (13, 12, 11)
- Button connected between pin 2 and GND
- All components share common GND rail

---

## Future Improvement
- Replace delay-based timing with millis() for non-blocking control
- Improve real-time responsiveness of button input
