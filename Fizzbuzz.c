/* Write a program that prints the numbers from 1 to 100. But for multiples of three print "Fizz", instead of the number 3, 
    and for multiples of five print "Buzz". For numbers which are multiples of both three and five, print "FizzBuzz"
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
//Simple straight-forward implementation of Fizzbuzz
void FizzBuzz1()
{
    for (int i = 1; i <= 100; ++i)
    {
        if (i % 3 == 0 && i % 5 == 0)
            printf("FizzBuzz\n");
        else if (i % 3 == 0)
            printf("Fizz\n");
        else if (i % 5 == 0)
            printf("Buzz\n");
        else
            printf("%d\n", i);
    }
}

//Slightly better implementation by removing redundancy
#define FIZZ "Fizz"
#define BUZZ "buzz"
void FizzBuzz2()
{
    char *value = malloc(sizeof(char) * 3);
    bool modThree = false;
    bool modFive = false;
    for (int i = 1; i <= 100; ++i)
    {
        modThree = i % 3 == 0;
        modFive = i % 5 == 0;
        value = itoa(i, value, 10);

        printf("%s\n", (modThree && modFive) ? "FizzBuzz" : ((modThree) ? "Fizz" : (modFive) ? "Buzz"
                                                                                             : value));
    }
}
//Taken from Keith S Thompson github
void FizzBuzz3()
{
    for (int i = 1; i <= 100; i++)
    {
        char s[4];
        sprintf(s, "%d", i);
        int three = 3 * 5 * !(i % 3);
        int five = 3 * 5 * !(i % 5);
        printf("%.*s", three, "Fizz");
        printf("%.*s", five, "Buzz");
        printf("%.*s", 3 * 5 * !(three + five), s);
        putchar('\n');
    }
}
int main()
{
    FizzBuzz3();
    return 0;
}