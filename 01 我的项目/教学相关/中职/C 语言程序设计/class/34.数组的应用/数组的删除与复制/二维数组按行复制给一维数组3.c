#include<stdio.h>
#define M 2
#define N 3
void main()
{
   int a[6];
   int b[2][3]={1,2,3,4,5,6};
   int i,j,k=0;
   for(i=0;i<M*N;i++){
   	  a[i]=b[i/N][i%N];
   }
   //二维数组输出 
   for(k=0;k<6;k++){
	  printf("%d ",a[k]);
   }
}

