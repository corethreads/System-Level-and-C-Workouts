#include <stdio.h>

int sum(int n) {
  // YOUR CODE HERE
  // Hint: Base case when n == 1
  // Recursive: return n + sum(n-1)
  if (n == 1) {
    return 1;
  }

  unsigned int result = n + sum(n - 1);
  for (int j = 0; j <= n; j++) {
    printf("%d\n", j);
  }
  return result;
}

int main() {
  int result = sum(5);
  printf("Sum of 1 to 5 = %d\n", result); // Should be 15
  return 0;
}
