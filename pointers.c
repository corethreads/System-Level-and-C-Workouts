#include <stdio.h>

void test1(char *ptr) {
  printf("test1: sizeof parameter = %lu\n", sizeof(ptr)); // 8 (pointer size)
}

void test2(char arr[100]) {
  printf("test2: sizeof parameter = %lu\n", sizeof(arr)); // ALSO 8! Not 100!
}

int main() {
  int value = 100;
  int *p1 = &value;
  int **p2 = &p1;
  int ***p3 = &p2;

  int arr[] = {1, 2, 3, 4, 5};
  int *ptr = arr;

  // All these print 100:
  printf("%d\n", value);
  printf("%d\n", *p1);
  printf("%d\n", **p2);
  printf("%d\n", ***p3);

  // Memory layout:
  // p3  --> p2  --> p1  --> value
  // [&p2]   [&p1]    [&value] [100]
  //
  char my_string[] = "Hello";

  printf("In main: sizeof my_string = %lu\n",
         sizeof(my_string)); // 6 (array size)

  test1(my_string);
  test2(my_string);

  return 0;
}
