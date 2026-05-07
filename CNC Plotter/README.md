# 🖊️ CNC Plotter 

A 3-axis CNC Plotter machine built from scratch as a graduation project. The machine runs **GRBL** firmware and receives G-code commands, translating them into precise stepper motor movements to draw vector graphics on paper.

---

## 📌 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Hardware Components](#hardware-components)
- [Software & Tools](#software--tools)
- [System Architecture](#system-architecture)
- [G-code Support](#g-code-support)
- [Getting Started](#getting-started)
- [Project Structure](#project-structure)

---

## Overview

The CNC Plotter is a Computer Numerical Control machine that automates the drawing process. It uses three **28BYJ-48** stepper motors to control X, Y, and Z axes, each driven by a **ULN2003** driver board connected directly to an Arduino microcontroller running **GRBL** firmware. The Z-axis controls the pen lift/lower mechanism, while X and Y handle the drawing movement. GRBL interprets and executes G-code instructions sent from a PC over serial.

---

## ✨ Features

- 3-axis (X/Y/Z) movement with stepper motors
- Z-axis controls pen lift/lower
- **GRBL** firmware for G-code parsing and real-time motion control
- Support for drawing vector graphics and text
- Serial communication between PC and Arduino via GRBL
- Configurable drawing speed and resolution

---

## 🔧 Hardware Components

| Component | Description |
|---|---|
| Arduino Uno/Mega | Main microcontroller |
| 28BYJ-48 Stepper Motors (×3) | X, Y, and Z axis movement |
| ULN2003 Driver Boards (×3) | Stepper motor drivers, connected directly to Arduino |
| 3D Printed Parts | Custom frame and mechanical parts (STL files included) |
| 9V 1A DC Adapter | System power supply |
| Pen / Marker | Drawing tool |

---

## 🛠️ Software & Tools

- **GRBL** — Open-source CNC firmware running on Arduino (G-code interpreter)
- **Arduino IDE** — Used to flash GRBL onto the Arduino
- **Universal Gcode Sender (UGS)** — PC-side G-code sender to communicate with GRBL
- **Inkscape + G-code extension** — Convert SVG drawings to G-code

---

## 🏗️ System Architecture

```
[PC / G-code Sender (UGS)]
        │
        │  Serial (USB)
        ▼
  [Arduino + GRBL Firmware]
        │
   ┌────┼────┐
   ▼    ▼    ▼
[ULN2003] [ULN2003] [ULN2003]
   │          │          │
[X Motor] [Y Motor] [Z Motor (Pen Up/Down)]
```

---

## 📄 G-code Support

| Command | Function |
|---|---|
| `G0` | Rapid move (pen up travel) |
| `G1` | Linear move (pen down draw) |
| `G28` | Home all axes |
| `M3` / `M5` | Pen down / Pen up |

---

## 🚀 Getting Started

### 1. Download the Project
- Download the project files from GitHub
- Extract the folder if needed

### 2. Upload Firmware

- Open the firmware sketch in **Arduino IDE**
- Select your board (Arduino Uno/Mega) and COM port
- Upload the sketch

### 3. Prepare a Drawing

- Create or import an SVG file in **Inkscape**
- Use the G-code extension to export as `.gcode`

### 4. Send G-code

- Open your G-code sender
- Connect to the Arduino's COM port
- Load your `.gcode` file and start plotting

---

## 📁 Project Structure

```
CNC_Plotter/
├── firmware/           # Arduino sketch (.ino) and GRBL config
├── gcode/              # Sample G-code files
├── hardware/           # Schematics and wiring diagrams
├── stl/                # 3D printed parts (STL files)
├── docs/               # presentation
└── README.md
```
