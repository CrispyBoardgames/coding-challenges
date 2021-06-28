/* See jumping-on-the-clouds.pdf for info on the problem statement 
*/

#include <stdio.h>
#include <stdlib.h>

//Successfully tested
int jumpingOnClouds(int c_count, int *c);

int main()
{
    int c[6] = {0, 0, 0, 0, 1, 0};
    printf("Number of jumps: %d\n", jumpingOnClouds(6, c));
    return 0;
}

/*
    Constraints: 
        At least 2 clouds. Max 100 clouds.
        Integer values of array can be 0 or 1.
        First cloud and last cloud is always = 0 (land-able)
        Always able to get to the end.
*/

/*
    Goal is to get to the end with the least amount of jumps. Player can jump 1 or 2 clouds ahead (if cloud != 1)
    Meaning, if 2 cloud jump is possible it is preferred over jumping only 1 cloud.
    Count number of jumps.
*/
int jumpingOnClouds(int c_count, int *c)
{
    int jumps = 0;
    int i = 0;
    while (i < c_count)
    {
        //Check the two clouds ahead as long as they are not outside index range.
        if ((i + 2) < c_count)
        {
            if (c[i + 2] == 0) //Land-able
            {
                i += 2;
                ++jumps;
            }
            else if (c[i + 1] == 0) //Land-able
            {
                i += 1;
                ++jumps;
            }
        }
        else if ((i + 1) < c_count)
        {
            if (c[i + 1] == 0) //Land-able
            {
                i += 1;
                ++jumps;
            }
        }
        else
            ++i; //Exit situation
    }
    return jumps;
}