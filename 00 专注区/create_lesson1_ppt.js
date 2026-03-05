const PptxGenJS = require("pptxgenjs");
const pptx = new PptxGenJS();

pptx.layout = "LAYOUT_16x9";
pptx.author = "周磊";
pptx.title = "数字电路基础 + 与门";

const colors = {
  primary: "1C2833",
  secondary: "2E4053",
  accent: "3498DB",
  question: "F1C40F",
  exercise: "E8F8F5",
  answer: "D5F4E6"
};

// 第 1 页：封面
let slide = pptx.addSlide();
slide.background = { color: colors.primary };
slide.addText("数字电路基础 + 与门", {
  x: 1, y: 2.5, w: 8, h: 1,
  fontSize: 44, bold: true, color: "FFFFFF", align: "center"
});
slide.addText("第 1 课", {
  x: 1, y: 3.5, w: 8, h: 0.5,
  fontSize: 24, color: "FFFFFF", align: "center"
});

// 第 2 页：提问 1
slide = pptx.addSlide();
slide.background = { color: colors.question };
slide.addText("?", {
  x: 4, y: 1, w: 2, h: 2,
  fontSize: 120, bold: true, color: "FFFFFF", align: "center"
});
slide.addText("生活中哪些情况是", {
  x: 1, y: 2.8, w: 8, h: 0.5,
  fontSize: 32, bold: true, color: "2C3E50", align: "center"
});
slide.addText('"同时满足"才能发生的？', {
  x: 1, y: 3.3, w: 8, h: 0.5,
  fontSize: 32, bold: true, color: "2C3E50", align: "center"
});
slide.addText("请举 2-3 个例子", {
  x: 1, y: 4.2, w: 8, h: 0.5,
  fontSize: 20, color: "7F8C8D", align: "center"
});

// 第 3 页：数字电路基础
slide = pptx.addSlide();
slide.addText("一、数字电路基础", {
  x: 0.5, y: 0.3, w: 9, h: 0.6,
  fontSize: 32, bold: true, color: colors.primary
});
slide.addText("电子线路中的电信号有两大类：模拟信号 和 数字信号", {
  x: 0.5, y: 1.2, w: 9, h: 0.5,
  fontSize: 20
});

const concepts = [
  "• 模拟信号：在数值上和时间上都是连续变化的信号",
  "• 数字信号：在数值上和时间上不连续变化的信号",
  "• 模拟电路：处理模拟信号的电路",
  "• 数字电路：处理数字信号的电路"
];

let yPos = 2;
concepts.forEach(text => {
  slide.addText(text, {
    x: 1, y: yPos, w: 8, h: 0.5,
    fontSize: 18
  });
  yPos += 0.6;
});

// 第 4 页：逻辑状态
slide = pptx.addSlide();
slide.addText("二、逻辑状态的表示", {
  x: 0.5, y: 0.3, w: 9, h: 0.6,
  fontSize: 32, bold: true, color: colors.primary
});
slide.addText("用数字符号 0 和 1 表示相互对立的逻辑状态", {
  x: 1, y: 1.5, w: 8, h: 0.8,
  fontSize: 24, align: "center", color: colors.accent
});
slide.addShape(pptx.ShapeType.rect, {
  x: 2, y: 2.5, w: 2.5, h: 1.5,
  fill: { color: "E8F8F5" }
});
slide.addText("逻辑 0", {
  x: 2, y: 2.9, w: 2.5, h: 0.6,
  fontSize: 28, bold: true, align: "center"
});
slide.addShape(pptx.ShapeType.rect, {
  x: 5.5, y: 2.5, w: 2.5, h: 1.5,
  fill: { color: "E8F8F5" }
});
slide.addText("逻辑 1", {
  x: 5.5, y: 2.9, w: 2.5, h: 0.6,
  fontSize: 28, bold: true, align: "center"
});

// 第 5 页：提问 2
slide = pptx.addSlide();
slide.background = { color: colors.question };
slide.addText("?", {
  x: 4, y: 1, w: 2, h: 2,
  fontSize: 120, bold: true, color: "FFFFFF", align: "center"
});
slide.addText("如果用 0 和 1 表示开关的状态", {
  x: 1, y: 2.8, w: 8, h: 0.5,
  fontSize: 28, bold: true, color: "2C3E50", align: "center"
});
slide.addText("开关打开用什么表示？关闭呢？", {
  x: 1, y: 3.4, w: 8, h: 0.5,
  fontSize: 28, bold: true, color: "2C3E50", align: "center"
});

// 第 6 页：高低电平
slide = pptx.addSlide();
slide.addText("三、高低电平", {
  x: 0.5, y: 0.3, w: 9, h: 0.6,
  fontSize: 32, bold: true, color: colors.primary
});
slide.addText("用高电平、低电平来描述电位的高低", {
  x: 1, y: 1.2, w: 8, h: 0.5,
  fontSize: 20
});
slide.addText("重要：高低电平不是固定值，而是电平变化范围", {
  x: 1, y: 2, w: 8, h: 0.5,
  fontSize: 20, bold: true, color: "E74C3C"
});

