# 蓝桥杯嵌入式真题参考代码

## Introduction（简介）

本仓库旨在提供蓝桥杯嵌入式历届真题的参考代码，涵盖省赛和国赛，帮助学生和爱好者学习嵌入式编程并备战比赛。这些代码按年份和题目编号组织，采用的是官方的 **CT117E-M4** 嵌入式平台，该平台采用的主控芯片是 **STM32G431RBT6**，同时采用 **HAL 库** 进行代码的编写，开发平台采用的是 **STM32CubeMX+MDK**。目标是为用户提供实用的代码示例，提升编程能力并加深对蓝桥杯嵌入式竞赛的理解。

>如果需要需要相关的工程模版和参考资料，可前往 [蓝桥杯嵌入式比赛模板](https://github.com/rsecss/lqb-hal) 下载查看

## Directory structure（目录结构）

为了方便用户快速找到所需代码，本项目按年份和题目编号进行分类。以下是目录结构的示例：

```plaintxt
|-- 第十五届（2024）/
   |-- 国赛/
      |-- 代码
      |-- 
   |-- 省赛
   |-- ADC采集控制系统
|-- 第十四届（2023）/
   |-- 国赛
   |-- 省赛
|-- 第十三届（2022）/
   |-- 国赛
   |-- 省赛
```

## Usage（用法）

以下是如何下载和使用这些参考代码的步骤：

- 访问 GitHub 仓库：[liaoyige/blue-bridge-cup](https://github.com/liaoyige/blue-bridge-cup)

- 通过 git clone 克隆仓库，或直接下载 ZIP 文件

- 打开参考代码下的 MDK -ARM 文件下的工程文件进行编译调试即可

## Contributions（贡献指南）

欢迎社区贡献新代码或改进现有代码。具体步骤如下：

1. 新增题目
   - 在对应年份下创建新题目目录，保持现有结构
   - 提供完整的源代码和使用说明
2. 改进现有代码
   - 通过 PR 提交代码优化或错误修复
3. 贡献指南
   - 代码需有清晰的注释，遵循项目编码规范
   - 在提交 PR 时，需说明更改内容和目的
4. 如有疑问或建议，请通过以下方式联系
   - **邮箱**：[FengYu](mailto:rsecss@outlook.com)
   - **Issues**：在仓库中提交 Issue 以寻求帮助或提出建议。


## Disclaimer（免责声明）

- 本项目所有资源仅限学习和参考使用，未经许可不得用于商业目的。
- 本项目针对特定蓝桥杯题目设计，未必适用于其他场景，使用前请核对题目要求。
- 作者 **不提供任何保证**，请自行评估内容的适用性。
- 继续使用本项目，即表明你已同意本免责声明

