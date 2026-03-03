  #include <stdio.h>

  int main() {
      int my_chinese, my_math, my_english;
      int friend_chinese, friend_math, friend_english;

      printf("=== 我的成绩 ===\n");
      printf("语文：");
      scanf("%d", &my_chinese);
      printf("数学：");
      scanf("%d", &my_math);
      printf("英语：");
      scanf("%d", &my_english);

      int my_total = 0;
      my_total += my_chinese;
      my_total += my_math;
      my_total += my_english;

      printf("\n=== 同桌成绩 ===\n");
      printf("语文：");
      scanf("%d", &friend_chinese);
      printf("数学：");
      scanf("%d", &friend_math);
      printf("英语：");
      scanf("%d", &friend_english);

      int friend_total = 0;
      friend_total += friend_chinese;
      friend_total += friend_math;
      friend_total += friend_english;

      printf("\n我的总分：%d\n", my_total);
      printf("同桌总分：%d\n", friend_total);
      printf("我比同桌高：%d (1=是，0=否)\n", my_total > friend_total);
      printf("我们分数相同：%d\n(1=相同，0表示不同)", my_total == friend_total);
      return 0;
  }
