#include <stdio.h>

  int main() {
      int small, big;
      printf("打败小怪数量：");
      scanf("%d", &small);
      printf("打败大怪数量：");
      scanf("%d", &big);

      int score = small * 10 + big * 50;
      printf("总分：%d\n", score);
      return 0;
  }
