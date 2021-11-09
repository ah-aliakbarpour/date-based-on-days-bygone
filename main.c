#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year)
{
    if ((year % 100 == 0 && year % 400 != 0) || year == 0)
        return 0;
    
    return year % 4 == 0 ? 1 : 0;
}

int main()
{
    printf("Enter number of days: ");
    int n;
    scanf("%d", &n);

    int year = 0, month = 1, day = 1;
    
    // Determine year
    while (n > 365)
    {
        // Break if it is the exactly last day of leap year
        if (n == 366 && isLeapYear(year))
            break;

        n -= 365;
        if (isLeapYear(year))
            n -= 1;

        year++;
    }
    
    // Defining months of Gregorian calender
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year))
        months[1] = 29;

    // Determine month
    while (n > months[month - 1])
    {
        n -= months[month - 1];
        month++;
    }

    // Determine day
    day = n;
    
    printf("Date (yyyy/mm/dd): %04d/%02d/%02d", year, month, day);

    return 1;
}