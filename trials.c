#include <stdio.h>

int main() {
  int arr[100] = {10, 20, 30, 40, 50};
  int current_size = 5;
  int index_to_delete = 2; // Index of element 30

  // Validate the index
  if (index_to_delete >= 0 && index_to_delete < current_size) {
    // Shift elements to the left, starting from the index to delete
    for (int i = index_to_delete; i < current_size - 1; i++) {
      arr[i] = arr[i + 1];
    }

    // Decrement the logical size of the array
    current_size--;
  } else {
    printf("Invalid index for deletion.\n");
  }

  printf("What removed: %d\n", arr[index_to_delete]);
  // Print the modified array
  printf("Array after deletion: ");
  for (int i = 0; i < current_size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
