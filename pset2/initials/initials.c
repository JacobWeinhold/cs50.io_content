#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    // get user input
    string name=get_string();
    if(name!=NULL)
    {
    //check if first char in input string is a letter, print it if it is
     if ((name[0] >= 'a'&&name[0] <= 'z')|| (name[0] >= 'A'&&name[0] <= 'Z'))
        {
            printf("%c", toupper(name[0]));
        }
        
    //start iterating through string input
    //check if current char is a letter and ONLY print letters so names like David J. Malan work too
    
        for(int i=0, n=strlen(name);i<n;i++)
        {
            if(!(isalpha(name[i])) && isalpha(name[i+1]))
            {
                printf("%c",toupper(name[i+1]));
            }
        }
    }
    printf("\n");
}