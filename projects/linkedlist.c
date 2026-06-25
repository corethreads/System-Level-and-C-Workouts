/**********************************************************
 * Name: linked.c                                         *
 * Purpose: ***.                                          *
 * Author: CoreThreads                                    *
 **********************************************************/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  unsigned int data;
  struct node *next;
} Node;

Node *CreateNode(int value) {

  Node *createnode = (Node *)malloc(sizeof(Node));
  createnode->data = value;
  createnode->next = NULL;

  return createnode;
}

void BInsert(Node **head, unsigned int value) {
  Node *newNode = CreateNode(value);
  newNode->next = *head;
  *head = newNode;
}

void Einsert(Node **head, unsigned int value) {
  Node *newNode = CreateNode(value);
  if (*head == NULL) {
    *head = newNode;
    return;
  }

  Node *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = newNode;
}

void DeleteNode(Node **head, unsigned int nodeDelete) {

  if (*head == NULL) {
    return;
  }

  if ((*head)->data == nodeDelete) {
    Node *RepresentHead = *head;
    *head = (*head)->next;
    free(RepresentHead);
    return;
  }

  Node *StartingNode = *head;
  Node *followingNode = (*head)->next;

  while (followingNode != NULL && followingNode->data != nodeDelete) {
    StartingNode = followingNode;
    followingNode = followingNode->next;
  }

  if (followingNode != NULL) {
    printf("Node is [%d], \n", followingNode->data);
    StartingNode->next = followingNode->next;
    printf("Freeing Node {%d}... \n", followingNode->data);
    free(followingNode);
    printf("Done...\n");
  }
}

void PrintList(Node *head) {
  Node *current = head;
  if (current == NULL) {
    printf("List is empty");
  }
  while (current != NULL) {
    printf("Data = [%p][%d] points to --> [%p]\n", &current->data,
           current->data, current->next);
    current = current->next;
  }
}

void FreeList(Node *head) {
  Node *current = head;
  while (current != NULL) {
    Node *temp = current;
    current = current->next;
    printf("Freed data[ %d ] --> Address [%p]\n", temp->data, temp);
    free(temp);
  }
}

int main(void) {
  Node *head = NULL;

  BInsert(&head, 5);
  Einsert(&head, 20);
  Einsert(&head, 30);
  Einsert(&head, 40);
  DeleteNode(&head, 20);
  PrintList(head);
  FreeList(head);
  return EXIT_SUCCESS;
}
