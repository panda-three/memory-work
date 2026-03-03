#include <stdio.h>

  int containsFour(int n) {
      while (n > 0) {
          if (n % 10 == 4) return 1;
          n /= 10;
      }
      return 0;
  }

  int main() {
      int count = 0;
      int num = 1;

      printf("前30个不含4的幸运数：\n");

      while (count < 30) {
          if (containsFour(num)) {
              num++;
              continue;
          }

          count++;
          printf("%d ", num);

          if (count % 10 == 0) {
              printf("\n");
          }

          num++;
      }
      return 0;
  }
