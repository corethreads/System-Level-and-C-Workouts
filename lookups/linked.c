#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

// Create a new node
Node *create_node(int value) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL) {
    printf("Memory allocation failed!\n");
    exit(1); // Or handle gracefully
  }
  new_node->data = value;
  new_node->next = NULL;
  return new_node;
}

// Insert at beginning
void insert_at_beginning(Node **head, int value) {
  Node *new_node = create_node(value);
  new_node->next = *head; // New node points to old head
  *head = new_node;       // Head now points to new node
                          // Visual: new -> old_head -> ...
}

// Insert at end
void insert_at_end(Node **head, int value) {
  Node *new_node = create_node(value);

  if (*head == NULL) {
    // Empty list
    *head = new_node;
    return;
  }

  // Find the last node
  Node *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }

  // current is now the last node
  current->next = new_node;
}

// Insert in middle (after a specific node)
void insert_after(Node *prev_node, int value) {
  if (prev_node == NULL) {
    printf("Previous node cannot be NULL\n");
    return;
  }

  Node *new_node = create_node(value);
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

// Delete a node with given value
void delete_node(Node **head, int value) {
  if (*head == NULL)
    return;

  Node *current = *head;
  Node *prev = NULL;

  // If head node itself has the value
  if (current != NULL && current->data == value) {
    *head = current->next;
    free(current);
    return;
  }

  // Search for the node
  while (current != NULL && current->data != value) {
    prev = current;
    current = current->next;
  }

  // If value not found
  if (current == NULL)
    return;

  // Unlink the node
  prev->next = current->next;
  free(current);
}

// Print the list
void print_list(Node *head) {
  Node *current = head;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

// Free entire list
void free_list(Node **head) {
  Node *current = *head;
  while (current != NULL) {
    Node *temp = current;
    current = current->next;
    printf("Freeing node with data: %d\n", temp->data);
    free(temp);
  }
  *head = NULL;
}

// Get list length
int length(Node *head) {
  int count = 0;
  Node *current = head;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

// Search for a value
Node *search(Node *head, int value) {
  Node *current = head;
  while (current != NULL) {
    if (current->data == value) {
      return current; // Found it!
    }
    current = current->next;
  }
  return NULL; // Not found
}

int main() {
  Node *head = NULL; // Empty list

  printf("--- Building list ---\n");
  insert_at_end(&head, 10);
  insert_at_end(&head, 20);
  insert_at_end(&head, 30);
  print_list(head); // 10 -> 20 -> 30 -> NULL
  printf("Length: %d\n\n", length(head));

  printf("--- Insert at beginning ---\n");
  insert_at_beginning(&head, 5);
  print_list(head); // 5 -> 10 -> 20 -> 30 -> NULL

  printf("--- Insert after 20 ---\n");
  Node *twenty = search(head, 20);
  if (twenty != NULL) {
    insert_after(twenty, 25);
  }
  print_list(head); // 5 -> 10 -> 20 -> 25 -> 30 -> NULL

  printf("--- Delete 20 ---\n");
  delete_node(&head, 20);
  print_list(head); // 5 -> 10 -> 25 -> 30 -> NULL

  printf("--- Clean up ---\n");
  free_list(&head);

  if (head == NULL) {
    printf("List is now empty\n");
  }

  return 0;
}
