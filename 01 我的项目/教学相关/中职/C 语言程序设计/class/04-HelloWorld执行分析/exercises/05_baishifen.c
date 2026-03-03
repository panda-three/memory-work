#include <stdio.h>

int main(){
	printf("请输入一个三位数:");
	int a;
	scanf("%d",&a);
	printf("百位为:%d,",a/100);
	printf("十位为:%d,",a/10%10);
	printf("个位为:%d",a%10);
	return 0;
} 
