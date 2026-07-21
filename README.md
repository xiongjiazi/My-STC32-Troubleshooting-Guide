## 🛠️ Case Study: Motor Unresponsiveness & RZ7899 Driver Debugging

 **Soldering & Debugging Guidelines:**
 - **Header Pin Contact & Cold Joints:** When driving motors with SMD ICs (e.g., RZ7899), if the motor fails to respond after powering on, **do not replace the MCU blindly**. Always perform a "pin-by-pin sliding contact test" first to rule out cold solder joints.
 - **Soldering Ergonomics & Safety:** Use a lightweight, constant-temperature soldering iron paired with a compact fume extractor to ensure steady hand control during delicate SMD soldering while protecting respiratory health.

---

### 🔍 FAE Field Troubleshooting Table

| Fault Symptom | Step-by-Step Investigation | Root Cause | Solution & Workaround |
| :--- | :--- | :--- | :--- |
| **Motor completely unresponsive after code upload & power-on** | 1. Slid the motor terminal up and down along the header pins to test contact consistency.<br>2. Swapped in a spare motor for cross-validation.<br>3. Identified that only the bottom-right pin contact triggered a response. | **SMD Driver Pin Cold Joint:** Cold solder joints on the bottom pins of the RZ7899 driver IC caused unstable power delivery to the header pins. | Re-soldered the IC pins on the bottom layer of the PCB. Practiced on a spare board beforehand to ensure first-time soldering success. |
| **Single-side (bottom-left) motor failed to run after soldering** | 1. Re-soldered the bottom pins (issue persisted).<br>2. Measured output voltage across the header pins; voltage was normal.<br>3. Tested the motor on a verified functional test board. | **Damaged Motor Terminal:** Soldering in tight physical space damaged the motor terminal, preventing conduction via flat surface contact. | Located a specific conductive physical angle on the damaged terminal. Used a mounting bracket to secure the motor's angle, firmly pressing the tip against the pin to achieve stable conduction. |

# Multifunctional Line-Tracking & Obstacle-Avoidance Robot Based on STC32G12K128
*(FAE Debugging & Hardware Design Record)*

This repository documents an embedded mechatronic system based on the 8051/STC32 architecture. It features a complete record of hardware component selection, PCB layout anti-interference design, soldering and assembly debugging, as well as field-style FAE (Field Application Engineer) troubleshooting protocols.

---

## 🛠️ Hardware Architecture

* **Microcontroller Unit (MCU):** STC32G12K128 Core Board (53 × 23 mm Compact Footprint)
* **Motor Driver Module:** RZ7899 H-Bridge Motor Driver
* **Sensor Suite:** Infrared Line-Tracking Module + Ultrasonic Ranging Module + ADC Voltage Divider for Battery Level Detection
* **Audio-Visual Feedback:** 5V Active Buzzer Driver Circuit + LED Headlight Driver Circuit

---

## 📐 PCB Layout Guidelines & Anti-Interference Rules

> [!WARNING]
> **Critical PCB Layout Rules:**
> 1. **Power Traces:** Maintain a minimum trace width of **35–40 mil** (or wider). **Never form closed loop paths** to prevent ground/power loops and severe EMI.
> 2. **ADC Signal Protection:** Keep high-precision ADC voltage divider traces physically isolated from high-frequency switching lines and power routes. Minimize trace length to ensure sampling stability.
> 3. **Ground Plane Management:** Clear all "Island Copper" (unconnected ground pour). Place GND stitching vias in continuous linear rows to eliminate airwires and stabilize the bottom ground plane.

---

## 🔍 FAE Debugging & Case Studies

For in-depth technical reports on RZ7899 SMD cold joint troubleshooting, physical workarounds for damaged motor terminals, and battery socket footprint jumpers, please refer to the following documentation:
To be determined
