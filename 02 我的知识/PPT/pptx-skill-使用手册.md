---
title: pptx skill 使用手册
type: 工具使用记录
date: 2026-03-04
tags: [pptx, skill, Claude, OOXML, 教学PPT]
---

# pptx skill 使用手册

> 记录 Claude 使用内置 pptx skill 的工作方式，方便复查和复用。

---

## 一、skill 能做什么

| 场景 | 触发方式 | 工具路径 |
|------|----------|----------|
| 读取/分析现有 PPT | "读取这个 pptx"、"分析内容" | markitdown 提取文字 |
| 从零创建 PPT | "帮我做一个 PPT" | html2pptx 工作流 |
| 基于模板创建 PPT | "用这个模板制作…" | rearrange.py + replace.py |
| 编辑现有 PPT | "修改第X张幻灯片" | OOXML 直接编辑 XML |

---

## 二、我实际怎么工作的（OOXML 编辑流程）

### 第一步：解包

```bash
python3 .claude/skills/pptx/ooxml/scripts/unpack.py <file.pptx> <output_dir>
```

解包后结构：
- `ppt/slides/slide{N}.xml` — 每张幻灯片内容
- `ppt/slides/_rels/slide{N}.xml.rels` — 每张幻灯片的资源关联（图片、布局）
- `ppt/media/` — 图片等媒体文件

### 第二步：理解内容

**批量提取文字**（快速了解全部幻灯片）：
```python
import os, re
from xml.etree import ElementTree as ET

slides_dir = '/tmp/pptx_analyze/ppt/slides'
slides = sorted([f for f in os.listdir(slides_dir) if f.startswith('slide') and f.endswith('.xml')],
                key=lambda x: int(re.search(r'\d+', x).group()))

for fname in slides:
    tree = ET.parse(os.path.join(slides_dir, fname))
    texts = [t.text for t in tree.getroot().iter('{http://schemas.openxmlformats.org/drawingml/2006/main}t') if t.text and t.text.strip()]
    print(f"=== {fname} ===")
    print(' | '.join(texts))
```

**查看幻灯片中的图片**：
```python
# 读 _rels 文件，找每张幻灯片引用了哪些图片
rels_dir = '/tmp/pptx_analyze/ppt/slides/_rels'
for fname in slides:
    rel_file = os.path.join(rels_dir, fname + '.rels')
    if not os.path.exists(rel_file): continue
    tree = ET.parse(rel_file)
    images = [os.path.basename(rel.get('Target','')) for rel in tree.getroot() if 'media' in rel.get('Target','')]
    if images: print(f"{fname}: {images}")
```

**直接读图片内容**：用 `mcp_Read` 工具读取图片文件，Claude 能视觉识别图片内容。

### 第三步：精确定位需要改的 XML

用 Python 字符串搜索，找到目标文本附近的 XML 上下文：
```python
with open('slide{N}.xml') as f:
    content = f.read()
idx = content.find('目标文字')
print(repr(content[max(0, idx-200):idx+300]))
```

### 第四步：编辑 XML

**改文字**（最简单）：
```python
s = s.replace('<a:t>旧文字</a:t>', '<a:t>新文字</a:t>')
```

**删除整个段落**（`<a:p>...</a:p>`）：
```python
def remove_para_containing(content, marker):
    """删除包含 marker 的完整 <a:p>...</a:p> 段落"""
    result = []
    i = 0
    while i < len(content):
        if content[i:].startswith('<a:p>') or content[i:].startswith('<a:p '):
            end = content.find('</a:p>', i)
            if end == -1:
                result.append(content[i:])
                break
            para = content[i:end+6]
            if marker in para:
                i = end + 6
                while i < len(content) and content[i] in '\n':
                    i += 1
            else:
                result.append(para)
                i = end + 6
        else:
            result.append(content[i])
            i += 1
    return ''.join(result)
```

**删除图片元素**（`<p:pic>...</p:pic>`）：
```python
import re
# 先在 _rels 文件中找到图片对应的 rId
m = re.search(r'Id="(rId\d+)"[^>]*Target="\.\.\/media\/image17\.png"', rels_content)
rid = m.group(1)
# 然后删除引用该 rId 的 <p:pic> 元素
pic_pattern = rf'<p:pic>.*?r:embed="{rid}".*?</p:pic>'
s = re.sub(pic_pattern, '', s, flags=re.DOTALL)
```

