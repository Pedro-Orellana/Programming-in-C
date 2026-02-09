#include <stdio.h>

// prototypes

int findString(char string[], char search[]);

int main(void)
{
    int index = findString("I'm liking C somewhat", "hat");
    printf("The index is %i", index);
}

int findString(char string[], char search[])
{

    int i = 0, j = 0, index = -1;
    // while there are letters in the string
    while (string[i] != '\0')
    {

        // if we find the first letter of search in the string
        if (string[i] == search[j])
        {

            // this is where the search word starts in the string
            index = i;
            // loop to ensure the whole word is inside the string
            for (; search[j] != '\0'; j++)
            {
                if (string[i + j] != search[j])
                {
                    index = -1;
                    j = 0;
                    break;
                }
            }
            // already found the word, return and don't keep doing comparisons
            if (index != -1)
            {
                return index;
            }
        }

        i++;
    }

    return index;
}