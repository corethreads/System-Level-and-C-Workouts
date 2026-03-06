#include <stdio.h>

void balance(int *money) {

  int kakitu = 80;
  money = &kakitu;
  printf("%d\n", *money);
}

int main() {
  int cash = 10;
  int *pesa = &cash;

  balance(pesa);
  return 0;
}
