#include <stdio.h>

#define SIZE 8

void sort(int array[], int size)
{
	int counter;
	do{
		counter=0;	
		
		for(int i=0; i<size-1; i++)
		{
		if(array[i]>array[i+1])
			{
			int tmp=array[i+1];
			
			array[i+1]=array[i];
			
			array[i]=tmp;
			counter++;
			}
		}
		
	}
	while(counter>0);
	
	
    // do while swaps > 0

        // reset swaps to 0

        // iterate through entire array

            // if array[i] > array[i+1]

                // swap them

                // increment swaps
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