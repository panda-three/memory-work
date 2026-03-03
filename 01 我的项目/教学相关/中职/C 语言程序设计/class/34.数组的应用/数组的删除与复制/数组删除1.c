#include<stdio.h>
//删除 
void main()
{
   int a[10]={1,2,3,4,5,6};
   //查找5所在位置 
    int i,j;
    int index=-1;//没找到 
	for(i=0;i<6;i++){
		if(a[i]==5){
			index=i;
			break; 
		}
	} 
   
   //向左移动 
   for(j=index+1;j<10;j++){
   	  a[j-1]=a[j];
   } 
   
   for(i=0;i<10;i++)
	   printf("%d ",a[i]); 
}

