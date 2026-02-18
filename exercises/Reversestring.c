#include <stdio.h>

#define S 13
int main(void) {
  char string[] = "Hello, Leonne";

  int size = sizeof(string) / sizeof(string[0]);

  for (int j = 0; j < 13; j++) {
    printf("%c ", string[j]);
  }
  printf("\n");
  printf("Reverse Order: \n");
  for (int j = size - 1; j >= 0; j--) {
    printf("%c", string[j]);
  }
}
