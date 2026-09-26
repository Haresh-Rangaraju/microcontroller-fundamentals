# Memory Map

## Overview

A memory map is the organization of the MCU address space into different regions, where each region corresponds to a specific hardware resource.

Examples:

* Flash Memory → Program instructions
* RAM → Variables and stack
* Peripheral Registers → GPIO, UART, ADC, Timers

The CPU accesses everything using addresses.

---

## Why Memory Maps Exist

Memory maps provide a systematic way for the CPU to access:

* Program instructions
* Variables
* Registers
* Hardware peripherals

Instead of using different mechanisms, everything is assigned an address.

Address → Resource

---

## Typical MCU Memory Map

```
High Address
──────────────────

Peripheral Registers
0x40000000

──────────────────

RAM
0x20000000

──────────────────

Flash Memory
0x00000000

──────────────────
Low Address
```

---

## Internal Working

Example: Reading an ADC value

1. CPU requests sensor data.
2. CPU places an address on the address bus.
3. Address decoder selects the peripheral.
4. ADC register returns data.
5. CPU processes the data.
6. Result is stored in RAM.

Flow:

```
Sensor
 ↓
ADC Register
 ↓
CPU Register
 ↓
ALU
 ↓
RAM
 ↓
Output Register
 ↓
Actuator
```

---

## Memory-Mapped I/O

Peripherals are assigned addresses inside the memory map.

Example:

```
CPU
 ↓
GPIO Register Address
 ↓
GPIO Register
 ↓
GPIO Hardware
 ↓
LED ON
```

The CPU never controls hardware directly.

It accesses registers through addresses.

---

## Major Regions

### Flash Memory

Stores:

* Program instructions
* Constants

Typical base address:

```
0x00000000
```

---

### RAM

Stores:

* Variables
* Stack
* Temporary data

Typical base address:

```
0x20000000
```

---

### Peripheral Region

Contains:

* GPIO Registers
* UART Registers
* ADC Registers
* Timer Registers

Typical base address:

```
0x40000000
```

---

## Embedded and Automotive Examples

### Engine ECU

```
Flash
 ↓
Fuel Algorithm

ADC Register
 ↓
Throttle Data

RAM
 ↓
Calculation

PWM Register
 ↓
Injector
```

### ABS ECU

```
Wheel Sensor
 ↓
Timer Register
 ↓
CPU
 ↓
PWM Register
 ↓
Brake System
```

### CAN Communication

```
CAN Receive Register
 ↓
CPU
```

---

## Interview Questions

### What is a memory map?

A memory map is the organization of address space into Flash, RAM, and peripheral regions.

### Why is a memory map needed?

It allows the CPU to access memory and hardware through addresses.

### What is memory-mapped I/O?

Memory-mapped I/O is a technique where peripheral registers are assigned addresses and accessed like memory locations.

### What is stored in Flash?

Program instructions and constants.

### What is stored in RAM?

Variables, stack, and temporary data.

### Can CPU directly control GPIO?

No. CPU accesses GPIO registers through their addresses.

### Are peripherals memory?

No. Their registers are mapped into the memory address space.

---

## Common Confusions

### Memory Map ≠ Only RAM and Flash

It includes:

* Flash
* RAM
* Peripheral Registers

### Peripheral Registers ≠ RAM

They occupy address space but belong to hardware peripherals.

### CPU Does Not Directly Control Hardware

Actual flow:

```
CPU
 ↓
Address
 ↓
Register
 ↓
Hardware
```

---

## Final Summary

A memory map organizes the MCU address space into Flash, RAM, and peripheral regions, enabling the CPU to access memory and hardware through addresses using memory-mapped I/O.

### One-Line Interview Answer

A memory map is the organization of MCU address space into Flash, RAM, and peripheral regions, allowing the CPU to access memory and hardware using addresses.
