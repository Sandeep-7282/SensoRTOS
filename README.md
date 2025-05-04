# 📟 SensoRTOS

📟 SensoRTOS is a FreeRTOS-based embedded project for the 🔌STM32F103C8 (Blue Pill), developed entirely with ** bare-metal register-level programming ** (no HAL). It demonstrates real-time multitasking by integrating multiple peripherals and sensors, including **DHT22**, **HC-SR04**, **UART**, and an **SSD1306 OLED** (I2C), using FreeRTOS tasks.

---

## 🔧 Features

- 🧠 **FreeRTOS CMSIS v1**: Task-based scheduling
- 🌡️ **DHT22**: Temperature and humidity sensing
- 📏 **HC-SR04**: Ultrasonic distance measurement
- 📟 **SSD1306 OLED**: 128x32 display via I2C (bare-metal I2C driver)
- 🖥️ **UART Control**: LED and Buzzer via simple serial commands
- ⏱️ **Microsecond Delay**: Using TIM1

---

## 🧱 Architecture Overview

main.c
├── Initializes FreeRTOS
├── Creates & starts all tasks

Drivers/
├── uart-driver.c/.h → UART RX/TX via PA9/PA10
├── delay.c/.h → delay_us using TIM1
├── dht22-driver.c/.h → DHT22 bit-level communication
├── hc_sr04-driver.c/.h → HC-SR04 distance measurement
└── ssd1306-i2c-driver.c/.h → OLED via I2C (bare-metal)

Tasks/
├── task_dht22.c/.h → Reads temp/humidity every 1s
├── task_hcsr04.c/.h → Reads distance every 50ms
├── task_display.c/.h → Displays distance on OLED
└── task_command.c/.h → Handles UART commands


---

## 🔌 Pin Mapping (STM32F103C8T6)

| Peripheral | Pin(s)                 | Description               |
|------------|------------------------|---------------------------|
| UART       | PA9 (TX), PA10 (RX)    | Serial command interface  |
| DHT22      | PA0                    | Temp & humidity sensor    |
| HC-SR04    | PA1 (Trig), PA2 (Echo) | Ultrasonic sensor         |
| OLED (I2C) | PB6 (SCL), PB7 (SDA)   | SSD1306 128x32 display    |
| LED        | PA5                    | UART-controllable output  |
| Buzzer     | PA4                    | UART-controllable output  |

---

## 📦 Tools & Environment

-🛠️ Development IDE     --> STM32CubeIDE
-🧩 Middleware Package  --> FreeRTOS CMSIS-RTOS v1
-🔌 Microcontroller     --> STM32F103C8T6 (Blue Pill) — Simulated
-🧪 Simulation Tool     --> Proteus 8 Professional
-🧬 Programming Style   --> Bare-metal (Register-level access) — ❌ No HAL Lib Used

---

## 📸 Demo 

> <img  alt="Embedded Dev" width="300" height="200" src="https://github.com/user-attachments/assets/1ea52915-6e50-49ca-80fb-91f33a15ebe0">


---

---

## 🙋 Author

Nadegouni Sandeep  
[GitHub Profile](https://github.com/Sandeep-7282)

