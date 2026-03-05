#include <stdio.h>
#include <string.h>
int main()
{
//    char *file="\\aa\\a.txt";
//    printf("%s\n",file);
   char  str[] = "\ab\0663\x45\n0\0";
//    int len=strlen(str);
//    int i;
//    for(i=0;i<len;i++){
//       printf("%c",str[i]);
//    }
   printf("%s",str);
   return 0;
}