# 🤖 STC32 Multifunctional Line Tracking Robot

A compact embedded robotic platform based on STC32G12K128,
integrating mechanical structure design,
PCB hardware development,
embedded control,
and engineering debugging.

This project documents the complete development process,
including component selection,
PCB layout optimization,
hardware assembly,
and FAE-style troubleshooting.


## Project Overview


This project is a multifunctional mobile robot platform developed around
STC32G12K128 MCU.

The goal is to build a compact robotic system integrating:

- motion control
- sensor acquisition
- motor driving
- hardware debugging

Unlike a simple competition robot,
this project focuses on engineering development workflow,
including hardware selection,
PCB design,
assembly verification,
and fault diagnosis.

## Key Features


### Motion System

✔ Four-wheel motor drive system

✔ RZ7899 H-bridge motor driver


### Sensor System

✔ Infrared line tracking

✔ Ultrasonic obstacle detection

✔ ADC battery voltage monitoring


### Hardware Development

✔ Custom PCB design

✔ Component selection

✔ Soldering and hardware debugging


              Battery
                 |
                 |
          Power Management
                 |
                 |
             STC32 MCU
          /      |       \
         /       |        \
 Infrared    Ultrasonic   ADC
 Sensor      Sensor       Battery

                 |
                 |
            Motor Driver
              RZ7899

                 |
              Motors


## System Architecture

The system consists of four major modules:

1. Control Unit
2. Sensor Unit
3. Motor Drive Unit
4. Power Monitoring Unit


## Mechanical Design


The mechanical design focuses on:

- compact electronic integration
- component accessibility
- modular assembly


The robot structure was designed around
the 53×23mm compact controller footprint,
allowing easier PCB installation and maintenance.


## Hardware Design


### MCU

STC32G12K128 core board


### Motor Driver

RZ7899 H-Bridge driver


### PCB Design Considerations

- Power trace width optimization
- ADC signal isolation
- Ground plane management
- GND stitching vias


## Firmware Architecture


Firmware is responsible for:


- motor control
- sensor acquisition
- decision logic
- actuator control


The firmware structure will be continuously optimized
with future PID speed control and communication functions.


## Engineering Debug Cases


### Case 1: RZ7899 Motor Driver Failure


Problem:

Motor failed after firmware upload.


Investigation:

- checked motor replacement
- tested header contact
- inspected solder joints


Root Cause:

SMD soldering instability.


Solution:

Reworked solder joints and verified motor operation.


## Test Results


Current validation includes:

✔ Motor operation test

✔ PCB functional verification

✔ Sensor response testing


Detailed quantitative testing
will be added after optimization.


## Future Improvement


Planned improvements:


- Improve mechanical structure
- Add PID motor speed control
- Improve sensor filtering
- Optimize PCB layout
- Add wireless communication


## Engineering Skills Demonstrated


### Mechanical Engineering

- Structural design thinking
- Assembly optimization


### Hardware Engineering

- PCB layout
- Component selection
- Soldering
- Debugging


### Embedded Development

- STC32 MCU
- Sensor integration
- Motor control


### Engineering Practice

- Failure analysis
- Troubleshooting
- Documentation
