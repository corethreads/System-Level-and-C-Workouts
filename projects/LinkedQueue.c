#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Node structure
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Queue structure
typedef struct {
  Node *head;
  Node *tail;
  int size;
} LinkedListQueue;

// Create new queue
LinkedListQueue *createLinkedListQueue() {
  LinkedListQueue *q = (LinkedListQueue *)malloc(sizeof(LinkedListQueue));
  q->head = NULL;
  q->tail = NULL;
  q->size = 0;
  return q;
}

// Add to queue (enqueue)
void enqueueLinkedList(LinkedListQueue *q, int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = value;
  newNode->next = NULL;

  if (q->size == 0) {
    q->head = newNode;
    q->tail = newNode;
  } else {
    q->tail->next = newNode;
    q->tail = newNode;
  }
  q->size++;
}

// Remove from queue (dequeue)
int dequeueLinkedList(LinkedListQueue *q) {
  if (q->size == 0) {
    printf("Error: Queue is empty!\n");
    return -1;
  }

  Node *temp = q->head;
  int value = temp->data;
  q->head = q->head->next;

  if (q->head == NULL) {
    q->tail = NULL;
  }

  free(temp);
  q->size--;
  return value;
}

// Check if empty
int isEmptyLinkedList(LinkedListQueue *q) { return q->size == 0; }

// Print queue (for debugging)
void printLinkedListQueue(LinkedListQueue *q) {
  Node *current = q->head;
  printf("Queue (size=%d): ", q->size);
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Free entire queue
void freeLinkedListQueue(LinkedListQueue *q) {
  while (!isEmptyLinkedList(q)) {
    dequeueLinkedList(q);
  }
  free(q);
}

// Test function
void testLinkedListQueue() {
  printf("\n========== LINKED LIST QUEUE DEMO ==========\n");
  LinkedListQueue *q = createLinkedListQueue();

  printf("Adding 5 items...\n");
  enqueueLinkedList(q, 10);
  enqueueLinkedList(q, 20);
  enqueueLinkedList(q, 30);
  enqueueLinkedList(q, 40);
  enqueueLinkedList(q, 50);
  printLinkedListQueue(q);

  printf("Removing 2 items...\n");
  printf("Removed: %d\n", dequeueLinkedList(q));
  printf("Removed: %d\n", dequeueLinkedList(q));
  printLinkedListQueue(q);

  printf("Adding 3 more items...\n");
  enqueueLinkedList(q, 60);
  enqueueLinkedList(q, 70);
  enqueueLinkedList(q, 80);
  printLinkedListQueue(q);

  printf("Removing all items...\n");
  while (!isEmptyLinkedList(q)) {
    printf("Removed: %d\n", dequeueLinkedList(q));
  }

  freeLinkedListQueue(q);
}

int main(void) {
  testLinkedListQueue();
  return 0;
}
