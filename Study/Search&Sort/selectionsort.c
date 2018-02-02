#include <stdio.h>

#define SIZE 8

void sort(int array[], int size)
{
    int min=0;
    int count=0;
    
    for(int i=0;i<size;i++)
    {
    if(array[i]>array[i+1];
    count=i;
    break;
    }
    
    
    
    

    
    
    // for i = 1 to size - 1

        // start by setting min = i

        // compare min to all other elements in unsorted subarray

             // if you find an even smaller element, that is now min

        // swap to put min in correct position in sorted subarray
}

int main(void)
{
    int numbers[SIZE] = { 4, 15, 16, 50, 8, 23, 42, 108 };
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    sort(numbers, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}