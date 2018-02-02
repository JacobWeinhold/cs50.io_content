#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct node
{
    // the value to store in this node
    int n;

    // the link to the next node in the list
    struct node* next;
}
node;

node* head = NULL;

void append(int i)
{
    if(head == NULL)
    {
        head = malloc(sizeof(node));
        head->n=i;
        head->next=NULL;
    }
    
    else
    {
        node* ptr;
        node* new = malloc(sizeof(node));
        for(ptr = head; ptr->next!=NULL; ptr = ptr->next);
        
        ptr->next=new;
        new->n=i;
        new->next=NULL;
    }
    
}

int main()
{
    // creating list
    printf("Appending ints 0-%i onto the list...\n", SIZE - 1);
    for (int i = 0; i < SIZE; i++)
    {
        append(i);
    }
    printf("done!\n");

    // printing out list
    printf("Your list contains ");
    for (node*  ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%i ", ptr->n);
    }
    printf("\n");

    return 0;
}