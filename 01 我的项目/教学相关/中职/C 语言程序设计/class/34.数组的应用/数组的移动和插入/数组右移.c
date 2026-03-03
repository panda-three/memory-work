#include <stdio.h>
void main()
{
	int a[6]={10,9,11,8,20,13};
    int x= a[n-1];
    int i;
	for (i = n-2; i >= 0; i--)
	    a[i+1] = a[i];
	a[0] = x;
	for(i=0;i<6;i++)
	   printf("%d ",a[i]); 
}

