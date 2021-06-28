/*
    An avid hiker keeps meticulous records of their hikes. During the last hike that took exactly *steps* steps, for every step it was noted if it was an uphill, U, 
    or a downhill, step. Hikes always start and end at sea level, and each step up or down represents a

    unit change in altitude. We define the following terms:

        A mountain is a sequence of consecutive steps above sea level, starting with a step up from sea level and ending with a step down to sea level.
        A valley is a sequence of consecutive steps below sea level, starting with a step down from sea level and ending with a step up to sea level.

    Given the sequence of up and down steps during a hike, find and print the number of valleys walked through

    Function Description
        Complete the countingValleys function in the editor below.

    countingValleys has the following parameter(s):
        int steps: the number of steps on the hike
        string path: a string describing the path

    Returns
        int: the number of valleys traversed
*/

#include <stdio.h>
#include <stdlib.h>

//Succesfully tested.

int UpOrDown(char elevation);
int countingValleys(int steps, char *path);

int main()
{
    char pathTaken[8] = "UDDDUDUU";
    printf("Number of valleys:\t%d\n", countingValleys(8, pathTaken));
    return 0;
}

//Steps Range: 2 to 10^6
//SN: State 0, 1, and 2.
//  0 is default-neutral state.
//  1 valley
int countingValleys(int steps, char *path)
{
    int elevation = 0; //Sea level start
    const int seaLevel = 0;
    int SN = 0;
    int valleys = 0;
    //Recognize a valley when, after zero we go down and then finally back to zero.
    //Simple state machine
    for (int i = 0; i < steps; ++i)
    {
        if ((elevation == seaLevel) && (SN == 0)) //Loop to itself S0 -> S0
            SN = 0;
        else if ((elevation < seaLevel) && (SN == 0)) //Stepped into a hill: S0 -> S1
            SN = 1;
        else if ((elevation == seaLevel) && (SN == 1)) //Back to sea level: S1 -> S2
        {
            //Add to counter.
            SN = 2;
            ++valleys;
            //S2 -> S0
            SN = 0;
        }
        else if ((elevation < seaLevel) && (SN == 1))
            SN = 1;

        elevation += UpOrDown(path[i]); //Do nothing.
        printf("%d -\t State: %d -\t  Elevation: %d Valleys: %d\n\n", i, SN, elevation, valleys);
    }
    //Code won't check last step taken, and I'm too lazy to restructure my code so I just call the same code that is necessary to detect the uphill to sea level.
    if ((elevation == seaLevel) && (SN == 1)) //Back to sea level: S1 -> S2
    {
        //Add to counter.
        SN = 2;
        ++valleys;
        //S2 -> S0
        SN = 0;
    }
    return valleys;
}

int UpOrDown(char elevation)
{
    if (elevation == 'U')
        return 1;
    else
        return -1;
}
