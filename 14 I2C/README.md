# I²C (Inter-Integrated Circuit)

## Phase 1 Foundation

This document provides Phase 1 notes on **I²C (Inter-Integrated Circuit)**, a widely used synchronous serial communication interface in embedded systems.

The goal is to understand **what I²C is, why it is used, how it works inside a microcontroller, and where it is used in embedded and automotive systems.** Programming, timing diagrams, and protocol implementation are beyond the Phase 1 scope.

---

# 1. Big Picture

## What is I²C?

I²C (Inter-Integrated Circuit) is a **synchronous serial communication peripheral** inside a microcontroller that enables communication with multiple external devices using only **two communication lines**.

Unlike SPI, I²C identifies devices using **unique addresses** instead of separate chip-select lines.

---

## Why Does I²C Exist?

Embedded systems often communicate with several external sensors and integrated circuits.

Instead of dedicating separate communication lines to every device, I²C allows all supported devices to share the same communication bus.

Benefits include:

- Reduced MCU pin usage
- Simpler PCB routing
- Lower wiring complexity
- Easy expansion with multiple peripherals

---

## Where Does I²C Fit Inside a Microcontroller?

```text
+----------------------+
|         CPU          |
+----------------------+
|      Registers       |
+----------------------+
|    I²C Peripheral    |
+----------------------+
|      SDA     SCL     |
+----------------------+
           │
           ▼
 External I²C Devices
```

The I²C peripheral acts as the communication bridge between the CPU and external devices.

---

## Why Should an Embedded Engineer Learn I²C?

I²C is one of the most common communication interfaces in embedded systems.

Typical I²C devices include:

- Temperature sensors
- EEPROM
- Real-Time Clock (RTC)
- Environmental sensors
- Configuration ICs
- Battery monitoring ICs

Understanding I²C is important because many embedded products connect several peripherals over a single shared bus.

---

# 2. ECU / Automotive Connection

## How is I²C Used Inside an ECU?

I²C is primarily used **inside an ECU** for communication with low-speed peripherals and configuration devices.

Unlike CAN, I²C is not intended for communication between different ECUs.

---

## Example 1 – Temperature Sensor

```text
Temperature Sensor
        │
        ▼
       I²C
        │
        ▼
     ECU MCU
```

The MCU periodically reads engine or cabin temperature.

---

## Example 2 – EEPROM

```text
MCU
 │
 ▼
I²C
 │
 ▼
EEPROM
```

Stores calibration data and configuration settings.

---

## Example 3 – Real-Time Clock (RTC)

```text
RTC
 │
 ▼
I²C
 │
 ▼
CPU
```

Provides date and time information to the ECU.

---

## Sensor Applications

Common I²C sensors include:

- Temperature sensors
- Humidity sensors
- Pressure sensors
- Light sensors
- Accelerometers

---

## Actuator / Configuration Applications

I²C is less commonly used for direct actuator control but often configures:

- LED driver ICs
- Display controllers
- Power management ICs

---

## Communication Role

I²C enables communication between one MCU and multiple low-speed peripherals using a shared two-wire bus.

---

# 3. Internal Working

Suppose the MCU wants to read temperature from an external sensor.

---

## Step 1

CPU prepares a read request.

```text
CPU
 │
 ▼
Read Request
```

---

## Step 2

CPU writes the request into the I²C transmit register.

```text
CPU
 │
 ▼
I²C TX Register
```

---

## Step 3

The I²C peripheral generates a Start Condition and sends the sensor address.

```text
CPU
 │
 ▼
I²C Peripheral
 │
 ▼
Start + Device Address
```

---

## Step 4

The addressed sensor recognizes its address and acknowledges.

```text
SDA Line
 │
 ▼
Temperature Sensor
 │
 ▼
ACK
```

---

## Step 5

Sensor transmits the requested data.

```text
Temperature Sensor
 │
 ▼
SDA
 │
 ▼
I²C Peripheral
```

---

## Step 6

Received data is stored.

```text
I²C RX Register
 │
 ▼
CPU
```

---

## Complete Data Flow

```text
CPU
 │
 ▼
I²C TX Register
 │
 ▼
I²C Peripheral
 │
 ▼
SDA + SCL
 │
 ▼
Sensor
 │
 ▼
SDA
 │
 ▼
I²C RX Register
 │
 ▼
CPU
```

---

## Hardware Blocks

```text
CPU
 │
 ▼
I²C Registers
 │
 ▼
I²C Peripheral
 │
 ▼
SDA & SCL
 │
 ▼
Sensor
 │
 ▼
CPU
```

---

# 4. Text Diagrams

## Basic Communication

```text
CPU
 │
 ▼
I²C
 │
 ▼
Sensor
```

---

## Shared I²C Bus

```text
MCU

SDA ----------------------------

SCL ----------------------------

        │
   ┌────┴────┐
   ▼         ▼
Sensor    EEPROM
```

---

## Multiple Devices

```text
            MCU
             │
        SDA & SCL Bus
   ┌────────┼─────────┐
   ▼        ▼         ▼
Sensor     RTC     EEPROM
```

---

## Display Controller Example

```text
MCU
 │
 ▼
I²C
 │
 ▼
Display Controller
```

---

# 5. Register-Level Thinking

