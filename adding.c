#include <stdio.h>

unsigned int add(unsigned int a, unsigned int b) {
  int sum = (a + b);
  return sum;
}

int main() {
  unsigned int a;
  unsigned int b;
  unsigned int sum;

  printf("first number:-> ");
  scanf("%u", &a);
  printf("second number:-> ");
  scanf("%u", &b);

  sum = add(a, b);

  if (sum != 0) {
    printf("Success");
    printf("%u", sum);

  } else {
    printf("Error");
  }

  return 0;
}
