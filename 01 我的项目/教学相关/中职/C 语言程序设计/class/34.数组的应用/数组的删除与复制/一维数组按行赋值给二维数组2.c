#include<stdio.h>
#define M 2
#define N 3
void main()
{
   int a[6]={1,2,3,4,5,6};
   int b[2][3];
   int i,j,k=0;
   for(i=0;i<M;i++){
   	  for(j=0;j<N;j++){
   	  	  b[i][j]=a[i*N+j];
	  }
   }
   //二维数组输出 
   for(i=0;i<M;i++){
   	  for(j=0;j<N;j++){
   	  	  printf("%d ",b[i][j]); 
	  }
	  printf("\n");
   }
   
  
}

