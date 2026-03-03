#include <stdio.h>
int t(int x,int y)
{
    return (y-x)*x;
}
void main()
{
    int a=3,b=4,c=5,d;
    d=t(t(a,b),t(a,c));
    printf("%d\n",d);
}
