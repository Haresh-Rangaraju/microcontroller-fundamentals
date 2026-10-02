# Microcontroller Fundamentals

A structured learning repository focused on **microcontrollers, MCU architecture, peripherals, register-level programming, firmware interaction, and embedded-system integration**.

This is the primary repository for the microcontroller-related portion of my embedded engineering learning roadmap.

---

## Purpose

The purpose of this repository is to develop the ability to:

- Understand microcontroller architecture
- Understand MCU memory organisation
- Work with registers and memory-mapped peripherals
- Configure MCU peripherals
- Understand GPIO and alternate functions
- Understand interrupts and execution flow
- Work with timers, PWM and ADC
- Work with UART, SPI and I2C
- Understand driver structure
- Debug embedded-system problems
- Integrate peripherals and firmware
- Explain hardware–software interaction clearly

---

## Repository Structure

```text
microcontroller-fundamentals/
│
├── README.md
│
├── phase-1/
│   └── Phase 1 learning documentation
│
└── phase-2/
    │
    ├── C1-stm32-mcu-depth/
    ├── C2-gpio-interrupts/
    ├── C3-timers-pwm-adc/
    ├── C4-communication-peripherals/
    ├── C5-firmware-debugging/
    └── C6-engineering-integration/
```

---

# Phase 1 — Microcontroller Foundation

Phase 1 establishes the basic microcontroller knowledge required before moving into deeper MCU programming.

Major areas include:

- Introduction to microcontrollers
- CPU architecture
- Registers
- Memory maps
- GPIO
- GPIO applications
- Interrupt fundamentals
- Timers
- ADC
- UART
- SPI
- I2C
- Basic MCU applications
- MCU revision and interview preparation

Phase 1 focuses on **understanding the fundamental building blocks of a microcontroller**.

---

# Phase 2 — Embedded Engineering Depth

Phase 2 moves from basic understanding toward working with a real MCU and reasoning about firmware at a deeper level.

## Cycle 1 — STM32 & MCU Depth

Focus:

- STM32 architecture and ecosystem
- STM32 internal architecture
- Clock system
- Memory organisation
- Register architecture
- Memory-mapped registers
- Register-level programming
- GPIO architecture
- GPIO register configuration

## Cycle 2 — GPIO, Interrupts & Firmware Control

Focus:

- GPIO input/output configuration
- GPIO modes
- Alternate functions
- Interrupt fundamentals
- Interrupt sources and configuration
- Interrupt execution flow
- Interrupt-related firmware design
- Interrupt debugging
- State-machine fundamentals

## Cycle 3 — Timers, PWM & ADC

Focus:

- Timer architecture
- Timer configuration
- Counters and timing
- Timer interrupts
- PWM generation
- PWM configuration and applications
- ADC architecture
- ADC configuration
- ADC data acquisition and processing

## Cycle 4 — Communication Peripherals & Drivers

Focus:

- UART hardware and operation
- UART configuration
- UART driver structure
- SPI hardware and operation
- SPI configuration
- SPI driver structure
- I2C hardware and operation
- I2C configuration
- I2C driver structure

## Cycle 5 — Modular Firmware & Debugging

Focus:

- Embedded firmware architecture
- Header/source organisation
- Modular driver design
- Hardware abstraction concepts
- State-machine based firmware
- Embedded debugging methodology
- Fault isolation
- Hardware vs software debugging
- Firmware integration and troubleshooting

## Cycle 6 — Engineering Integration

Focus:

- Peripheral integration
- Interrupt and peripheral interaction
- Driver and application interaction
- Timing and execution-flow reasoning
- Integrated firmware debugging
- Embedded engineering problem solving
- Technical explanation

---

## Learning Progression

Phase 2 follows this engineering progression:

```text
Requirement
     ↓
MCU Peripheral
     ↓
Register Configuration
     ↓
Driver
     ↓
Application Logic
     ↓
Hardware Behaviour
     ↓
Debugging
```

The goal is to understand not only **what** a peripheral does, but also:

- Why it is used
- How it is configured
- How firmware controls it
- How hardware responds
- How problems can be diagnosed

---

## Phase 2 Capacity

Phase 2 is planned around:

```text
15 weeks
     ↓
75 raw blocks
     ↓
15 buffer blocks
     ↓
60 planned blocks
```

The 60 planned blocks contain:

- 42 technical learning blocks
- 12 revision blocks
- 6 mock interview blocks

The buffer is deliberately kept outside the syllabus.

---

## Scope

This repository focuses on **microcontrollers and embedded hardware–firmware interaction**.

C and firmware concepts are primarily documented in:

- `embedded-c-fundamentals`

Supporting electronics concepts are documented in:

- `electronics-fundamentals`

Automotive engineering context is documented in:

- `automotive-fundamentals`

---

## Important Boundary

Phase 2 is an **Embedded Engineering Depth** phase.

It intentionally does not attempt to cover advanced topics such as:

- AUTOSAR
- Advanced CAN
- RTOS mastery
- Advanced Embedded Linux
- Advanced control systems

These are reserved for later stages of the roadmap.

---

## Roadmap Role

This repository supports the progression:

```text
Embedded Fundamentals
        ↓
Microcontroller Depth
        ↓
Firmware Development
        ↓
Automotive Embedded
        ↓
Automotive R&D
```

---

## Author

**Haresh R.**

BE Electronics and Communication Engineering
