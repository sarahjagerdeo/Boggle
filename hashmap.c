#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <math.h>
#include <string.h>

#include "llist.h"
#include "hashmap.h"

//local function for hashing an input value (do not edit)
unsigned int _hash(hashmap_t * hm, char * val){
  //based on Java's String.hashcode()
  double k = 0;
  double len = (double) strlen(val);
  int i=1;
  for(char * c = val; *c ; c++,i++){
    k += (*c) * pow(31,len-i);
  }

  return (unsigned int) (((unsigned long) k) % hm->num_buckets);
}


//local function: resize the hashmap by doubling the number of buckets and rehashing
void _resize(hashmap_t * hm){
  //TODO: resize the hashmap if the load gets too high
  llist_t ** buckets1 = hm->buckets; //size of old buckets
  int resize = 2*hm->num_buckets; //size of new buckets
  hm->buckets = calloc(sizeof(llist_t * ),resize);
  hm->num_buckets = resize;
  hm->size=0;
  for(int i =0; i<resize; i++){
    hm->buckets[i] = ll_init(); 
    //free(hm);
  }
  //hm->size=0;
  for(int i =0; i < hm->num_buckets/2; i++){
    ll_node_t * cur;
    cur = buckets1[i]->head; 
   
    while(cur != NULL){
      // int index_new = _hash(hm,cur->val);//call this for index
      // ll_push(buckets1[index_new],cur->val);
      // cur = cur->next;
      hm_add(hm,cur->val);
      cur = cur->next;
      // free(cur); //doesnt do anything
    }
  }
    for(int i =0; i<hm->num_buckets/2; i++){
    ll_delete(buckets1[i]);
    }
   free(buckets1);
   //free(hm);
//add each node to hashmap
//go through 
//multiple by 2
//insert that into each bucket
//asign new pointer
//delete old hashmap
//double number of buckets
//new double pointer buckets
}

//initliaze a hashmap with initial number of buckets
hashmap_t * hm_init(){

  //create the hashmap
   hashmap_t * hm = calloc(sizeof(hashmap_t),1);
   hm->num_buckets = HM_INIT_NUM_BUCKETS ; //create memory for hashmap
   hm->buckets = calloc(sizeof(llist_t ),hm->num_buckets); //create memory for list 
   hm->size = 0;
   for(int i=0; i<hm->num_buckets; i++){
     hm->buckets[i] = ll_init(); //initalize list 
   }
  
 return hm;
  
}


//delete/deallocate the hashmap
void hm_delete(hashmap_t * hm){
   
    for(int i =0; i < hm->num_buckets; i++){
      ll_delete(hm->buckets[i]);
    }
  free(hm->buckets);
  free(hm);
}

//add a string value to the hashmap
void hm_add(hashmap_t * hm, char * val){
  // You get this function for free :)
  
  //check the load on the hashtable, if > max load, resize!
  if(((hm->size+1)/(double) hm->num_buckets) > HM_MAX_LOAD){
    _resize(hm); 
  }

  unsigned int h = _hash(hm,val); //get hash
 // printf("h is %d", h);
 // if(!hm->buckets[h]){printf("hm buckets thing is null");}
  ll_push(hm->buckets[h],val); //note that list does string dup
  hm->size++; //increase size


}

//see if a string value is in the hashmap
bool hm_check(hashmap_t * hm, char * val){

  //TODO check if a value is in the hashmap
 // hm = calloc(sizeof(hashmap_t),1);
  unsigned int x =  _hash(hm,val);
  ll_node_t * cur;
  cur = hm->buckets[x]->head;
  while(cur){
     if(strcmp(cur->val, val)==0){
      return true;
     }
     cur = cur->next;
  }
  return false; //otherwise false
}


