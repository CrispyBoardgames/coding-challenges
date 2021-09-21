#include <stdio.h>

struct Person
{
    struct Person *nextInLine;

} person;

int GetPositionInLine(struct Person personInLine)
{
    if (personInLine.nextInLine == NULL) //Base case. No one in front of you.
        return 1;

    return GetPositionInLine(*personInLine.nextInLine) + 1;
}

int main()
{
    struct Person Jake;
    struct Person Charles;
    struct Person Amy;
    struct Person Holt;
    struct Person Terry;
    struct Person Gina;
    struct Person Rosa;
    struct Person Hitchcock;
    struct Person Scully;

    Jake.nextInLine = &Charles;
    Charles.nextInLine = &Amy;
    Amy.nextInLine = &Holt;
    Holt.nextInLine = &Terry;
    Terry.nextInLine = &Gina;
    Gina.nextInLine = &Rosa;
    Rosa.nextInLine = &Hitchcock;
    Hitchcock.nextInLine = &Scully;
    Scully.nextInLine = NULL;

    printf("Position of Jake: %d\n", GetPositionInLine(Terry));

    return 0;
}