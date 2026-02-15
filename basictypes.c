#include <stdio.h>

int main() {
  char word[] = "hello";
  printf("%zu\n", sizeof(word));
  printf("%zu\n", sizeof(char));
  return 0;
}
