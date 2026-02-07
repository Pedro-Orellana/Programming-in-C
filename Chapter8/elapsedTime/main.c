#include <stdio.h>

// prototypes
struct time elapsed_time(struct time time1, struct time time2);

// structures
struct time
{
    int hour;
    int minute;
    int second;
}

main(void)
{
    struct time wakeUpTime, currentTime;
    printf("At what time did you wake up today?: (enter in format hh:mm:ss) ");
    scanf("%i:%i:%i", &wakeUpTime.hour, &wakeUpTime.minute, &wakeUpTime.second);
    printf("And what time is it now? (enter in formate hh:mm::ss) ");
    scanf("%i:%i:%i", &currentTime.hour, &currentTime.minute, &currentTime.second);

    const struct time difference = elapsed_time(wakeUpTime, currentTime);

    printf("You have been awake for %i hours, with %i minutes and %i seconds!", difference.hour, difference.minute, difference.second);
}

struct time elapsed_time(struct time wakeUpTime, struct time currentTime)
{
    struct time difference;

    if (currentTime.second < wakeUpTime.second)
    {
        currentTime.second += 60;
        currentTime.minute--;
        if (currentTime.minute < 0)
        {
            currentTime.minute += 60;
            currentTime.hour--;
        }
    }

    difference.second = currentTime.second - wakeUpTime.second;

    if (currentTime.minute < wakeUpTime.minute)
    {
        currentTime.minute += 60;
        currentTime.hour--;
    }

    difference.minute = currentTime.minute - wakeUpTime.minute;
    difference.hour = currentTime.hour - wakeUpTime.hour;

    return difference;
}