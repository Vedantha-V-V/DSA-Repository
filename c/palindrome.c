#include<stdio.h>
#include<string.h>

void main()
{
    int i,j=0,count=0;
    char word[20];
    printf("Enter the word:");
    scanf("%s",word);
    count=strlen(word);
    char rev_word[count+1];
    rev_word[count]='\0';
    for(i=count;i>0;i--)
    {
        rev_word[j]=word[i-1];
        j++;
    }

    if(strcmp(rev_word,word)==0)
        printf("The word is a Palindrome.");
    else
        printf("The word is not a Palindrome.");
}




