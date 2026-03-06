#include <stdio.h>
#include <string.h>

int main(void) {
  char string[] = "Hello, Leonne";
  int length = strlen(string);

  for (int j = length - 1; j >= 0; j--) {
    printf("%c", string[j]);
  }
}
