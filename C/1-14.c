#include <stdio.h>

#define ASCIISTART 33

int main ()
{
    int array [95][2];
    int c=0;

    for(int i=ASCIISTART; i<127;i++)
    {
    array[i-ASCIISTART][0]=i;
    array[i-ASCIISTART][1]=0;
    }

    while((c = getchar()) != EOF)
    {
        for(int i=ASCIISTART; i<127; i++)
        {
            if(i==c)
            {
                ++array[i-ASCIISTART][1];
            }
        
        }
    }
    
    for(int i=0; i<94; i++)
    {
        printf("|%c|\t", array[i][0]);
        for(int n=0; n<array[i][1]; n++)
        {
            printf("*");
        }
        printf("\n");
    }
}