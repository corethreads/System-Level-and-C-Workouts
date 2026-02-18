#include <stdio.h>

#define N 10
int main(void) {

  int array[N];

  printf("Enter Nums: ");
  for (int j = 0; j <= N; j++) {
    scanf("%d", &array[j]);
  }

  printf("In reverse order");
  for (int j = N - 1; j >= 0; j--) {
    printf("%d", array[j]);
  }

  printf("\n");

  return 0;
}
