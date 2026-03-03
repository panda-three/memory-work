#include <stdio.h>
int main()
{
  //素数/质数：只能找到1和它本身能被他整除 
  // 7 6    2~6
  int n=6; //1.找数的范围：2~n-1   
  //  2.判断能否被该数整除 
  //  3.如何判断 
  int i;
  int flag=1//标志位,假设这个数它就是素数 
  for(i=2;i<n;i++){
  	  if(n%i==0){
  	  	 flag=0; 
  	  	 break;
	  }
  }
  if(flag==1){
  	printf("是素数"); 
  } else{
  	 printf("不是素数");
  }

   return 0;	
}
