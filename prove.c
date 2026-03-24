#include <stdio.h>

int main(void) {

  int arr[] = {
      1,
      2,
      3,
      4,

  };

  for (int j = 0; j < 4; j++) {
    printf("%d", arr[j]);
  }

  printf("\n");
  unsigned int newarr[5] = {arr[0], arr[1], arr[2], arr[3], 5};
  for (int j = 0; j < 5; j++) {
    printf("%d", newarr[j]);
  }

  return 0;
}
