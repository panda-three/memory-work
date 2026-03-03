#include <stdio.h>
int main()
{
  int num=20;
  int i=1; 
  while(i<=5){
  	 printf("请输入你要猜的数字:");
  	 int x;
  	 scanf("%d",&x);
  	 if(x>num)
  	    printf("猜大了，还有%d次机会\n",5-i);
	 if(x<num)
	    printf("猜小了\n"); 
	 if(x==num){
	 	printf("猜对了\n"); 
	 	break; 
	 } 
  }
  return 0; 
}
