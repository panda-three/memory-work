#include <stdio.h>

  int main() {
      int distance, amount, is_vip;

      printf("配送距离(公里)：");
      scanf("%d", &distance);
      printf("订单金额(元)：");
      scanf("%d", &amount);
      printf("是否VIP(1/0)：");
      scanf("%d", &is_vip);

      int near = distance <= 5;
      int expensive = amount >= 50;
      int can_deliver = (near || expensive) || is_vip;

      printf("\n=== 配送条件检查 ===\n");
      printf("距离合适(<=5km)：%d\n", near);
      printf("金额达标(>=50元)：%d\n", expensive);
      printf("VIP用户：%d\n", is_vip);
      printf("满足任一条件：%d\n", near || expensive || is_vip);
      printf("可以配送：%d\n", can_deliver);

      return 0;
  }
