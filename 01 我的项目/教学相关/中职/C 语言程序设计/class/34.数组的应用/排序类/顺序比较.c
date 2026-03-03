#include<stdio.h>
void main(){
	int a[6]={10,9,11,8,20,13};
	int i,j,t;
	//顺序比较法 
	for(i=0;i<5;i++){
		for(j=i+1;j<6;j++){
			if(a[i]>a[j]){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		} 
	} 
	//输出
	for(i=0;i<6;i++){
		printf("%d ",a[i])
	} 
	
} 
