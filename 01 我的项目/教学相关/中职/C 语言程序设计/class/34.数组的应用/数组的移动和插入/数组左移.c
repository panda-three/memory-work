#include <stdio.h>
void main()
{
	int a[6]={10,9,11,8,20,13};
	int n=6; 
    int x= a[0];
    int i;
	for (i = 1; i<n; i++)
	    a[i-1] = a[i];
	a[n-1] = x;
	for(i=0;i<6;i++)
	   printf("%d ",a[i]); 
}

