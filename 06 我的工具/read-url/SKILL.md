---
name: read-url
type: skill
trigger: 用户提供 URL 并希望读取网页内容时
version: 1.1
created: 2026-02-24
updated: 2026-02-26
---

# read-url

## 用途

读取用户提供的 URL 内容。三级降级策略：直接抓取 → Jina Reader → Playwright 本地浏览器，覆盖微信公众号等强防爬场景。

## 触发方式

技能型——用户提供 URL 并表达阅读/提取/总结意图时触发。语义匹配示例：

- "帮我读一下这篇文章"
- "这个链接讲了什么"
- "总结一下这个 URL"
- "提取这篇文章的内容"

## 执行流程

### 抓取策略（三级降级）

1. 先用 Jina Reader 抓取（对动态渲染页面兼容性最好）：
   ```bash
   curl -s "https://r.jina.ai/<原始URL>"
   ```
2. 如果 Jina Reader 失败或返回内容不完整，尝试直接抓取原始 URL
3. 仍失败（如微信公众号），调用本地 Playwright 脚本：
   ```bash
   python "06 我的工具/read-url/fetch_article.py" "<URL>"
   ```
   脚本返回 JSON，字段：`success`, `title`, `author`, `publish_time`, `content`, `error`

> Jina Reader 升级为首选方案。实测对笔记类 app（biji.com）、动态渲染页面效果好，直接返回 Markdown 格式。

### 内容入库（抓取成功后）

4. 根据内容类型判断存放位置：

| 内容类型 | 存放路径 | 示例 |
|----------|----------|------|
| 视频/播客笔记 | `02 我的阅读/视频与播客/` | 课程笔记、动态观察 |
| 文章 | `02 我的阅读/文章/` | 公众号文章、博客 |
| 工具/技术 | `08 最佳实践/` 对应子目录 | 工具链实践 |

5. 整理为结构化笔记，包含 YAML frontmatter：
   ```yaml
   ---
   title: <标题>
   source: <原始URL>
   author: <作者（如有）>
   tags: [相关标签]
   created: <当天日期>
   ---
   ```
6. 正文按层级整理，末尾附「我的收获」区块，关联用户当前知识体系

## 输入

- `url`（必填）：目标网页地址
- `intent`（可选）：用户希望对内容做什么（默认：提取正文）

## 输出

- 网页正文的 Markdown 格式内容
- 如用户有后续意图（总结、存档），继续执行对应操作

## 依赖项

Playwright 降级（第 3 步）需要以下依赖，首次使用时安装：

```bash
pip install playwright beautifulsoup4
playwright install chromium
```

## 注意事项

- Jina Reader 免费，无需 API Key
- Playwright 降级针对微信公众号做了专门解析（标题、作者、时间、正文），其他页面走通用提取
- 首次使用 Playwright 需安装 chromium 浏览器（约 150MB），安装后后续调用无需重复下载
- 三级均失败时，提示用户手动复制正文
