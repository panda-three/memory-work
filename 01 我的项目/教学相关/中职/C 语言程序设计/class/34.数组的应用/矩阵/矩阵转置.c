#include <stdio.h>
/*
   矩阵：二维数组 

   矩阵的转置即为行列互换，转置前矩阵的行和转置后矩阵的列相同 
*/
#define ROW 2
#define COL 3
main()
{
    int i,j,k;
    int a[ROW][COL]={1,2,3,4,5,6};
    int b[COL][ROW]; 
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
            b[j][i]=a[i][j];
    }
	
	for(i=0;i<COL;i++){
    	for(j=0;j<ROW;j++)
        	printf("%d ",b[i][j]);
        printf("\n");
	}
    
}
