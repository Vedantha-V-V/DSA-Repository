#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void main(){
    int i=0,j,num,rem,choice,deci=0;
    int b[10]={0};
    printf("Enter your choice 1.) Decimal to Binary 2.) Binary to Decimal: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter the number: ");
            scanf("%d",&num);
            rem=num;
            while(rem>0){
                b[i]=rem%2;
                rem=rem/2;
                i+=1;
            }

            for(j=i-1;j>=0;j--){
                printf("%d",b[j]);
            }
            break;
        case 2:
            char binary[1024];
            int exp = 0;
            printf("Enter the number in binary: ");
            scanf("%s",binary);
            for(int i=strlen(binary)-1;i>=0;i--){
                int val = binary[i] - '0';
                deci = deci+(val*pow(2,exp));
                exp++;
            }
            printf("%d",deci);
            break;
        default:
            printf("Invalid Choice");
    }
}