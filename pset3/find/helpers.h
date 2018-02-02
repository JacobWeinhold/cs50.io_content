/**
 * helpers.h
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n);

bool binarysearch(int value, int values[], int n);

bool binarysearchrecursive(int needle, int haystack[], int min, int size);

/**
 * Sorts array of n values.
 */
void sort(int array[], int size);

void selectionsort(int haystack [], int size);
    
void bubblesort(int array[], int size);



void countsort(int array[], int size);