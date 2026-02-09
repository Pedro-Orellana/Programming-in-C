#include <stdio.h>

// prototypes

void uppercase(char lowercase[], char buffer[]);

int main(void)
{
    char buffer[50];
    uppercase("my name is pedro orellana", buffer);
    printf("%s", buffer);
}

void uppercase(char lowercase[], char buffer[])
{
    int i = 0;
    for (; lowercase[i] != '\0'; i++)
    {
        if (lowercase[i] >= 'a' && lowercase[i] <= 'z')
        {
            buffer[i] = lowercase[i] - 'a' + 'A';
        }
        else
        {
            buffer[i] = lowercase[i];
        }
    }

    // add the null terminator at the end
    buffer[++i] = '\0';
}