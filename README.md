# IoT Industrial Vibration Monitor using ESP32

## 📝 Project Overview
This project is an **Edge-AI prototype** designed for predictive maintenance of industrial motors. It monitors vibration intensity in real-time and provides local and remote alerts.

## 🚀 Live Simulation
* [Run on Wokwi](https://wokwi.com/projects/new/esp32) *(Note: Replace this with your actual Wokwi project URL)*

## 🛠️ Hardware Stack
* **MCU:** ESP32 (Dual-Core)
* **Sensor:** MPU6050 (6-Axis Accelerometer & Gyroscope)
* **Display:** SSD1306 OLED (128x64) via I2C

## ⚙️ Core Features
* **I2C Bus Integration:** Multiple devices (Sensor + Display) on a single bus.
* **Vector Magnitude Logic:** Calculates resultant acceleration $\sqrt{x^2 + y^2 + z^2}$ to detect anomalies.
* **IoT Dashboard:** Integrated Web Server for remote monitoring via WiFi.
* **Local Alert System:** Real-time threshold alerts on OLED display.

## 📂 File Structure
* `vibration_monitor.ino`: Main firmware code.
* `diagram.json`: Digital wiring blueprint for Wokwi.
