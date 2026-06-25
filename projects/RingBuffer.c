#include <stdio.h>
#include <stdlib.h>


// Ring buffer structure
typedef struct {
  int *data;
  int size;
  int head;
  int tail;
  int count;
} RingBuffer;

// Create ring buffer (must know size!)
RingBuffer *createRingBuffer(int size) {
  RingBuffer *rb = (RingBuffer *)malloc(sizeof(RingBuffer));
  rb->data = (int *)malloc(size * sizeof(int));
  rb->size = size;
  rb->head = 0;
  rb->tail = 0;
  rb->count = 0;
  return rb;
}

// Add to ring buffer
int enqueueRingBuffer(RingBuffer *rb, int value) {
  if (rb->count == rb->size) {
    printf("Error: Ring buffer is full! Cannot add %d\n", value);
    return -1; // Full
  }

  rb->data[rb->tail] = value;
  rb->tail = (rb->tail + 1) % rb->size;
  rb->count++;
  return 0; // Success
}

// Remove from ring buffer
int dequeueRingBuffer(RingBuffer *rb) {
  if (rb->count == 0) {
    printf("Error: Ring buffer is empty!\n");
    return -1;
  }

  int value = rb->data[rb->head];
  rb->head = (rb->head + 1) % rb->size;
  rb->count--;
  return value;
}

// Check if empty
int isEmptyRingBuffer(RingBuffer *rb) { return rb->count == 0; }

// Check if full
int isFullRingBuffer(RingBuffer *rb) { return rb->count == rb->size; }

// Print ring buffer (shows internal state)
void printRingBuffer(RingBuffer *rb) {
  printf("Ring Buffer (count=%d/%d, head=%d, tail=%d): ", rb->count, rb->size,
         rb->head, rb->tail);

  if (rb->count == 0) {
    printf("empty");
  } else {
    for (int i = 0; i < rb->size; i++) {
      if (rb->count > 0) {
        // Show actual data
        if (i >= rb->head && i < rb->head + rb->count) {
          printf("%d ", rb->data[i % rb->size]);
        } else if (rb->head + rb->count > rb->size &&
                   i < (rb->head + rb->count) % rb->size) {
          printf("%d ", rb->data[i]);
        } else {
          printf("_ ");
        }
      } else {
        printf("_ ");
      }
    }
  }
  printf("\n");
}

// Free ring buffer
void freeRingBuffer(RingBuffer *rb) {
  free(rb->data);
  free(rb);
}

// Test function
void testRingBuffer() {
  printf("\n========== RING BUFFER DEMO ==========\n");
  RingBuffer *rb = createRingBuffer(8); // Fixed size of 8

  printf("Adding 5 items to size-8 buffer...\n");
  enqueueRingBuffer(rb, 10);
  enqueueRingBuffer(rb, 20);
  enqueueRingBuffer(rb, 30);
  enqueueRingBuffer(rb, 40);

  enqueueRingBuffer(rb, 50);
  printRingBuffer(rb);

  printf("Removing 2 items...\n");
  printf("Removed: %d\n", dequeueRingBuffer(rb));
  printf("Removed: %d\n", dequeueRingBuffer(rb));
  printRingBuffer(rb);

  printf("Adding 3 more items...\n");
  enqueueRingBuffer(rb, 60);
  enqueueRingBuffer(rb, 70);
  enqueueRingBuffer(rb, 80);
  printRingBuffer(rb);

  printf("Adding 2 more (should wrap around)...\n");
  enqueueRingBuffer(rb, 90);
  enqueueRingBuffer(rb, 100);
  printRingBuffer(rb);

  printf("Try to add one more (should fail - full)...\n");
  enqueueRingBuffer(rb, 110);

  printf("Removing all items...\n");
  while (!isEmptyRingBuffer(rb)) {
    printf("Removed: %d\n", dequeueRingBuffer(rb));
  }

  freeRingBuffer(rb);
}

int main(void) {
  testRingBuffer();
  return 0;
}
