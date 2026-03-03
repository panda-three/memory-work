#include <stdio.h>

  int main() {
      int num, reversed = 0, digit;

      printf("请输入一个正整数：");
      scanf("%d", &num);

      while (num > 0) {
          digit = num % 10;
          reversed = reversed * 10 + digit;
          num = num / 10;
      }

      printf("反转后的数字：%d\n", reversed);
      return 0;
  }