**新增形状/文本框**（在 `</p:spTree>` 前插入）：
```python
new_shape = '''      <p:sp>
        <p:nvSpPr>
          <p:cNvPr id="99" name="新形状名"/>
          <p:cNvSpPr txBox="1"/>
          <p:nvPr/>
        </p:nvSpPr>
        <p:spPr>
          <a:xfrm>
            <a:off x="1300000" y="1700000"/>
            <a:ext cx="9200000" cy="4000000"/>
          </a:xfrm>
          <a:prstGeom prst="rect"><a:avLst/></a:prstGeom>
          <a:noFill/>
        </p:spPr>
        <p:txBody>
          <a:bodyPr wrap="square" rtlCol="0"><a:spAutoFit/></a:bodyPr>
          <a:lstStyle/>
          <a:p>
            <a:r>
              <a:rPr lang="zh-CN" altLang="en-US" sz="2400" b="1" dirty="0"/>
              <a:t>文字内容</a:t>
            </a:r>
          </a:p>
        </p:txBody>
      </p:sp>'''
s = s.replace('    </p:spTree>', new_shape + '    </p:spTree>')
```

### 第五步：保存前处理 ASCII 编码

**重要**：解包的 XML 文件声明 `encoding="ascii"`，写入含中文的内容时必须先转义：

```python
# 把所有非 ASCII 字符转为 &#xxxx; 实体
def to_ascii_entities(content):
    return ''.join(f'&#{ord(ch)};' if ord(ch) > 127 else ch for ch in content)

with open(path, 'w', encoding='ascii') as f:
    f.write(to_ascii_entities(content))
```

### 第六步：验证 XML

```python
import xml.etree.ElementTree as ET
try:
    ET.parse(path)
    print("XML valid")
except Exception as e:
    print(f"ERROR: {e}")
```

### 第七步：打包

```bash
# 需要 Python 3.10+（pack.py 用了 match 语法）
/opt/miniconda3/bin/python3.13 .claude/skills/pptx/ooxml/scripts/pack.py <input_dir> <output.pptx>
```

---

## 三、环境踩坑记录

| 问题 | 原因 | 解决 |
|------|------|------|
| `No module named markitdown` | 未安装 | `pip install "markitdown[pptx]"` |
| `No module named defusedxml` | 未安装 | `pip3 install defusedxml` |
| `SyntaxError: match` | Python 3.9（系统默认），不支持 match 语句 | 改用 `/opt/miniconda3/bin/python3.13` |
| XML 写入报 invalid token | 文件是 ASCII 编码，直接写中文会出错 | 用 `&#xxxx;` 实体转义所有非 ASCII 字符 |
| pack.py 报"must be a .pptx file" | 路径用了相对路径 `.` | 使用绝对路径 |

---

## 四、关键 OOXML 结构速查

```
幻灯片文件         ppt/slides/slide{N}.xml
资源关联           ppt/slides/_rels/slide{N}.xml.rels
媒体文件           ppt/media/image{N}.png
主题               ppt/theme/theme1.xml
```

文本结构层级：
```
<p:sp>              形状（文本框）
  <p:txBody>
    <a:p>           段落
      <a:r>         文字 run
        <a:rPr>     文字属性（字号 sz、加粗 b="1"、颜色等）
        <a:t>       文字内容
```

图片结构：
```
<p:pic>
  <p:blipFill>
    <a:blip r:embed="rId2"/>   ← rId 对应 _rels 文件中的图片路径
```

坐标单位：EMU（English Metric Units），1 厘米 = 360000 EMU，1 英寸 = 914400 EMU。

---

## 五、实战案例：52-文件-读.pptx 改版（2026-03-04）

**需求**：C 语言教学 PPT，根据分析建议做针对性修改

**改动清单**：

| 幻灯片 | 改动 |
|--------|------|
| Slide 11 | 删除 14 行转义字符大表图片（image17），替换为只讲 `\\` 和 `\n` 的精简文字框 |
| Slide 13 | 步骤图中 `fgetc fgets fread` 改为只保留 `fgetc` |
| Slide 14 | 练习页删除 fgets、fread 两行说明 |
| Slide 18 | 代码从单字符读取改为 `while ((c = fgetc(file)) != -1)` 完整循环；注释同步更新 |
| Slide 21 | 空白检测页补充 ① ~ ④ 四步综合题 |

**产出文件**：`52-文件-读-v2.pptx`（与原文件同目录）

---

## 六、分析 PPT 的思路（给自己的备注）

分析一份 PPT 时关注：
1. **目标与内容是否对齐** — 列出来的知识点，幻灯片里有没有实际讲
2. **核心示例是否完整** — 代码/操作步骤是否能单独运行/完成
3. **图片是否可替换为可编辑文字** — 图片代码学生无法复制，建议改文本
4. **练习题有无答案** — 中职课堂节奏快，答案页必须有
5. **限时检测是否有内容** — 空页是常见遗漏
