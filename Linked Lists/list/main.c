#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*
struct node {
	elem value;
	struct node *next;
};
typedef struct node node_t;

struct list {
	node_t *head;
};
typedef struct list list_t;
*/

int main() {
  //printf("test\n");
  list_t list;
  //printf("Test\n");
  
  list.head->next = NULL;
  list.head = NULL;
  //printf("Test\n");
  //list_print(list);
  list_add_to_front(&list, 10);
  list_add_to_front(&list, 9);
  list_add_to_front(&list, 8);
  list_print(&list);
  
  list_add_to_back(&list, 11);
  list_print(&list);
    
    
  printf("Test for linked list implementation\n");
  return 0;
}