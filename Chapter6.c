/** Chapter 6 Notes and Exercises: Iteration **/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define false 0
#define true 1

// Function that uses a while loop--countdown from n to 0
void countdown(int n) {
  while (n > 0) {
    printf("%i, ", n);
    n -= 1;
  }
  printf("%i\n", 0);
}

// Function to print n x n multiplication table
void multiplicationTable(int n) {
  int i, j;
  i = j = 1;
  while (i <= n) {
    while (j <= n) {
      printf("%i ", i * j);
      j += 1;
    }
    j = 1;
    printf("\n");
    i += 1;
  }
  printf("\n");
}

/**
Exercise 6.1
Use a while loop to return the nth fibonacci number
0 --> 0
1 --> 1
2 --> 1
3 --> 2
4 --> 3
5 --> 5
6 --> 8
7 --> 13
**/
int fib(int n) {
  if (n < 0) {
    return 0;
  } else {
    int prev, curr;
    prev = 0;
    curr = 1;
    while (n > 0) {
      int temp = prev;
      prev = curr;
      curr += temp;
      n -= 1;
    }
    return prev;
  }
}

/**
Exercise 6.2
Use a while loop to find n! (Given that n >= 0)
4 --> 24
5 --> 120
**/
int fact(int n) {
  if (n < 0) {
    return 0;
  } else if (n <= 1) {
    return 1;
  } else {
    int prod = 1;
    while (n > 1) {
      prod = prod * n;
      n -= 1;
    }
    return prod;
  }
}
/**
Exercise 6.3
Find the palindrome representation of an integer
123 --> 123321
455 --> 455554
**/
int palindrome(int n) {
  int pal = n;
  while (n > 0) {
    int lastDigit = n % 10;
    n = n / 10;
    pal = pal * 10 + lastDigit;
  }
  return pal;
}

/**
Exercise 6.4
Find whether the sum of the digits a number are divisible by 7
**/
int sumDivSev (int n) {
  int digitSum = 0;
  while (n > 0) {
    digitSum += n % 10;
    n = n / 10;
  }
  if (digitSum % 7 == 0) {
    return true;
  }
  return false;
}

int main() {
  // Testing countdown function
  countdown(10);
  countdown(5);
  printf("\n");
  // Testing multiplication table
  multiplicationTable(5);
  multiplicationTable(10);
  // Testing 6.1
  printf("Fibonacci number #%i: %i\n", 5, fib(5));
  printf("Fibonacci number #%i: %i\n", 2, fib(2));
  printf("Fibonacci number #%i: %i\n", 7, fib(7));
  // Testing 6.2
  printf("%i factorial is: %i\n", 5, fact(5));
  printf("%i factorial is: %i\n", 1, fact(1));
  printf("%i factorial is: %i\n", 0, fact(-4));
  // Testing 6.3
  printf("Palindrome of %i is: %i\n", 45, palindrome(45));
  printf("Palindrome of %i is: %i\n", 142, palindrome(142));
  printf("Palindrome of %i is: %i\n", 0, palindrome(0));
  // Testing 6.4
  printf("The digits of %i are divisible by 7? %i\n", 3838, sumDivSev(3838));
  printf("The digits of %i are divisible by 7? %i\n", 1805, sumDivSev(1805));
  printf("The digits of %i are divisible by 7? %i\n", 911, sumDivSev(911));
}
