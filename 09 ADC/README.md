# ADC (Analog-to-Digital Converter)

## Overview
An Analog-to-Digital Converter (ADC) is a hardware peripheral inside a microcontroller that converts an analog voltage into a digital value that the CPU can process.

In embedded systems and automotive ECUs, ADCs are essential because many sensors produce analog voltages, while the CPU can process only digital data.

---

## Why ADC is Needed

Most real-world quantities are analog in nature, such as:
- Temperature
- Pressure
- Light intensity
- Battery voltage
- Accelerator pedal position

The CPU understands only digital data. Therefore, the ADC acts as a bridge between the analog world and the digital processor.

```
Real World
     ↓
Analog Voltage
     ↓
ADC
     ↓
Digital Value
     ↓
CPU
```

---

## ADC in a Microcontroller

```
+----------------------+
|         CPU          |
+----------------------+
|      Registers       |
+----------------------+
|         ADC          |
+----------------------+
|    Analog Input Pin  |
+----------------------+
```

The ADC sits between the external analog signal and the CPU.

---

## Automotive Applications

### Engine Coolant Temperature
```
Temperature Sensor
        ↓
Analog Voltage
        ↓
ADC
        ↓
CPU
        ↓
Cooling Fan Control
```

### Accelerator Pedal Position
```
Pedal Sensor
      ↓
Voltage
      ↓
ADC
      ↓
CPU
      ↓
Throttle Control
```

### Battery Voltage Monitoring
```
Battery
   ↓
Voltage
   ↓
ADC
   ↓
CPU
   ↓
Battery Management
```

---

## Internal Working

1. A sensor produces an analog voltage.
2. The analog voltage enters the ADC input pin.
3. The ADC samples the voltage.
4. The ADC converts the voltage into a digital number.
5. The result is stored in the ADC result register.
6. The CPU reads the digital value and makes a decision.

Example:
```
Temperature
   ↓
Temperature Sensor
   ↓
Analog Voltage
   ↓
ADC
   ↓
Digital Value
   ↓
CPU
   ↓
Decision
```

---

## ADC Registers

### Control Register
Used to:
- Enable or disable the ADC
- Start a conversion
- Configure ADC settings

### Channel Selection Register
Selects which analog input pin will be converted.

### Result Register
Stores the converted digital value.

### Status Register
Indicates:
- Conversion complete
- ADC busy
- Error conditions

---

## Important Concepts

### ADC Resolution
Resolution determines how many digital values the ADC can represent.

Example:
- 8-bit ADC → 256 values
- 10-bit ADC → 1024 values
- 12-bit ADC → 4096 values

### Reference Voltage
The ADC compares the input voltage against a reference voltage, often called Vref.

### Conversion Result
A higher analog voltage produces a higher digital value, provided the reference voltage remains the same.

---

## Embedded and Automotive Relevance

ADC is used with sensors such as:
- Temperature sensors
- Pressure sensors
- Fuel level sensors
- Potentiometers
- Battery voltage sensors

The ADC does not directly control actuators. Instead, the CPU uses the converted digital value to decide how to control actuators through peripherals such as GPIO or PWM.

---

## Common Interview Questions

### What is an ADC?
An ADC is a hardware peripheral that converts an analog voltage into a digital value that the CPU can process.

### Why is an ADC needed?
Because the CPU processes digital data, while many sensors produce analog voltages.

### What is the output of an ADC?
A digital number representing the input analog voltage.

### Does the CPU perform analog-to-digital conversion?
No. The ADC hardware performs the conversion. The CPU only configures the ADC and reads the result.

### Can GPIO read analog voltages?
No. Standard GPIO reads only digital HIGH or LOW. Analog voltages require an ADC.

---

## Common Confusions

### ADC vs GPIO
- GPIO reads digital HIGH or LOW signals.
- ADC reads analog voltages.

### ADC vs Sensor
- The sensor produces the analog signal.
- The ADC converts that analog signal into a digital value.

### CPU Measures Voltage Directly
The CPU cannot measure analog voltage directly. The ADC performs the conversion first.

---

## Key Takeaways

- ADC converts analog voltage into digital data.
- It enables the CPU to read sensor values.
- It is widely used in automotive ECUs for monitoring temperature, pressure, pedal position, and battery voltage.
- The ADC hardware performs the conversion, while the CPU reads and processes the result.

---

## One-Line Interview Answer

An ADC is a hardware peripheral that converts an analog voltage into a digital value so that the CPU can process real-world sensor signals in embedded and automotive systems.
