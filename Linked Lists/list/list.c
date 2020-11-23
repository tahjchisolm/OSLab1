// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_alloc() { return NULL; }
void list_free(list_t *l) { 
   struct node* curr = l->head; 
  struct node* next;
  
   while (curr != NULL)  
   { 
       next = curr->next; 
       free(curr); 
       curr = next; 
   } 
    
   l->head = NULL; 
   return;
} 

void list_print(list_t *l) {
  struct node* curr = l->head;
  if (curr == NULL) {
    printf("List is empty.\n");
    return;
  }
  while( curr->next != NULL ){
    printf("%d\n", curr->value);
    curr = curr->next;
  }
  printf("%d\n", curr->value);
}

int list_length(list_t *l) { 
  struct node* curr = l->head;
  int len = 1;
  if (curr == NULL) {
    printf("List is empty.\n");
    return;
  }
  while( curr->next != NULL ){
    len += 1;
    curr = curr->next;
  }
  printf("Length of the list is: %d\n", len);
}

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
  struct node* new = (struct node*)malloc(sizeof(struct node));
  
  new->value = value;
  new->next = l->head;
  l->head = new;
}
void list_add_at_index(list_t *l, elem value, int index) {
  printf("Adding at index: %d\n", index);
  int key = 0;
  struct node* curr = l->head;
  struct node* prev = l->head;
  struct node* new = (struct node*)malloc(sizeof(struct node));
  new->value = value;
  if (curr != NULL && key == index) 
    { 
        l->head->next = l->head;   
        l->head = new;
        return; 
    } 
  while (curr != NULL && key != index) 
    { 
        prev = curr; 
        curr = curr->next; 
        key += 1;
    } 
  
  if (curr == NULL) return;
  
  prev->next = curr->next;
  free(curr);

  return;
}

elem list_remove_from_back(list_t *l) { 
  struct node* curr = l->head;
  struct node* prev = l->head;
  
  if (curr == NULL) return; 
  
  while (curr != NULL && curr->next != NULL) 
    { 
        prev = curr; 
        curr = curr->next; 
    } 
  
  if (curr == NULL) return;
  
  prev->next = NULL;
  free(curr->next);

  return;
}
elem list_remove_from_front(list_t *l) { 
  struct node* curr = l->head;
  if (curr != NULL) 
    { 
        l->head = l->head->next; 
        free(curr);               
        return; 
    } 

  return;
}

elem list_remove_at_index(list_t *l, int index) { 
  int key = 0;
  struct node* curr = l->head;
  struct node* prev = l->head;
  
  if (curr != NULL && key == index) 
    { 
        l->head = curr->next;   
        free(curr);
        return; 
    } 
  while (curr != NULL && key != index) 
    { 
        prev = curr; 
        curr = curr->next; 
        key += 1;
    } 
  
  if (curr == NULL) return;
  
  prev->next = curr->next;
  free(curr);

  return;
}

bool list_is_in(list_t *l, elem val) { 
  struct node* curr = l->head;
  if (curr != NULL && curr->value == val) 
    { 
        return true; 
    } 
  while (curr != NULL && curr->value != val) 
    { 
        curr = curr->next; 
    } 
  
  if (curr == NULL) return false;


  return true;
}

elem list_get_elem_at(list_t *l, int index) { 
  int key = 0;
  struct node* curr = l->head;
  
  if (curr != NULL && key == index) 
    { 
        return curr->value; 
    } 
  while (curr != NULL && key != index) 
    { 
        curr = curr->next; 
        key += 1;
    } 
  
  if (curr == NULL) return -1;


  return curr->value;
}
int list_get_index_of(list_t *l, elem val) { 
  int key = 0;
  struct node* curr = l->head;
  
  if (curr != NULL && curr->value == val) 
    { 
        return key; 
    } 
  while (curr != NULL && curr->value != val) 
    { 
        curr = curr->next; 
        key += 1;
    } 
  
  if (curr == NULL) return -1;


  return key;
}