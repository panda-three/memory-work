#include <stdio.h>

void main()
{
	//插入_从前往后 
	int a[6]={1,2,3,4,6};
//	int size=sizeof(arr)/sizeof(arr[0]); 
    int n=6;
    int x=7;
    int i,j;
    for(i=0;i<n-1;i++){
    	 if(x<=a[i]){
    	 	for(j=n-2;j>=i;j--)
    	 	  a[j+1]=a[j];
    	 	a[i]=x;
    	 	break;
		 }
	}
	if(i==n-1){
		a[i]=x;
	}
    for(i=0;i<n;i++)
       printf("%d ",a[i]);
	
}

