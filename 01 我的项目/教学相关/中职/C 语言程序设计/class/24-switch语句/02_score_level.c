 #include <stdio.h>
  int main() {
      char grade;

      printf("请输入成绩等级（A、B、C、D、F）：");
      scanf("%c", &grade);

      switch (grade) {
          case 'A':
          case 'a':
              printf("90-100分，优秀\n");
              break;
          case 'B':
          case 'b':
              printf("80-89分，良好\n");
              break;
          case 'C':
          case 'c':
              printf("70-79分，中等\n");
              break;
          case 'D':
          case 'd':
              printf("60-69分，及格\n");
              break;
          case 'F':
          case 'f':
              printf("0-59分，不及格\n");
              break;
          default:
              printf("输入的等级无效！\n");
              break;
      }

      return 0;
  }
