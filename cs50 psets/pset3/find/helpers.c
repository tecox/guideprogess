/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // exit if array doesn't exist
    if (n <= 0)
    {
        return false;
    }

    // initialize bounds and middle
    int lowerbound = 0;
    int upperbound = n - 1;
    int middle = (n - 1) / 2;

    // binary search
    while (true)
    {
        // search failure
        if (lowerbound > upperbound)
        {
            break;
        }
        // search success
        if (value == values[middle])
        {
            return true;
        }
        // refine search bounds
        else if (value < values[middle])
        {
            upperbound = middle - 1;
        }
        else if (value > values[middle])
        {
            lowerbound = middle + 1;
        }
        middle = ((upperbound + lowerbound) / 2) + ((upperbound - lowerbound) % 2);
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // initialize counting array and index counter
    int keys[65536] = {0};
    int valueindex = 0;

    // counting sort (fill counting array)
    for (int i = 0; i < n; i++)
    {
        keys[values[i]]++;
    }
    // counting sort (replace values[] with sorted values)
    for (int i = 0; i < 65536; i++)
    {
        while (keys[i] > 0)
        {
            values[valueindex] = i;
            keys[i]--;
            valueindex++;
        }
    }

    return;
}
