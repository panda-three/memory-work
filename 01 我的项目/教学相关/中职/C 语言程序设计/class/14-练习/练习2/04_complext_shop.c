#include <stdio.h>

  int main() {
      // 定义变量
      float price;          // 商品原价
      int quantity;       // 购买数量
      int discount;       // 折扣（如85表示85折）
      double total_original; // 原总价
      double amount_due;     // 应付金额
      double paid;          // 实付金额
      double change;        // 找零

      // 输入数据
      printf("请输入商品原价：");
      scanf("%f", &price);

      printf("请输入购买数量：");
      scanf("%d", &quantity);

      printf("请输入折扣（如85表示85折）：");
      scanf("%d", &discount);

      printf("请输入实付金额：");
      scanf("%lf", &paid);

      // 计算原总价和应付金额
      total_original = price * quantity;
      amount_due = total_original * discount / 100;  // 计算折扣后价格

      // 计算找零
      change = paid - amount_due;

      // 输出结果
      printf("商品原价：%.1f元\n", price);
      printf("购买数量：%d个\n", quantity);
      printf("折扣：%d折\n", discount);
      printf("应付金额：%.1lf元\n", amount_due);
      printf("实付金额：%.1lf元\n", paid);
      printf("找零：%.1lf元\n", change);

      return 0;
  }
