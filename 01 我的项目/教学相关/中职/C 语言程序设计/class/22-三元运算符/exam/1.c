#include <stdio.h>
  int main()
  {
      int a = 2, b = 3, c = 4, d = 5;
      int result = (a++ > ++b) ? (c *= d++) : (d += ++c);
      printf("a=%d, b=%d, c=%d, d=%d, result=%d\n", a, b, c, d, result);
      return 0;
  }
