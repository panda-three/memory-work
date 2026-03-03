#include <stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	int bai=x/100;
	int shi=x/10%10;
	int ge=x%10;
	if(bai*bai*bai+shi*shi*shi+ge*ge*ge==x){
		printf("是水仙花数"); 
	}else{
		printf("不是水仙花数"); 
	}
	return 0;
}
