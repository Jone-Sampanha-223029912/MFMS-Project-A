#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "input.h"


void clearExtraInput(void)
{
    int character;

    while ((character = getchar()) != '\n' &&
           character != EOF)
    {
        /* Discard unwanted characters */
    }
}


int readInt(const char *prompt, int minimum, int maximum)
{
    char line[100];
    char extraCharacter;
    int value;

    while (1)
    {
        printf("%s", prompt);

        if (fgets(line, sizeof(line), stdin) == NULL)
        {
            printf("Input error. Please try again.\n");
            continue;
        }

        /*
         * Accept the input only when exactly
         * one integer was entered.
         */
        if (sscanf(line, " %d %c",
                   &value,
                   &extraCharacter) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        if (value < minimum || value > maximum)
        {
            printf(
                "Please enter a value between %d and %d.\n",
                minimum,
                maximum
            );

            continue;
        }

        return value;
    }
}


double readNonNegativeDouble(const char *prompt)
{
    char line[100];
    char extraCharacter;
    double value;

    while (1)
    {
        printf("%s", prompt);

        if (fgets(line, sizeof(line), stdin) == NULL)
        {
            printf("Input error. Please try again.\n");
            continue;
        }

        if (sscanf(line, " %lf %c",
                   &value,
                   &extraCharacter) != 1)
        {
            printf(
                "Invalid input. Please enter a valid number.\n"
            );

            continue;
        }

        if (value < 0)
        {
            printf(
                "Value cannot be negative. Please try again.\n"
            );

            continue;
        }

        return value;
    }
}


void readText(
    const char *prompt,
    char *buffer,
    int size
)
{
    int i;
    int containsText;

    while (1)
    {
        printf("%s", prompt);

        if (fgets(buffer, size, stdin) == NULL)
        {
            printf("Input error. Please try again.\n");
            continue;
        }

        /*
         * If fgets did not capture the newline,
         * the user entered more characters than
         * the array could hold.
         */
        if (strchr(buffer, '\n') == NULL)
        {
            clearExtraInput();
        }
        else
        {
            buffer[strcspn(buffer, "\n")] = '\0';
        }

        containsText = 0;

        for (i = 0; buffer[i] != '\0'; i++)
        {
            if (!isspace((unsigned char)buffer[i]))
            {
                containsText = 1;
                break;
            }
        }

        if (!containsText)
        {
            printf("Input cannot be empty.\n");
            continue;
        }

        return;
    }
}