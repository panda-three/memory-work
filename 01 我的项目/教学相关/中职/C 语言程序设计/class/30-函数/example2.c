#include <stdio.h>
//º¯ÊıµÄÉùÃ÷ 
float getMul(float a,float b){
    a=a-1;
    b=b+1;
    return a;
} 
int main() {
	float a=1.5;
	float b=2.5;
	float x=getMul(a,b);
	printf("%f,%f,%f",a,b,x);
    return 0;
}



