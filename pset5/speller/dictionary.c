
/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"
#include "trie.h"
#include <ctype.h>


node *root = NULL;
unsigned int dic_size = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    return search(root, word);
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    root = get_node();
    
    FILE *dic=fopen(dictionary, "r");
    
    if(dic == NULL)
        return false;
    
    char c;
    char buffer[45];
    int length = 0;
    
    while((c = fgetc(dic)) != EOF)
    {
        if( c != '\n')
        { 
            buffer[length++] = c;
        }
        else
        {
            //char currentLine[length+1];
            //for(int i = 0; i < length; i++)
            //{
            //    currentLine[i]=buffer[i];
            //}
            buffer[length]='\0';
            if(insert(root, buffer))
                dic_size++;
            length = 0;
        }

    }

    if (ferror(dic))
    {
        fclose(dic);
        return false;
    }
    else
    {
        fclose(dic);
        return true;
    }


}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dic_size;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    deleteTrie(root);
    return true;
}
