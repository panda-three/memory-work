#include <stdio.h>
#include <string.h>
void main()
{
    int i, j, x, min;
    int a[5][5] = {{11, 12, 6, 9, 13}, {21, 28, 4, 6, 29}, {11, 12, 10, 14, 15},
                   {12, 24, 55, 6, 11}, {18, 9, 22, 33, 10}};
    for(i = 0; i < 5; i++)
    {
        ________(1)________;
        for(j = 1; j < 5; j++)
            if (a[i][j] < min) min = a[i][j];
        while (________(2)________)
        {
        	x = a[i][0];
			for (j = 1; j < 5; j++)
			    ________(3)________;
				a[i][j-1] = x;
		}
		
    }
		for (i = 0; i < 5; i++)
		{
		    for (j = 0; j < 5; j++)
		        printf("%4d", a[i][j]);
		    printf("\n");
		}
}
