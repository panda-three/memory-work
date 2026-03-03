#include <stdio.h>
  int main() {
      int num;

      printf("请输入一个整数：");
      scanf("%d", &num);

      if (num % 2 == 0) {
          printf("%d是偶数\n", num);
      } else {
          printf("%d是奇数\n", num);
      }

      return 0;
  }
