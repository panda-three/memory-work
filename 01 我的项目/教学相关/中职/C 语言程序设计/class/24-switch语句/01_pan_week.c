#include <stdio.h>
int main() {
    int x=2;
	switch(x)
	{
	case 1:printf("%d",x++);
	case 2:printf("%d",x++);
	case 3:printf("%d",x++);
	default:printf("%d",x++);
	}
    return 0;
	  
}
