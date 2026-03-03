#include <stdio.h>

  int main() {
      int level, gold;

      printf("玩家等级：");
      scanf("%d", &level);
      printf("拥有金币：");
      scanf("%d", &gold);

      int can_enter = (level >= 10) && (gold >= 100);
      int level_ok = level >= 10;
      int gold_ok = gold >= 100;

      printf("\n=== 登录检测 ===\n");
      printf("等级达标(>=10)：%d\n", level_ok);
      printf("金币达标(>=100)：%d\n", gold_ok);
      printf("可以进入游戏：%d\n", can_enter);
      printf("被拒绝：%d\n", !can_enter);

      return 0;
  }
