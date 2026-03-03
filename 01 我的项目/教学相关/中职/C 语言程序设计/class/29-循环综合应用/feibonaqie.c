#include <stdio.h>
//1 1 2 3 5
int main()
{
    int n = 20;          
    int f1 = 1, f2 = 1;   
    int i;
    for (i = 1; i <= n; ++i)
    {
        printf("%d ", f1);     
        int nxt = f1 + f2;
        f1 = f2;
        f2 = nxt;
    }
    return 0;
}
