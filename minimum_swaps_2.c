/*You are given an unordered array consisting of 
consecutive integers [1, 2, 3, ..., n] without 
any duplicates. You are allowed to swap any two 
elements. Find the minimum number of swaps 
required to sort the array in ascending order. */

#include <stdio.h>
#include <stdlib.h>

#define SIZEOFARRAY(x) (sizeof(x) / sizeof((x)[0]))

int minimumSwaps(int arr_count, int *arr)
{
    int swaps = 0;

    //Find out where each value actually is
    int* posArr = malloc(arr_count * sizeof(int));

    for(int i = 0; i < arr_count; ++i)
    {
        posArr[arr[i]-1] = i;
        //printf("posArr[%d] = %d\n", arr[i], i);
        
    }

    for(int i = 0; i < arr_count; ++i)
    {
        if(arr[i] != (i+1)) //Does not match position
        {
            ++swaps;
            int temp = arr[i];
            int temp2 = posArr[i];
            arr[i] = i+1;
            arr[posArr[i]] = temp;
            posArr[i] = i;
            posArr[temp-1] = temp2;
            //printf("arr[%d] = %d\n", i, arr[i]);
        }
    }

    //Printing to visually see outcome
    // for(int i = 0; i < arr_count; ++i)
    // {
    //     printf("%d\n", arr[i]);
    // }

    free(posArr);
    return swaps;
}

int main()
{
    int arr[4] = {4,3,1,2};
    int swaps = minimumSwaps(SIZEOFARRAY(arr),arr);
    printf("Number of swaps: %d\n", swaps);
    return 0;
}