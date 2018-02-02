#include <stdio.h>

void swap(int* a, int* b)
{
    int aVal = *a;
    *a=*b;
    *b=aVal;
    
    
}

int main(void)
{
    int x = 1;
    int y = 2;
    printf("x is %i\n", x);
    printf("y is %i\n", y);
    printf("Swapping...\n");
    swap(&x, &y);
    printf("Swapped!\n");
    printf("x is %i\n", x);
    printf("y is %i\n", y);
}