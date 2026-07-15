<div align="center">
  <h1> LQ Embedded Solutions </h1>
  <p> <strong> 蓝桥杯嵌入式设计与开发 — 历届真题参考代码 & 工程模板 </strong> </p>
  <p> 基于 CT117E-M4 竞赛平台 · STM32G431RBT6 · HAL 库 · STM32CubeMX + MDK </p>
  <p>
    <a href="https://creativecommons.org/licenses/by-nc-sa/4.0/"><img src="https://img.shields.io/badge/license-CC%20BY--NC--SA%204.0-blue" alt="CC BY-NC-SA 4.0"></a>
    <a href="https://github.com/rsecss/lq-embedded-solutions/stargazers"><img src="https://img.shields.io/github/stars/rsecss/lq-embedded-solutions?style=flat&color=yellow" alt="Stars"></a>
    <a href="https://github.com/rsecss/lq-embedded-solutions/network/members"><img src="https://img.shields.io/github/forks/rsecss/lq-embedded-solutions?style=flat&color=blue" alt="Forks"></a>
    <a href="https://github.com/rsecss/lq-embedded-solutions/issues"><img src="https://img.shields.io/github/issues/rsecss/lq-embedded-solutions?color=green" alt="Issues"></a>
    <a href="https://github.com/rsecss/lq-embedded-solutions/commits"><img src="https://img.shields.io/github/last-commit/rsecss/lq-embedded-solutions?color=orange" alt="Last Commit"></a>
    <img src="https://img.shields.io/badge/Platform-STM32G431-red" alt="Platform">
    <img src="https://img.shields.io/badge/HAL-Library-blueviolet" alt="HAL">
  </p>
  <p> 如果你发现了 Bug 或有改进建议，欢迎提交 <a href="https://github.com/rsecss/lq-embedded-solutions/issues"> Issue </a> 或 <a href="https://github.com/rsecss/lq-embedded-solutions/pulls"> PR </a>。觉得有帮助的话，请点个 star ⭐ 支持一下</p>
</div>

---

## 特点

- **静态任务调度器** — 轻量级多任务框架，无需 RTOS 即可实现周期性任务管理
- **聚合头文件管理** — 通过 `bsp_system.h` 统一管理各模块依赖，一行 `#include` 即可引入全部 BSP 驱动
- **开箱即用的工程模板** — 预配置 CubeMX + MDK 工程，涵盖 LCD / LED / KEY / ADC / UART / I2C / RTC / PWM / 输入捕获等常用外设
- **历届真题收录** — 第十二届至第十七届省赛真题 & 第十五、十六届国赛真题，含赛题 PDF + 参考代码

## 赛题覆盖
> 由于从第十五届开始全部使用了新的开发板，此前国赛题目中的部分功能需要拓展板实现，遂不再收录第十二至十四届国赛赛题。第十六届国赛与第十七届省赛参考代码整理中，当前仅提供赛题 PDF。

| 届数 | 省赛 | 国赛 | 模拟题 |
|:---:|:---:|:---:|:---:|
| 第十二届（2021） | ✅ | — | — |
| 第十三届（2022） | ✅ | — | — |
| 第十四届（2023） | ✅ | — | — |
| 第十五届（2024） | ✅ | ✅ | ✅ |
| 第十六届（2025） | ✅ | 📄 | ✅ |
| 第十七届（2026） | 📄 | — | — |

**图例**: ✅ 含参考代码 | 📄 仅赛题 PDF | — 未收录

## 目录结构

```
lq-embedded-solutions/
├── Past-contest-solutions/			# 历届赛题 & 参考代码
│   ├── 01-第十二届/                 # 第十二至十四届仅含省赛，赛题直接位于届目录下
│   ├── 02-第十三届/
│   ├── 03-第十四届/
│   ├── 04-第十五届/                 # 自第十五届起按省赛 / 国赛 / 模拟题分类
│   │   ├── 省赛/
│   │   ├── 国赛/
│   │   └── 模拟题/
│   ├── 05-第十六届/
│   │   ├── 省赛/
│   │   ├── 国赛/
│   │   └── 模拟题/
│   └── 06-第十七届/
│       └── 省赛/
├── Reference/                      # 参考资料
│   └── individual/                 # 竞赛平台手册、原理图、芯片数据手册等(13份)
├── Template/                       # 项目工程模板
│   ├── Core/                       # CubeMX 生成的核心层
│   ├── Drivers/                    # HAL & CMSIS 驱动
│   ├── MyApplication/              # 应用层（BSP 驱动 + 调度器）
│   ├── MDK-ARM/                    # Keil 工程文件
│   └── Project.md                  # 工程模板文档
└── Tools/                          # 工具软件（固件包、USB 驱动）
```

## 快速开始

### 环境要求

| 工具 | 说明 |
|-----|------|
| **Keil MDK** | v5.x，使用 **AC5 (ARMCC) 工具链** |
| **STM32CubeMX** | >= 6.12.0，用于查看 / 修改外设配置 |
| **DAP-Link** | 调试器，用于烧录和调试 |
| **STM32G4xx DFP** | Keil 芯片固件包，已包含于 `Tools/Keil.STM32G4xx_DFP.2.0.0.pack` |

### 使用步骤

```bash
git clone https://github.com/rsecss/lq-embedded-solutions.git
```

**使用工程模板**:
1. 打开 `Template/MDK-ARM/Template.uvprojx` 即可基于模板开发

**使用历届参考代码**:
1. 找到 `Past-contest-solutions/` 下对应届数目录
2. 解压 `.zip` 工程文件
3. 打开 MDK 工程即可编译调试

> [!IMPORTANT]
>
> 首次使用模板前，请务必阅读 [说明（非常重要）](Template/Project.md#说明重要) 中的环境配置要点（CubeMX 版本、时钟、MicroLIB、固件包等），可避免绝大多数搭建问题。遇到外设异常时也可查阅其中的 [故障排查指南](Template/Project.md#故障排查指南注意事项)。

## 常见问题

- **LCD 黑屏/卡死?** → 查看 [故障排查指南 - LCD](Template/Project.md#3-lcd-屏幕黑屏和卡死问题)
- **串口无输出?** → 查看 [故障排查指南 - 串口](Template/Project.md#4-如何解决使用串口无法打印输出的问题)
- **ADC 采集异常?** → 查看 [故障排查指南 - ADC](Template/Project.md#5-adc-无法采集到数据)
- **更多问题** → 查阅完整 [故障排查指南](Template/Project.md#故障排查指南注意事项)

## 参与贡献

详见 [CONTRIBUTING.md](CONTRIBUTING.md)。

## 许可证

本项目采用 [CC BY-NC-SA 4.0](https://creativecommons.org/licenses/by-nc-sa/4.0/) 许可协议。

- **参考代码**: 仅供学习参考，禁止商业用途
- **赛题 PDF**: 版权归蓝桥杯组委会所有，本仓库仅作交流学习

## 免责声明

- 本项目内容 **按原样提供(AS-IS)**，不提供任何明示或暗示的保证
- 作者不对代码的正确性、完整性、适用性或可靠性做任何承诺
- 使用者需自行评估内容适用性并承担全部使用风险
- 在任何情况下，作者均不对因使用或无法使用本项目内容而导致的任何直接、间接、偶然、特殊、惩罚性或后果性损害承担责任
