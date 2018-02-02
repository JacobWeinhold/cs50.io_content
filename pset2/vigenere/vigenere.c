#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv [])
{
    //check for correct usage
    if (argc!=2)
    {
    printf("Usage: ./vigenere k\n");
    return 1;
    }
    
    //initialize key array         
    string keytext=argv[1];
    int key [strlen(keytext)];

    //build alphabet array
    char alphabet[26];
    char letter='A';
    for(int i=0;i<26;i++)
    {
        alphabet[i]=letter;
        letter++;
    }
    

    //check if user input is correct and only consists of letters
    for(int i=0, n=strlen(keytext);i<n;i++)
    {
        if(!(isalpha(keytext[i])))
        {
            printf("Insert a key string of alphabets when starting the program!\n");
            return 1;
        }
    }
    
    //fill key array with user input keytext
    int count=0;
    for(int i=0, n=strlen(keytext);i<n;i++)
    {
        key[i]=toupper(keytext[i])-65;
        count++;
    }
    
    int zahl=0;                                          
    //ask user for plain text
    printf("plaintext: ");
    string text=get_string();
      
    //cipher plain text
    printf("ciphertext: ");
       
    //iterate through plain text
    //check if current char in plain text is a letter, if not print it like it is
    //if char is a letter, move letter in alphabet for the position in the alphabet of the current letter of the ciphertext 
    for(int j=0,l=strlen(text);j<l;j++)
    {
        if(isalpha(text[j]))
        {
            for(int i=0;i<25;i++)
             {
                if(alphabet[i]==text[j])
                {
                    printf("%c",
                    ((((text[j]-65)+key[zahl])%26)+65));
                     zahl++;
                     if(zahl==count)
                     {
                         zahl=0;
                     }
                }
            
           
                if(text[j]==tolower(alphabet[i]))
                {
                    printf("%c",
                    ((((text[j]-97)+key[zahl])%26)+97) );
                         zahl++;
                     
                        //iterate key array by counting up when a letter is moved and resetting when end is reached
                        if(zahl==count)
                        {
                            zahl=0;
                        } 
                }
            }
        }
        else
        {
            printf("%c",text[j]);
        }       
    }   
    printf("\n");
    return 0;
}
