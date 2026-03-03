 #include <stdio.h>
  int main() {
      int sum = 0;

      printf("计算1到100的和：\n");
	  int i;
      for ( i = 1; i <= 100; i++) {
          sum = sum + i;
      }

      printf("1 + 2 + 3 + ... + 100 = %d\n", sum);

      // 验证公式：n(n+1)/2
      int formula_result = 100 * 101 / 2;
      printf("验证公式：100×101/2 = %d\n", formula_result);

      return 0;
  }
