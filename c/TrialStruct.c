#include<stdio.h>

int i;
struct ELEMENT{
    int real;
    int imag; 
}s1[2];

struct SUM{
    int real_sum;
    int imag_sum;
}res;

void add(struct ELEMENT s1[],struct SUM *res);

void main()
{
    struct ELEMENT s1[2];
    struct SUM res={0,0};
    for(i=0;i<2;i++)
    {
        scanf("%d",&s1[i].real);
        scanf("%d",&s1[i].imag);
    }
    add(s1,&res);
}

void add(struct ELEMENT s1[],struct SUM *res)
{
    int i;
    for(i=0;i<2;i++)
    {
        res.real_sum+=s1[i].real;
        res.imag_sum+=s1[i].imag;
    }

    printf("Sum:\n%d+(%d)i",res.real_sum,res.imag_sum);
}