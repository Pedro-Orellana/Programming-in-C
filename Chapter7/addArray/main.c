#include <stdio.h>

// prototypes
int arraySum(int values[], int length);
// int getArraySize(int values[]);

int main(void)
{

    int values[] = {10, 20, 30, 40, 50};
    int length = sizeof(values) / sizeof(values[0]);

    int result = arraySum(values, length);

    printf("The result of the sum is %i\n", result);

    return 0;
}

int arraySum(int values[], int length)
{
    int acc = 0;
    for (int i = 0; i < length; i++)
    {
        acc += values[i];
    }
    return acc;
}

// THIS WILL NOT WORK
// passing an array as an argument means that I'm passing a pointer, not the array itself
// so using sizeof(values) is the size of the pointer, not the size of the array
//  int getArraySize(int values[])
//  {
//      int length = sizeof(values) / sizeof(values[0]);
//      printf("length of array: %i\n", length);
//      return length;
//  }