/* See 2D-Array.pdf for info on the problem statement 
*/

#include <stdio.h>
#include <stdlib.h>

/*
    Max and min values of hourglass: -9 and 9
*/
int hourglassSum(int arr_rows, int arr_columns, int arr[][6]);

int main()
{
    int hourGlassArray[6][6] = {
        {-1, -1, 0, -9, -2, -2},
        {-2, -1, -6, -8, -2, -5},
        {-1, -1, -1, -2, -3, -4},
        {-1, -9, -2, -4, -4, -5},
        {-7, -3, -3, -2, -9, -9},
        {-1, -3, -1, -2, -4, -5}};
    printf("Max hour glass sum: %d\n", hourglassSum(6, 6, hourGlassArray));
    return 0;
}

/*  Given arr of size arr_rows x arr_columns
    Hourglass looks like this:
        x x x
          x
        x x x
    The array looks like (numbers vary) this: (if 6x6)
        1 2 3 4 5 6
        0 1 0 2 3 4
        5 6 7 8 9 0
        1 2 3 4 5 6
        7 8 9 0 1 2
        3 4 5 6 7 8 

        Thus, for each hourglass, we start at the middle (origin), look behind and in front.
        For each array, we don't look at [Y][0] or [Y][arr_columns - 1], as there are no sides for the hourglass.
        We also stop two rows before the end of our array: [arr_rows -3][X] is the last row.
        Hacker Rank's challenge only provides 6x6 arrays. So, static amount of variables to keep track of each hourglass sum.
*/
int hourglassSum(int arr_rows, int arr_columns, int arr[][6])
{
    int Sums[16] = {0};

    int hourglass = 0;
    for (int i = 0; i < arr_rows - 2; ++i)
    {
        for (int k = 1; k < arr_columns - 1; ++k)
        {
            //First row
            Sums[hourglass] += arr[i][k - 1];
            printf("%d ", arr[i][k - 1]);
            Sums[hourglass] += arr[i][k];
            printf("%d ", arr[i][k]);
            Sums[hourglass] += arr[i][k + 1];
            printf("%d \n", arr[i][k + 1]);
            //Second row
            Sums[hourglass] += arr[i + 1][k];
            printf("- %d -\n", arr[i + 1][k]);
            //Third row
            Sums[hourglass] += arr[i + 2][k - 1];
            printf("%d ", arr[i + 2][k - 1]);
            Sums[hourglass] += arr[i + 2][k];
            printf("%d ", arr[i + 2][k]);
            Sums[hourglass] += arr[i + 2][k + 1];
            printf("%d\n", arr[i + 2][k + 1]);
            printf("Sum: %d", Sums[hourglass]);
            ++hourglass;
            printf("\n");
        }
        printf("\n\n");
    }
    //Find maximum of sums
    int maxHourGlassSum = Sums[0]; //Set to first value in array.
    for (int j = 0; j < 16; ++j)
    {
        if (Sums[j] > maxHourGlassSum)
            maxHourGlassSum = Sums[j];
    }
    return maxHourGlassSum;
}