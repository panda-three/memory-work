 #include <stdio.h>

  int main() {
      // 定义变量
      int original_number;
      int thousand, hundred, ten, unit;
      int reversed_number, sum_digits, product_digits;
      int odd_position, even_position;  // 改名更清晰
      int magic_result1, magic_result2, magic_result3;

      // 输入四位数
      printf("=== 数字魔法师 ===\n");
      printf("请输入一个四位数（1000-9999）：");
      scanf("%d", &original_number);

      // 分离各位数字
      thousand = original_number / 1000;         // 千位
      hundred = (original_number / 100) % 10;    // 百位
      ten = (original_number / 10) % 10;         // 十位
      unit = original_number % 10;               // 个位

      printf("\n=== 数字分解 ===\n");
      printf("原数字：%d\n", original_number);
      printf("千位：%d，百位：%d，十位：%d，个位：%d\n",
             thousand, hundred, ten, unit);

      // 数字重组
      reversed_number = unit * 1000 + ten * 100 + hundred * 10 + thousand;     
      sum_digits = thousand + hundred + ten + unit;
      product_digits = thousand * hundred * ten * unit;

      printf("\n=== 数字重组 ===\n");
      printf("反转数字：%d\n", reversed_number);
      printf("各位数字和：%d\n", sum_digits);
      printf("各位数字乘积：%d\n", product_digits);

      // 按位置分组（从右往左数）
      odd_position = hundred * 10 + unit;    // 第3位和第1位（奇数位置）       
      even_position = thousand * 10 + ten;   // 第4位和第2位（偶数位置）       

      printf("奇数位置组合（百位十位）：%d\n", odd_position);
      printf("偶数位置组合（千位个位）：%d\n", even_position);

      // 魔法计算
      magic_result1 = original_number + reversed_number;
      magic_result2 = sum_digits * sum_digits;
      magic_result3 = odd_position - even_position;

      printf("\n=== 魔法运算 ===\n");
      printf("魔法公式1（原数+反转数）：%d + %d = %d\n",
             original_number, reversed_number, magic_result1);
      printf("魔法公式2（数字和的平方）：%d × %d = %d\n",
             sum_digits, sum_digits, magic_result2);
      printf("魔法公式3（位置差）：%d - %d = %d\n",
             odd_position, even_position, magic_result3);

      // 正确的自增自减演示
      printf("\n=== 自增自减魔法 ===\n");
      int temp_thousand = thousand;
      int temp_unit = unit;

      printf("千位数字原值：%d\n", temp_thousand);
      printf("执行++temp_thousand后：%d\n", ++temp_thousand);

      printf("个位数字原值：%d\n", temp_unit);
      printf("执行--temp_unit后：%d\n", --temp_unit);

      // 最终魔法结果
      int final_magic = (magic_result1 + magic_result2 + magic_result3) %      
  1000;
      printf("\n=== 最终魔法数字 ===\n");
      printf("所有魔法运算的综合结果之和 mod 1000 = %d\n", final_magic);

      return 0;
  }

