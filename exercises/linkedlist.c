#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;

} Node_t;

int main(void) {

  Node_t *head = NULL;

  head = (Node_t *)malloc(sizeof(Node_t));
  head->data = 1;
  head->next = NULL;

  Node_t *second = (Node_t *)malloc(sizeof(Node_t));
  second->data = 2;
  second->next = NULL;
  head->next = second;

  Node_t *third = (Node_t *)malloc(sizeof(Node_t));
  third->data = 3;
  third->next = NULL;
  second->next = third;

  // Printing Full list
  Node_t *current = head;
  while (current != NULL) {
    printf("current Data %d\n", current->data);
    current = current->next;
  }

  current = head;

  while (current != NULL) {
    Node_t *temp = current;
    current = current->next;
    free(temp);
  }
  return 0;
}
