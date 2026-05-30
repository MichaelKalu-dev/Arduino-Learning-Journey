# Project 02 — Traffic Light Controller

## Objective
Simulate a traffic light system using three LEDs.

## Components Used
- Arduino Uno
- Red LED
- Yellow LED
- Green LED
- 3 × 220Ω resistors
- Jumper wires

## Pin Configuration
| Component | Pin |
|------------|------|
| Red LED | 13 |
| Yellow LED | 12 |
| Green LED | 11 |

## Traffic Light Sequence

1. Red ON for 5 seconds
2. Red + Yellow ON for 2 seconds
3. Green ON for 5 seconds
4. Yellow ON for 2 seconds
5. Repeat

## Concepts Learned
- Multiple digital outputs
- Output sequencing
- State transitions
- Timing using delay()
- Debugging output logic

## Result
The LEDs simulate a basic traffic light cycle using timed state transitions.

## Future Improvements
- Add a pedestrian button
- Add a countdown display
- Replace delay() with millis()
- Create a state-machine implementation
