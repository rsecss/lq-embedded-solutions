# Changelog

本文档记录项目的所有重要变更。

格式遵循 [Keep a Changelog](https://keepachangelog.com/zh-CN/1.0.0/)。

## [v2.1] - 2026-07-15

### 新增
- 收录第十六届省赛、国赛赛题及省赛参考代码
- 收录第十七届省赛赛题
- 收录第十六届模拟二赛题及参考代码

### 变更
- 将工程模板文档从 `Template/Project.md` 迁移至 `Reference/docs/`，并同步更新 README、CONTRIBUTING 索引
- 扁平化仅含省赛的前三届目录，移除第十四届国赛赛题
- 重新编号 `Reference/individual/` 文档
- 使用 CubeMX 6.17 重新生成工程模板
- 统一历届赛题文件命名规范
- 移除英文版 README

### 修复
- 修复 LCD 驱动中文显示乱码问题
- 修复 `pwm_set_frequency` 定时器编号分发错误
- 修复调度器 tick 回绕问题并统一任务周期
- 修复中值滤波比较函数的无符号回绕
- 修复输入捕获上电阶段的浮点除零
- 统一 `fonts.h` 与 `i2c_hal.c` 为 UTF-8 编码

## [v2.0] - 2026-02-26

### 新增
- 添加完整的工程模板 (Template/)，包含静态任务调度器和聚合头文件管理
- 添加参考资料目录 (Reference/)，收录竞赛平台手册、原理图、芯片数据手册等 13 份文档
- 添加贡献指南 (CONTRIBUTING.md) 和行为准则 (CODE_OF_CONDUCT.md)
- 添加英文版 README (README.en.md)

### 变更
- 重构目录结构：将历届赛题统一迁移至 `Past-contest-solutions/` 目录
- 重写 README 文档，改进结构和内容说明
- 改进工程模板文档 (Template/Project.md)，完善配置说明和故障排查指南
- 将许可证从 MIT 更换为 CC BY-NC-SA 4.0

### 修复
- 清理 .gitignore 冗余规则
- 修正 .gitattributes 配置（最终移除以保持兼容性）

## [v1.0] - 2025-04-16

### 新增
- 初始发布
- 收录第十二届至第十五届省赛赛题及参考代码
- 收录第十五届国赛赛题、笔记及上位机参考代码
- 添加工具包：ARMCC 工具链、Keil STM32G4xx DFP、USB 驱动
- 添加 .gitignore 配置

---

[v2.1]: https://github.com/rsecss/lq-embedded-solutions/compare/v2.0...v2.1
[v2.0]: https://github.com/rsecss/lq-embedded-solutions/compare/v1.0...v2.0
[v1.0]: https://github.com/rsecss/lq-embedded-solutions/releases/tag/v1.0
