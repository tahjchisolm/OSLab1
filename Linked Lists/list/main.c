#include <stdio.h>
#include <stdlib.h>

#include "list.h"


int main() {
  
  list_t list;
  list.head->next = NULL;
  list.head = NULL;
  printf("Adding 10, 9, 8 to the front in their respective order.\n");
  list_add_to_front(&list, 10);
  list_add_to_front(&list, 9);
  list_add_to_front(&list, 8);
  list_print(&list);
  
  printf("Adding 11, 12 to the back in their respective order.\n");
  list_add_to_back(&list, 11);
  list_add_to_back(&list, 12);
  list_print(&list);

  list_length(&list);
  printf("Is list element 13 in the list? %s\n",list_is_in(&list, 13) ? "true" : "false");
  printf("Is list element 12 in the list? %s\n",list_is_in(&list, 12) ? "true" : "false");
  printf("List element at index 1 is: %d\n",list_get_elem_at(&list, 1));
  printf("List element 10 is at index: %d\n",list_get_index_of(&list, 10));
  printf("Removing the list element at index 2.\n");
  list_remove_at_index(&list, 2);
  list_print(&list);
  printf("List element at index 1 is: %d\n",list_get_elem_at(&list, 1));
  printf("Removing from the front.\n");
  list_remove_from_front(&list);
  list_print(&list);
  printf("Removing from the back.\n");
  list_remove_from_back(&list);
  list_print(&list);
  printf("Deleting the List.\n");
  list_free(&list);
  list_print(&list);
  list_length(&list);
  return 0;
}