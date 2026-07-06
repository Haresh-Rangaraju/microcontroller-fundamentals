# GPIO (General Purpose Input Output)

## What is GPIO?

GPIO (General Purpose Input Output) is the interface that allows a microcontroller to interact with the external world through its pins.

GPIO pins can operate as:

- Input → Read signals from sensors, switches, and buttons
- Output → Control LEDs, relays, buzzers, and actuators

Think of GPIO pins as the MCU's eyes, ears, and hands.

External Device
      ↕
   GPIO Pin
      ↕
     MCU

---

## Why GPIO Exists

The CPU cannot directly interact with external hardware.

GPIO provides the electrical interface between:

Hardware ↔ MCU

Without GPIO:

- Sensors cannot send information
- Switches cannot be read
- Actuators cannot be controlled

---

## GPIO in a Microcontroller

CPU
↓
GPIO Registers
↓
GPIO Hardware
↓
GPIO Pins

GPIO is a peripheral controlled through registers.

The CPU never directly changes a pin state.

It writes to GPIO registers, and GPIO hardware changes the pin voltage.

---

## Input Mode

Used to read digital signals from external devices.

Examples:

- Door switches
- Brake switches
- Push buttons
- Digital sensors

Flow:

Button
↓
GPIO Pin
↓
Input Register
↓
CPU

---

## Output Mode

Used to control external devices.

Examples:

- LEDs
- Relays
- Buzzers
- Driver circuits

Flow:

CPU
↓
Output Register
↓
GPIO Pin
↓
LED / Relay

---

## Important GPIO Registers

### Direction Register

Determines whether a pin operates as:

- Input
- Output

---

### Input Data Register (IDR)

Stores the current logic level of an input pin.

- 1 = HIGH
- 0 = LOW

CPU reads this register.

---

### Output Data Register (ODR)

Stores the output state of a GPIO pin.

- 1 = HIGH
- 0 = LOW

CPU writes to this register.

---

### Pull-Up / Pull-Down Register

Provides a default logic state for input pins.

Purpose:

- Prevent floating inputs
- Ensure stable readings

---

## GPIO and Memory-Mapped I/O

GPIO registers occupy addresses in the peripheral region of the memory map.

Example:

Flash         → 0x00000000
RAM           → 0x20000000
Peripherals   → 0x40000000

GPIO registers are accessed like memory locations.

CPU
↓
GPIO Register Address
↓
GPIO Register
↓
GPIO Hardware
↓
Pin State

This technique is called Memory-Mapped I/O.

---

## Automotive Examples

### Door Open Detection

Door Switch
↓
GPIO Input
↓
Body ECU

---

### Brake Switch Detection

Brake Switch
↓
GPIO Input
↓
ABS ECU

---

### Fuel Pump Relay Control

ECU
↓
GPIO Output
↓
Relay
↓
Fuel Pump

---

## Common Interview Questions

### What is GPIO?

GPIO stands for General Purpose Input Output and provides digital interfacing between the MCU and external devices.

### Can GPIO act as both input and output?

Yes. GPIO pins are configurable.

### What is a floating input?

An unconnected input pin whose voltage level is undefined.

### Why are pull-up and pull-down resistors used?

To provide a known default logic state and avoid floating inputs.

### How does a CPU control a GPIO pin?

By writing to GPIO output registers.

### How does a CPU read a button?

By reading the GPIO input register.

---

## Key Interview Statement

GPIO is a configurable digital interface that allows a microcontroller to communicate with external hardware through input and output pins controlled by GPIO registers.
