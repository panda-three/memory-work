#include <stdio.h>
#include <stdlib.h>
//猜数字 --基础功能
// 1.5次机会  
// 2.加分数  猜中得分=(6-次数)*10 
// 3.可以玩多轮，算总分 (y/n)
// 4.美化 变成成品 
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
/*
 * 函数名：printScoreLevel
 * 功能：根据总分打印评价等级
 * 参数：
 *   totalScore - 总分
 */
void printScoreLevel(int totalScore) {
    printf("\n╔═══════════════════════════╗\n");
    printf("║      游戏结束！总分：%-3d  ║\n", totalScore);
    printf("╠═══════════════════════════╣\n");

    if (totalScore >= 150) {
        printf("║       幸运之神！！！     ║\n");
    } else if (totalScore >= 100) {
        printf("║       超级幸运儿！       ║\n");
    } else if (totalScore >= 50) {
        printf("║       运气不错哦！       ║\n");
    } else if (totalScore >= 20) {
        printf("║        还需努力...        ║\n");
    } else {
        printf("║       运气欠佳...        ║\n");
    }

    printf("╚═══════════════════════════╝\n");
}
int main()
{
	char c='y';
	int totalScore; 
	int roundNumber = 1;     // 当前轮次
	printf("╔═══════════════════════════════════╗\n");
    printf("║    欢迎来到幸运数字轮盘游戏！     ║\n");
    printf("╠═══════════════════════════════════╣\n");
    printf("║  规则说明：                       ║\n");
    printf("║  1. 系统生成1-50的幸运数字        ║\n");
    printf("║  2. 你有5次猜测机会               ║\n");
    printf("║  3. 猜中得分 = (6-次数)×10       ║\n");
    printf("║  4. 可以玩多轮，累计总分          ║\n");
    printf("╚═══════════════════════════════════╝\n");
    while(c=='y') 
    {
    	printf("\n━━━━━━━━━ 第 %d 轮 ━━━━━━━━━\n", roundNumber);
    	int score=playOneRound();
    	totalScore=totalScore+score;
	    printf("当前的分数为:%d",totalScore);
	    printf("\n要再玩一轮吗？(y/n): ");
        scanf(" %c", &c);  // 注意空格，吸收之前的回车符
        roundNumber++; 
	}
	 // 游戏结束，显示总分和评价
    printScoreLevel(totalScore);

    printf("\n感谢游玩！再见！\n");
	return 0;
}
