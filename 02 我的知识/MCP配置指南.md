---
title: Claude Code MCP 配置指南
tags: [工具, MCP, Claude Code]
created: 2026-03-02
---

# Claude Code MCP 配置指南

## 核心概念

MCP（Model Context Protocol）让 Claude Code 接入外部工具。配置后 AI 自动获得新能力（搜索、数据库、API 等）。

## 通用安装命令格式

```bash
claude mcp add <server名称> --transport stdio --scope user --env <环境变量名>=<值> -- npx -y <npm包名>
```

> **注意**：命令必须写成一整行，不要用 `\` 换行，macOS 终端换行容易出问题。

### 参数说明

| 参数 | 说明 |
|------|------|
| `<server名称>` | 自定义名称，用于管理（如 brave-search） |
| `--transport stdio` | 传输方式，本地进程用 stdio（最常用） |
| `--scope user` | 全局生效（所有项目）。不加则仅当前项目 |
| `--env KEY=VALUE` | 传入环境变量（如 API Key），可多个 |
| `-- npx -y <包名>` | 实际启动命令，`--` 是分隔符 |

## 管理命令

```bash
claude mcp list              # 查看所有已配置的 MCP server
claude mcp get <名称>         # 查看某个 server 的详细配置
claude mcp remove <名称>      # 删除某个 server
```

会话内用 `/mcp` 查看连接状态。

## 已安装的 MCP Server

### Brave Search（2026-03-02 安装）

- **包名**: `@brave/brave-search-mcp-server`
- **GitHub**: https://github.com/brave/brave-search-mcp-server
- **API Key 来源**: https://brave.com/search/api（Free 计划 2000 次/月）
- **提供的工具**: brave_web_search, brave_local_search, brave_video_search, brave_image_search, brave_news_search, brave_summarizer

安装命令：
```bash
claude mcp add brave-search --transport stdio --scope user --env BRAVE_API_KEY=<你的KEY> -- npx -y @brave/brave-search-mcp-server
```

## 安装新 MCP 的通用流程

1. 找到 npm 包名（通常在 GitHub README 里）
2. 确认需要的环境变量（通常是 API Key）
3. 执行 `claude mcp add` 命令
4. 重启 Claude Code
5. 用 `/mcp` 验证连接状态

## 注意事项

- 旧包名可能被 deprecated，注意用最新的官方包
- `--scope user` 写入 `~/.claude/settings.json`，项目级写入 `.claude/settings.json`
- API Key 通过 `--env` 传入，不会暴露在配置文件明文中
- transport 除了 stdio 还有 http（远程服务用），一般本地用 stdio
