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

void insert_sorted(int i)
{

     
    if(head==NULL)
    {
        head = malloc(sizeof(node));
        head->next = NULL;
        head->n = i;
        return;
    }
    

     
    if(head->next==NULL)
    {
        if(head->n>=i)
        {
            node* new = malloc(sizeof(node));
            new->n=i;
            new->next=head;
            head=new;
        }
        else{
            node* new = malloc(sizeof(node));
            new->n=i;
            new->next=NULL;
            head->next=new;
            head=new;
        }
        
    }
    
    node* first = head;
    node* second = first->next;
    
    while(second)
    {
        if(first->n >= i)
        {
            node* new = malloc(sizeof(node));
            new->n = i;
            new->next=head;
            head= new;
            return;
        }
        
        if(first->n <= i && second->n >=i)
        {
            node* new = malloc(sizeof(node));
            new->n = i;
            first->next=new;
            new->next=second;
            return;
        }

        first=second;
        second=second->next;
    }
}




int main()
{
    printf("Inserting %i random ints to the list...\n", SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        insert_sorted(rand() % SIZE);

    }
    printf("done!\n");

    // printing out list
    printf("Your list now contains ");
    for (node*  ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%i ", ptr->n);
    }
    printf("\n");

    return 0;
}