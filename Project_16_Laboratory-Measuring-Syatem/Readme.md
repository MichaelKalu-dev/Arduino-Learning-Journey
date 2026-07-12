# Project 17 – Laboratory Temperature Monitoring System

## Overview

This project is a laboratory temperature monitoring system built with Arduino. It continuously measures the ambient temperature using a TMP36 temperature sensor and provides visual and audible feedback to indicate whether the laboratory conditions are safe for storing temperature-sensitive chemicals.

The system was designed from a client requirement rather than a predefined tutorial, focusing on solving a real engineering problem.

## Features

- Continuous temperature monitoring
- Four temperature states:
  - Too Cold (<15°C)
  - Suitable (15°C–30°C)
  - Warm (31°C–40°C)
  - Too Hot (>40°C)
- LCD displays:
  - Current temperature
  - Current system status
- Four-color LED indication:
  - Blue – Too Cold
  - Green – Suitable
  - Yellow – Warm
  - Red – Too Hot
- Audible warning using a piezo buzzer
- LCD updates only when the temperature changes, reducing unnecessary screen refreshes.

## Components Used

- Arduino Uno
- TMP36 Temperature Sensor
- 16×2 LCD
- Piezo Buzzer
- Blue LED
- Green LED
- Yellow LED
- Red LED
- Current-limiting resistors
- Breadboard
- Jumper wires

## Working Principle

The TMP36 outputs an analog voltage proportional to temperature.

The Arduino:
1. Reads the analog value.
2. Converts it to voltage.
3. Calculates the temperature in degrees Celsius.
4. Determines the temperature state.
5. Updates the LCD.
6. Activates the appropriate LED.
7. Sounds the buzzer when necessary.

## Skills Demonstrated

- Analog sensor interfacing
- Voltage-to-temperature conversion
- Decision making using conditional statements
- LCD interfacing
- Piezo buzzer control
- Multi-output system integration
- Efficient LCD updating

## Future Improvements

- Replace continuous buzzer tones with timed warning beeps using `millis()`.
- Allow configurable temperature thresholds.
- Log temperature history.
- Add EEPROM support for saving settings.
- Integrate wireless notifications.

## Screenshot

_Add a screenshot of the completed Tinkercad circuit here._

## Author

Michael Kalu
Mechatronics Engineering Student
