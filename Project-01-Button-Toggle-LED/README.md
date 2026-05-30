# Project 01 — Button Toggle LED

## Objective
Control an LED using a push button. Each press toggles the LED ON or OFF.

## Components Used
- Arduino Uno
- Push button
- LED
- 220Ω resistor
- Jumper wires

## Circuit Description
The button is connected to digital pin 2 using INPUT_PULLUP mode.
The LED is connected to digital pin 6.

## How It Works
- When the button is not pressed, the input reads HIGH.
- When pressed, the input reads LOW.
- A transition from HIGH → LOW is detected as a single press event.
- Each press toggles the LED state.

## Concepts Learned
- INPUT_PULLUP configuration
- Digital input reading
- Edge detection (HIGH to LOW transition)
- State variables
- Basic event-driven programming

## Result
Each button press toggles the LED state once, regardless of how long the button is held.
