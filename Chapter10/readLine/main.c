// includes
#include <stdio.h>

// prototypes
void readLine(char *text);

int main()
{
    char text[81];
    readLine(text);

    printf("%s\n\n", text);

    return 0;
}

void readLine(char *text)
{
    char character = getchar();

    while (character != '\n')
    {
        *text++ = character;
        character = getchar();
    }
    // add null terminator at the end
    *text = '\0';
}