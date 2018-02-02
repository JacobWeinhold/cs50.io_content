#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isNotlastIndex(char Array[], int index);

int indexesToGo (char array[], int index);


bool isNotlastIndex(char array[], int index)
{
    int count = 0;
    char test='a';
    
    while(test!='\0')
    {
        if(count==2)
            return 0;
            
        test=array[index++];
        
        count++;    
        
    }
    return false;
}

int indexesToGo (char array[], int index)
{
    int count = 0;
    char test='a';
    
    while(test!='\0')
    {
        test=array[++index];
        count++;
    }
    
    return --count;
    
    
}


int main(void)
{
char *foo = "foo";
char *bar = "bar";
char str[80];

strcat(str, foo);
strcat(str, bar);
}