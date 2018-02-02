#include <stdio.h>
#include <cs50.h>

// Implement strchr(), a standard function that returns a substring of a C
//string that starts with a given character. If the character is not in the string, it should return NULL.


char* my_strchr(char* str, char c)
{   
    int i=0;
    char s;
    char* ptr=NULL;
    
    while(str[i]!='\0')
    {
    s=str[i++];
    if(s==c)
    {
        ptr=str+i;
    return  ptr;
    }
    
        
    }
    
    return NULL;
    
    // iterate through string

        // if c is found
            // return substring

    // if c wasn't found return NULL
}

int main(void)
{
    printf("String: ");
    char* str = get_string();
    printf("Character: ");
    char c = get_char();
    printf("Looking for substring...\n");
    char* result = my_strchr(str, c);
    if (result == NULL)
    {
        printf("Couldn't find %c.\n", c);
    }
    else
    {
        printf("Substring: %s \n", result);
    }
}