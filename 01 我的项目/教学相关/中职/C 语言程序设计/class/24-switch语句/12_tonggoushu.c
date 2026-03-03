#include <stdio.h>
int main() {
	int m;
	scanf("%d",&m);
	int n=m*m;
	if(n%10==m||n%100==m){
		printf("是同构数");
	}else{
		printf("不是同构数"); 
	}
	
    return 0;	  
}
