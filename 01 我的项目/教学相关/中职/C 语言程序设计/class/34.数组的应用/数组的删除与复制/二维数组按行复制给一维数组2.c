#include<stdio.h>
#define M 2
#define N 3
void main()
{
   int a[6];
   int b[2][3]={1,2,3,4,5,6};
   int i,j,k;
   for(i=0;i<M;i++){
   	  for(j=0;j<N;j++){
   	     a[i*N+j]=b[i][j];
	  }
   }
   //二维数组输出 
   for(k=0;k<6;k++){
	  printf("%d ",a[k]);
   }
}

