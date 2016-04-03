/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Binary search recursive call.
 */
bool bin_search(int value, int values[], int start, int end)
{
    // Failure condition.
    if (start > end)
        return false;
    
    // Identify middle index.
    int mid = (start + end) / 2;
    
    // Determine where search value falls in array.
    if (values[mid] == value)
        return true;
    else if (value < values[mid])
        return bin_search(value, values, start, mid-1);
    else
        return bin_search(value, values, mid+1, end);
        
    // Ensure a boolean is returned.
    return false;
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    return bin_search(value, values, 0, n-1);
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Implement insertion sort.
    
    // Set counter for number of sorted elements.
    int sorted = 0;
    
    // List will be sorted after the n-1 smallest elements are sorted.
    while (sorted < n-1)
    {
        // Identify minimum value.
        int min = values[sorted];
        int index = sorted;
        
        for (int i = sorted; i < n; i++)
        {
            if (values[i] < min)
            {
                min = values[i];
                index = i;
            }
        }
    
        // Move minimum to end of sorted list; increase length of sorted list.
        for (int j = index; j > sorted; j--)
        {
            values[j] = values[j-1];
        }
        
        values[sorted] = min;
        sorted++;
    }
}