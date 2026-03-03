#include <stdio.h>
void fun(int arr[]){
	arr[0]=7;
}

void main()
{
    int arr[3]={2,3,4};
    fun(arr);
	printf("%d",arr[0]);
}
