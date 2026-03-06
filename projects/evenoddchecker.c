#include <limits.h> // Required for CHAR_BIT
#include <stdio.h>

/**
 * Prints the binary representation of an integer.
 * Assumes a char has 8 bits.
 */
void printBinary(int num) {
  // Determine the number of bits in an int type portably
  const int bits = sizeof(int) * CHAR_BIT;
  int i;

  // Iterate from the most significant bit to the least significant bit
  for (i = bits - 1; i >= 0; i--) {
    // Create a mask with a 1 at the current bit position
    int mask = 1 << i;

    // Perform bitwise AND to check the bit
    // If (num & mask) is non-zero, the bit is 1, otherwise it is 0
    if (num & mask) {
      printf("1");
    } else {
      printf("0");
    }

    // Optional: Add a space for readability, e.g., every 4 bits
    if (i % 4 == 0) {
      printf(" ");
    }
  }
  printf("\n");
}

int main() {
  int number = 2;
  printf("Binary representation of %d: ", number);
  printBinary(number);

  int another_number = 4;
  printf("Binary representation of %d: ", another_number);
  printBinary(another_number);

  return 0;
}
