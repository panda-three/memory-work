#include <stdio.h>

  int main() {
      int i = 2;
      int sum = 0;

      while (i <= 50) {
          sum = sum + i;
          i = i + 2;
      }

      printf("1到50之间偶数的和为：%d\n", sum);
      return 0;
  }
