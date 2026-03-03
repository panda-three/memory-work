#include<stdio.h>
void main(){
	int a[6]={10,9,11,8,20,13};
	int i,j,t,k;
	//选择比较法 
	for(i=0;i<5;i++){
		k=i;
		for(j=i+1;j<6;j++){
			if(a[k]>a[j]){
		        k=j;
			}
		} 
		if(k!=i){
			t=a[k];
			a[k]=a[i];
			a[i]=t;
		}
	} 
	//输出
	for(i=0;i<6;i++){
		printf("%d ",a[i])
	} 
	
} 
