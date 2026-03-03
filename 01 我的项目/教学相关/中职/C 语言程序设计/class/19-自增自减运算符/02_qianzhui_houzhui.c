#include <stdio.h>

int main() {
      int num;
      printf("输入一个数字：");
      scanf("%d", &num);
      int a = num;
      int b = num;
      printf("\n===前缀++测试===\n");
      printf("a的值：%d\n", a);
      printf("执行 ++a 后直接输出：%d\n", ++a);
      printf("a现在的值：%d\n", a);

      printf("\n===后缀++测试===\n");
      printf("b的值：%d\n", b);
      printf("执行 b++ 后直接输出：%d\n", b++);
      printf("b现在的值：%d\n", b);

      printf("\n总结：前缀++先加再用，后缀++先用再加\n");
      return 0;
  }
