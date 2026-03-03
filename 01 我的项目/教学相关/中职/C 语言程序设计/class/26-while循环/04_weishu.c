#include <stdio.h>

  int main() {
      int num, count = 0;

      printf("请输入一个正整数：");
      scanf("%d", &num);

      while (num > 0) {
          count++;
          num = num / 10;
      }

      printf("这个数有%d位\n", count);
      return 0;
  }
