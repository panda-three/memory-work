#include <stdio.h>

int main(){
	int a,b,c;
	printf("请输入长方形的长:");
	scanf("%d",&a);
	printf("请输入长方形的宽:");
	scanf("%d",&b); 
	printf("周长为:%d,",2*(a+b));
	printf("面积为:%d",a*b);
	return 0;
} 
