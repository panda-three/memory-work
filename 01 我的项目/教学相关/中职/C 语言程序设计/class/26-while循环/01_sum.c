 #include <stdio.h>

  int main() {
      int i = 1;
      int sum = 0;

      while (i <= 100) {
          sum = sum + i;
          i++;
      }

      printf("1到100的累加和为：%d\n", sum);
      return 0;
  }
