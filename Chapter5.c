/** Chapter 5 Notes/Exercises: Functions/Booleans **/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/** Look more into macros/C preprocessing later **/
// Defining true/false values
#define false 0
#define true 1
// Can use define with an expression
#define AGE (30/2)
// Define a string
#define message "We can say anything we want"

// Function that returns area of a circle
double CircleArea(double r) {
  double pi = acos(-1.0);
  return pi * pow(r, 2);
}

// Function that returns distance b/w 2 points
double distanceFormula(double x0, double y0, double x1, double y1) {
  return pow(pow(y1-y0, 2) + pow(x1-x0, 2), 0.5);
}

// Function that returns a "boolean"
int isEvenPosUnderTwenty(int x) {
  if (x >= 20 || x <= 0) {
    return false;
  } else {
    if (x % 2 == 0) {
      return true;
    }
    return false;
  }
}

/**
Exercise 5.1
  Write a function named IsTriangle() that it takes three integers as arguments, and
  that returns either TRUE or FALSE, depending on whether you can or cannot form a
  triangle from sticks with the given lengths.
**/
int isTriangle(int a, int b, int c) {
  if (a <= 0 || b <= 0 || c <= 0) {
    return false;
  } else {
    if (a + b <= c || a + c <= b || b + c <= a) {
      return false;
    }
    return true;
  }
}


/**
Exercise 5.4
  Write a recursive function called Power() that takes a double x and
  an integer n and that returns x ^ n
**/
double Power(double x, int n) {
  if (n == 0) {
    return 1.0;
  } else if (n < 0) {
    return 1.0/(Power(x, -1 * n));
  } else {
    return x * Power(x, n - 1);
  }
}


/**
Exercise 5.5
  Write a function called gcd that takes two integer parameters and that uses Euclid’s
  algorithm to compute and return the greatest common divisor of the two numbers.
  - Euclid's Alogrithm: gcd(a,b) = gcd(b, a %b) and gcd(a, 0) = a
**/
int gcd(int x, int y) {
  if (y == 0) {
    return x;
  } else {
    return gcd(y, x % y);
  }
}

/**
NOTES
- C does not have a boolean "type"
  - 0 and 1 represent true/false values
  - Any non-zero integer is true
- Cannot have a boolean as input/output--replace with int (0/1)
**/

/**
main()
- stdlib.h has 2 predefined constants: EXIT_SUCCESS & EXIT_FAILURE
  - EXIT_SUCCESS = 0: program succeeded
  - EXIT_FAILURE = -1: some error occurred
- From the system's perspective, the operating system can use the return value
  of main() to determine whether the program executed correctly or not
- Useful note: main() can take in parameters
**/

int main() {
  double e = exp(1.0);
  printf("Value of e: %f\n", e);
  // Testing area function
  printf("Area of radius %f: %f\n", 2.0, CircleArea(2.0));
  printf("Area of radius %f: %f\n", 10.0, CircleArea(10.0));
  // Testing distance formula function
  printf("Distance between (%f, %f) (%f, %f) is: %f\n", 0.0, 0.0, 3.0, 4.0, distanceFormula(0.0, 0.0, 3.0, 4.0));
  printf("Distance between (%f, %f) (%f, %f) is: %f\n", 3.0, -1.0, 5.0, -1.0, distanceFormula(3.0, -1.0, 5.0, -1.0));

  if (!false) {
    short tester = false; // short acts as "boolean" variable
    printf("Working with pre-defined false value??\n");
    printf("Printing a boolean? %i\n", tester); // false value still represented as 0
  }
  if (true) {
    printf("True value is working\n");
  }
  // Testing isEvenUnderTwenty function
  printf("%i is even under 20? %i\n", 55, isEvenPosUnderTwenty(55));
  printf("%i is even under 20? %i\n", 16, isEvenPosUnderTwenty(16));
  printf("%i is even under 20? %i\n", -4, isEvenPosUnderTwenty(-4));

  printf("Using #define: %s\n", message);

  // Testing 5.3
  printf("%i, %i, %i is a triangle? %i\n", 3, 4, 5, isTriangle(3, 4, 5));
  printf("%i, %i, %i is a triangle? %i\n", 3, 4, 8, isTriangle(3, 4, 8));
  printf("%i, %i, %i is a triangle? %i\n", 5, 7, 4, isTriangle(5, 7, 4));
  printf("%i, %i, %i is a triangle? %i\n", 15, 13, 3, isTriangle(15, 13, 3));
  // Testing 5.4
  printf("%i ^ %f = %f\n", 3, 5.0, Power(3, 5.0));
  printf("%i ^ %f = %f\n", 2, -3.0, Power(2, -3.0));
  printf("%i ^ %f = %f\n", 4, 3.0, Power(4, 3.0));
  // Testing 5.5
  printf("GCD of %i and %i is: %i\n", 15, 20, gcd(15, 20));
  printf("GCD of %i and %i is: %i\n", 17, 28, gcd(17, 28));
  printf("GCD of %i and %i is: %i\n", 48, 42, gcd(48, 42));

}
