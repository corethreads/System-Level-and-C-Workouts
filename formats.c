#include <stdio.h>

int main() {
  /*
  int itemNumber;
  float price;
  int day, month, year;

  printf("Welcome To the Inventory Store....\n");

  printf("Enter the Item Number: ");
  scanf("%d", &itemNumber);
  printf("Size of itemNumber: %zu bytes\n", sizeof(itemNumber));

  printf("Enter the Price: ");
  scanf("%f", &price);
  printf("Size of price: %zu bytes\n", sizeof(price));

  printf("Enter Date (DD MM YYYY): ");
  scanf("%d/%d/%d", &day, &month, &year);
  printf("Size of day: %zu bytes\n", sizeof(day));
  printf("Size of month: %zu bytes\n", sizeof(month));
  printf("Size of year: %zu bytes\n", sizeof(year));

  printf("Item Number\tPrice\tDate\n");
  printf("%d\t Ksh %f\t %d/%d/%d\n", itemNumber, price, day, month, year); */

  int countryCode, areaCode, phoneNumber;

  printf("Enter phoneNumber and country code (CODE)0000-000: ");
  scanf("(%d) %d-%d", &countryCode, &areaCode, &phoneNumber);

  printf("Phone Number: +%d (%d).%d\n ", countryCode, areaCode, phoneNumber);

  // printf("Name\tAge\tHeight\n");
  // printf("Alice\t30\t5.5\n");

  return 0;
}
