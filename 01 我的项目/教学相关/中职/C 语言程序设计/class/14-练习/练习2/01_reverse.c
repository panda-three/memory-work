#include <stdio.h>

  int main() {
      // 定义变量
      int num;          // 输入的三位数
      int hundreds;     // 百位数
      int tens;         // 十位数
      int ones;         // 个位数
      int reversed;     // 反转后的数字

      // 输入三位数
      printf("请输入三位数：");
      scanf("%d", &num);

      // 拆分各位数字
      hundreds = num / 100;           // 百位
      tens = (num / 10) % 10;         // 十位
      ones = num % 10;                // 个位

      // 重新组合成反转数字
      reversed = ones * 100 + tens * 10 + hundreds;

      // 输出结果
      printf("原数字：%d\n", num);
      printf("反转后：%d\n", reversed);

      return 0;
  }
