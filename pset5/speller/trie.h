#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
typedef struct node
{
    bool is_word;
    struct node* children[27];
}
node;


int get_index(int c)
{
    if(c == 39)
        return 26;
    if(isupper(c))
        return (int) c - (int) 'a' + 32;
        
    else
        return (int)c - (int)'a';
}

node* get_node()
{
    node *myNode = NULL;
 
    myNode = (node*) malloc(sizeof(node));
 
    if (myNode)
    {
        int i;
 
        myNode->is_word = false;
 
        for (i = 0; i < 27; i++)
            myNode->children[i] = NULL;
    }
 
    return myNode;
}


bool insert(node *root, const char *key)
{
    int flag = 0;
    int index;
    node *entry = root;
    
    for(int i = 0; i < strlen(key); i++)
    {
        if(key[i] == 39)
            index = 26;
        else
            index = get_index(key[i]);
        
        if(entry->children[index] == NULL)
        {
            flag = 1;
            entry->children[index] = get_node();
        }
        entry = entry->children[index];
    }

    entry->is_word = true;
    return flag;
}

bool search(node *root, const char *key)
{
    node *entry = root;
    int index;
    for(int i = 0; i < strlen(key); i++)
    {
        index = get_index(key[i]);
        if(!entry->children[index])
            return false;
            
        entry = entry->children[index];
    }
    
    return entry->is_word;
    
}

void deleteTrie(node *root)
{
    node * entry = root;
    for(int i = 0; i < 27; i++)
    {
        if (entry -> children[i] != NULL)
        {
            deleteTrie(entry -> children[i]);
        }
    }
    free(entry);
    return;
}

 