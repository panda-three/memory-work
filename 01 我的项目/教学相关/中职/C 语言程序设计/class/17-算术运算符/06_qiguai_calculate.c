  #include <stdio.h>

  int main() {
      int a, b;
      printf("输入两个数：");
      scanf("%d %d", &a, &b);

      printf("相加：%d\n", a + b);
      printf("相乘：%d\n", a * b);
      printf("平均值：%d\n", (a + b) / 2);
      printf("差的绝对值：%d\n", (a > b) ? (a - b) : (b - a));
      printf("合并成一个数：%d\n", a * 100 + b);  // 如12和34变成1234
      return 0;
  }
