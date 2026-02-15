#include <stdio.h>

// iteration numbers you assign for each number is squared by itself

int main(void) {
  int rows = 5;

  for (int currentrow = 1; currentrow <= rows; currentrow++) {

    for (int column = 1; column <= currentrow; column++) {
      printf("*");
    }

    printf("\n");
  }
}
