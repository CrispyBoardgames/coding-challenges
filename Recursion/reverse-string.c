#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ReverseString(char *string, char *reversed)
{
    if (string[0] == '\0') //End of string
    {
        printf("Reached end of string\n");
        strcat(reversed, "\0");
        return;
    }

    char lastChar[2];
    lastChar[1] = '\0';
    strncpy(lastChar, string, 1);

    int size = strlen(string);

    ReverseString(string + 1, reversed);
    strcat(reversed, lastChar);

    return;
}

int main()
{
    char temp[3] = "Hi";
    char reversed[3];

    ReverseString(temp, reversed);
    printf("%s\n", reversed);
    return 0;
}