#include <stdio.h>
#include <stdlib.h>

//No city has more than one space station
//At least one city has a space station
//n is number of cities
//c_count is size of space station array
//c is array containing the indexes of cities with space stations
//Find the maximum distance from any city to its nearest space station
int flatlandSpaceStations(int n, int c_count, int *c)
{
    int max = 0;
    int *distances = malloc(n * (sizeof(int)));
    for (int i = 0; i < n; ++i)
    {
        int min = 2147483647; //Max int size
        //printf("i : %d\n", i);
        //Determine distances to nearest space station from current city
        //Go through each element in c and compare distance
        for (int k = 0; k < c_count; ++k)
        {
            //Check if new distance is the smallest
            if (min > abs(i - c[k]))
            {
                distances[i] = abs(i - c[k]);
                min = distances[i];
                //printf("\t%d > %d - %d\n", min, i, c[k]);
            }
        }
    }
    //Determine max
    for (int x = 0; x < n; ++x)
    {
        if (max < distances[x])
            max = distances[x];
    }
    return max;
}

int main()
{
    int n = 95;
    int stationsCount = 19;
    int c[19] = {
        68,
        81,
        46,
        54,
        30,
        11,
        19,
        23,
        22,
        12,
        38,
        91,
        48,
        75,
        26,
        86,
        29,
        83,
        62,
    };
    printf("%d\n", flatlandSpaceStations(n, stationsCount, c));
    //This is a test case that hackerrank fails. It is a runtime error.  Probably due to allocating more memory than is allowed.
    return 0;
}