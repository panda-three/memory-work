#include<stdio.h>
void main(){
    int a[6]={10,9,11,8,20,13};
    int i,j,t;
	for(i=0;i<5;i++){
		for(j=0;j<5-i;j++){
			if(a[j]>a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	} 
	for(i=0;i<6;i++){
		printf("%d ",a[i]);
	}

}
