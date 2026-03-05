#include <stdio.h>
int main()
{
   //���ļ� 
   FILE *fp=fopen("11.txt","r");
   //��ȡ�ļ� 
   char c=fgetc(fp);
   printf("%c\n",c);
   //�ر��ļ� 
   fclose(fp);

   return 0;
}
