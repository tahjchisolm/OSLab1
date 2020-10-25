// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list_t *list_alloc() { return NULL; }
void list_free(list_t *l) {}

void list_print(list_t *l) {
  printf("'list_print' function\n");
  struct node* curr = l->head;
  while( curr->next != NULL ){
    printf("%d\n", curr->value);
    curr = curr->next;
  }
  printf("%d\n", curr->value);
  //l->head = new;
  
   //printf("Done with 'list_print' function\n");
  
}
int list_length(list_t *l) { return -1; }

void list_add_to_back(list_t *l, elem value) {
  
  struct node* curr = l->head;
  struct node* new = (struct node*)malloc(sizeof(struct node));
  new->value = value;
  new->next = NULL;
  if(l->head==NULL){
    l->head = new;
    return;
  }
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = new;
  return;
  
}
void list_add_to_front(list_t *l, elem value) {
  //printf("values are %d and %d\n", l->head->value, value);
  struct node* new = (struct node*)malloc(sizeof(struct node));
  
  new->value = value;
  new->next = l->head;
  //printf("values are %d and %d\n", l->head->value, value);
  l->head = new;
  //printf("values are %d and %d\n", l->head->value, value);
}
void list_add_at_index(list_t *l, elem value, int index) {}

elem list_remove_from_back(list_t *l) { return -1; }
elem list_remove_from_front(list_t *l) { return -1; }
elem list_remove_at_index(list_t *l, int index) { return -1; }

bool list_is_in(list_t *l, elem value) { return false; }
elem list_get_elem_at(list_t *l, int index) { return -1; }
int list_get_index_of(list_t *l, elem value) { return -1; }