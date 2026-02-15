printf is designed to show content as strings
format --> printf("", content,content etc..)

we use % to show content in a specific format converts content from internal form(binary) to printed form(characters);

%s --> string
%d --> integer
%f --> float
%.2f --> float with 2 decimal points

example:
   short i, j;
  float x, y;
  char str[20] = "Hello, World!";

  i = 10;
  j = 20;

  x = 45.343;
  y = 98.7654;

  printf("i = %d, j = %d\n", i, j);
  printf("size of int = %zu bytes\n", sizeof(i));
  printf("x = %f, y = %.1f\n", x, y);
  printf("size of floats = %zu bytes\n", sizeof(float));
  printf("str = %s\n", str);
  printf("size of str = %zu bytes\a", sizeof(char));



scanf is designed to read contents according to a particular format

%d --> integer
%f --> float
%s --> string 
%i --> integer (decimal, octal or hexadecimal)

