#include <stdio.h>

int main(void) {

  for (int j = 1; j < 100; j++) {
    if (j % 15 == 0) {
      printf("fizzbuzz\n");
    } else if (j % 3 == 0) {
      printf("Fizz\n");
    } else if (j % 5 == 0) {
      printf("Buzz\n");
    } else {
      printf("\n");
    }
  }
}
