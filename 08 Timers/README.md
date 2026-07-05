# ⏱️ Timers in Embedded Systems (Phase 1 Foundation)

## 📌 Overview

A **Timer** is a dedicated hardware peripheral inside a microcontroller that automatically counts clock pulses. Unlike the CPU, which executes program instructions, the timer continues counting independently, making it essential for measuring time, generating periodic events, and supporting real-time embedded applications.

Think of it as a **hardware stopwatch** running alongside the CPU.

---

# 🎯 Why Timers Exist

Many embedded applications require precise timing.

Examples:

- Wait for 1 ms
- Blink an LED every second
- Measure engine RPM
- Measure wheel speed
- Generate periodic interrupts
- Measure pulse widths

Using the CPU alone for timing would waste processing time.

Timers solve this problem by handling time measurement in dedicated hardware.

---

# 🏗️ Timer Architecture

```
+----------------------+
|         CPU          |
+----------------------+
|     Timer Registers  |
+----------------------+
|        Timer         |
+----------------------+
|      Clock Input     |
+----------------------+
```

The timer receives clock pulses and counts them automatically while the CPU performs other tasks.

---

# ⚙️ Internal Working

## Step 1

The system clock generates pulses.

```
Clock
   ↓
Tick Tick Tick Tick ...
```

---

## Step 2

The timer receives these clock pulses.

```
Clock
   ↓
Timer Counter
```

---

## Step 3

The counter increments automatically.

```
0 → 1 → 2 → 3 → 4 → ...
```

---

## Step 4

The counter reaches a predefined value stored in the compare register.

Example:

```
Target = 1000
```

When:

```
Counter == 1000
```

an event occurs.

---

## Step 5

The timer sets an interrupt flag.

```
Timer
   ↓
Interrupt Flag
```

---

## Step 6

The interrupt controller notifies the CPU.

```
Timer
   ↓
Interrupt
   ↓
CPU
```

---

## Step 7

The CPU executes the Timer Interrupt Service Routine (ISR).

Example tasks:

- Read sensors
- Update variables
- Check communication timeout

---

## Step 8

Depending on the timer mode, the counter either restarts or continues counting.

---

# 🔄 Complete Timer Flow

```
Clock
   ↓
Timer Counter
   ↓
Target Reached
   ↓
Interrupt
   ↓
CPU
   ↓
ISR
   ↓
Continue Counting
```

---

# 🚗 Automotive Applications

## 1. Engine RPM Measurement

```
Crankshaft Sensor
        ↓
      Timer
        ↓
       CPU
        ↓
Calculate RPM
```

---

## 2. ABS Wheel Speed

```
Wheel Sensor
      ↓
    Timer
      ↓
     CPU
      ↓
Vehicle Speed
```

---

## 3. ECU Periodic Scheduler

```
1 ms Timer
      ↓
Interrupt
      ↓
Read Sensors
Update Outputs
Check Faults
```

Most automotive ECUs schedule their periodic software tasks using timers.

---

## 4. Communication Timing

Timers are used for:

- Communication timeouts
- Message scheduling
- Protocol timing

---

# 📚 Register-Level Understanding

## Control Register

Controls timer operation.

Examples:

- Enable timer
- Disable timer
- Select timer mode

---

## Counter Register

Stores the current timer count.

Example:

```
0
1
2
3
...
```

The hardware updates this register automatically.

---

## Prescaler Register

Sometimes the system clock is too fast.

The prescaler divides the clock frequency before it reaches the timer.

```
Clock
   ↓
Prescaler
   ↓
Slower Clock
   ↓
Timer
```

This allows longer timing intervals.

---

## Compare Register

Stores the target count value.

Example:

```
Compare = 1000
```

When:

```
Counter == Compare
```

the timer generates an event such as an interrupt.

---

## Status Register

Stores timer status information.

Examples:

- Overflow
- Compare Match
- Interrupt Pending

---

# 🧠 Memory-Mapped I/O

Timer registers are located in the MCU's peripheral memory region.

Example:

```
Flash              0x00000000

RAM                0x20000000

Timer Registers    0x400xxxxx
```

The CPU configures the timer by reading and writing these registers.

The timer hardware performs the counting independently.

---

# ⭐ Important Interview Concept

The CPU **does not increment the timer counter**.

The **timer hardware** increments the counter automatically using clock pulses.

---

# 🌍 Real-World Examples

## Automotive

- Engine RPM measurement
- ABS wheel speed calculation
- ECU periodic task scheduling

---

## Consumer Electronics

- Washing machine delays
- Microwave countdown timers

---

## Industrial Systems

- PLC periodic scan cycles
- Conveyor encoder speed measurement

---

# 📝 Interview Questions

### Q1. What is a timer?

A timer is a hardware peripheral that counts clock pulses to measure time or generate timed events.

---

### Q2. Why are timers needed?

They provide accurate timing without requiring the CPU to continuously count time.

---

### Q3. Does the CPU increment the timer?

No.

The timer hardware increments its counter automatically using the clock.

---

### Q4. What is a timer interrupt?

A timer interrupt is generated when the timer reaches a specified condition such as a compare match or overflow.

---

### Q5. What is a prescaler?

A prescaler divides the input clock frequency before it reaches the timer, allowing longer timing intervals.

---

### Q6. What is stored in the counter register?

The current timer count value.

---

### Q7. Can a timer work while the CPU executes other tasks?

Yes.

The timer operates independently of the CPU.

---

### Q8. Where are timer registers located?

They are located in the memory-mapped peripheral region of the microcontroller.

---

### Q9. Give two automotive applications of timers.

- Measuring engine RPM
- Measuring wheel speed for ABS

---

# ⚠️ Common Misconceptions

## ❌ Timer and Clock are the same

Incorrect.

```
Clock
   ↓
Provides Pulses

Timer
   ↓
Counts Pulses
```

The clock generates pulses.

The timer counts them.

---

## ❌ The CPU counts time

Incorrect.

The CPU only:

- Configures the timer
- Reads timer values
- Handles timer interrupts

The timer hardware performs the counting.

---

## ❌ Timers are only used for delays

Incorrect.

Timers are also used for:

- Time measurement
- Frequency measurement
- Pulse width measurement
- Periodic scheduling
- ADC triggering
- Motor control (PWM in later phases)

---

# 🚀 Key Takeaways

- Timers are dedicated hardware peripherals.
- They automatically count clock pulses.
- They operate independently of the CPU.
- Timers provide accurate timing for real-time systems.
- They are heavily used in automotive ECUs for RPM measurement, wheel speed calculation, communication timing, and periodic task scheduling.
- The CPU configures the timer, but the timer hardware performs the counting.

---

# 🎯 One-Line Interview Answer

A timer is a hardware peripheral that automatically counts clock pulses independently of the CPU to measure time, generate periodic events, and support real-time embedded applications such as engine RPM measurement, ABS wheel speed calculation, communication timing, and periodic ECU task scheduling.
