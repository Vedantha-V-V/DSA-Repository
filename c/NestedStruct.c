#include <stdio.h>

void main()
{
    struct date_time
    {
        struct date1
        {
            int day;
            int month;
            int year;
        } d; 

        struct time
        {
            int hours;
            int minutes;
            int seconds;
        } t; 
    } dt; 

    printf("Enter the date[DD MM YYYY] and time[Hours:Minutes:Seconds]: ");
    scanf("%d%d%d%d%d%d", &dt.d.day, &dt.d.month, &dt.d.year, &dt.t.hours, &dt.t.minutes, &dt.t.seconds);
    
    printf("Date: %d|%d|%d\n", dt.d.day, dt.d.month, dt.d.year);
    printf("Time: %d:%d:%d\n", dt.t.hours, dt.t.minutes, dt.t.seconds);
}

