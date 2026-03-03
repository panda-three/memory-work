#include <stdio.h>
#define K 4
#define N 5
long f1(int n,int k)
{
    long power=n;
    int i;
    for(i=1;i<=k;i++)
        power *= n;
    return power;
}
long f2(int n,int k)
{
    long sum=0;
    int i;
    for(i=1;i<=n;i++)
        sum += f1(i,k);
    return sum;
}
void main()
{
	  printf("%d,%d",K,N); 
//    printf("%d\n",f2(N,K));
}
