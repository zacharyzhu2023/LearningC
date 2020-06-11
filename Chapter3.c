#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/** Notes and exercises for Chapter 3! */

/* Sample function */
// Note to self: function must be written before it's called
void printNewLine() {
  printf("\n");
}

void printThreeNewLines() {
  printNewLine();
  printNewLine();
  printNewLine();
}

void printNumbers(int i0, int i1) {
  printf("Integers: %i %i\n", i0, i1);
}

/*
Exercise 3.2
  a. Write the first line of a function named Zool() that takes three parameters: an
  int and two char.
  b. Write a line of code that invokes Zool(), passing as arguments the value 11, the
  letter a, and the letter z.
*/
void Zool(int a, char b, char c) {
  printf("An int and two chars walk into a bar... %i, %c, %c\n", a, b, c);
}

/*
Exercise 3.3
  a. Write a function called PrintDateAmerican() that takes the day, month and
  year as parameters and that prints them in American format.
  b. Test your function by invoking it from main() and passing appropriate arguments. The output should look something like this (except that the date might
  be different):
  3/29/2009
  c. Once you have debugged PrintDateAmerican(), write another function called
  PrintDateEuropean() that prints the date in European format.
*/
void printDateAmerican(int day, int month, int year) {
  printf("American: %i/%i/%i\n", month, day, year);
}
void printDateEuropean(int day, int month, int year) {
  printf("European: %i.%i.%i\n", day, month, year);
}

/*
Exercise 3.4
  a. Create a new program called Multadd.c.
  b. Write a function called Multadd() that takes three doubles as parameters and
  that prints their multadditionization: a * b + c.
  c. Write a main() function that tests Multadd() by invoking it with a few simple
  parameters, like 1.0, 2.0, 3.0, and then prints the result, which should be
  5.0.
  d. Also in main(), use Multadd() to compute the following value:
  sin(π/4) + cos(π/4)/2
  e. Write a function called Yikes() that takes a double as a parameter and that
  uses Multadd() to calculate and print
  xe^−x + sqrt(1-e^-x)
*/

void Multadd(double d0, double d1, double d2) {
  printf("multadditionization: %f\n", d0 * d1 + d2);
}
void Yikes(double d) {
  printf("Yikes! This is a hard problem\n");
  Multadd(d, exp(-1*d), sqrt(1-exp(-1*d)));
}
int main(void) {
  // Floats
  double pi = 3.14159;
  double third = 1.0/3.0;
  printf("Pi, third: %f %func\n", pi, third);
  const double e = 2.7; // Can never be changed in program: saves space
  printf("Constant e: %f\n", e);
  int intE = (int) e; // Casting e to an int: intE = 2
  // Math operations: log, sin/cos/tan, acos/atan/asin
  //printNewLine();
  printThreeNewLines();
  printNumbers(50, 23);
  Zool(11, 'a', 'z');
  printDateAmerican(4, 6, 2020);
  printDateEuropean(4, 6, 2020);
  // 3.4.c
  Multadd(1.0, 2.0, 3.0); // Checking MultAdd function works properly
  // 3.4.d
  Multadd(cos(pi/4.0), 0.5, sin(pi/4.0));
  //3.4.e
  Yikes(3.0);

}

/**
Syntax for a function
returnType NAME (LIST PARAMETERS) {
  STATEMENTS
}
**/
