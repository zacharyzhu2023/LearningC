#include <stdio.h>
#include <stdlib.h>
int main(void) {
  printf("Printing text easily\n");
  printf("%i\n", 22); // Printing an integer: %i acts as placeholder

  /* Declaration */
  char c0; // Single character variable declaration
  int x; // Integer variable declaration
  int y, z; // Oh look: we can do multiple at the same time
  c0 = 't'; // Assignment of a variable

  /* Assignment */
  x = 55;
  y = 20;
  z = 5;
  printf("%c\n", c0); // Printing out a char
  printf("Three integers: %i, %i, %i\n", x, y, z); // Using multiple variables

  /* Operations */
  int i0 = 15;
  int i1 = 25;
  int i2 = 79;
  printf("Integer operations: %i, %i, %i\n", i0 * i1, i0 + i2, i2/i0); // Math operations
  int i3 = 'a';
  printf("%i\n", i3); // chars can be treated as ints too

  /* Exercise 2.1
a. Create a new program named MyDate.c. Copy or type in something like the
"Hello, World" program and make sure you can compile and run it.
b. Following the example in Section 2.5, write a program that creates variables
named day, month and year What type is each variable?
Assign values to those variables that represent today’s date.
c. Print the value of each variable on a line by itself. This is an intermediate step
that is useful for checking that everything is working so far.
d. Modify the program so that it prints the date in standard American form:
  mm/dd/yyyy.
e. Modify the program again so that the total output is:
  American format:
  3/18/2009
  European format:
  18.3.2009
  */

  /* Part a/b */
  int day, month, year;
  day = 4;
  month = 6;
  year = 2020;
  /*
  Part  c
  printf("%i\n", day);
  printf("%i\n", month);
  printf("%i\n", year);
  */
  printf("American format:\n");
  printf("%i/%i/%i\n", month, day, year);
  printf("European format:\n");
  printf("%i.%i.%i\n", day, month, year);

/*
Exercise 2.2
  a. Create a new program called MyTime.c. From now on, I won’t remind you to
  start with a small, working program, but you should.
  b. Following the example in Section 2.7, create variables named hour, minute and
  second, and assign them values that are roughly the current time. Use a 24-hour
  clock, so that at 2pm the value of hour is 14.
  c. Make the program calculate and print the number of seconds since midnight.
  d. Make the program calculate and print the number of seconds remaining in the
  day.
  e. Make the program calculate and print the percentage of the day that has passed.
  f. Change the values of hour, minute and second to reflect the current time (I
  assume that some time has elapsed), and check to make sure that the program
  works correctly with different values.
*/
  int hour, minute, second;
  hour = 20;
  minute = 23;
  second = 44;
  // Part c
  int secondsSinceMidnight = hour * 3600 + minute * 60 + second;
  printf("Seconds since midnight: %i\n", secondsSinceMidnight);
  // Part d
  int secondsTillMidnight = 24 * 60 * 60 - secondsSinceMidnight;
  printf("Seconds till midnight: %i\n", secondsTillMidnight);
  // Part e
  int percentageDayPassed = (secondsSinceMidnight * 100)/(24 * 60 * 60);
  printf("Percentage of day passed: %i\n", percentageDayPassed);
  // Part f -- pedantic
  hour = 20;
  minute = 30;
  second = 21;

}
