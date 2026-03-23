# 🤖 Arduino & Smart Hardware Laboratory

Welcome to my personal playground for Arduino, embedded systems, and robotics prototyping. 
This repository acts as a live portfolio documenting my journey from basic electronic circuits to automated smart devices.

---

## 🛠️ Hardware & Tools Ecosystem

Here are the standard tools I use across different modules in this laboratory:

* **Microcontroller:** Arduino Uno R3
* **Displays:** 16x2 I2C LCD Character Display
* **Sensors:** HC-SR04 Ultrasonic Distance Sensor, Potentiometer Modules
* **Actuators:** Standard LEDs, DC Motors (via L293N drivers), Piezo Buzzers
* **Prototyping:** Solderless Breadboards, Resistors, Jumper Wires (F-M and M-M)

---

## 📂 Project Directory

Below is a curated list of active projects inside this repository:

| Folder Name | Project Concept | Primary Components | Learning Outcome |
| :--- | :--- | :--- | :--- |
| `01-led-dimmer` | Interactive LED Brightness Control | Arduino, Potentiometer, LED | Mastering PWM and Analog reading |
| `02-lcd-loading-bar` | Visual Progress Metrics | Arduino, I2C LCD, Potentiometer | Display mechanics and UI mapping |
| `03-ultrasonic-radar` | Non-contact Distance Meter | Arduino, HC-SR04, Serial Monitor | Understanding Sonar & Speed of Sound |
| `04-dc-motor-control` | Bi-directional Motor Spinning | Arduino, L293N Driver, DC Motor | Handling external high-voltage loads |

---

## 🧠 Core Engineering Concepts Covered

Throughout these modules, I am actively building a foundation in:

1.  **I2C Communication Protocols:** Sending serial data over SDA and SCL using just 2 wires.
2.  **Pulse Width Modulation (PWM):** Simulating analog voltage using binary digital duty cycles.
3.  **Sensor Physics:** Utilizing trigonometry and physics (the speed of sound in air) to calculate distances.
4.  **Hardware Scoping:** Utilizing breadboards to partition power buses and safety grounds.

---

## 🚀 How to Navigate This Repo

Each project sits inside its own dedicated folder containing:
1. A `.ino` Arduino sketch file.
2. A short `wiring.txt` connection instruction sheet.
3. A sub-README file explaining how the code functions.

Feel free to fork the repository, run the code using simulator engines like **Wokwi** or **Tinkercad Circuits**, or upload them to physical boards!
