#include <stdio.h>
main()
{
	int i,j;
	i=1;
	do{
		for(j=1;j<4-i;j++)
		  printf(" ");
		for(j=3-i;j<5;j++)
		  printf("*");
		  printf("\n");
		  i++;
	}while(i<=3);
}
