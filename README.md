<div align="center">
  <h1> LQ Embedded Solutions </h1>
  <p> <strong> 蓝桥杯嵌入式设计与开发 — 历届真题参考代码 & 工程模板 </strong> </p>
  <p> 基于 CT117E-M4 竞赛平台 · STM32G431RBT6 · HAL 库 · STM32CubeMX + MDK </p>
  <p>
    简体中文 | <a href="README.en.md"> English </a>
  </p>
  <p>
    <a href="LICENSE"> <img src="https://img.shields.io/badge/license-CC%20BY--NC--SA%204.0-blue" alt="CC BY-NC-SA 4.0"> </a>&nbsp;
    <a href="https://github.com/rsecss/lq-embedded-solutions/network/members"> <img src="https://img.shields.io/github/forks/rsecss/lq-embedded-solutions?style=flat&color=blue" alt="Forks"> </a>&nbsp;
    <a href="https://github.com/rsecss/lq-embedded-solutions/issues"> <img src="https://img.shields.io/github/issues/rsecss/lq-embedded-solutions" alt="Issues"> </a>&nbsp;
    <a href="https://github.com/rsecss/lq-embedded-solutions/pulls"> <img src="https://img.shields.io/badge/PRs-welcome-brightgreen.svg" alt="PRs Welcome"> </a>&nbsp;
    <a href="https://github.com/rsecss/lq-embedded-solutions/commits"> <img src="https://img.shields.io/github/last-commit/rsecss/lq-embedded-solutions" alt="Last Commit"> </a>&nbsp;
    <a href="https://github.com/rsecss/lq-embedded-solutions"> <img src="https://img.shields.io/github/repo-size/rsecss/lq-embedded-solutions?color=orange" alt="Repo Size"> </a>
  </p>
  <p> 如果你发现了 Bug 或有改进建议，欢迎提交 <a href="https://github.com/rsecss/lq-embedded-solutions/issues"> Issue </a> 或 <a href="https://github.com/rsecss/lq-embedded-solutions/pulls"> PR </a>。觉得有帮助的话，请点个 star ⭐ 支持一下</p>
</div>

---

## 特性

- **静态任务调度器** — 轻量级多任务框架，无需 RTOS 即可实现周期性任务管理
- **聚合头文件管理** — 通过 `bsp_system.h` 统一管理各模块依赖，一行 `#include` 即可引入全部 BSP 驱动
- **开箱即用的工程模板** — 预配置 CubeMX + MDK 工程，涵盖 LCD / LED / KEY / ADC / UART / I2C / RTC / PWM / 输入捕获等常用外设
- **历届真题收录** — 第十二届至第十五届省赛 & 国赛真题，含赛题 PDF + 参考代码

## 赛题覆盖

| 届数 | 省赛 | 国赛 | 模拟题 |
|:---:|:---:|:---:|:---:|
| 第十二届（2021） | ✅ | — | — |
| 第十三届（2022） | ✅ | — | — |
| 第十四届（2023） | ✅ | ✅ | — |
| 第十五届（2024） | ✅ | ✅ | ✅ |

## 目录结构

```
lq-embedded-solutions/
├── Past-contest-solutions/        # 历届赛题 & 参考代码
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
├── Reference/                     # 参考资料
│   ├── individual/                # 竞赛规则、原理图、芯片手册等
│   └── lanqiao-cup-*.zip          # 蓝桥杯电子类历届真题汇编
├── Template/                      # 项目工程模板
│   ├── Core/                      # CubeMX 生成的核心层
│   ├── Drivers/                   # HAL & CMSIS 驱动
│   ├── MyApplication/             # 应用层（BSP 驱动 + 调度器）
│   ├── MDK-ARM/                   # Keil 工程文件
│   └── Project.md                 # 工程模板文档
└── Tools/                         # 工具软件（ARMCC、固件包、USB 驱动）
```

## 快速开始

### 环境要求

| 工具 | 说明 |
|-----|------|
| **Keil MDK** | v5.x，使用 AC5 (ARMCC) 工具链 |
| **STM32CubeMX** | 用于查看 / 修改外设配置 |
| **DAP-Link** | 调试器，用于烧录和调试 |
| **STM32G4xx DFP** | Keil 芯片固件包（已包含于 `Tools/`） |

### 使用步骤

```bash
git clone https://github.com/rsecss/lq-embedded-solutions.git
```

1. 打开 `Template/MDK-ARM/Template.uvprojx` 即可基于模板开发
2. 历届参考代码位于 `Past-contest-solutions/` 对应届数目录下的 `.zip` 文件中，解压后打开 MDK 工程即可编译调试

> [!IMPORTANT]
>
> 首次使用模板前，请务必阅读 [`Template/Project.md` — 说明（重要）](Template/Project.md#说明重要) 中的环境配置要点（CubeMX 版本、时钟、MicroLIB、固件包等），可避免绝大多数搭建问题。遇到外设异常时也可查阅其中的 [故障排查指南](Template/Project.md#故障排查指南注意事项)。

## 参与贡献

欢迎提交 PR 和 Issue。详见 [CONTRIBUTING.md](CONTRIBUTING.md)。

---

> 本项目采用 [CC BY-NC-SA 4.0](LICENSE) 许可协议开源。代码仅供学习与参考，禁止商业用途。针对特定蓝桥杯赛题设计，作者 **不提供任何保证**，使用前请自行评估内容的适用性以及核对题目要求。
