#include <stdio.h>
#include <stdlib.h>
//猜数字 --基础功能
// 1.5次机会  
int playOneRound(){
	int maxAttempt=5;
	srand(time(NULL));
	int num=rand()%50+1;
	int attempt=1;
	while(attempt<=maxAttempt){
		int x;
		printf("第%d次猜测,请输入你猜的数字:",attempt);
		scanf("%d",&x);
		if(x==num){
			printf("恭喜你猜对了,幸运数字就是%d\n",num);
			break;
		}else if(x<num){
			printf("猜小了,还有%d次机会\n",maxAttempt-attempt);
		} else{
			printf("猜大了,还有%d次机会\n",maxAttempt-attempt); 
		} 
		attempt++;
	}
	return 0;
}
int main()
{
    playOneRound();
	return 0;
}
