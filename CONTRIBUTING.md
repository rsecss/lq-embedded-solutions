# 贡献指南

感谢你对本项目的关注！无论是提交新的赛题参考代码、改进工程模板，还是修复一个文档错别字，所有贡献都同样重要。

本文档将帮助你了解参与贡献的流程和规范，请在提交 Issue 或 Pull Request 之前阅读相关章节。

## 目录

- [贡献指南](#贡献指南)
  - [目录](#目录)
  - [行为准则](#行为准则)
  - [贡献方式](#贡献方式)
    - [欢迎的贡献](#欢迎的贡献)
    - [不在范围内的贡献](#不在范围内的贡献)
  - [开发环境](#开发环境)
  - [项目结构与命名规范](#项目结构与命名规范)
    - [目录结构](#目录结构)
    - [赛题目录命名](#赛题目录命名)
    - [赛题目录内容](#赛题目录内容)
  - [代码规范](#代码规范)
    - [文件编码](#文件编码)
    - [命名风格](#命名风格)
    - [头文件](#头文件)
    - [CubeMX 相关](#cubemx-相关)
    - [注释](#注释)
  - [赛题解答提交规范](#赛题解答提交规范)
    - [必须满足](#必须满足)
    - [建议满足](#建议满足)
  - [Issue 指南](#issue-指南)
    - [Bug 报告](#bug-报告)
    - [功能建议](#功能建议)
  - [Pull Request 流程](#pull-request-流程)
    - [1. Fork \& Clone](#1-fork--clone)
    - [2. 创建分支](#2-创建分支)
    - [3. 提交更改](#3-提交更改)
    - [4. 同步上游](#4-同步上游)
    - [5. 推送 \& 创建 PR](#5-推送--创建-pr)
    - [Review 说明](#review-说明)
  - [Commit Message 规范](#commit-message-规范)
    - [Type](#type)
    - [Scope（可选）](#scope可选)
    - [示例](#示例)
  - [许可协议与版权声明](#许可协议与版权声明)

## 行为准则

我们希望营造一个友善、包容的社区环境。参与本项目时请遵守以下原则：

- **尊重他人** — 对不同的解题思路和代码风格保持开放态度
- **友善沟通** — 在 Issue 和 PR 中保持礼貌、建设性的讨论
- **乐于助人** — 如果你发现其他人的问题，欢迎帮忙解答

## 贡献方式

### 欢迎的贡献

| 类型 | 说明 |
|------|------|
| **新增赛题解答** | 提交新届/新题目的完整参考代码 |
| **优化现有解答** | 改进已有代码的逻辑、效率或可读性 |
| **模板改进** | 完善 BSP 驱动、调度器、外设封装等 |
| **文档完善** | 修复错误、补充说明、改善排版 |
| **Bug 修复** | 修复代码中的缺陷 |
| **赛题资料补充** | 补充缺失的赛题 PDF 或参考资料 |

### 不在范围内的贡献

- 非 CT117E-M4 竞赛平台（STM32G431RBT6）的代码
- 与蓝桥杯嵌入式赛道无关的项目
- 使用 RTOS（如 FreeRTOS）的方案 — 本仓库以裸机 + 静态调度器为主
- 使用 LL 库或寄存器直接操作的方案 — 本仓库统一使用 HAL 库

## 开发环境

| 工具 | 版本要求 |
|------|----------|
| **Keil MDK** | v5.x，使用 AC5 (ARMCC) 工具链 |
| **STM32CubeMX** | >= 6.12.0 |
| **STM32G4xx DFP** | >= 1.4.0，固件包 `Keil.STM32G4xx_DFP.2.0.0.pack` |
| **DAP-Link** | 用于烧录和调试 |

详细的配置步骤和注意事项请参阅 [`Template/Project.md`](Template/Project.md#说明重要)。

## 项目结构与命名规范

### 目录结构

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
├── Template/                      # 项目工程模板
└── Tools/                         # 工具软件
```

### 赛题目录命名

- 届数目录：`{序号}-第{N}届/`，序号从 `01` 开始，如 `05-第十六届/`
- 下级分类：`省赛/`、`国赛/`、`模拟题/`

### 赛题目录内容

每个赛题目录下应包含：

```
省赛/
├── 第{N}届省赛程序设计题赛题一.pdf    # 赛题 PDF
├── 第{N}届省赛客观题赛题一.pdf        # 客观题 PDF（如有）
└── 第{N}届省赛真题参考代码.zip        # 完整 MDK 工程压缩包
```

> `{N}` 为中文数字，如 `十六`。

## 代码规范

### 文件编码

- 编码：**UTF-8**（无 BOM）
- 换行符：**LF**（`\n`）

### 命名风格

| 对象 | 风格 | 示例 |
|------|------|------|
| 文件名 | `snake_case` | `led_app.c`、`key_app.h` |
| BSP 模块文件 | `{模块名}_app.c/h` | `adc_app.c`、`uart_app.c` |
| 函数名 | `PascalCase` 或 `snake_case` | 与模板已有风格保持一致 |
| 宏定义 | `UPPER_SNAKE_CASE` | `#define LED_GPIO_PORT GPIOC` |
| 全局变量 | 带模块前缀 | `adc_dma_buffer`、`key_value` |

### 头文件

- 使用 `#ifndef` / `#define` / `#endif` 保护宏
- 模块对外接口通过 `bsp_system.h` 统一聚合，不直接 `#include` 各模块头文件

### CubeMX 相关

- 所有用户代码必须写在 `/* USER CODE BEGIN */` 和 `/* USER CODE END */` 之间，否则重新生成时会被覆盖
- 修改 `.ioc` 文件后，请在 PR 中说明改动原因

### 注释

- 描述意图和设计理由，不要复述代码
- 保持简洁

## 赛题解答提交规范

提交新的赛题参考代码时，请遵循以下要求：

### 必须满足

1. **能够通过编译** — 使用 Keil MDK + AC5 工具链可以成功编译
2. **完整的 MDK 工程** — 压缩包内包含完整的可编译工程，而非零散的源文件
3. **赛题 PDF** — 附带对应的赛题文件
4. **正确的目录位置** — 放在 `Past-contest-solutions/` 下对应届数和分类目录中

### 建议满足

- 在关键业务逻辑处添加简要注释，帮助读者理解解题思路
- 使用本仓库的工程模板作为基础框架
- 清理编译产生的中间文件（可使用 `keilkill.bat`），以压缩包形式提交

## Issue 指南

提交 Issue 前，请先：

1. 搜索 [已有 Issue](https://github.com/rsecss/lq-embedded-solutions/issues) 确认问题未被提出过
2. 查阅 [`Template/Project.md` 故障排查指南](Template/Project.md#故障排查指南注意事项) 尝试自行解决

### Bug 报告

请包含以下信息：

- **环境信息**：Keil 版本、CubeMX 版本、固件包版本
- **问题描述**：发生了什么、期望的行为是什么
- **复现步骤**：从头到尾的操作步骤
- **相关截图**：如有编译错误或运行异常的截图，请一并附上

### 功能建议

请说明：

- 你希望添加什么功能或改进
- 这个改动对其他使用者的价值

## Pull Request 流程

### 1. Fork & Clone

```bash
git clone https://github.com/<你的用户名>/lq-embedded-solutions.git
cd lq-embedded-solutions
git remote add upstream https://github.com/rsecss/lq-embedded-solutions.git
```

### 2. 创建分支

从 `main` 分支创建新分支：

```bash
git checkout -b feat/第十六届省赛
```

分支命名约定：

| 前缀 | 用途 | 示例 |
|------|------|------|
| `feat/` | 新增赛题或功能 | `feat/第十六届省赛` |
| `fix/` | 修复 Bug | `fix/lcd-display-bug` |
| `docs/` | 文档改进 | `docs/update-project-md` |
| `refactor/` | 重构代码 | `refactor/adc-module` |

### 3. 提交更改

```bash
git add <具体文件>
git commit -m "feat(省赛): 添加第十六届省赛赛题和参考代码"
```

- 每个 commit 只做一件事
- 使用 [Conventional Commits](#commit-message-规范) 格式
- 避免使用 `git add .`，明确指定要提交的文件

### 4. 同步上游

```bash
git fetch upstream
git rebase upstream/main
```

### 5. 推送 & 创建 PR

```bash
git push origin feat/第十六届省赛
```

然后在 GitHub 上创建 Pull Request，PR 描述中请说明：

- **改了什么** — 新增/修改了哪些内容
- **为什么改** — 解决了什么问题或满足了什么需求
- **如何验证** — 是否经过编译测试、在开发板上验证过

### Review 说明

- 维护者会尽快 Review 你的 PR
- 如果需要修改，请直接在原分支上追加 commit，不要关闭 PR 后重新创建
- PR 合并后，你的贡献将出现在项目的 Contributors 列表中

## Commit Message 规范

本项目采用 [Conventional Commits](https://www.conventionalcommits.org/) 格式：

```
<type>(<scope>): <description>
```

### Type

| type | 说明 |
|------|------|
| `feat` | 新增功能或赛题 |
| `fix` | 修复 Bug |
| `docs` | 文档变更 |
| `refactor` | 重构（不改变功能） |
| `chore` | 构建、工具等杂项 |

### Scope（可选）

用于标识改动范围，常用值：`省赛`、`国赛`、`模板`、`README`

### 示例

```
feat(省赛): 添加第十六届省赛赛题和参考代码
fix: 修复 ADC 多通道采集数据交叉问题
docs(README): 更新目录结构说明
refactor: 迁移第十五届赛题至 Past-contest-solutions
chore: 调整目录结构
```

## 许可协议与版权声明

- 本项目采用 [MIT 许可证](LICENSE) 开源。提交贡献即表示你同意将代码以同一许可证发布
- **赛题 PDF 的版权归蓝桥杯组委会所有**，本仓库仅作学习参考用途收录
- 请勿在提交中包含密钥、凭据等敏感信息

---

再次感谢你的贡献！如有任何问题，欢迎通过 [Issue](https://github.com/rsecss/lq-embedded-solutions/issues) 联系我们。
