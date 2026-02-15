#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define MIN 0;
// #define MAX 100;

int main() {

  srand(time(NULL));

  int randomNumber = (rand() % 10) + 1;
  int guess;

  while (1) {
    printf("Enter your guess: ");
    scanf("%d", &guess);

    if (guess < randomNumber) {
      printf("Low!!!\n");
    } else if (guess > randomNumber) {
      printf("HIGH!!\n");
    } else {
      printf("Guess Found!!! Guess:%d :randomNumber: %d\n", guess,
             randomNumber);
      break;
    }
  }
}
