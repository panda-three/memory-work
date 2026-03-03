#include <stdio.h>
void main()
{
    int a[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}, b[4][4];
    int i,j;
     for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            printf("%3d",a[i][j]);
        printf("\n");
    }
    printf("-----------------------------\n");

    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            b[j][3-i]=a[i][j];
            
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            printf("%3d",b[i][j]);
        printf("\n");
    }
}
