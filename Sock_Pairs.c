/* There is a large pile of socks that must be paired by color. 
Given an array of integers representing the color of each sock, 
determine how many pairs of socks with matching colors there are.
    
    Function Description
        Complete the sockMerchant function in the editor below.

    sockMerchant has the following parameter(s)
        int n: the number of socks in the pile
                n is within 1 to 100, inclusive
        int ar[n]: the colors of each sock
            ar[i] =  Color of a particular sock can be within 1 to 100, so 100 different colored socks.
    Returns
        int: the number of pairs

*/

//Succesfully tested
#include <stdio.h>
#include <stdlib.h>

#define MAXPILE 100

int sockMerchant(int n, int *arr);
void SetArrZeroes(int n, int *arr);

int main()
{
    //0: 2 pair, 50: 1 pair, 11: 1 pair, 26: 1 pair, 88: 1 pair, 91: 1 pair -> 7 pairs
    int pile1[100] = {50, 49, 38, 49, 78, 36, 25, 96, 10, 67, 78, 58, 98, 8, 53, 1, 4, 7,
                      29, 6, 59, 93, 74, 3, 67, 47, 12, 85, 84, 40, 81, 85, 89, 70, 33, 66,
                      6, 9, 13, 67, 75, 42, 24, 73, 49, 28, 25, 5, 86, 53, 10, 44, 45, 35,
                      47, 11, 81, 10, 47, 16, 49, 79, 52, 89, 100, 36, 6, 57, 96, 18, 23,
                      71, 11, 99, 95, 12, 78, 19, 16, 64, 23, 77, 7, 19, 11, 5, 81, 43, 14,
                      27, 11, 63, 57, 62, 3, 56, 50, 9, 13, 45};

    printf("Number of pairs in pile: %d\n", sockMerchant(9, pile1));
    return 0;
}

//Works on a "Count to Two" system.  Keeps track of each possible type of color
int sockMerchant(int n, int *arr)
{
    int colors[MAXPILE];
    int pairs = 0;

    SetArrZeroes(MAXPILE, colors);
    for (int i = 0; i < n; ++i)
    {
        //Go through array
        ++colors[arr[i] - 1];
        if (colors[arr[i] - 1] >= 2)
        {
            ++pairs;
            colors[arr[i] - 1] = 0; //Resetting "Count to Two"
        }
    }
    return pairs;
}

//Sets all elements of an integer array to 0.
void SetArrZeroes(int n, int *arr)
{
    for (int i = 0; i < n; ++i)
        arr[i] = 0;

    return;
}
