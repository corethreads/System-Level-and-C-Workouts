#include <stdio.h>

int main(void) {
  int x = 50;
  int *ptr = &x;
  *ptr = 80;
  int node = *ptr;

  int **dptr = &ptr;

  **dptr = 100;
  printf("%d\n", node);
  printf("x address %p \n", &x);
  printf("x %d \n", x);
  printf("x address %p \n", &ptr);
  printf("%d\n", node);
  printf("ptr %d\n", *ptr);
  printf("x address %p \n", &dptr);
  printf("dptr %d \n", **dptr);
}
