# UART (Universal Asynchronous Receiver/Transmitter)

## Overview

UART (Universal Asynchronous Receiver/Transmitter) is a hardware communication peripheral inside a microcontroller that enables **asynchronous serial communication**.

Instead of sending multiple bits at once, UART sends **one bit at a time** through communication lines.

It allows a microcontroller to communicate with devices such as:
- Another microcontroller
- PC/Laptop
- GPS module
- Bluetooth module
- Wi-Fi module
- Diagnostic tools

---

# Why UART is Needed

Without UART, the CPU would have to manually control every communication bit.

UART hardware automatically handles serial transmission and reception, reducing CPU workload.

---

# UART Inside a Microcontroller

```
+----------------------+
|         CPU          |
+----------------------+
|      Registers       |
+----------------------+
|        UART          |
+----------------------+
|      TX      RX      |
+----------------------+
```

UART acts as a bridge between the CPU and external communication devices.

---

# How UART Works

Suppose the CPU wants to send the character **'A'**.

### Step 1
CPU writes the data into the UART Transmit Register.

```
CPU
 ↓
TX Register
```

### Step 2
UART converts the byte into a serial bit stream.

Example:

```
'A'

↓

01000001
```

### Step 3
UART adds framing bits.

Typical frame:

```
Start Bit

Data Bits

Stop Bit
```

Example:

```
0 01000001 1
```

### Step 4
Bits are transmitted one at a time through the TX pin.

```
UART
 ↓
TX Pin
 ↓
External Device
```

### Step 5
Receiving UART collects the incoming bits.

```
RX Pin
 ↓
UART Receiver
```

### Step 6
UART reconstructs the original byte.

```
Bits
 ↓
Byte ('A')
```

### Step 7
Received data is stored in the Receive Register.

```
UART
 ↓
RX Register
 ↓
CPU
```

---

# Complete UART Data Flow

```
CPU
 ↓
TX Register
 ↓
UART Hardware
 ↓
TX Pin
 ↓
Communication Wire
 ↓
RX Pin
 ↓
UART Receiver
 ↓
RX Register
 ↓
CPU
```

---

# Embedded & Automotive Relevance

UART is commonly used for:

- ECU debugging
- Firmware downloading
- GPS communication
- Bluetooth communication
- Wi-Fi modules
- Manufacturing tests
- Diagnostic interfaces

Although CAN, LIN and Ethernet are used for ECU-to-ECU communication, UART remains important during development and testing.

---

# Register-Level View

## Transmit Data Register (TX Register)

Stores data waiting to be transmitted.

```
CPU
 ↓
TX Register
 ↓
UART
```

---

## Receive Data Register (RX Register)

Stores received data.

```
UART
 ↓
RX Register
 ↓
CPU
```

---

## Control Register

Controls UART operation.

Typical settings:
- UART Enable
- Transmitter Enable
- Receiver Enable

---

## Status Register

Stores UART status.

Examples:
- Transmit Complete
- Receive Complete
- Busy
- Error

---

## Baud Rate Register

Stores communication speed.

Examples:

- 9600
- 115200
- 230400

Both communicating devices must use the same baud rate.

---

# Memory Map Connection

UART registers are memory-mapped.

```
Flash
0x00000000

RAM
0x20000000

UART Registers
0x400xxxxx
```

The CPU accesses UART by reading and writing these registers.

The UART hardware performs the actual serial communication.

---

# Real-World Examples

## Automotive

- ECU Debug Console
- GPS Communication
- Firmware Download

## Consumer Electronics

- Bluetooth Modules
- ESP8266 Wi-Fi Module

## Industrial Systems

- Barcode Scanner
- PLC HMI Display

---

# Interview Questions

### What is UART?

UART is a hardware peripheral that performs asynchronous serial communication by transmitting and receiving one bit at a time.

---

### What does UART stand for?

Universal Asynchronous Receiver/Transmitter.

---

### Is UART serial or parallel communication?

Serial communication.

---

### Why is UART asynchronous?

UART does not use a separate clock line.

Both devices communicate using the same configured baud rate.

---

### What are TX and RX?

- TX → Transmit
- RX → Receive

---

### What is baud rate?

Baud rate is the communication speed, usually measured in bits per second (bps).

---

### Can UART communicate with a PC?

Yes.

Typically through a USB-to-UART converter.

---

### Where is received data stored?

In the UART Receive Data Register (RX Register).

---

### Can UART generate interrupts?

Yes.

Many MCUs generate interrupts when:
- Data is received
- Transmission completes

---

# Common Mistakes

### UART is USB

Wrong.

UART is a serial communication peripheral.

USB is a much more complex communication standard.

Many development boards include a USB-to-UART converter.

---

### UART is the same as SPI or I²C

Wrong.

| UART | SPI | I²C |
|------|-----|-----|
| No Clock Line | Uses Clock | Uses Clock |
| TX & RX | Master-Slave | Two-Wire Bus |
| Asynchronous | Synchronous | Synchronous |

---

### CPU sends every bit

Wrong.

The CPU writes a complete byte to the TX Register.

UART hardware automatically shifts the bits out.

---

# Key Takeaways

- UART is an asynchronous serial communication peripheral.
- Sends data one bit at a time.
- Uses TX and RX communication lines.
- No separate clock line is required.
- CPU writes bytes; UART hardware transmits bits.
- Commonly used for debugging, firmware updates, GPS, Bluetooth, and diagnostics.

---

# One-Line Interview Answer

UART (Universal Asynchronous Receiver/Transmitter) is a hardware peripheral that enables asynchronous serial communication by transmitting and receiving one bit at a time over TX and RX lines. It is widely used in embedded systems for debugging, firmware downloading, and communication with external modules such as GPS, Bluetooth, and Wi-Fi.
