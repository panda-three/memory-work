#include <stdio.h>

  int main() {
      int gold = 1000;
      int item1, item2, item3;

      printf("初始金币：%d\n", gold);

      printf("装备1价格：");
      scanf("%d", &item1);
      gold -= item1;
      printf("购买后余额：%d\n", gold);

      printf("装备2价格：");
      scanf("%d", &item2);
      gold -= item2;
      printf("购买后余额：%d\n", gold);

      printf("装备3价格：");
      scanf("%d", &item3);
      gold -= item3;

      printf("\n最终余额：%d金币\n", gold);
      printf("是否破产：%d (1=破产，0=还有钱)\n", gold < 0);
      printf("还能买100金币的装备：%d\n", gold >= 100);
      return 0;
  }
