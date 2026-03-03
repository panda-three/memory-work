#include <stdio.h>
void main()
{
    FILE *fp;
    int i=20,j=30,k,n;
    fp=fopen("d1.dat","w");
    fprintf(fp,"%d\n",i);
    fprintf(fp,"%d\n",j);
    fclose(fp);

    fp=fopen("d1.dat","r");
    fscanf(fp,"%d%d",&k,&n);
    printf("%d%d\n",k,n);
    fclose(fp);
}

