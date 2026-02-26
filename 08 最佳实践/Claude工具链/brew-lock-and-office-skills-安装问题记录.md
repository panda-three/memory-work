---
title: "⚠️ 未解决：Claude Code 中读取 PDF/docx 的工具链问题"
domain: Claude工具链
source: 自己摸索
verified: false
created: 2026-02-26
status: 未解决
tags: [brew, poppler, libreoffice, claude-office-skills, macOS-12]
---

# ⚠️ 未解决：Claude Code 中读取 PDF/docx 的工具链问题

> 这不是最佳实践，是一份**失败记录**。目的是留住上下文，等找到解决方案后回来补完。

## 目标

在 Claude Code 中读取 PDF 和 docx 文件（具体场景：提取 12 份江苏职教高考计算机试卷内容）。

## 验证结论：Claude Code 原生能力边界

| 格式 | 原生能力 | 缺什么 |
|------|---------|--------|
| PDF | 能识别文件，但渲染/读取页面内容需要 `poppler`（pdftoppm） | `brew install poppler` |
| docx | 完全不支持，报错 `This tool cannot read binary files` | 需要转换工具 |

## 尝试安装 brew 依赖：全部失败

### 环境

- macOS 12 Monterey（Homebrew Tier 3，官方不再支持）
- Homebrew 5.0.15
- 需要安装：poppler、pandoc、libreoffice

### 问题 1：brew install 锁文件死锁（poppler / pandoc）

**现象**：反复出现 `A brew install process has already locked xxx.incomplete`

**尝试过的方法**（均未彻底解决）：
- `pkill -f "brew install"` + `rm *.incomplete`
- `killall brew && killall curl` + `find ... -name "*.incomplete" -delete`
- `HOMEBREW_NO_AUTO_UPDATE=1 brew install poppler` 单独安装
- `brew install --force-bottle poppler` 强制用预编译包

**根因推测**：
- Claude Code 后台任务机制残留 brew 子进程，锁文件清理不干净
- macOS 12 Tier 3 下，brew 的依赖下载链路不稳定，频繁中断
- 多次并行 brew install 调用互相冲突

### 问题 2：nasm 依赖下载失败

**现象**：`Failed to download resource "nasm (3.01)"`，源站 nasm.us 不可达。

### 问题 3：LibreOffice 下载失败

**现象**：curl 报错 `HTTP/2 stream 1 was not closed cleanly: CANCEL (err 8)`，镜像源连接中断。

## 已完成的部分

- `claude-office-skills` 已克隆到 `06 我的工具/claude-office-skills/`（待迁移到全局位置）
- Python venv 和 npm install 未执行（等 brew 依赖就绪）

## 待探索的替代方案

### 方案 A：conda 安装 poppler
```bash
conda install -c conda-forge poppler
```
conda-forge 镜像可能比 brew 源稳定，但未验证。

### 方案 B：纯 Python 方案（不依赖 brew）
- PDF 文本提取：`pypdf`（纯 Python，不需要 poppler）
- docx 文本提取：`python-docx`（纯 Python，不需要 LibreOffice）
- 局限：pypdf 对扫描版 PDF 无能为力，python-docx 不处理复杂排版

### 方案 C：升级 macOS
macOS 12 已是 Tier 3，brew 很多 bottle 不再提供预编译包，需要从源码编译（依赖链更容易断）。升级到 macOS 13+ 可能根治问题。

### 方案 D：Claude Desktop 替代
Claude Desktop 版本原生支持 Office 文档操作，如果 Claude Code 这条路走不通，可以在 Desktop 端处理文档，Code 端处理代码逻辑。

### 方案 E：手动下载安装
- poppler：从 GitHub releases 或 conda-forge 下载预编译二进制
- LibreOffice：从官网手动下载 DMG 安装，绕过 brew

## 下次回来时的检查清单

- [ ] brew 锁文件问题是否已解决（重启后重试）
- [ ] conda install poppler 是否可行
- [ ] 纯 Python 方案（pypdf + python-docx）是否满足试卷提取需求
- [ ] 是否需要升级 macOS
- [ ] claude-office-skills 迁移到全局位置 + 完成安装
