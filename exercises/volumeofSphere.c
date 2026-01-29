#include <stdio.h>

#define PI 3.14159
#define Sphere ((4.0f / 3.0f) * PI)

int main() {
  int radius;
  float results;

  radius = 10;
  results = Sphere * (radius * radius * radius);
  printf("short size: %zu bytes\n", sizeof(int));
  printf("int size: %zu bytes\n", sizeof(float));
  printf("The volume of a sphere with radius %d is %6f\n", radius, results);

  return 0;
}
