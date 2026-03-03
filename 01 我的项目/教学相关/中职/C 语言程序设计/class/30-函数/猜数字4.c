#include <stdio.h>
#include <stdlib.h>
//猜数字 --基础功能
// 1.5次机会  
// 2.加分数  猜中得分=(6-次数)*10 
// 3.可以玩多轮，算总分 (y/n)
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
			printf("你在第%d次猜中\n",attempt); 
			return (6-attempt)*10;
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
	char c;
	int totalscore; 
    do{
    	int score=playOneRound();
    	totalscore=totalscore+score;
	    printf("当前的分数为:%d",totalscore);
	    printf("\n要再玩一轮吗？(y/n): ");
        scanf(" %c", &c);  // 注意空格，吸收之前的回车符
	}while(c=='y') ;
	return 0;
}
