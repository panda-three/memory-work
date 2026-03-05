#!/bin/bash
# publish.sh - 排版 + 发布公众号文章一键脚本
#
# 用法：
#   ./publish.sh <markdown文件> [主题]
#
# 主题：default（默认）| grace | simple
#
# 注意：运行前关闭所有 Chrome 窗口

set -e

MD_FILE="$1"
THEME="${2:-default}"

# ── 参数校验 ───────────────────────────────────────────────────────────────────
if [ -z "$MD_FILE" ]; then
  echo "用法：$0 <markdown文件路径> [主题]"
  echo "主题：default（默认）| grace | simple"
  exit 1
fi

if [ ! -f "$MD_FILE" ]; then
  echo "错误：文件不存在：$MD_FILE"
  exit 1
fi

# ── 路径处理 ──────────────────────────────────────────────────────────────────
# 脚本所在目录（工具路径的基准）
ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"

# 将用户传入的路径（可能是相对路径）转为绝对路径
MD_ABS="$(python3 -c "import os,sys; print(os.path.abspath(sys.argv[1]))" "$MD_FILE")"

TOOL_RENDER="$ROOT_DIR/06 我的工具/jimliu-baoyu-markdown-to-html/scripts/main.ts"
TOOL_PUBLISH="$ROOT_DIR/06 我的工具/jimliu-baoyu-post-to-wechat/scripts/wechat-article.ts"

# ── 步骤 1：排版 ──────────────────────────────────────────────────────────────
echo "[1/2] 排版：$(basename "$MD_ABS")  主题：$THEME"

# stdout = JSON（title/htmlPath），stderr = 进度日志（直接显示到终端）
RENDER_JSON="$(npx -y bun "$TOOL_RENDER" "$MD_ABS" --theme "$THEME")"

TITLE="$(echo "$RENDER_JSON" | python3 -c "import json,sys; print(json.load(sys.stdin)['title'])")"
HTML_PATH="$(echo "$RENDER_JSON" | python3 -c "import json,sys; print(json.load(sys.stdin)['htmlPath'])")"

echo "    标题：$TITLE"
echo "    HTML ：$HTML_PATH"

# ── 步骤 2：发布 ──────────────────────────────────────────────────────────────
echo ""
echo "[2/2] 发布到公众号（保存为草稿）..."
echo "    首次使用需扫码登录，session 会缓存到本地"
echo ""

no_proxy="127.0.0.1,localhost" NO_PROXY="127.0.0.1,localhost" \
  npx -y bun "$TOOL_PUBLISH" \
  --title "$TITLE" \
  --html "$HTML_PATH"

# ── 完成 ──────────────────────────────────────────────────────────────────────
echo ""
echo "完成。草稿已保存到公众号后台，手动确认后发布。"
