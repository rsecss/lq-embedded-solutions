# Changelog

本文档记录项目的所有重要变更。

格式遵循 [Keep a Changelog](https://keepachangelog.com/zh-CN/1.0.0/)。

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

[v2.0]: https://github.com/rsecss/lq-embedded-solutions/compare/v1.0...v2.0
[v1.0]: https://github.com/rsecss/lq-embedded-solutions/releases/tag/v1.0