const levels = [
  "• 标准高电平 VSH —— 高电平的下限值",
  "• 标准低电平 VSL —— 低电平的上限值",
  "• 应用时：高电平 ≥ VSH，低电平 ≤ VSL"
];
yPos = 2.8;
levels.forEach(text => {
  slide.addText(text, {
    x: 1, y: yPos, w: 8, h: 0.5,
    fontSize: 18
  });
  yPos += 0.6;
});

// 第 7 页：练习 0.1（题目）
slide = pptx.addSlide();
slide.background = { color: colors.exercise };
slide.addText("练习 0.1：判断题", {
  x: 0.5, y: 0.5, w: 6, h: 0.6,
  fontSize: 28, bold: true, color: colors.primary
});
slide.addText("⏱ 答题时间：2 分钟", {
  x: 7, y: 0.5, w: 2.5, h: 0.5,
  fontSize: 16, color: "E74C3C", align: "right"
});

const questions1 = [
  "1. 高电平一定是 5V。",
  "2. 低电平一定小于或等于 VSL。",
  "3. 高电平和低电平是固定值。"
];
yPos = 1.8;
questions1.forEach(q => {
  slide.addText(q, {
    x: 1, y: yPos, w: 8, h: 0.6,
    fontSize: 22
  });
  yPos += 1;
});

// 第 8 页：练习 0.1（答案）
slide = pptx.addSlide();
slide.background = { color: colors.answer };
slide.addText("练习 0.1：答案", {
  x: 0.5, y: 0.5, w: 9, h: 0.6,
  fontSize: 28, bold: true, color: colors.primary
});

slide.addText("1. 高电平一定是 5V。 ×", {
  x: 1, y: 1.5, w: 8, h: 0.4,
  fontSize: 20, bold: true, color: "E74C3C"
});
slide.addText("   高电平是范围，不是固定值", {
  x: 1, y: 1.9, w: 8, h: 0.3,
  fontSize: 16, color: "7F8C8D", italic: true
});

slide.addText("2. 低电平一定小于或等于 VSL。 √", {
  x: 1, y: 2.5, w: 8, h: 0.4,
  fontSize: 20, bold: true, color: "27AE60"
});
slide.addText("   正确", {
  x: 1, y: 2.9, w: 8, h: 0.3,
  fontSize: 16, color: "7F8C8D", italic: true
});

slide.addText("3. 高电平和低电平是固定值。 ×", {
  x: 1, y: 3.5, w: 8, h: 0.4,
  fontSize: 20, bold: true, color: "E74C3C"
});
slide.addText("   是范围，不是固定值", {
  x: 1, y: 3.9, w: 8, h: 0.3,
  fontSize: 16, color: "7F8C8D", italic: true
});

// 第 9 页：正负逻辑
slide = pptx.addSlide();
slide.addText("四、正逻辑和负逻辑", {
  x: 0.5, y: 0.3, w: 9, h: 0.6,
  fontSize: 32, bold: true, color: colors.primary
});

slide.addShape(pptx.ShapeType.rect, {
  x: 1, y: 1.5, w: 3.5, h: 2,
  fill: { color: "E8F8F5" }
});
slide.addText("正逻辑", {
  x: 1, y: 1.7, w: 3.5, h: 0.5,
  fontSize: 24, bold: true, align: "center", color: colors.accent
});
slide.addText("1 = 高电平", {
  x: 1, y: 2.3, w: 3.5, h: 0.4,
  fontSize: 18, align: "center"
});
slide.addText("0 = 低电平", {
  x: 1, y: 2.7, w: 3.5, h: 0.4,
  fontSize: 18, align: "center"
});

slide.addShape(pptx.ShapeType.rect, {
  x: 5.5, y: 1.5, w: 3.5, h: 2,
  fill: { color: "FCF3CF" }
});
slide.addText("负逻辑", {
  x: 5.5, y: 1.7, w: 3.5, h: 0.5,
  fontSize: 24, bold: true, align: "center", color: "F39C12"
});
slide.addText("1 = 低电平", {
  x: 5.5, y: 2.3, w: 3.5, h: 0.4,
  fontSize: 18, align: "center"
});
slide.addText("0 = 高电平", {
  x: 5.5, y: 2.7, w: 3.5, h: 0.4,
  fontSize: 18, align: "center"
});

slide.addText("本课程默认使用正逻辑", {
  x: 1, y: 4, w: 8, h: 0.5,
  fontSize: 20, bold: true, color: "E74C3C", align: "center"
});

// 第 10 页：练习 0.2（题目）
slide = pptx.addSlide();
slide.background = { color: colors.exercise };
slide.addText("练习 0.2：填空题", {
  x: 0.5, y: 0.5, w: 6, h: 0.6,
  fontSize: 28, bold: true, color: colors.primary
});
slide.addText("⏱ 答题时间：2 分钟", {
  x: 7, y: 0.5, w: 2.5, h: 0.5,
  fontSize: 16, color: "E74C3C", align: "right"
});

