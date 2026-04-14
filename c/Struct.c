#include <stdio.h>

void main()
{
    struct date_time
    {
        struct date
        {
            int day;
            int month;
            int year;
        }d;

        struct time
        {
            int hours;
            int minutes;
            int seconds;
        } t;   
    } dt;
    printf("Read the date [DD/MM/YYYY]:\n");
    scanf("%d%d%d",&dt.d.day,&dt.d.month,&dt.d.year);
    printf("Read the date [Hours/Minutes/Seconds]:\n");
    scanf("%d%d%d",&dt.t.hours,&dt.t.minutes,&dt.t.seconds);
    printf("Date: %d|%d|%d\n",dt.d.day,dt.d.month,dt.d.year);
    printf("Time: %d:%d:%d\n",dt.t.hours,dt.t.minutes,dt.t.seconds);
}