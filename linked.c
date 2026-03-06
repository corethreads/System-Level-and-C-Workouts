#include <stdio.h>
#include <stdlib.h>

// Define our node structure
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Function to create a new node
Node *create_node(int value) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = value;
  new_node->next = NULL;
  return new_node;
}

// The function you're asking about
void insert_at_beginning(Node **head, int value) {
  printf("\n--- INSIDE FUNCTION ---\n");
  printf("Step 1: Function received head = %p (address of main's head)\n",
         head);

  // Create new node
  Node *new_node = create_node(value);
  printf("Step 2: Created new node at address %p with data=%d\n", new_node,
         value);

  // Line 1: new_node->next = *head
  printf("Step 3: *head = %p (what main's head points to)\n", *head);
  new_node->next = *head;
  printf("        new_node->next now = %p\n", new_node->next);

  // Line 2: *head = new_node
  printf("Step 4: Setting *head = %p (new node's address)\n", new_node);
  *head = new_node;
  printf("        Now *head = %p\n", *head);
  printf("--- EXITING FUNCTION ---\n");
}

// Function to print the list
void print_list(Node *head) {
  printf("List: ");
  Node *current = head;
  while (current != NULL) {
    printf("[%d|next:%p] → ", current->data, current->next);
    current = current->next;
  }
  printf("NULL\n");
}

int main() {
  printf("=== START OF PROGRAM ===\n");

  // Step 1: Create an empty list
  Node *head = NULL;
  printf("Step 1: Created head at address %p\n", &head);
  printf("        head contains: %p (NULL)\n", head);

  // Step 2: Insert first node (10)
  printf("\n>>> Calling insert_at_beginning(&head, 10)\n");
  insert_at_beginning(&head, 10);

  printf("\nAfter first insertion:\n");
  printf("        main's head at %p now contains: %p\n", &head, head);
  print_list(head);

  // Step 3: Insert second node (5) at beginning
  printf("\n>>> Calling insert_at_beginning(&head, 5)\n");
  insert_at_beginning(&head, 5);

  printf("\nAfter second insertion:\n");
  printf("        main's head at %p now contains: %p\n", &head, head);
  print_list(head);

  // Step 4: Insert third node (1) at beginning
  printf("\n>>> Calling insert_at_beginning(&head, 1)\n");
  insert_at_beginning(&head, 1);

  printf("\nAfter third insertion:\n");
  printf("        main's head at %p now contains: %p\n", &head, head);
  print_list(head);

  // Clean up
  printf("\n=== CLEANING UP ===\n");
  Node *current = head;
  while (current != NULL) {
    Node *temp = current;
    current = current->next;
    printf("Freeing node at %p with data %d\n", temp, temp->data);
    free(temp);
  }

  return 0;
}
