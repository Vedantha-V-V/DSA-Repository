#include<stdio.h>
#include<stdlib.h>

void main()
{
    FILE *fp;
    char sentence[1000];
    fp=fopen("Input.txt","w");
    fgets(sentence,sizeof(sentence),stdin);
    fprintf(fp,"%s",sentence);
    fclose(fp);

    fp=fopen("Input.txt","r");
    char ch;
    printf("Text in File:");
    while((ch==fgetc(fp))!=EOF)
    {
        putchar(ch);
    }
    fclose(fp);
}