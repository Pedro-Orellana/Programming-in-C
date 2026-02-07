#include <stdio.h>

int main(void)
{
    int integerVar = 100;
    float floatingVar = 331.76;
    double doubleVar = 8.44e+11;
    char charVar = 'F';

    _Bool boolVar = 25;

    printf("integerVar = %i\n", integerVar);
    printf("floatingVar = %f\n", floatingVar);
    printf("doubleVar = %f\n", doubleVar);
    printf("charVar = %c\n", charVar);

    return 0;
}