slide.addText("1. 正逻辑规定：用 ___ 表示高电平，用 ___ 表示低电平。", {
  x: 1, y: 2, w: 8, h: 0.8,
  fontSize: 20
});
slide.addText("2. 负逻辑规定：用 ___ 表示低电平，用 ___ 表示高电平。", {
  x: 1, y: 3, w: 8, h: 0.8,
  fontSize: 20
});

// 第 11 页：练习 0.2（答案）
slide = pptx.addSlide();
slide.background = { color: colors.answer };
slide.addText("练习 0.2：答案", {
  x: 0.5, y: 0.5, w: 9, h: 0.6,
  fontSize: 28, bold: true, color: colors.primary
});

slide.addText("1. 正逻辑规定：用 1 表示高电平，用 0 表示低电平。", {
  x: 1, y: 2, w: 8, h: 0.8,
  fontSize: 20, bold: true, color: "27AE60"
});

slide.addText("2. 负逻辑规定：用 1 表示低电平，用 0 表示高电平。", {
  x: 1, y: 3, w: 8, h: 0.8,
  fontSize: 20, bold: true, color: "27AE60"
});

// 第 12 页：提问 3
slide = pptx.addSlide();
slide.background = { color: colors.question };
slide.addText("?", {
  x: 4, y: 1, w: 2, h: 2,
  fontSize: 120, bold: true, color: "FFFFFF", align: "center"
});
slide.addText('"两个开关都打开，灯才亮"', {
  x: 1, y: 2.8, w: 8, h: 0.5,
  fontSize: 28, bold: true, color: "2C3E50", align: "center"
});
slide.addText("这是什么逻辑关系？", {
  x: 1, y: 3.4, w: 8, h: 0.5,
  fontSize: 28, bold: true, color: "2C3E50", align: "center"
});

// 第 13 页：与门定义
slide = pptx.addSlide();
slide.addText("五、与门（AND Gate）", {
  x: 0.5, y: 0.3, w: 9, h: 0.6,
  fontSize: 32, bold: true, color: colors.primary
});

slide.addText("1. 与逻辑关系", {
  x: 0.5, y: 1.2, w: 9, h: 0.5,
  fontSize: 24, bold: true, color: colors.accent
});
slide.addText("当决定一件事情的几个条件全部具备后，这件事情才能发生。", {
  x: 1, y: 1.8, w: 8, h: 0.6,
  fontSize: 18
});

slide.addText("2. 逻辑符号", {
  x: 0.5, y: 2.6, w: 9, h: 0.5,
  fontSize: 24, bold: true, color: colors.accent
});
slide.addText("&", {
  x: 4, y: 3.2, w: 2, h: 1,
  fontSize: 60, bold: true, align: "center", color: colors.primary
});

// 第 14 页：与门真值表
slide = pptx.addSlide();
slide.addText("与门真值表", {
  x: 0.5, y: 0.3, w: 9, h: 0.6,
  fontSize: 32, bold: true, color: colors.primary
});

const truthTable = [
  [{ text: "A", options: { bold: true, fontSize: 24, fill: colors.accent, color: "FFFFFF" } },
   { text: "B", options: { bold: true, fontSize: 24, fill: colors.accent, color: "FFFFFF" } },
   { text: "Y", options: { bold: true, fontSize: 24, fill: colors.accent, color: "FFFFFF" } }],
  [{ text: "0", options: { fontSize: 24 } }, { text: "0", options: { fontSize: 24 } }, { text: "0", options: { fontSize: 24 } }],
  [{ text: "0", options: { fontSize: 24 } }, { text: "1", options: { fontSize: 24 } }, { text: "0", options: { fontSize: 24 } }],
  [{ text: "1", options: { fontSize: 24 } }, { text: "0", options: { fontSize: 24 } }, { text: "0", options: { fontSize: 24 } }],
  [{ text: "1", options: { fontSize: 24 } }, { text: "1", options: { fontSize: 24 } }, { text: "1", options: { fontSize: 24, bold: true, color: "27AE60" } }]
];

slide.addTable(truthTable, {
  x: 2.5, y: 1.5, w: 5, h: 2.5,
  align: "center",
  valign: "middle",
  border: { pt: 2, color: colors.primary }
});

slide.addText("逻辑函数式：Y = A · B  或  Y = AB", {
  x: 1, y: 4.2, w: 8, h: 0.5,
  fontSize: 20, align: "center", bold: true, color: colors.accent
});

slide.addText("口诀：全 1 出 1，有 0 出 0", {
  x: 1, y: 4.7, w: 8, h: 0.4,
  fontSize: 18, align: "center", bold: true, color: "E74C3C"
});

// 保存文件
pptx.writeFile({ fileName: "第1课-数字电路基础与与门.pptx" })
  .then(() => {
    console.log("PPT 生成成功！");
  })
  .catch(err => {
    console.error("生成失败：", err);
  });
