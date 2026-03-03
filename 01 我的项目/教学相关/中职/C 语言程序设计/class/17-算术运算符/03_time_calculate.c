 #include <stdio.h>

  int main() {
      int total;
      printf("输入总秒数：");
      scanf("%d", &total);

      int min = total / 60;
      int sec = total % 60;

      printf("%d秒 = %d分%d秒\n", total, min, sec);
      return 0;
  }
