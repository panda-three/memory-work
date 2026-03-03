#include <stdio.h>
void main()
{
   //打开文件 
   FILE *fp=fopen("11.txt","r");
   //读取文件 
   char c=fgetc(fp);
   //关闭文件 
   printf("%c\n",c);
   
}
