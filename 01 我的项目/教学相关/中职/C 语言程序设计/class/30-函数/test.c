#include <stdio.h>
void main()
{
    int i, a[5] = {0};
	for(i=1; i<=4; i++)
	{
		a[i] = a[i-1] * 2 + 1;
		printf("%4d", a[i]);
	}
}
