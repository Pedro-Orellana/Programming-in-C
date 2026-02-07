#include <stdio.h>

// prototypes
double f2c(int);

int main(void)
{
    int f;
    printf("Please enter the number of fahrenheit degrees you want to transform to celsius: ");
    scanf("%i", &f);
    double result = f2c(f);
    printf("The result is %.2fC\n", result);
    return 0;
}

double f2c(int f)
{
    return (f - 32) / 1.8;
}