#include <stdio.h>

  int main() {
      int count = 0;
      int i,j,k;
      for ( i = 2; i <= 50; i++) {
          int isPrime = 1;

          for ( j = 2; j * j <= i; j++) {
              if (i % j == 0) {
                  isPrime = 0;
                  break;
              }
          }

          if (isPrime) {
              printf("%3d ", i);
              count++;
              if (count % 5 == 0) {
                  printf("\n");
              }
          }
      }
      printf("\n");
      return 0;
  }
