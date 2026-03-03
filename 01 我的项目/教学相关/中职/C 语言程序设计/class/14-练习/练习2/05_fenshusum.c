#include <stdio.h>

  int main() {
      int num1, den1;     // 第一个分数的分子分母
      int num2, den2;     // 第二个分数的分子分母
      int new_num1, new_num2;  // 通分后的分子
      int common_den;     // 公分母
      int result_num;     // 结果分子

      printf("请输入第一个分数（分子 分母）：");
      scanf("%d %d", &num1, &den1);

      printf("请输入第二个分数（分子 分母）：");
      scanf("%d %d", &num2, &den2);

      // 计算公分母（简单用两分母相乘）
      common_den = den1 * den2;

      // 通分
      new_num1 = num1 * den2;
      new_num2 = num2 * den1;

      // 相加
      result_num = new_num1 + new_num2;

      printf("第一个分数：%d/%d\n", num1, den1);
      printf("第二个分数：%d/%d\n", num2, den2);
      printf("通分后：%d/%d + %d/%d\n", new_num1, common_den, new_num2, common_den);
      printf("相加结果：%d/%d\n", result_num, common_den);

      return 0;
  }
