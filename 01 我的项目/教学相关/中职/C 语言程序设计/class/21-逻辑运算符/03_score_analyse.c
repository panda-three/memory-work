#include <stdio.h>

  int main() {
      int chinese, math, english;

      printf("语文成绩：");
      scanf("%d", &chinese);
      printf("数学成绩：");
      scanf("%d", &math);
      printf("英语成绩：");
      scanf("%d", &english);

      int total = chinese + math + english;
      int no_fail = (chinese >= 50) && (math >= 50) && (english >= 50);
      int total_ok = total >= 180;
      int pass = total_ok && no_fail;

      printf("\n=== 成绩分析 ===\n");
      printf("总分：%d\n", total);
      printf("总分达标(>=180)：%d\n", total_ok);
      printf("无不及格科目：%d\n", no_fail);
      printf("语文不及格：%d\n", !(chinese >= 50));
      printf("数学不及格：%d\n", !(math >= 50));
      printf("英语不及格：%d\n", !(english >= 50));
      printf("最终及格：%d\n", pass);

      return 0;
  }
