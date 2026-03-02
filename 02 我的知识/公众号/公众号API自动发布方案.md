---
title: 微信公众号 API 自动发布方案
tags: [公众号, API, 自动化, Python]
created: 2026-03-02
status: 待配置
---

# 微信公众号 API 自动发布方案

## 目标

从知识库中选定主题 → AI 生成公众号文章 → 通过 API 自动发布，实现「内容生产 + 发布」的全自动化。

---

## 整体流程

```
1. 选定主题，从知识库检索相关素材
2. AI 生成公众号文章（Markdown → HTML）
3. 上传封面图到微信素材库
4. 上传正文中的图片到微信素材库
5. 创建草稿（draft/add）
6. 发布草稿（freepublish/submit）
7. 查询发布状态确认成功
```

流程图：

```
知识库素材 → AI 生成文章 → Markdown 转 HTML
                                    ↓
                        上传封面图 → media_id
                        上传正文图片 → 替换 img src
                                    ↓
                          创建草稿 (draft/add)
                                    ↓
                        发布草稿 (freepublish/submit)
                                    ↓
                        轮询发布状态 (freepublish/get)
                                    ↓
                              发布完成 ✓
```

---

## API 接口清单

所有接口的 Base URL：`https://api.weixin.qq.com`

### 1. 获取 Access Token

```
GET /cgi-bin/token?grant_type=client_credential&appid={APPID}&secret={APPSECRET}
```

**返回：**
```json
{
  "access_token": "ACCESS_TOKEN",
  "expires_in": 7200
}
```

> access_token 有效期 2 小时，需要缓存并在过期前刷新。

### 2. 上传永久素材（封面图）

```
POST /cgi-bin/material/add_material?access_token={TOKEN}&type=image
```

- Content-Type: `multipart/form-data`
- 参数：`media` 文件字段

**返回：**
```json
{
  "media_id": "MEDIA_ID",
  "url": "URL"
}
```

### 3. 上传正文图片

```
POST /cgi-bin/media/uploadimg?access_token={TOKEN}
```

- Content-Type: `multipart/form-data`
- 参数：`media` 文件字段

**返回：**
```json
{
  "url": "https://mmbiz.qpic.cn/..."
}
```

> 正文图片返回的是 URL（不是 media_id），用于替换文章 HTML 中的 img src。

### 4. 新建草稿

```
POST /cgi-bin/draft/add?access_token={TOKEN}
```

**请求 Body：**
```json
{
  "articles": [
    {
      "title": "文章标题",
      "author": "作者",
      "digest": "摘要（可选，不填则自动抓取正文前54字）",
      "content": "<p>正文 HTML 内容</p>",
      "content_source_url": "原文链接（可选）",
      "thumb_media_id": "封面图的 media_id",
      "need_open_comment": 0,
      "only_fans_can_comment": 0
    }
  ]
}
```

**返回：**
```json
{
  "media_id": "DRAFT_MEDIA_ID"
}
```

### 5. 发布草稿

```
POST /cgi-bin/freepublish/submit?access_token={TOKEN}
```

**请求 Body：**
```json
{
  "media_id": "DRAFT_MEDIA_ID"
}
```

**返回：**
```json
{
  "publish_id": "PUBLISH_ID"
}
```

### 6. 查询发布状态

```
POST /cgi-bin/freepublish/get?access_token={TOKEN}
```

**请求 Body：**
```json
{
  "publish_id": "PUBLISH_ID"
}
```

**返回：**
```json
{
  "publish_id": "PUBLISH_ID",
  "publish_status": 0,
  "article_id": "ARTICLE_ID",
  "article_detail": {
    "count": 1,
    "item": [
      {
        "idx": 1,
        "article_url": "https://mp.weixin.qq.com/s?..."
      }
    ]
  }
}
```

> publish_status：0=成功，1=发布中，2+=失败

---

## 前提条件

### 必须满足

- [ ] 公众号类型：**已认证的服务号或订阅号**
- [ ] 获取 **AppID** 和 **AppSecret**（公众号后台 → 设置与开发 → 基本配置）
- [ ] 配置 **IP 白名单**（调用 token 接口的服务器 IP）
- [ ] 开通 **发布权限**（部分接口需要额外开通）

### 重要限制

> **2025年7月起**，个人主体账号、企业主体未认证账号及不支持认证的账号将被回收发布接口（freepublish）的调用权限。

### 接口频率限制

| 接口 | 频率限制 |
|------|----------|
| 获取 access_token | 2000 次/天 |
| 上传永久素材 | 5000 次/天（总量上限因账号类型不同） |
| 新建草稿 | 无明确限制，但建议控制频率 |
| 发布草稿 | 每天发布次数与群发次数共享配额 |

---

## Python 实现参考

### 依赖

```bash
pip install requests markdown
```

### 核心代码

