/* See Left-Rotation.pdf for info on the problem statement 
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *rotLeft(int a_count, int *a, int d, int *result_count);

int main()
{
    int arr[SIZE] = {1, 2, 3, 4, 5};

    int result_count;
    int *rotatedArr = rotLeft(SIZE, arr, 4, &result_count);

    for (int i = 0; i < result_count; ++i)
    {
        printf("%d ", rotatedArr[i]);
    }
    return 0;
}

int *rotLeft(int a_count, int *a, int d, int *result_count)
{
    *result_count = a_count;

    //Allocate new array dynamically
    int *rotated_Arr = malloc(*result_count * (sizeof(int)));
    int rotate_Iter = d;

    for (int i = 0; i < *result_count; ++i)
    {
        rotated_Arr[i] = a[rotate_Iter % (*result_count)];
        ++rotate_Iter;
    }
    return rotated_Arr;
}