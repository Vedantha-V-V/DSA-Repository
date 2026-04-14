#include<stdio.h>
#include<stdlib.h>

void main()
{
    FILE *f1,*f2;
    char fname1[10],fname2[10];
    int c;
    printf("Enter the file name:");
    scanf("%s",fname1);
    printf("Enter the destination file name ");
    scanf("%s",fname2);
    f1=fopen(fname1,"r");
    f2=fopen(fname2,"w");
    while((c=fgetc(f1))!=EOF)
    {
        fputc(c,f2);
    }
    fclose(f1);
    fclose(f2);
}