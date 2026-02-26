<div align="center">
  <h1> LQ Embedded Solutions </h1>
  <p> <strong> Lanqiao Cup Embedded Design & Development — Past Contest Solutions & Project Template </strong> </p>
  <p> Based on CT117E-M4 Competition Platform · STM32G431RBT6 · HAL Library · STM32CubeMX + MDK </p>
  <p>
    <a href="README.md"> 简体中文 </a> | English
  </p>
  <p>
    <a href="LICENSE"> <img src="https://img.shields.io/badge/license-CC%20BY--NC--SA%204.0-blue" alt="CC BY-NC-SA 4.0"> </a>&nbsp;
    <a href="https://github.com/rsecss/lq-embedded-solutions/network/members"> <img src="https://img.shields.io/github/forks/rsecss/lq-embedded-solutions?style=flat&color=blue" alt="Forks"> </a>&nbsp;
    <a href="https://github.com/rsecss/lq-embedded-solutions/issues"> <img src="https://img.shields.io/github/issues/rsecss/lq-embedded-solutions" alt="Issues"> </a>&nbsp;
    <a href="https://github.com/rsecss/lq-embedded-solutions/pulls"> <img src="https://img.shields.io/badge/PRs-welcome-brightgreen.svg" alt="PRs Welcome"> </a>&nbsp;
    <a href="https://github.com/rsecss/lq-embedded-solutions/commits"> <img src="https://img.shields.io/github/last-commit/rsecss/lq-embedded-solutions" alt="Last Commit"> </a>&nbsp;
    <a href="https://github.com/rsecss/lq-embedded-solutions"> <img src="https://img.shields.io/github/repo-size/rsecss/lq-embedded-solutions?color=orange" alt="Repo Size"> </a>
  </p>
  <p> Found a bug or have a suggestion? Feel free to open an <a href="https://github.com/rsecss/lq-embedded-solutions/issues"> Issue </a> or submit a <a href="https://github.com/rsecss/lq-embedded-solutions/pulls"> PR </a>. If you find this helpful, please give it a star ⭐</p>
</div>

---

## Features

- **Static Task Scheduler** — A lightweight multi-task framework enabling periodic task management without an RTOS
- **Aggregated Header Management** — Unified module dependency management via `bsp_system.h`; a single `#include` brings in all BSP drivers
- **Ready-to-Use Project Template** — Pre-configured CubeMX + MDK project covering LCD / LED / KEY / ADC / UART / I2C / RTC / PWM / Input Capture and other common peripherals
- **Past Contest Archive** — Provincial and national contest problems from the 12th to 15th editions, including problem PDFs and reference code

## Contest Coverage

| Edition | Provincial | National | Mock Exam |
|:---:|:---:|:---:|:---:|
| 12th (2021) | ✅ | — | — |
| 13th (2022) | ✅ | — | — |
| 14th (2023) | ✅ | ✅ | — |
| 15th (2024) | ✅ | ✅ | ✅ |

## Directory Structure

```
lq-embedded-solutions/
├── Past-contest-solutions/        # Past contest problems & reference code
│   ├── 01-第十二届/
│   │   └── 省赛/
│   ├── 02-第十三届/
│   │   └── 省赛/
│   ├── 03-第十四届/
│   │   ├── 省赛/
│   │   └── 国赛/
│   └── 04-第十五届/
│       ├── 省赛/
│       ├── 国赛/
│       └── 模拟题/
├── Reference/                     # Reference materials
│   ├── individual/                # Competition rules, schematics, datasheets, etc.
│   └── lanqiao-cup-*.zip          # Lanqiao Cup past problem compilations
├── Template/                      # Project template
│   ├── Core/                      # CubeMX-generated core layer
│   ├── Drivers/                   # HAL & CMSIS drivers
│   ├── MyApplication/             # Application layer (BSP drivers + scheduler)
│   ├── MDK-ARM/                   # Keil project files
│   └── Project.md                 # Template documentation
└── Tools/                         # Utilities (ARMCC, firmware packages, USB drivers)
```

## Quick Start

### Prerequisites

| Tool | Description |
|-----|------|
| **Keil MDK** | v5.x with AC5 (ARMCC) toolchain |
| **STM32CubeMX** | For viewing / modifying peripheral configurations |
| **DAP-Link** | Debugger for flashing and debugging |
| **STM32G4xx DFP** | Keil device firmware package (included in `Tools/`) |

### Usage

```bash
git clone https://github.com/rsecss/lq-embedded-solutions.git
```

1. Open `Template/MDK-ARM/Template.uvprojx` to start development based on the template
2. Past contest reference code is located in `.zip` files under the corresponding edition directory in `Past-contest-solutions/`. Extract and open the MDK project to compile and debug

> [!IMPORTANT]
>
> Before using the template for the first time, please read the environment setup notes in [`Template/Project.md`](Template/Project.md) (CubeMX version, clock configuration, MicroLIB, firmware packages, etc.) to avoid most setup issues.

## Contributing

PRs and Issues are welcome. See [CONTRIBUTING.md](CONTRIBUTING.md) for details.

---

> This project is licensed under [CC BY-NC-SA 4.0](LICENSE). The code is provided for learning and reference purposes only, and commercial use is prohibited. Designed for specific Lanqiao Cup contest problems, the author **provides no warranty**. Please evaluate the applicability and verify contest requirements before use.
