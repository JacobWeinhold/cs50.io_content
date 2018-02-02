#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

char c,tmp,cry;
char alph[26];
char Letter='A';
int count=0;
int zahl=0;

int main(int argc, string argv[])
{
    //fill alph array with every letter in the alphabet
    
    for(int i=0;i<26;i++)
    {
        alph[i]=Letter;
        Letter++;
    }
    
    //cancel program execution if not exactly one parameter is given
    if (argc!=2)
    {
        printf("Insert a key parameter when starting the program!\n");
        return 1;
    }
    
    //convert string argv[1] to int
     int key=atoi(argv[1]);

    //get plain text
     printf("plaintext: ");
       
    string text=get_string();

    printf("ciphertext: ");
    //iterate through every char in plain text
    for(int i=0,n=strlen(text);i<n;i++)
    {
        //check if current char is a letter
        if(isalpha(text[i]))
        {
            //build ciphered char by adding the key to the position in char array of the corresponding char from plain text
            //prevent overflow in the array with modulo
             
            if(isupper(text[i]))
            {
                tmp=text[i];
                for(int j=0;j<25;j++)
                {
                    if(alph[j]==tmp)
                    {
                     count=(j+key)%26;
                     printf("%c",alph[count]);
                     
                    }
                }   
            }
            
            //same as for upper with toupper and to lower conversion in order to only need one alphabet array            
            if(islower(text[i]))
            {
                tmp=text[i];
                for(int h=0;h<25;h++)
                {
                    if(alph[h]==toupper(tmp))
                    {
                        count=(h+key)%26;
                        printf("%c",tolower(alph[count]));
                    }
                }
            }
        }
        //print chars in text other than letters without change
        else
        {
        printf("%c",text[i]);
        }
    }
    printf("\n");
}