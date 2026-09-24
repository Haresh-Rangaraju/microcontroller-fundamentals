# CPU Architecture

## What is CPU Architecture?

CPU Architecture describes how the CPU is organized internally and how it executes instructions.

The CPU is the processing and decision-making unit of a microcontroller.

A CPU mainly consists of:

- Control Unit (CU)
- Arithmetic Logic Unit (ALU)
- Registers

---

## Why CPU Architecture is Important

The CPU is responsible for:

- Executing instructions
- Performing calculations
- Making logical decisions
- Controlling peripherals

Without the CPU, an embedded system cannot process inputs or control outputs.

---

## CPU Inside a Microcontroller

```text
+----------------------+
|        CPU           |
+----------------------+
| Flash | RAM          |
+----------------------+
| GPIO UART ADC        |
| SPI I2C Timers       |
+----------------------+
```

The CPU communicates with memory and peripherals to control the system.

---

## Main CPU Blocks

### Control Unit (CU)

Responsibilities:

- Fetch instructions
- Decode instructions
- Coordinate execution

---

### Arithmetic Logic Unit (ALU)

Performs:

- Addition
- Subtraction
- Comparisons
- AND
- OR
- XOR
- Shift operations

Example:

```c
if(temp > limit)
```

The comparison is performed by the ALU.

---

### Registers

Very fast storage locations inside the CPU.

Used for:

- Temporary data
- Addresses
- Results
- Status information

---

## Fetch-Decode-Execute Cycle

The CPU continuously performs:

1. Fetch instruction from Flash
2. Decode instruction
3. Execute instruction
4. Store result
5. Repeat

```text
Fetch
  ↓
Decode
  ↓
Execute
  ↓
Repeat
```

---

## Register-Level Thinking

### Program Counter (PC)

Stores the address of the next instruction.

### Stack Pointer (SP)

Points to stack memory.

Used during:

- Function calls
- Interrupts

### Status Register

Stores CPU status flags such as:

- Zero Flag
- Carry Flag
- Overflow Flag

---

## CPU and Memory Map

Typical memory regions:

```text
0x00000000 → Flash
0x20000000 → RAM
0x40000000 → Peripherals
```

The CPU accesses all resources through memory addresses.

---

## Memory-Mapped I/O

The CPU controls peripherals by reading and writing peripheral registers.

```text
CPU
 ↓
Peripheral Register Address
 ↓
Peripheral Hardware
```

Important:

The CPU does not directly control hardware pins.

It writes to peripheral registers, and the peripheral hardware changes the pin state.

---

## Automotive Relevance

### Engine ECU

Sensors
↓
CPU
↓
Fuel Injector

The CPU calculates fuel quantity and ignition timing.

### ABS ECU

Wheel Speed Sensors
↓
CPU
↓
Brake Pressure Control

The CPU determines whether wheel lock is occurring and controls braking accordingly.

---

## Harvard vs Von Neumann

### Harvard Architecture

Separate memory paths for:

- Instructions
- Data

Used by most modern microcontrollers.

### Von Neumann Architecture

Single memory path for:

- Instructions
- Data

---

## Interview Questions

### What is a CPU?

The CPU is the processing unit that executes instructions and controls MCU operation.

### What are the main parts of a CPU?

- Control Unit
- ALU
- Registers

### What does the ALU do?

It performs arithmetic and logical operations.

### What is the Fetch-Decode-Execute cycle?

The CPU fetches an instruction, decodes it, executes it, and repeats continuously.

### What is the Program Counter?

A register that stores the address of the next instruction.

### Why are registers faster than RAM?

Registers are located inside the CPU and require fewer clock cycles to access.

### Where are instructions stored?

Flash memory.

### Where are variables stored?

RAM.

### How does the CPU control peripherals?

By reading and writing peripheral registers through memory-mapped addresses.

---

## Common Confusions

### CPU vs MCU

```text
MCU
├── CPU
├── Flash
├── RAM
└── Peripherals
```

The CPU is only one part of the MCU.

### ALU vs CPU

```text
CPU
├── ALU
├── Control Unit
└── Registers
```

The ALU is a component of the CPU.

### Does the CPU directly control GPIO pins?

No.

The CPU writes to GPIO registers, and GPIO hardware changes the pin state.

---

## Summary

CPU Architecture explains how the CPU executes instructions, processes data, uses registers, accesses memory, and controls peripherals inside a microcontroller.
