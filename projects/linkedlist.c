#include <stdio.h>
#include <stdlib.h>

/****************************
 *Create the Node Structure *
 ****************************/

typedef struct Node {
  int data;
  struct Node *next;
} Node_t;

// Create Node
Node_t *CreateNode(int value) {
  Node_t *createnode = (Node_t *)malloc(sizeof(Node_t));

  if (createnode == NULL) {
    printf("Memory Allocation Failed..\n");
    exit(1);
  }

  createnode->data = value;
  createnode->next = NULL;

  return createnode;
}

void BInsert(Node_t **head, int value) {
  Node_t *new_node = CreateNode(value);

  // points to the address of head which the address contains NULL;
  new_node->next = *head;

  // Now we replace head with the new_node
  *head = new_node;
}

void EInsert(Node_t **head, int value) {
  Node_t *new_node = CreateNode(value);

  if (*head == NULL) {
    *head = new_node;
  }

  Node_t *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
}
void PrintList(Node_t *head) {
  printf("Linked List...\n");

  Node_t *current = head;
  while (current != NULL) {
    printf("Data = [%d] points to --> [%p]\n", current->data, current->next);
    current = current->next;
  }
}

void FreeList(Node_t *head) {
  printf("Free List\n");

  Node_t *current = head;
  while (current != NULL) {
    Node_t *temp = current;
    current = current->next;
    printf("Freed Address = %p, Data --> [%d]\n", temp, temp->data);
    free(temp);
  }
}

int main(void) {
  // A head pointer that is NULL
  Node_t *head = NULL;
  BInsert(&head, 10);
  EInsert(&head, 20);
  EInsert(&head, 30);
  PrintList(head);
  FreeList(head);

  return 0;
}
