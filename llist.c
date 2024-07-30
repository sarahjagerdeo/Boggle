#include <stdlib.h>
#include <string.h>

#include "llist.h"

//initialize a linked list
llist_t * ll_init(){
 llist_t * newlist = malloc(sizeof(llist_t));

    newlist->head = NULL;
    newlist->size = 0;

    return newlist;
}

//delete a linked list
void ll_delete(llist_t * ll){
   ll_node_t * cur = ll->head;
   ll_node_t * next_node = NULL;
    while(cur != NULL){
        next_node = cur->next;
        free(cur->val);
        free(cur);
        cur = next_node;
    
    }
  free(ll);
}


//push an item onto the front of the list
void ll_push(llist_t * ll, char * s){
     ll_node_t * cur =  calloc(sizeof(ll_node_t),1);

     //ll_node_t * temp = ll->head; //memory error

     cur->val = strdup(s);
     cur->next = ll->head;
     ll->head = cur;
     ll-> size++;

     
     //shouldn't need to handle the null case
     //use strdup with s
     //increase the size
     
}

    
 




