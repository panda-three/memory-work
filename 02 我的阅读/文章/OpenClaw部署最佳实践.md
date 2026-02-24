---
title: OpenClaw 部署最佳实践
tags: [OpenClaw, VPS, 部署, 最佳实践]
created: 2026-02-24
---

# OpenClaw 部署最佳实践

从零开始：选购海外服务器 → 连接 → 安装 → 后台运行，全流程实操记录。

---

## 1. 选购海外云服务器

OpenClaw 需要部署在海外服务器上。8GB 内存够用，选性价比高的即可。

### 推荐方案

| 厂商 | 配置 | 价格 | 适合场景 |
|------|------|------|----------|
| RackNerd（推荐） | 6 vCPU / 8GB / 150GB SSD / 20TB流量 | ~$62.5/年 | 预算有限，不在意延迟 |
| Hetzner CX33 | 4 vCPU / 8GB / 80GB SSD / 20TB流量 | ~€5.49/月 | 需要亚洲节点（新加坡） |
| Contabo | 4-6 vCPU / 8GB / 200GB SSD | ~$6-8/月 | 大存储需求 |

### 购买要点

- 系统选 Ubuntu 22.04 或 24.04 LTS
- RackNerd 机房选洛杉矶（LA）或圣何塞（SJ）
- 购买后邮件会收到：服务器 IP、root 密码、SSH 端口

---

## 2. 连接服务器

### 推荐工具：FinalShell

终端命令行对中文用户不够友好，推荐使用 FinalShell：

- 全中文界面，国产软件
- 左边终端 + 右边文件管理器，可视化操作
- 自带系统监控（CPU、内存、网络）
- 免费下载：https://www.hostbuf.com

### 连接步骤

1. 打开 FinalShell，新建 SSH 连接
2. 填入：IP 地址、端口 22、用户名 root、密码
3. 保存后点击即可连接，以后一键直达

---

## 3. 安装 OpenClaw

连上服务器后，按 OpenClaw 官方流程安装。安装完成后先配置网关模式：

```bash
openclaw config set gateway.mode local
```

然后启动：

```bash
openclaw gateway run
```

看到启动信息即表示安装成功。

---

## 4. 后台持续运行（关键）

直接在 SSH 里运行 OpenClaw，关闭 FinalShell 后进程会被杀掉。需要让它在后台持续运行。

### 方案对比

| 方案 | 复杂度 | 适合场景 |
|------|--------|----------|
| `nohup`（推荐） | 一行命令 | 快速上手，轻量 |
| `screen` | 简单 | 需要随时回到终端查看 |
| `systemd` 服务 | 较重 | 需要开机自启、自动重启 |

### nohup 用法（推荐）

启动：

```bash
nohup openclaw gateway run > /root/openclaw.log 2>&1 &
```

查看日志：

```bash
tail -f /root/openclaw.log
```

停止：

```bash
pkill -f "openclaw gateway"
```

---

## 5. 注意事项

- 服务器密码不要存在 Git 仓库里，用 FinalShell 保存连接或密码管理器
- 如果 OpenClaw 异常退出，重新执行 nohup 命令即可
- 想要更稳定的方案，后续可以升级为 systemd 服务（支持开机自启和崩溃自动重启）