The CPU controls the I²C peripheral using memory-mapped registers.

---

## Control Register

Stores:

- I²C Enable
- Master/Slave mode
- Clock settings
- Start/Stop control

---

## Status Register

Stores:

- Transfer complete
- ACK received
- Bus busy
- Error flags

---

## TX Register

Stores outgoing addresses or data.

```text
CPU
 │
 ▼
TX Register
 │
 ▼
I²C Hardware
```

---

## RX Register

Stores received data.

```text
I²C Hardware
 │
 ▼
RX Register
 │
 ▼
CPU
```

---

## Address Register

Stores the slave device address.

```text
CPU
 │
 ▼
Address Register
 │
 ▼
Selected Device
```

---

## Register Flow

```text
CPU
 │
 ▼
Control Register
 │
 ▼
Address Register
 │
 ▼
TX Register
 │
 ▼
I²C Hardware
 │
 ▼
RX Register
 │
 ▼
CPU
```

---

# 6. Memory Map Connection

The I²C peripheral occupies dedicated addresses in the MCU peripheral memory space.

Example:

```text
Flash Memory       0x00000000

RAM                0x20000000

I²C Registers      0x400xxxxx
```

(Exact addresses depend on the microcontroller.)

---

## CPU Access

```text
CPU
 │
 ▼
I²C Register Address
 │
 ▼
I²C Registers
 │
 ▼
I²C Hardware
```

---

## Memory-Mapped I/O

The CPU configures I²C by reading and writing memory-mapped registers.

The hardware automatically generates the clock signal and manages communication, reducing CPU workload.

---

# 7. Real-World Embedded Examples

## Automotive

### Temperature Sensor

```text
Temperature Sensor
 │
 ▼
I²C
 │
 ▼
ECU
```

---

### EEPROM

```text
EEPROM
 │
 ▼
I²C
 │
 ▼
ECU
```

---

### Battery Monitoring IC

```text
Battery Monitor
 │
 ▼
I²C
 │
 ▼
Battery ECU
```

---

## Consumer Electronics

- Real-Time Clock (RTC)
- Environmental sensors
- Wearable sensors
- Smart home sensors

---

## Industrial Systems

- Pressure sensors
- Configuration EEPROM
- Monitoring modules
- Industrial controllers

---

# 8. Interview Questions

## Q1. What is I²C?

**Answer:**

I²C is a synchronous serial communication peripheral that enables a microcontroller to communicate with multiple external devices using two communication lines.

---

## Q2. What does I²C stand for?

**Answer:**

Inter-Integrated Circuit.

---

## Q3. How many communication lines does I²C use?

**Answer:**

Two:

- SDA (Serial Data)
- SCL (Serial Clock)

---

## Q4. Why is I²C popular?

**Answer:**

Because multiple devices can share the same two-wire communication bus using unique addresses.

---

## Q5. What is the purpose of the device address?

**Answer:**

It allows the master device to identify and communicate with a specific slave device on the shared bus.

---

## Q6. Is I²C synchronous or asynchronous?

**Answer:**

Synchronous, because communication is synchronized using the SCL clock line.

---

## Q7. Name the two I²C communication lines.

**Answer:**

- SDA
- SCL

---

## Q8. Give three devices that commonly use I²C.

**Answer:**

- EEPROM
- RTC
- Temperature sensor

---

## Q9. Why is I²C preferred over SPI in some applications?

**Answer:**

Because it requires only two communication lines and allows multiple devices to share the same bus, reducing wiring complexity and MCU pin usage.

---

# 9. Common Confusions

## Confusion 1

**"I²C and SPI are the same."**

❌ Incorrect.

SPI uses:

- MOSI
- MISO
- SCK
- SS

I²C uses:

- SDA
- SCL

SPI selects devices using chip-select lines, whereas I²C uses unique device addresses.

---

## Confusion 2

**"Every I²C device needs separate communication wires."**

❌ Incorrect.

All devices share the same SDA and SCL lines.

---

## Confusion 3

**"I²C is faster than SPI."**

❌ Incorrect.

SPI generally provides higher communication speeds than I²C.

---

## Interview Trap

**Question:**

Why is I²C suitable for connecting multiple sensors?

**Strong Answer:**

Each sensor has a unique address, allowing multiple devices to communicate over the same SDA and SCL lines without requiring separate communication pins.

---

## Interview Trap

**Question:**

What is the biggest advantage of I²C?

**Strong Answer:**

Its shared two-wire bus simplifies hardware design and significantly reduces MCU pin usage when connecting multiple peripherals.

---

# Phase 1 Summary

I²C (Inter-Integrated Circuit) is a synchronous two-wire serial communication interface that allows a microcontroller to communicate with multiple external devices using SDA and SCL. Unlike SPI, I²C identifies devices using unique addresses, allowing many peripherals to share the same communication bus. It is widely used for low-speed communication with sensors, EEPROMs, RTCs, battery monitoring ICs, and other configuration devices. Inside the MCU, the CPU communicates with the I²C peripheral through memory-mapped registers, while the hardware manages clock generation and serial data transfer.

---

# One-Line Interview Answer

> I²C is a synchronous two-wire serial communication interface that enables a microcontroller to communicate efficiently with multiple addressed peripherals over a shared communication bus.

---