```python
"""
微信公众号自动发布脚本
使用前请配置 config 中的 APPID 和 APPSECRET
"""

import requests
import json
import time
import markdown

# ============ 配置区 ============

config = {
    "APPID": "你的AppID",
    "APPSECRET": "你的AppSecret",
    "BASE_URL": "https://api.weixin.qq.com",
}

# ============ Token 管理 ============

_token_cache = {"token": None, "expires_at": 0}

def get_access_token():
    """获取 access_token，带简单缓存"""
    now = time.time()
    if _token_cache["token"] and now < _token_cache["expires_at"]:
        return _token_cache["token"]

    url = f"{config['BASE_URL']}/cgi-bin/token"
    params = {
        "grant_type": "client_credential",
        "appid": config["APPID"],
        "secret": config["APPSECRET"],
    }
    resp = requests.get(url, params=params).json()

    if "access_token" not in resp:
        raise Exception(f"获取 token 失败: {resp}")

    _token_cache["token"] = resp["access_token"]
    _token_cache["expires_at"] = now + resp["expires_in"] - 300  # 提前5分钟刷新
    return _token_cache["token"]

# ============ 素材上传 ============

def upload_thumb_image(image_path):
    """上传封面图（永久素材），返回 media_id"""
    token = get_access_token()
    url = f"{config['BASE_URL']}/cgi-bin/material/add_material"
    params = {"access_token": token, "type": "image"}
    with open(image_path, "rb") as f:
        files = {"media": f}
        resp = requests.post(url, params=params, files=files).json()

    if "media_id" not in resp:
        raise Exception(f"上传封面图失败: {resp}")

    return resp["media_id"]

def upload_content_image(image_path):
    """上传正文图片，返回可用于正文的 URL"""
    token = get_access_token()
    url = f"{config['BASE_URL']}/cgi-bin/media/uploadimg"
    params = {"access_token": token}
    with open(image_path, "rb") as f:
        files = {"media": f}
        resp = requests.post(url, params=params, files=files).json()

    if "url" not in resp:
        raise Exception(f"上传正文图片失败: {resp}")

    return resp["url"]

# ============ 草稿与发布 ============

def create_draft(title, content_html, thumb_media_id, author="", digest=""):
    """创建草稿，返回草稿 media_id"""
    token = get_access_token()
    url = f"{config['BASE_URL']}/cgi-bin/draft/add"
    params = {"access_token": token}
    data = {
        "articles": [
            {
                "title": title,
                "author": author,
                "digest": digest,
                "content": content_html,
                "thumb_media_id": thumb_media_id,
                "need_open_comment": 0,
                "only_fans_can_comment": 0,
            }
        ]
    }
    resp = requests.post(url, params=params, json=data).json()

    if "media_id" not in resp:
        raise Exception(f"创建草稿失败: {resp}")

    return resp["media_id"]

def publish_draft(draft_media_id):
    """发布草稿，返回 publish_id"""
    token = get_access_token()
    url = f"{config['BASE_URL']}/cgi-bin/freepublish/submit"
    params = {"access_token": token}
    data = {"media_id": draft_media_id}
    resp = requests.post(url, params=params, json=data).json()

    if "publish_id" not in resp:
        raise Exception(f"发布草稿失败: {resp}")

    return resp["publish_id"]

def check_publish_status(publish_id, max_retries=10, interval=5):
    """轮询发布状态，返回文章 URL"""
    token = get_access_token()
    url = f"{config['BASE_URL']}/cgi-bin/freepublish/get"
    params = {"access_token": token}

    for i in range(max_retries):
        resp = requests.post(url, params=params, json={"publish_id": publish_id}).json()
        status = resp.get("publish_status", -1)

        if status == 0:  # 发布成功
            article_url = resp["article_detail"]["item"][0]["article_url"]
            print(f"发布成功: {article_url}")
            return article_url
        elif status == 1:  # 发布中
            print(f"发布中... ({i+1}/{max_retries})")
            time.sleep(interval)
        else:  # 失败
            raise Exception(f"发布失败: {resp}")

    raise Exception("发布超时，请手动检查")

# ============ Markdown → HTML ============

def md_to_wechat_html(md_content):
    """将 Markdown 转为微信兼容的 HTML"""
    html = markdown.markdown(
        md_content,
        extensions=["extra", "codehilite", "tables"],
    )
    # 微信正文不支持外部 CSS，需要内联样式
    # 这里可以根据需要添加内联样式包装
    return html

# ============ 主流程 ============

def auto_publish(title, md_content, thumb_image_path, author="", digest=""):
    """
    一键发布：Markdown 文章 → 微信公众号

    参数：
        title: 文章标题
        md_content: Markdown 格式的文章内容
        thumb_image_path: 封面图本地路径
        author: 作者名（可选）
        digest: 文章摘要（可选，不填则取正文前54字）
    """
    print(f"[1/5] 上传封面图: {thumb_image_path}")
    thumb_media_id = upload_thumb_image(thumb_image_path)

    print("[2/5] 转换 Markdown → HTML")
    content_html = md_to_wechat_html(md_content)

    print(f"[3/5] 创建草稿: {title}")
    draft_media_id = create_draft(title, content_html, thumb_media_id, author, digest)

    print("[4/5] 发布草稿")
    publish_id = publish_draft(draft_media_id)

    print("[5/5] 等待发布完成")
    article_url = check_publish_status(publish_id)

    return article_url


# ============ 使用示例 ============

if __name__ == "__main__":
    # 示例：从文件读取 Markdown 并发布
    import sys

    if len(sys.argv) < 3:
        print("用法: python wechat_publish.py <markdown文件> <封面图路径> [标题]")
        print("示例: python wechat_publish.py article.md cover.jpg '我的文章标题'")
        sys.exit(1)

    md_file = sys.argv[1]
    cover_image = sys.argv[2]
    title = sys.argv[3] if len(sys.argv) > 3 else "未命名文章"

    with open(md_file, "r", encoding="utf-8") as f:
        md_content = f.read()

    url = auto_publish(title, md_content, cover_image)
    print(f"\n文章已发布: {url}")
```

