 #include <stdio.h>

  int main() {
      float principal;     // 本金
      float rate;         // 年利率
      int years;          // 存款年数
      float total;        // 本息合计
      float interest;     // 利息

      printf("请输入本金：");
      scanf("%f", &principal);

      printf("请输入年利率（如0.03）：");
      scanf("%f", &rate);

      printf("请输入存款年数：");
      scanf("%d", &years);

      // 计算本息合计和利息
      total = principal * (1 + rate * years);
      interest = total - principal;

      printf("本金：%.2f元\n", principal);
      printf("年利率：%.2f%%\n", rate * 100);
      printf("存款年数：%d年\n", years);
      printf("利息：%.2f元\n", interest);
      printf("本息合计：%.2f元\n", total);

      return 0;
  }
