# Project 15 – Smart Temperature Monitoring System

## 📌 Overview

This project is a simple embedded temperature monitoring system built using an Arduino Uno and a TMP36 temperature sensor. The system continuously measures the ambient temperature, displays the current temperature on a 16×2 LCD, and classifies the environment as **Cold**, **Normal**, or **Hot** using LED indicators.

The project also demonstrates analog sensor interfacing, analog-to-digital conversion, and efficient LCD updates by refreshing the display only when the measured temperature changes.

---

## 🎯 Objectives

- Learn how to interface the TMP36 temperature sensor with an Arduino.
- Understand analog-to-digital conversion using `analogRead()`.
- Convert sensor voltage into temperature in degrees Celsius.
- Display live temperature readings on a 16×2 LCD.
- Indicate environmental conditions using LEDs.
- Reduce unnecessary LCD updates for smoother operation.

---

## 🧰 Components Used

- Arduino Uno
- TMP36 Temperature Sensor
- 16×2 LCD (Parallel Interface)
- Potentiometer (LCD Contrast)
- Red LED
- Green LED
- Breadboard
- Jumper Wires

---

## ⚙️ System Behavior

The Arduino continuously reads the analog output of the TMP36 sensor and converts it into a temperature value.

The LCD displays:

- Current temperature (rounded to the nearest whole number)
- Temperature status

The system classifies the temperature into three ranges:

### 🟢 Cold
- Temperature ≤ 20°C
- Green LED ON
- LCD displays:
  ```
  18 C (Cold)
  ```

### 🟡 Normal
- Temperature > 20°C and ≤ 40°C
- Both LEDs OFF
- LCD displays:
  ```
  28 C (Normal)
  ```

### 🔴 Hot
- Temperature > 40°C
- Red LED ON
- LCD displays:
  ```
  45 C (Hot)
  ```

---

## 🔄 System Workflow

1. Read the analog output of the TMP36 sensor.
2. Convert the ADC reading into voltage.
3. Convert the voltage into temperature in degrees Celsius.
4. Round the temperature to the nearest whole number.
5. Determine the current temperature range.
6. Update the LCD only when the displayed temperature changes.
7. Turn on the appropriate LED based on the temperature range.

---

## 🧠 Key Concepts Practiced

- Analog Sensors
- `analogRead()`
- Analog-to-Digital Conversion (ADC)
- Voltage-to-Temperature Conversion
- Floating-Point Arithmetic
- LCD Interfacing
- Conditional Logic
- Efficient Display Updating
- Embedded Systems Programming

---

## 📖 Lessons Learned

This project strengthened my understanding of analog sensors and how the Arduino interprets varying voltages. Instead of memorizing the temperature conversion formula, I experimentally derived it by observing the relationship between ADC readings, voltage, and temperature.

I also learned the importance of using floating-point arithmetic correctly and discovered how integer division can produce incorrect results if not handled carefully.

Another valuable lesson was optimizing the LCD by updating it only when the displayed temperature changes, reducing unnecessary screen refreshes.

---

## 🚀 Future Improvements

Possible enhancements include:

- Add a buzzer for high-temperature alerts.
- Display temperature with one decimal place.
- Implement hysteresis to prevent rapid state switching near threshold temperatures.
- Add Fahrenheit display mode.
- Log temperature readings over time.
- Control a cooling fan or heater automatically.

---

## 📚 Learning Journey

This project is part of my Arduino and Embedded Systems learning series. Each project introduces a new hardware component while reinforcing concepts learned in previous projects, gradually building practical embedded systems design skills.
