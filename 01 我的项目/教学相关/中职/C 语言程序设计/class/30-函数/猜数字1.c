#include <stdio.h>
#include <stdlib.h>
//猜数字 --基础功能
// --加功能   
int main()
{
    srand(time(NULL));
	int num=rand()%50+1;
	while(1){
		int x;
		printf("请输入你猜的数字:");
		scanf("%d",&x);
		if(x==num){
			printf("恭喜你猜对了\n");
			break;
		}else if(x<num){
			printf("猜小了\n");
		} else{
			printf("猜大了\n"); 
		} 
	}
	return 0;
}
