#include <stdio.h>
void main()
{
	//数组的插入(从后往前) 
	int a[6]={1,2,3,4,6};
	int x=5;
	int n=6;
	int i;
	for (i = n-2; i >= 0; i--)
        if (x < a[i]) a[i + 1] = a[i];
        else break;
    a[i + 1] = x;
    
    for(i=0;i<6;i++)
       printf("%d ",a[i]);
	
}

