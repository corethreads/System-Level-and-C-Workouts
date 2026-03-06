#include <stdio.h>
#include <string.h>

// Define a structure (like a blueprint)
struct person {
  char name[50];
  int age;
  float height;
};

int main() {

  struct person person1;
  person1.age = 16;
  strcpy(person1.name, "Leonne");

  struct person *ptr;

  ptr = &person1;

  printf("Address of age:-> %p\n", (void *)&ptr->age);
  printf("Age old getting way : %d\n", (*ptr).age);
  printf("Age new getting way: %d\n", ptr->age);

  ptr->age = 70;
  printf("Address of age:-> %p\n", (void *)&ptr->age);
  printf("Age old getting way : %d\n", (*ptr).age);
  printf("Age new getting way: %d\n", ptr->age);

  return 0;
}
