#include <stdio.h>

  int main() {
      char area;          // 区域
      int floor;          // 楼层
      int spot_number;    // 车位号

      printf("请输入停车场区域（A/B/C）：");
      scanf("%c", &area);

      printf("请输入楼层（1-5）：");
      scanf("%d", &floor);

      printf("请输入车位号（1-99）：");
      scanf("%d", &spot_number);

      // 输出完整车位编号
      printf("\n您的车位编号是：%c%d-%02d\n", area, floor, spot_number);
      printf("区域：%c区\n", area);
      printf("楼层：%d楼\n", floor);
      printf("车位：%d号\n", spot_number);

      return 0;
  }
