#include <stdio.h>
/*
   逆时针旋转90度 
   
   解法：
     1.观察坐标如何变化
	 2.带俩个值 
*/
#define ROW 3
#define COL 3
main()
{
    int i,j,k;
    int a[ROW][COL]={1,2,3,4,5,6,7,8,9};
    int b[COL][ROW]; 
    for(i=0;i<ROW;i++){
    	for(j=0;j<COL;j++)
        	printf("%d ",a[i][j]); 
         printf("\n");
	} 
    printf("-----------------------------\n");
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
            b[ROW-1-j][i]=a[i][j];
    }
	
	for(i=0;i<ROW;i++){
    	for(j=0;j<COL;j++)
        	printf("%d ",b[i][j]);
        printf("\n");
	} 
}
