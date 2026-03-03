 #include <stdio.h>

  int main() {
      int num, hundred, ten, unit;
      int sum, cubeSum;

      printf("请输入一个三位数（100-999）：");
      scanf("%d", &num);

      // 提取各位数字
      hundred = num / 100;
      ten = (num / 10) % 10;
      unit = num % 10;

      // 计算特征值
      sum = hundred + ten + unit;
      cubeSum = hundred*hundred*hundred + ten*ten*ten + unit*unit*unit;

      printf("\n数字%d的分析结果：\n", num);
      printf("百位：%d，十位：%d，个位：%d\n", hundred, ten, unit);
      printf("各位数字之和：%d\n", sum);

      // 判断水仙花数
      printf("是否为水仙花数：%s", cubeSum == num ? "是" : "否");
      printf("（%d3+%d3+%d3=%d）\n", hundred, ten, unit, cubeSum);

      // 判断回文数
      printf("是否为回文数：%s\n", hundred == unit ? "是" : "否");

      // 判断奇偶性
      printf("该数是%s数\n", num % 2 == 0 ? "偶" : "奇");

      return 0;
  }
