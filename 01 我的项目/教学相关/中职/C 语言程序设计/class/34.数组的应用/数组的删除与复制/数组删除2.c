#include<stdio.h>
void main()
{
   int a[10]={1,2,3,4,5,6};
   //将不需要删除的元素，重新存放
   int i,j=0;
   for(i=0;i<10;i++){
   	  if(a[i]!=5){
   	  	  //重新放 
   	  	  a[j++]=a[i];
	  }
   }
   for(i=0;i<10;i++)
	   printf("%d ",a[i]); 
    
}

