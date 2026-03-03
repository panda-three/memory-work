 #include <stdio.h>

  int main() {
      int a, b, temp, result;

      printf("请输入两个整数（空格分隔）：");
      scanf("%d %d", &a, &b);

      printf("交换前：a=%d, b=%d\n", a, b);

      // 使用逗号运算符完成多个操作
      result = (temp = a, a = b, b = temp, a > b ? 1 : 0);

      printf("交换后：a=%d, b=%d\n", a, b);
  

      return 0;
  }

