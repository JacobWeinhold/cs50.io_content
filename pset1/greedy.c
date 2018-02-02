#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    int quarter=0, nickel=0, penny=0, dime=0, counter=0, ch=0;
    
    //get user input
    printf("How much change do you have in dollars? \n");
    float c= get_float();
    
    //ask again if input is zero or less
    while(c<=0)
    {
    printf("How much change do you have in dollars ?\n");
    c= get_float();
    }
    
    //convert user input in cents from dollar
    ch=(int)round(c*100);
    
    /*substract coin value from input number as long as possible
    start with biggest coin and end with smallest
    count the number of times it fits into user input
    */
    
    while(ch>=25)
    {
        ch=ch-25;
        counter++;
        quarter++;
    }
    
    while(ch>=10)
    {
        ch=ch-10;
        counter++;
        dime++;
    }
    
    while(ch>=5)
    {
        ch=ch-5;
        counter++;
        nickel++;
        
    }
    
    while (ch>=1)
    {
        ch=ch-1;
        counter++;
        penny++;
    }
    printf("%i\n",counter);
}