#include <math.h>
#include <stdio.h>

int main(void) {
  double k, y, z, x, r;
  k = 1;
  y = 2;
  z = k + y;
  x = 5.0;
  r = pow(x, 2.0);

  printf("Value of K: %f\n", k++);
  printf("Value of K: %f\n", k);
  printf("Value of Y: %f\n", ++y);
  printf("Total Z: %f\n", z);
  printf("Value of X: %f\n", x);
  printf("Value of R: %f\n", r);
}
