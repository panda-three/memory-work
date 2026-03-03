#include <stdio.h>
void main()
{
    int i,j,x;
    int a[6]={10, 9, 11, 8, 20, 13};
    for(i=1;i<=5;i++)
    {
        int temp=a[i];
        for(j=i-1; j>=0&&(a[j]>temp) ;j--)
        {
                a[j+1]=a[j];
        }1
        a[j+1]=temp;
    }
    printf("≈≈–Ú∫Û£∫");
    for(i=0;i<6;i++)
        printf("%d\t",a[i]);
    printf("\n");
}

