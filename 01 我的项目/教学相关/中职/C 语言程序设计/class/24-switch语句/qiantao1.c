#include <stdio.h>

  int main() {
      int score;
      printf("请输入学生成绩(0-100)：");
      scanf("%d", &score);

      if (score >= 90 && score <= 100) {
          if (score >= 95) {
              printf("优秀（特别优异）\n");
          } else {
              printf("优秀\n");
          }
      } else if (score >= 80) {
          if (score >= 85) {
              printf("良好（接近优秀）\n");
          } else {
              printf("良好\n");
          }
      } else if (score >= 60) {
          if (score >= 70) {
              printf("及格（中等）\n");
          } else {
              printf("及格（需要努力）\n");
          }
      } else if (score >= 0) {
          if (score < 30) {
              printf("不及格（需要补考）\n");
          } else {
              printf("不及格\n");
          }
      } else {
          printf("成绩输入有误\n");
      }

      return 0;
  }
