#include <stdio.h>
#include <stdlib.h>

void main()
{
    char sentence[1000];
    FILE *fp;

    fp = fopen("keep.txt", "w");
    if (fp == NULL) 
    {
        printf("Error opening file");
    }

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    fprintf(fp, "%s", sentence);
    fclose(fp);

    fp = fopen("keep.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file");
    }

    printf("\nContents of file 'keep':\n");
    char ch;
    while ((ch = fgetc(fp)) != EOF) 
    {
        putchar(ch);
    }
    fclose(fp);
}
