# GPIO Applications

## Overview
GPIO (General Purpose Input/Output) applications describe how a microcontroller uses its GPIO pins to interact with external hardware. GPIO serves as the bridge between the MCU and the physical world, allowing it to read digital inputs and control digital outputs.

Unlike the GPIO fundamentals topic, which explains how GPIO works internally, this topic focuses on **where** and **why** GPIO is used in real embedded systems and automotive Electronic Control Units (ECUs).

---

# Why GPIO Applications are Important

GPIO enables a microcontroller to:

- Read digital signals from external devices
- Control digital output devices
- Detect external events
- Enable or disable hardware modules

Without GPIO, the MCU would not be able to communicate with most external components.

Typical applications include:

- Buttons
- Switches
- LEDs
- Relays
- Buzzers
- Digital sensors
- Enable and Reset signals

---

# GPIO in an Embedded System

```
External Device
      │
      ▼
GPIO Pin
      │
GPIO Peripheral
      │
GPIO Registers
      │
CPU
```

GPIO acts as the interface between the CPU and external hardware.

---

# GPIO Applications in Automotive ECUs

Although many automotive sensors communicate using protocols like CAN, SPI, I²C, or ADC, GPIO is still widely used for simple digital signals.

### Door Open Detection

```
Door Switch
     │
     ▼
GPIO Input
     │
     ▼
CPU
     │
     ▼
Dashboard Warning Lamp
```

The ECU reads the GPIO input to determine whether the door is open or closed.

---

### Brake Pedal Detection

```
Brake Switch
      │
      ▼
GPIO Input
      │
      ▼
ABS ECU
```

The ECU detects the brake pedal status through a GPIO input.

---

### Fuel Pump Relay Control

```
CPU
 │
 ▼
GPIO Output
 │
 ▼
Relay
 │
 ▼
Fuel Pump
```

GPIO provides the control signal for the relay that powers the fuel pump.

---

### ECU Enable Signal

```
Engine ECU
      │
GPIO Output
      │
      ▼
Transmission ECU Enable
```

One ECU can enable or disable another ECU using a GPIO output.

---

# GPIO Applications

## Digital Inputs

GPIO is commonly used to read:

- Buttons
- Door switches
- Brake switches
- Limit switches
- Hall-effect digital sensors
- Motion sensors

---

## Digital Outputs

GPIO is commonly used to control:

- LEDs
- Relays
- Buzzers
- Solenoid enable signals
- Driver IC enable pins

---

## Communication Support

Even communication peripherals rely on GPIO pins for signals such as:

- Chip Select (SPI)
- Reset
- Enable
- Interrupt

GPIO therefore supports many communication interfaces indirectly.

---

# Example: Cooling Fan Relay Operation

When engine temperature becomes too high:

```
Temperature Sensor
        │
        ▼
       CPU
        │
        ▼
GPIO Output Register
        │
        ▼
GPIO Hardware
        │
        ▼
GPIO Pin
        │
        ▼
Relay Driver
        │
        ▼
Relay
        │
        ▼
Cooling Fan
```

The CPU writes to the GPIO output register, GPIO hardware changes the pin voltage, and the relay switches the cooling fan ON.

---

# Register-Level View

GPIO applications depend on several registers.

### Direction Register

Determines whether a pin operates as:

- Input
- Output

---

### Input Data Register

Stores the current logic level of an input pin.

Possible values:

- HIGH (1)
- LOW (0)

The CPU reads this register.

---

### Output Data Register

Stores the desired output logic level.

Possible values:

- HIGH (1)
- LOW (0)

The CPU writes to this register.

---

### Pull-up / Pull-down Register

Provides a defined default logic level for input pins and prevents floating inputs.

---

# Typical Register Flow

### Output

```
CPU
 │
 ▼
Direction Register
 │
 ▼
Output Register
 │
 ▼
GPIO Hardware
 │
 ▼
GPIO Pin
```

### Input

```
GPIO Pin
 │
 ▼
Input Register
 │
 ▼
CPU
```

---

# Memory Map Connection

GPIO registers are memory-mapped into the MCU's peripheral address space.

Typical layout:

| Memory Region | Example Address |
|--------------|----------------|
| Flash | 0x00000000 |
| RAM | 0x20000000 |
| GPIO Registers | 0x400xxxxx |

(Exact addresses depend on the MCU.)

---

# Memory-Mapped I/O

```
CPU
 │
 ▼
GPIO Register Address
 │
 ▼
GPIO Register
 │
 ▼
GPIO Hardware
 │
 ▼
External Device
```

The CPU never changes the GPIO pin directly. It accesses GPIO registers through memory-mapped I/O.

---

# Real-World Examples

## Automotive

- Door open detection
- Brake lamp control
- Fuel pump relay control

---

## Consumer Electronics

- Power button
- Status LED

---

## Industrial Systems

- Conveyor limit switch
- Alarm buzzer

---

# Interview Questions

### What are GPIO applications?

GPIO applications are the use of GPIO pins to read digital inputs and control digital outputs.

---

### Give examples of GPIO inputs.

- Buttons
- Switches
- Door sensors
- Limit switches
- Hall-effect sensors

---

### Give examples of GPIO outputs.

- LEDs
- Relays
- Buzzers
- Enable pins
- Digital control signals

---

### Why are pull-up resistors used?

They provide a defined logic level when no external device is driving the input, preventing floating inputs.

---

### Why is GPIO commonly used with relays?

GPIO provides the digital control signal to a relay driver, which switches higher-current loads.

---

### Can GPIO be used with communication peripherals?

Yes. GPIO pins are commonly used for Chip Select, Reset, Enable, and Interrupt signals.

---

### Can one GPIO pin be both input and output at the same time?

No. A GPIO pin is configured as either an input or an output at a given time (excluding alternate-function modes).

---

### Why can't the CPU directly control an LED?

The CPU writes to the GPIO output register, and the GPIO hardware drives the pin connected to the LED.

---

### What kind of signals does GPIO handle?

GPIO handles digital HIGH and LOW signals.

---

# Common Misconceptions

### GPIO vs ADC

GPIO:

- Reads digital HIGH/LOW signals

ADC:

- Converts analog voltages into digital values

---

### GPIO Can Drive Any Load

Incorrect.

GPIO pins can supply only limited current.

Large loads require:

- Transistor
- MOSFET
- Relay
- Driver IC

---

### GPIO is Only for LEDs

Incorrect.

GPIO is also used for:

- Switches
- Sensors
- Relays
- Enable signals
- Interrupt lines
- Chip Select signals
- Status indicators

---

# Interview Traps

### Can GPIO directly power a motor?

No.

GPIO provides only a low-power digital control signal. Motors require a transistor, MOSFET, relay, or dedicated motor driver because they draw much more current than a GPIO pin can safely supply.

---

### Can GPIO read analog voltage?

No.

Standard GPIO reads only digital HIGH or LOW logic levels. Analog voltages must first be converted by an ADC before the CPU can process them.

---

# Key Takeaways

- GPIO is the MCU's interface to the physical world.
- GPIO is used for digital inputs and outputs.
- GPIO is widely used in automotive ECUs for switches, relays, sensors, and indicators.
- GPIO registers are memory-mapped into the peripheral address space.
- GPIO handles digital signals only.
- High-current loads require external driver circuits.
- Many communication peripherals rely on GPIO pins for auxiliary control signals such as Chip Select, Reset, Enable, and Interrupt.
