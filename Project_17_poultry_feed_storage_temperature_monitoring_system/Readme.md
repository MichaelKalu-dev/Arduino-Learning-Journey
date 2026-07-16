Project 16 – Poultry Feed Storage Temperature Monitoring System

Overview

This project is an Arduino-based temperature monitoring system designed for a poultry feed storage room. It continuously monitors the room temperature and alerts workers whenever storage conditions move outside the recommended range.

The system was developed from a real-world client scenario, with emphasis on balancing functionality, simplicity, and cost.

Problem Statement

A poultry farm owner needed a reliable and affordable system to monitor the temperature inside a feed storage room.

The system should:

- Continuously monitor room temperature.
- Inform workers whether storage conditions are suitable.
- Warn workers when the room becomes warmer than the recommended range.
- Provide a more urgent warning if the temperature becomes dangerous.
- Stop the warning automatically when the temperature returns to a safe range.

Features

- Continuous temperature monitoring using a TMP36 sensor.
- Real-time temperature display on a 16×2 LCD.
- Displays the current storage condition:
  - Below Ideal Temperature
  - Suitable Temperature
  - Above Ideal Temperature
  - Dangerous Temperature
- Audible warning using a piezo buzzer.
- Two alarm levels:
  - Moderate warning for temperatures between 29°C and 35°C.
  - High-priority warning for temperatures above 35°C.
- LCD updates only when the temperature changes, reducing unnecessary display refreshes.

Components Used

- Arduino Uno
- TMP36 Temperature Sensor
- 16×2 LCD
- Piezo Buzzer
- Breadboard
- Jumper Wires

Temperature Ranges

Temperature| Status
Below 18°C| Below Ideal Temperature
18°C – 28°C| Suitable Temperature
29°C – 35°C| Above Ideal Temperature
Above 35°C| Dangerous Temperature

Working Principle

1. The Arduino reads the analog voltage from the TMP36 temperature sensor.
2. The voltage is converted into degrees Celsius.
3. The current temperature is displayed on the LCD.
4. The system determines the appropriate storage status.
5. The buzzer provides different warning patterns depending on the severity of the temperature.
6. When the temperature returns to the suitable range, the warning stops automatically.

Skills Demonstrated

- Analog sensor interfacing
- Temperature conversion
- LCD interfacing
- Piezo buzzer control
- Non-blocking timing using "millis()"
- State-based decision making
- Efficient LCD updating
- Requirement analysis and system design

Future Improvements

- Add colored LEDs for quick visual indication.
- Allow users to configure temperature thresholds.
- Store temperature logs in memory or on an SD card.
- Add Bluetooth or Wi-Fi for remote monitoring.
- Support multiple storage rooms with a single controller.


Michael Kalu

Mechatronics Engineering Student
