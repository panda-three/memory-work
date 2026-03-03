 #include <stdio.h>

  int main() {
      float num1, num2;    // 两个操作数
      char operator;       // 运算符
      float result;        // 结果

      printf("请输入第一个数：");
      scanf("%f", &num1);

      printf("请输入运算符（+、-、*、/）：");
      scanf(" %c", &operator);

      printf("请输入第二个数：");
      scanf("%f", &num2);

      // 这里需要条件判断才能根据运算符计算
      // 由于不能用条件判断，我们只能演示输入输出
      printf("\n计算式：%.2f %c %.2f\n", num1, operator, num2);
      printf("请您手动计算结果\n");

      return 0;
  }
