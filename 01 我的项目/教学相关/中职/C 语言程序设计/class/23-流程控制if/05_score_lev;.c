#include <stdio.h>
  int main() {
      int score;

      printf("请输入成绩（0-100）：");
      scanf("%d", &score);

      if (score < 0 || score > 100) {
          printf("输入的成绩无效！\n");
      } else if (score >= 90) {
          printf("等级：优秀\n");
      } else if (score >= 80) {
          printf("等级：良好\n");
      } else if (score >= 70) {
          printf("等级：中等\n");
      } else if (score >= 60) {
          printf("等级：及格\n");
      } else {
          printf("等级：不及格\n");
      }

      return 0;
  }
