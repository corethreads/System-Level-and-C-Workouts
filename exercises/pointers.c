#include <stdio.h>

typedef struct {
  int x;
  int y;
} Point;

void Modify(Point *p) {
  p->x = 60;
  p->y = 40;
}

int main() {
  Point original = {100, 100};
  Modify(&original);
  printf("x %d, y %d \n", original.x, original.y);
}
