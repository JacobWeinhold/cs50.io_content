#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct node
{
    // the value to store in this node
    int n;

    // the link to the next node in the list
    struct node* next;
}
node;

node* head = NULL;



bool contains(int i, node* entry)
{
    while(entry)
    {
        if(entry->n == i)
            return true;
            
        entry = entry->next;   
    }
    
    return false;
}

bool delete(int val)
{
    
node **pp = &head; /* pointer to a pointer */
node *entry = head;

while (entry)
{
    if (entry->n == val)
    {
        *pp = entry->next;
        free(entry);
        return true;
    }
    pp = &entry->next;
    entry = entry->next;
}
return false;

}







int main()
{
    // create linked list
    for (int i = SIZE; i > 0; i--)
    {
        node* new = malloc(sizeof(node));

        if (new == NULL)
        {
            exit(1);
        }
        new->n = i;
        new->next = head;
        head = new;
    }
    delete(3);
    
for(int j = 0; j < 5; j++)
{
    printf("What value are you looking for? ");
    int i = get_int();

    if (contains(i, head))
    {
        printf("Found it! The list contains ");
    }
    else
    {
        printf("Sorry, the list only contains ");
    }
    for (node*  ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%i ", ptr->n);
    }
    printf("\n");
}
    return 0;
}