---

## 待完善事项

- [ ] **公众号配置**：获取 AppID / AppSecret，配置 IP 白名单
- [ ] **正文样式**：微信不支持外部 CSS，需要做内联样式转换（可用 `premailer` 库或自定义模板）
- [ ] **图片处理**：正文中的本地图片需要先上传再替换 URL
- [ ] **封面图方案**：可以用 AI 生成，或预设一批模板封面
- [ ] **与知识库集成**：添加从 `02 我的知识/` 检索素材的逻辑
- [ ] **错误重试**：token 过期自动刷新、网络错误重试
- [ ] **安全存储**：AppID/AppSecret 不要硬编码，用环境变量或 `.env` 文件

---

## GitHub 开源方案（2026-03 调研）

自己从零搭之外，也可以直接用开源工具：

### 方案 A：zenbordercom/wechat-article-publisher（推荐）

- **地址**：https://github.com/zenbordercom/wechat-article-publisher
- **活跃度**：非常活跃（2026-03 仍在更新）
- **核心能力**：AI 写作 + Markdown + Python 本地渲染 HTML + 自动上传配图 + 发到草稿箱
- **架构思路**：AI 只负责生成 Markdown，Python 脚本负责渲染和上传，避免 AI 直接生成 HTML/CSS 导致格式不稳定
- **亮点**：十余种排版风格可选，支持自然语言调用（「帮我写篇xxx文章，用 Github 风格，发到草稿箱」）
- **依赖**：仅 Python
- **与我们系统的适配度**：高，天然契合「AI 写 Markdown → 脚本发布」的流程

### 方案 B：cheercheung/wechat-article-publisher

- **地址**：https://github.com/cheercheung/wechat-article-publisher
- **活跃度**：活跃维护中
- **核心能力**：Markdown → Wenyan 排版 → Evolink AI 生成封面 → 微信草稿箱
- **架构思路**：用 Wenyan MCP 做排版（排版更精致），Evolink API 自动生成封面图
- **依赖**：Python + Node.js（Wenyan MCP）+ Evolink API key
- **与我们系统的适配度**：中等，多了一层 Node.js 依赖

### 方案对比

| 维度 | 方案 A（zenborder） | 方案 B（cheercheung） | 自己从零搭（本文档） |
|------|---------------------|----------------------|-------------------|
| 复杂度 | 低，开箱即用 | 中，需 Node + Python | 高，但最可控 |
| 排版质量 | 多主题，本地渲染稳定 | Wenyan 排版更精致 | 自己搞 CSS |
| 封面图 | AI 生成 | Evolink API 生成 | 需自己接 |
| 依赖 | Python | Python + Node.js | Python |
| 灵活性 | 中 | 中 | 最高 |

> **建议**：先试方案 A，轻量且活跃。如果排版要求更高再考虑方案 B 或自己定制。

---

## 参考资料

- [微信公众号·发布接口文档](https://developers.weixin.qq.com/doc/offiaccount/Publish/Publish.html)
- [微信公众号·草稿箱接口文档](https://developers.weixin.qq.com/doc/offiaccount/Draft_Box/Add_draft.html)
- [微信公众号·素材管理接口文档](https://developers.weixin.qq.com/doc/offiaccount/Asset_Management/New_temporary_material.html)
- [zenbordercom/wechat-article-publisher](https://github.com/zenbordercom/wechat-article-publisher)
- [cheercheung/wechat-article-publisher](https://github.com/cheercheung/wechat-article-publisher)
