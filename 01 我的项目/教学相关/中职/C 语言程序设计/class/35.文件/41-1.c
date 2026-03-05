#include <stdio.h>
int main()
{
   int a=10;
   int *p=&a;
   printf("%p\n",p);
   printf("%d\n",*p);
   *p=200;
   printf("%d\n",*p);
   printf("%d\n",a);
   return 0;
}