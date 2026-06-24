# 🚦 Arduino Dual-Road Traffic Intersection Controller (Project 07)

This project simulates a two-road traffic intersection using an Arduino and a finite state machine.

Two independent roads share a single intersection. The controller ensures that only one road receives a green signal at a time, preventing conflicting traffic flow.

---

## 🎯 Project Objective

Design a traffic controller capable of coordinating two crossing roads while maintaining safe traffic flow.

The project focuses on:

- State machine design
- Non-blocking timing using `millis()`
- Multi-output coordination
- Traffic control logic

---

## 🧰 Components Used

- Arduino Uno
- 6 LEDs
  - Road A: Red, Yellow, Green
  - Road B: Red, Yellow, Green
- 6 × 220Ω Resistors
- Breadboard
- Jumper Wires

---

## 🛣️ Road Model

This project uses a simplified intersection model:

- Road A allows traffic from East → West
- Road B allows traffic from North → South

Only one road may have a green signal at any given time.

---

## 🔄 Traffic Sequence

### State 1

Road A: 🔴 Red

Road B: 🟢 Green

Duration: 5 seconds

---

### State 2

Road A: 🔴 Red

Road B: 🟡 Yellow

Duration: 2 seconds

---

### State 3

Road A: 🟢 Green

Road B: 🔴 Red

Duration: 5 seconds

---

### State 4

Road A: 🟡 Yellow

Road B: 🔴 Red

Duration: 2 seconds

---

The sequence then repeats continuously.

---

## 🧠 State Machine

The system is implemented using an enum-based finite state machine.

```cpp
enum trafficState{
  RED_A_GREEN_B,
  RED_A_YELLOW_B,
  GREEN_A_RED_B,
  YELLOW_A_RED_B,
};
```

Each state represents the complete condition of the intersection.

---

## ⏱ Timing Method

The project uses:

```cpp
millis()
```

instead of:

```cpp
delay()
```

This allows the controller to operate using non-blocking timing techniques commonly used in embedded systems.

---

## 📂 File Structure

```text
Dual_Road_Traffic_Intersection.ino
README.md
```

---

## 📚 Concepts Practiced

- Arduino digital outputs
- Breadboard wiring
- Traffic control systems
- State machines
- Enums
- Switch statements
- Non-blocking timing with millis()
- Multi-device coordination

---

## 🚀 Author

Created as Project 07 in a progressive Arduino and Embedded Systems learning journey.

This project marks the transition from single-device control systems to coordinated multi-system control using finite state machines.
