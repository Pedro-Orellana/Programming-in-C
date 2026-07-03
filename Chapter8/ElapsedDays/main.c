#include <stdbool.h>
#include <stdio.h>

// date structure
struct date
{
    int month;
    int day;
    int year;
};

static const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// function prototypes
bool isLeapYear(struct date d);
bool isLeapYearInt(int year);
int getNumberOfDaysInMonth(int month);
void getElapsedDaysSameMonth(struct date date2, struct date date1);
int getElapsedDaysDifferentMonth(struct date date2, struct date date1);
void getElapsedDaysDifferentYear(struct date date2, struct date date1);

// entry point of program
int main()
{
    struct date date1 = {
        .day = 20,
        .month = 1,
        .year = 2026};

    struct date date2 = {
        .day = 20,
        .month = 1,
        .year = 2027};

    if (date2.year > date1.year)
    {
        getElapsedDaysDifferentYear(date2, date1);
        return 0;
    }

    if (date2.month > date1.month)
    {
        getElapsedDaysDifferentMonth(date2, date1);
        return 0;
    }

    if (date2.day > date1.day)
    {
        getElapsedDaysSameMonth(date2, date1);
        return 0;
    }

    printf("Something went wrong and cannot calculate the distance between these 2 dates\n");
    return 1;
}

void getElapsedDaysSameMonth(struct date date2, struct date date1)
{
    const int difference = (date2.day - date1.day);
    printf("The difference in days between these 2 dates is: %i\n", difference);
}
int getElapsedDaysDifferentMonth(struct date date2, struct date date1)
{
    // check if the year is a leap year
    bool isLeap = isLeapYear(date1);

    // days to the end of the month in date1
    int difference = (daysPerMonth[date1.month] - date1.day);

    const int monthDifference = (date2.month - date1.month);

    if (monthDifference > 1)
    {
        for (int i = (date1.month + 1); i < date2.month; i++)
        {
            int daysInMonth;
            if (isLeap && i == 1)
            {
                daysInMonth = 29;
            }
            else
            {
                daysInMonth = daysPerMonth[i];
            }

            difference += daysInMonth;
        }
    }

    // number of days in date2
    difference += date2.day;

    printf("The difference in days between these 2 dates is: %i\n", difference);
    return difference;
}
void getElapsedDaysDifferentYear(struct date date2, struct date date1)
{
    // calculate distance from date1 to end of year
    struct date endOfYear = {.year = date1.year, .month = 11, .day = 31};
    int difference = getElapsedDaysDifferentMonth(endOfYear, date1);

    // calculate the difference of years
    int differenceOfYears = date2.year - date1.year;
    if (differenceOfYears > 1)
    {
        for (int i = (date1.year + 1); i < date2.year; i++)
        {
            int numberOfDays;
            if (isLeapYearInt(i))
            {
                numberOfDays = 366;
            }
            else
            {
                numberOfDays = 365;
            }

            difference += numberOfDays;
        }
    }

    // calculate distance from beginning of year to date2
    struct date startOfYear = {.year = date2.year, .month = 0, .day = 1};
    difference += getElapsedDaysDifferentMonth(date2, startOfYear);

    printf("The difference in days between these 2 dates is: %d days\n", difference);
}

bool isLeapYear(struct date d)
{
    bool leapYearFlag;
    if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
    {
        leapYearFlag = true;
    }
    else
    {
        leapYearFlag = false;
    }

    return leapYearFlag;
}

bool isLeapYearInt(int year)
{
    bool leapYearFlag;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        leapYearFlag = true;
    }
    else
    {
        leapYearFlag = false;
    }

    return leapYearFlag;
}
