#include <stdio.h>
  int main() {
      printf("========== 水仙花数查找程序 ==========\n");
      printf("水仙花数：三位数，各位数字的立方和等于该数本身\n\n");

      int count = 0;
	  int i;
      for ( i = 100; i <= 999; i++) {
          // 分离各位数字
          int ones = i % 10;              // 个位数
          int tens = (i / 10) % 10;       // 十位数  
          int hundreds = i / 100;         // 百位数

          // 计算各位数字的立方和
          int cube_sum = ones*ones*ones + tens*tens*tens + hundreds*hundreds*hundreds;

          // 判断是否为水仙花数
          if (cube_sum == i) {
              count++;
              printf("第%d个水仙花数：%d\n", count, i);
              printf("  计算过程：%d3 + %d3 + %d3 = %d + %d + %d = %d\n",
                     hundreds, tens, ones,
                     hundreds*hundreds*hundreds,
                     tens*tens*tens,
                     ones*ones*ones,
                     cube_sum);
              printf("  验证：%d = %d \n\n", i, cube_sum);
          }
      }

      printf("========== 查找完成 ==========\n");
      printf("在100到999之间共找到 %d 个水仙花数\n", count);

      // 拓展：显示水仙花数的特点
      printf("\n知识拓展：\n");
      printf("- 水仙花数又称阿姆斯特朗数\n");
      printf("- 每个n位的阿姆斯特朗数等于各位数字的n次幂之和\n");
      printf("- 三位的阿姆斯特朗数就是水仙花数\n");

      return 0;
  }
