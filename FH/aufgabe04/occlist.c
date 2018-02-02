#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "occlist.h"
#include "errors.h"

/* Referenzaehler fuer die gespeicherten OccList-Knoten */
int occlist_refs = 0;

OccList
occlist_empty() {
    OccList *root = NULL;
    root = (OccList*) malloc(sizeof(OccList));

    if(root)
    {
        root->prev  = NULL;
        root->next  = NULL;
        root->entry = NULL;
    }

    return *root;
}

int
occlist_isEmpty(OccList l) {


    if(l.entry == NULL)
        return 1;
    else
        return 0;

}

Occurrence
occlist_head(OccList l) {
    OccList temp;
     Occurrence occ;
    assert(!occlist_isEmpty(l));

    temp = l;

    if(temp.prev != NULL)
    {
        while(1)
        {
            if(temp.prev != NULL)
                temp = *temp.prev;

            else
                break;
        }
    }
    occ = *temp.entry;
    return occ;

}

OccList occlist_tail(OccList l) {
    OccList temp;
    OccList new_head;

    assert(!occlist_isEmpty(l));

    temp = l;

    while(1)
    {
        if(temp.prev != NULL)
            temp = *temp.prev;

        else
            break;
    }

    new_head = *temp.next;

    return new_head;

}

OccList
occlist_cons(Occurrence occ, OccList l) {

    OccList temp = l;
    OccList* new_head;

        while(1)
        {
            if(temp.prev != NULL)
                temp = *temp.prev;

            else
                break;
        }

    new_head = malloc(sizeof(OccList));
    if(new_head != NULL)
    {
        new_head->entry = &occ;
        new_head->prev  = NULL;
        new_head->next  = &temp;
        temp.prev = new_head;


    }

    return *new_head;
}

OccList
occlist_insert(OccList l, Occurrence occ) {
    OccList* first = & l;
    OccList* second

    while(1)
    {
        if(first->entry.line == occ.line && first->entry.pos = occ.pos)
            return l;



    }
}

OccList
occlist_delete(OccList l) {

    OccList *ptr = &l;
    OccList *second;


    while(1)
    {
        if(ptr->prev != NULL)
            ptr = ptr->prev;

        else
            break;
    }



    while(second != NULL)
    {
        second = ptr->next;
        free(ptr->entry);
        free(ptr);
        ptr = second;

    }
    free(second->entry);
    free(second);

    return *second;

}



