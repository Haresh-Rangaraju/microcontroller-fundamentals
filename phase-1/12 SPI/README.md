# 🔌 SPI (Serial Peripheral Interface)

## Overview

SPI (Serial Peripheral Interface) is a high-speed synchronous serial communication peripheral used by a microcontroller to communicate with external devices such as sensors, memories, displays, ADCs, DACs, and other microcontrollers.

Unlike UART, SPI uses a dedicated clock signal to synchronize data transfer and supports full-duplex communication (simultaneous transmission and reception).

---

# Why SPI is Needed

A microcontroller often communicates with fast external peripherals, including:

- External Flash Memory
- EEPROM
- ADC (Analog-to-Digital Converter)
- DAC (Digital-to-Analog Converter)
- IMU Sensors
- TFT/LCD Displays
- SD Cards
- Other Microcontrollers

SPI provides:

- High-speed communication
- Simple hardware interface
- Full-duplex data transfer
- Reliable communication over short distances

---

# SPI Inside a Microcontroller

```text
+----------------------+
|         CPU          |
+----------------------+
|      Registers       |
+----------------------+
|         SPI          |
+----------------------+
| MOSI MISO SCK SS     |
+----------------------+
```

The SPI peripheral acts as a bridge between the CPU and external digital devices.

---

# SPI Signals

SPI uses four main communication lines:

| Signal | Meaning | Direction |
|---------|---------|-----------|
| MOSI | Master Out Slave In | Master → Slave |
| MISO | Master In Slave Out | Slave → Master |
| SCK | Serial Clock | Master → Slave |
| SS (CS) | Slave Select / Chip Select | Master → Slave |

---

# How SPI Communication Works

1. CPU prepares data or a command.
2. CPU writes the data to the SPI Transmit Register.
3. CPU activates the required slave using the SS (Chip Select) line.
4. SPI hardware generates the clock (SCK).
5. Data is transmitted through MOSI.
6. The slave sends data back through MISO.
7. Received data is stored in the SPI Receive Register.
8. CPU reads the received data.

---

# SPI Communication Flow

```text
CPU
 ↓
SPI TX Register
 ↓
SPI Hardware
 ↓
MOSI
 ↓
Slave Device
 ↓
MISO
 ↓
SPI RX Register
 ↓
CPU
```

---

# Embedded and Automotive Applications

### Sensors

SPI is commonly used with:

- IMU
- Accelerometer
- Gyroscope
- Pressure Sensor ICs
- Magnetic Encoders

---

### Memory Devices

- External Flash Memory
- EEPROM
- SD Cards

---

### Displays

- TFT LCD Displays
- OLED Displays

---

### Actuators

SPI can communicate with:

- Motor Driver ICs
- DACs
- LED Driver ICs

---

# SPI in Automotive ECUs

SPI is mainly used **inside an ECU** for communication between the microcontroller and nearby peripherals.

Examples include:

- IMU Sensor Communication
- External Flash Memory
- High-Speed ADCs
- Motor Driver ICs

Unlike CAN or LIN, SPI is **not used for communication between different ECUs**.

---

# Register-Level View

Typical SPI peripheral registers include:

### Control Register

Configures:

- SPI Enable
- Master/Slave Mode
- Clock Settings

---

### Status Register

Stores:

- Transfer Complete
- Busy Status
- Error Flags

---

### Transmit Register (TX)

Stores data waiting to be transmitted.

---

### Receive Register (RX)

Stores received data.

---

### Chip Select (SS)

Selects the slave device that will communicate with the master.

---

# Memory Map

SPI registers are memory-mapped peripheral registers.

Example:

```text
Flash            0x00000000

RAM              0x20000000

SPI Registers    0x400xxxxx
```

The CPU communicates with SPI by reading and writing these registers.

---

# Real-World Examples

### Automotive

- IMU Sensor
- External Flash Memory
- Motor Driver IC

### Consumer Electronics

- TFT LCD Display
- SD Card

### Industrial Systems

- High-Speed ADC
- Digital Encoder

---

# Interview Questions

### What is SPI?

SPI is a high-speed synchronous serial communication peripheral used to exchange data between a microcontroller and external devices.

---

### What does SPI stand for?

Serial Peripheral Interface.

---

### Is SPI synchronous or asynchronous?

SPI is synchronous because it uses a clock signal (SCK).

---

### Name the four SPI signals.

- MOSI
- MISO
- SCK
- SS (Chip Select)

---

### Why is SPI faster than UART?

SPI uses a dedicated clock line, has lower protocol overhead, and supports full-duplex communication, allowing higher communication speeds.

---

### Can SPI transmit and receive simultaneously?

Yes.

SPI supports full-duplex communication.

---

### What is MOSI?

Master Out Slave In.

It carries data from the master to the slave.

---

### Why is the SS (Chip Select) line required?

It allows the master to select which slave device should communicate.

---

# SPI vs UART

| SPI | UART |
|------|------|
| Synchronous | Asynchronous |
| Uses Clock (SCK) | No Clock |
| MOSI & MISO | TX & RX |
| Full-Duplex | Full-Duplex |
| Higher Speed | Lower Speed |
| Multiple Slaves using SS | Point-to-Point Communication |

---

# SPI vs I²C

| SPI | I²C |
|------|-----|
| Four main signals | Two signals |
| Higher speed | Lower speed |
| Separate Chip Select for each slave | Device addressing |
| Full-duplex | Half-duplex |
| Simpler protocol | More complex protocol |

---

# Common Mistakes

❌ Thinking SPI is used between ECUs.

✔ SPI is mainly used inside an ECU between the MCU and nearby peripherals.

---

❌ Thinking the CPU manually generates every clock pulse.

✔ The SPI peripheral automatically generates the clock after the CPU loads the transmit register.

---

❌ Assuming SPI can communicate with multiple slaves without Chip Select.

✔ Each slave normally requires its own SS (Chip Select) line.

---

# Key Takeaways

- SPI is a high-speed synchronous serial communication protocol.
- Uses four main signals: MOSI, MISO, SCK, and SS.
- Supports full-duplex communication.
- Master generates the clock signal.
- Commonly used with sensors, memories, displays, and motor drivers.
- Primarily used inside an ECU rather than between ECUs.

---

# One-Line Interview Answer

SPI (Serial Peripheral Interface) is a high-speed synchronous serial communication peripheral that uses MOSI, MISO, SCK, and SS lines to exchange data between a microcontroller and external devices, making it ideal for fast communication with sensors, memories, and displays.
