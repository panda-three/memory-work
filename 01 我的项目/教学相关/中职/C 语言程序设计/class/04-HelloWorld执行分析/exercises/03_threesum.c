#include <stdio.h>

int main(){
	int a,b,c;
	printf("请输入第一个整数:");
	scanf("%d",&a);
	printf("请输入第二个整数:");
	scanf("%d",&b); 
	printf("请输入第三个整数:");
	scanf("%d",&c); 
	printf("三个数的整数和为:%d\n",a+b+c);
	printf("三个数的平均值为:%d",(a+b+c)/3);
	return 0;
} 
