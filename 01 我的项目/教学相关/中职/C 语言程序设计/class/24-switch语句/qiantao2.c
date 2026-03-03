 #include <stdio.h>

  int main() {
      int level;
      double amount, finalPrice;

      printf("请输入会员等级(1-普通,2-银卡,3-金卡)：");
      scanf("%d", &level);
      printf("请输入购买金额：");
      scanf("%lf", &amount);

      if (level == 1) {  // 普通会员
          if (amount < 1000) {
              finalPrice = amount;
              printf("普通会员，无折扣\n");
          } else if (amount <= 5000) {
              finalPrice = amount * 0.95;
              printf("普通会员，享受9.5折\n");
          } else {
              finalPrice = amount * 0.9;
              printf("普通会员，享受9折\n");
          }
      } else if (level == 2) {  // 银卡会员
          if (amount < 1000) {
              finalPrice = amount * 0.98;
              printf("银卡会员，享受9.8折\n");
          } else if (amount <= 5000) {
              finalPrice = amount * 0.9;
              printf("银卡会员，享受9折\n");
          } else {
              finalPrice = amount * 0.85;
              printf("银卡会员，享受8.5折\n");
          }
      } else if (level == 3) {  // 金卡会员
          if (amount > 5000) {
              finalPrice = amount * 0.8 * 0.95;
              printf("金卡会员，享受7.6折（8折基础上再打9.5折）\n");
          } else {
              finalPrice = amount * 0.8;
              printf("金卡会员，享受8折\n");
          }
      } else {
          printf("会员等级输入错误！\n");
          return 1;
      }

      printf("原价：%.2f元\n", amount);
      printf("实付：%.2f元\n", finalPrice);
      printf("节省：%.2f元\n", amount - finalPrice);

      return 0;
  }

