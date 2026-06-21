# 🚦 Pedestrian Traffic Light (FSM + millis)

## Overview
Arduino-based traffic light system using a finite state machine and non-blocking timing (`millis()`), with a pedestrian request button.

---

## System Behavior

### Normal Cycle
- RED → 5s  
- YELLOW → 2s  
- GREEN → 5s  
- YELLOW → 2s  
- Repeat

---

### Pedestrian Mode (on button press)
- Yellow blink × 3 (warning)
- Blue ON for 5s (crossing)
- Yellow blink × 3 (exit warning)
- Return to RED cycle

---

## Components
- Arduino Uno  
- Red LED (Pin 13)  
- Yellow LED (Pin 12)  
- Green LED (Pin 11)  
- Blue LED (Pin 10)  
- Push Button (Pin 2, INPUT_PULLUP)  
- Resistors  
- Breadboard + wires  

---

## Key Concepts
- Finite State Machine (FSM)
- `enum` states
- `switch-case` logic
- `millis()` timing (non-blocking)
- Event flag (`pedRequest`)
- Button edge detection
- Internal blink state tracking

---

## Wiring
- Red → 13  
- Yellow → 12  
- Green → 11  
- Blue → 10  
- Button → 2 (GND + INPUT_PULLUP)

---

## Note
System is fully non-blocking and continuously responsive to inputs using state-based logic.
