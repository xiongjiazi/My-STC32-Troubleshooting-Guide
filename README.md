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
