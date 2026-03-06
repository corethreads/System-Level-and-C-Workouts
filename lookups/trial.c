#include <stdio.h>

void add(int *node) { *node = 50; }

int main(void) {
  int x = 60;
  int *head = &x;
  add(head);

  printf("Data %d\n", *head);
  printf("Address of head %p\n", head);
  return 0;
}
