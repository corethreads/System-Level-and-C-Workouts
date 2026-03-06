#include <stdio.h>

void bubble_sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      // If current > next, swap them
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
    // Print after each pass to see progress
    printf("Pass %d: ", i + 1);
    for (int k = 0; k < n; k++) {
      printf("%d ", arr[k]);
    }
    printf("\n");
  }
}

int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("%d\n", n);

  printf("Original: ");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n\n");

  bubble_sort(arr, n);

  printf("\nSorted: ");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
