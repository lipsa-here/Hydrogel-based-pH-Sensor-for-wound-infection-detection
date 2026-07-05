# Hydrogel-Based Smart Patch for Early Detection of Wound Infection Using pH Monitoring

## Overview

This project presents an **Arduino-based Hydrogel pH Sensor** designed for the **early detection of wound infections** in a non-invasive manner. The prototype aims to enable **at-home wound monitoring** by measuring the pH of wound exudate absorbed through a hydrogel pad.

Healthy wounds generally exhibit an acidic environment, while infected wounds become increasingly alkaline. By continuously monitoring pH changes, the device provides a simple and affordable method to identify potential wound infections before they become severe.

---

## Project Objective

To develop a **low-cost, portable, and non-invasive wound monitoring system** capable of:

- Detecting pH changes in wound exudate.
- Classifying wound condition based on pH.
- Providing real-time pH readings on an LCD display.
- Supporting early intervention and reducing unnecessary hospital visits.

---

## Working Principle

1. A **hydrogel pad** is placed in contact with the wound dressing.
2. The hydrogel absorbs **wound exudate** released from the skin.
3. Infection alters the ionic concentration of the wound fluid.
4. These ionic changes affect the **pH sensor probe**.
5. The pH sensor sends an analog signal to the **Arduino Uno**.
6. Arduino processes the sensor readings and displays the calculated pH value on an **I2C LCD display**.
7. Based on the measured pH, the wound condition can be interpreted.

---

## Wound Classification

| pH Range | Wound Condition | Interpretation |
|----------|----------------|----------------|
| **pH < 5** | Healthy | Acidic environment indicating normal wound healing |
| **5 ≤ pH < 7** | Contaminating | Possible bacterial contamination; monitor closely |
| **pH ≥ 7** | Infected | Alkaline environment suggesting infection; immediate medical consultation is recommended |

> **Note:** This prototype is intended for educational and research purposes and is **not a certified medical diagnostic device**.

---

## Hardware Components

- Arduino Uno
- Analog pH Sensor Module
- pH Probe
- Hydrogel Pad
- 16×2 I2C LCD Display
- Breadboard
- Jumper Wires
- USB Cable
- Power Supply

---

## Software Requirements

- Arduino IDE
- Wire Library
- LiquidCrystal_I2C Library

---

## Circuit Connections

| Component | Arduino Pin |
|-----------|-------------|
| pH Sensor Output | A0 |
| LCD SDA | A4 |
| LCD SCL | A5 |
| LCD VCC | 5V |
| LCD GND | GND |
| Onboard LED | Pin 13 |

---

## Features

- Non-invasive wound monitoring
- Real-time pH measurement
- LCD display output
- Portable and low-cost prototype
- Hydrogel-based sample collection
- Arduino-powered processing
- Simple calibration using pH offset

---

## Code Description

The Arduino program performs the following operations:

- Reads 10 analog samples from the pH sensor.
- Sorts the readings to remove outliers.
- Averages the middle six values for improved accuracy.
- Converts the analog voltage into pH.
- Displays the pH value on the LCD.
- Sends readings to the Serial Monitor for debugging.
- Uses the onboard LED as a status indicator.

---

## Repository Structure

```
Hydrogel-Based-pH-Sensor/
│
├── Hydrogel_pH_Sensor.ino
├── README.md
└── images/
    ├── prototype.jpg
    ├── circuit.jpg
    └── working.jpg
```

---

## Future Improvements

- Wireless monitoring using Bluetooth or Wi-Fi.
- Mobile application for remote monitoring.
- Data logging and cloud storage.
- Smartphone notifications for abnormal pH values.
- Integration of temperature and moisture sensors.
- Flexible wearable electronics.
- Battery-powered portable enclosure.
- Machine learning for wound progression prediction.

---

## Applications

- Home healthcare
- Chronic wound monitoring
- Diabetic ulcer management
- Pressure ulcer monitoring
- Post-surgical wound care
- Elderly patient care
- Rural healthcare settings

---

## Limitations

- Prototype-level implementation.
- Requires calibration before use.
- Environmental factors may influence pH readings.
- Not intended to replace professional medical diagnosis.

---

## Results

The prototype successfully demonstrates that changes in wound pH can be detected using a hydrogel-assisted sampling mechanism and an Arduino-based pH sensing system. The LCD provides real-time pH readings, allowing users to identify healthy, contaminated, or infected wound conditions based on established pH thresholds.

---

## Authors

- Lipsa Priyadarshani Dash
- Anurag Baruah
---

## License

This project is intended for academic, educational, and research purposes.

---

## Acknowledgements

Special thanks to everyone who supported the development of this prototype and to the open-source Arduino community for providing libraries and resources that made this project possible.
