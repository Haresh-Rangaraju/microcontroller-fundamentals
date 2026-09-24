# Introduction to Microcontrollers (MCU)

## What is a Microcontroller?

A Microcontroller (MCU) is a compact computer integrated on a single chip that contains:

* CPU
* Flash Memory
* RAM
* Peripherals (GPIO, UART, SPI, I2C, ADC, Timers, etc.)

MCUs are designed to control embedded systems by reading inputs, processing data, and controlling outputs.

---

## Why Microcontrollers are Used

Microcontrollers provide:

* Processing capability
* Memory storage
* Hardware interfaces
* Low power consumption
* Real-time control

They act as the central controller of an embedded system.

---

## Basic Embedded System

```text
Sensor
   ↓
 MCU
   ↓
Actuator
```

Example:

```text
Temperature Sensor
        ↓
       MCU
        ↓
Cooling Fan
```

The MCU reads sensor data and controls the output device based on programmed logic.

---

## Main Components of an MCU

### CPU

Executes program instructions and performs calculations.

### Flash Memory

Non-volatile memory used to store firmware and program code.

### RAM

Temporary memory used during program execution.

### Peripherals

Hardware modules used for interfacing with external devices.

Examples:

* GPIO
* UART
* SPI
* I2C
* ADC
* Timers

---

## Embedded Perspective

When powered ON:

1. MCU receives power.
2. CPU starts executing instructions from Flash memory.
3. Data is processed using registers and RAM.
4. Peripherals are controlled through registers.

---

## Registers

Registers are small, high-speed memory locations used by the CPU and peripherals.

They store:

* Data
* Addresses
* Configuration settings
* Status information

Registers are the primary mechanism used to control hardware.

---

## Memory-Mapped I/O

Peripherals are assigned memory addresses.

Example:

```text
CPU
 ↓
Memory Address
 ↓
Peripheral Register
 ↓
Hardware Action
```

This technique is called Memory-Mapped I/O.

---

## Automotive Relevance

Microcontrollers are used in:

* Engine Control Units (ECU)
* ABS Controllers
* Airbag Systems
* Body Control Modules

Example:

```text
Wheel Speed Sensor
        ↓
       MCU
        ↓
   ABS Logic
        ↓
 Brake Actuator
```

The MCU processes sensor data and controls vehicle functions.

---

## MCU vs MPU

| MCU                                    | MPU                                               |
| -------------------------------------- | ------------------------------------------------- |
| CPU + Memory + Peripherals on one chip | Mainly CPU                                        |
| Lower power consumption                | Higher performance                                |
| Used in embedded control systems       | Used in complex systems requiring external memory |

---

## Interview Questions

### What is a microcontroller?

A microcontroller is a single-chip computer containing CPU, memory, and peripherals used to control embedded systems.

### Why is MCU used in embedded systems?

Because it provides processing, memory, and hardware interfaces in one compact device.

### Name some MCU peripherals.

GPIO, UART, SPI, I2C, ADC, Timers, and Interrupt Controller.

### What is Memory-Mapped I/O?

A method where peripheral registers are assigned memory addresses and accessed like memory.

### What is the role of RAM?

RAM stores temporary data and variables during program execution.

### What is Flash memory?

Flash is non-volatile memory used to store firmware and program code.

---

## Summary

A microcontroller is the central controller of an embedded system. It integrates CPU, memory, and peripherals on a single chip and enables real-time interaction with sensors, actuators, and communication interfaces.
