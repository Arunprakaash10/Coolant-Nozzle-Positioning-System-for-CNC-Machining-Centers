# Coolant Nozzle Positioning System for CNC Machining Centers

## Project Overview

This repository contains the code, hardware, and documentation for the **Coolant Nozzle Positioning System** designed for CNC machining centers. The system addresses the need for precise control of coolant nozzles during machining, significantly enhancing cooling performance and tool life by directing coolant to the exact spot with an accuracy of up to +/- 0.225 degrees.

## Project Details

- **Project Title**: Coolant Nozzle Positioning System for CNC Machines
- **Company**: Ace Manufacturing Systems Ltd., Bangalore
- **Duration**: March 28, 2023 – July 29, 2023
- **Guide**: Mr. Mithun M, R&D, ACE Manufacturing Systems Ltd.

## Features

- **Precision Control**: Uses a stepper motor with a worm gearbox for accurate positioning of the coolant nozzle.
- **Modes**: 
  - **Oscillating Mode**: Allows the nozzle to oscillate within a defined range (e.g., 0-90 degrees).
  - **Advanced Mode**: Adjusts the nozzle based on the tool’s height and radius.
- **Embedded System**: Powered by an STM32 Blue Pill microcontroller, interfacing with CNC machine outputs.
- **Step Angle Accuracy**: Achieves fine control with a step size of 0.225 degrees using an 8-microstep mode.

## Hardware Used

- **STM32 Blue Pill**: Microcontroller for system control.
- **NEMA 17 Stepper Motor**: For precise positioning of the coolant nozzle.
- **TB6600 Stepper Motor Driver**: Provides micro-stepping capability and current control.

## Software

- **STM32CubeIDE**: Used for programming the STM32 microcontroller in C/C++.
- The software integrates the CNC machine output signals to control the stepper motor's movement, based on tool parameters.

## How It Works

1. **Oscillating Mode**: The coolant nozzle moves back and forth within a specified range, providing broad coverage.
2. **Advanced Mode**: Based on tool height and radius, the system calculates the required angle for precise coolant direction.
3. **CNC Integration**: The system receives 9 signal lines from the CNC controller, computes the required nozzle direction, and moves the stepper motor accordingly.

## Results

- Accurate nozzle positioning, improving coolant flow during CNC machining.
- Enhanced cooling performance for various tool sizes and shapes, improving machining quality and tool life.

## Future Enhancements

- Expandable to cover additional angles beyond 90 degrees.
- Implement real-time feedback for closed-loop control.
- Integrate more advanced CNC machine communication protocols.

## Authors

- Arun Prakaash C (SSN College of Engineering)
