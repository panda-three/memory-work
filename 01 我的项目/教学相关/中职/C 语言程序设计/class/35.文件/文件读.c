#include <stdio.h>
void main()
{
   //打开文件 
   FILE *fp=fopen("11.txt","r");
   //读取文件 
   char c=fgetc(fp);
   printf("%c\n",c);
   //关闭文件 
   fclose(file);

   
}
