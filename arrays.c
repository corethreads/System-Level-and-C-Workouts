#include <stdio.h>

#define N 10
int main(void) {

  int matrix[3][4] = {
      {
          1,
          2,
          3,
          4,
      },
      {5, 6, 7, 8},
      {
          9,
          10,
          11,
          12,
      },

  };

  for (int rows = 0; rows < 3; rows++) {
    for (int columns = 0; columns < 4; columns++) {
      printf("%3d", matrix[rows][columns]);
    }

    printf("\n");
  }

  return 0;
}
