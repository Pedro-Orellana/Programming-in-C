// includes
#include <stdio.h>

// structs
struct date
{
    int day;
    int month;
    int year;
};

const int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// prototypes
void updateDate(struct date *toBeUpdated);
void printDate(struct date *toPrint);

int main()
{

    // create instance of date struct
    struct date today = {.day = 31, .month = 11, .year = 2026};
    printDate(&today);

    // now update the date and print again
    updateDate(&today);
    printDate(&today);
}

void printDate(struct date *toPrint)
{
    printf("Today is %i/%i/%i\n", (toPrint->month + 1), toPrint->day, toPrint->year);
}

void updateDate(struct date *toBeUpdated)
{
    if (toBeUpdated->month == 11 && toBeUpdated->day == 31)
    {
        toBeUpdated->year = ++toBeUpdated->year;
        toBeUpdated->month = 0;
        toBeUpdated->day = 1;
        return;
    }

    if (toBeUpdated->day < daysInMonths[toBeUpdated->month])
    {
        toBeUpdated->day = ++toBeUpdated->day;
    }
    else
    {
        toBeUpdated->month = ++toBeUpdated->month;
        toBeUpdated->day = 1;
    }
}