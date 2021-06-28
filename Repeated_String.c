/* See repeated-string.pdf for info on the problem statement 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STATIC_CHAR 'a'

//Successfully tested
long long repeatedString(char *s, long long n);

int main()
{
    char string[1] = {'a'};
    long long n = 1000000000000;
    printf("Number of a's : %lld\n", repeatedString(string, n));
    return 0;
}

/*
    Constraints: 
        Original string length is from 1 to 100, inclusive.
        String length, n is from 1 to 10^12 inclusive.
*/
/*
    Goal: find the number of a's in the string.
*/
long long repeatedString(char *s, long long n)
{
    long long frequency = 0;
    long long whole = 0;
    long long oneTripCount = 0;
    //Get length of original string, s
    long long size = strlen(s);
    printf("Size of string: %d\n", size);

    //Count how many times STATIC_CHAR appears in the string.
    for (int i = 0; i < size; ++i)
    {
        if (s[i] == STATIC_CHAR)
            ++oneTripCount;
    }
    printf("Number of a's in first trip: %d\n", oneTripCount);

    //Determine how many whole times the string fits in n
    whole = n / size;
    printf("Whole: %lld\n", whole);
    frequency = whole * (long long)oneTripCount;
    //Determine remainder
    int remainder = n % size;
    printf("Remainder: %d\n", remainder);
    //Calculate how many STATIC_CHAR appear in remainder of string
    for (int k = 0; k < remainder; ++k)
        if (s[k] == STATIC_CHAR)
            ++frequency;
    return frequency;
}