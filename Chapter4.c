#include <stdlib.h>
#include <stdio.h>
#include <math.h>


/** Chapter 4 Notes/Exercises: Conditionals & Recursion **/

int isEven(int x) {
  if (x % 2 == 0) {
    return 1;
  }
  return 0;
}

// Function that shows basic if/else if/else statements
void remainderThree(int x) {
  if (x % 3 == 0) {
    printf("Remainder: 0\n");
  } else if (x % 3 == 1) {
    printf("Remainder: 1\n");
  } else {
    printf("Remainder: 2\n");
  }
}

// Function that showcases nested if statements
void numberSize(int x) {
  if (x > 0) {
    if (x > 50) {
      printf("Big number!\n");
    } else {
      printf("A small but positive number\n");
    }
  } else {
    printf("Eww! Negative numbers?\n");
  }
}

// Function that uses recursion
void downByFour(int x) {
  if (x >= 0) {
    printf("%i ", x);
    downByFour(x - 4);
  }
}

/**
Exercise 4.2
The first verse of the song “99 Bottles of Beer” is:
  99 bottles of beer on the wall, 99 bottles of beer, ya’ take one down, ya’
  pass it around, 98 bottles of beer on the wall.
Subsequent verses are identical except that the number of bottles gets smaller by one
in each verse, until the last verse:
  No bottles of beer on the wall, no bottles of beer, ya’ can’t take one down,
  ya’ can’t pass it around, ’cause there are no more bottles of beer on the
  wall!
Print out the entire song for 99 bottles of beer.
**/
void bottlesOfBeer(int x) {
  if (x <= 0) {
    printf("No bottles of beer on the wall, no bottles of beer, ya\' can't take one down,\n"
    "ya\' can\'t pass it around, \'cause there are no more bottles of beer on the\n"
    "wall!\n");
  } else {
    printf("%i bottles of beer on the wall, %i bottles of beer, ya\' take one down, ya\'\n"
    "pass it around, %i bottles of beer on the wall.\n", x, x, x-1);
    bottlesOfBeer(x-1);
  }
}

/**
Exercise 4.3
  a. Write a program, that asks the user to input a digit between 0 and 9.
  b. Test the input from the user and display an error message if the returned value
  is not a digit. The program should then be terminated. If the test is successful,
  the program should print the input value on the computer screen
**/
void getDigit() {
  printf("\nEnter a digit: ");
  char c = getchar();
  if (c >= 48 && c <= 57) {
    printf("Your char is: %c\n", c);
  } else {
    printf("You didn't enter a digit.\n");
  }
}

/**
Exercise 4.4
  Write a function named checkFermat() that takes four integers as parameters—a, b,
  c and n—and that checks to see if Fermat’s theorem holds. If n is greater than 2 and
  it turns out to be true that a^n + b^n = c^n
  , the program should print “Holy smokes,
  Fermat was wrong!” Otherwise the program should print “No, that doesn’t work.”
  You should assume that there is a function named raiseToPow() that takes
  two integers as arguments and that raises the first argument to the power of the second
**/

void checkFermat(int a, int b, int c, int n) {
  if (pow(a, n) + pow(b, n) == pow(c, n) && n > 2) {
    // There is one obviously exception: didn't check a != b, b != c, or a or b or c == 1
    printf("Fermat is broken??\n");
  } else if (pow(a, n) + pow(b, n) == pow(c, n)) {
    printf("%f + %f == %f\n", pow(a, n), pow(b, n), pow(c, n));
  } else {
    printf("%f  + %f != %f\n", pow(a, n), pow(b, n), pow(c, n));
  }
}


int main() {

  /* If conditionals */
  printf("\nBASIC CONDITIONALS\n");
  printf("44 is even? %i\n", isEven(44));
  printf("45 is even? %i\n", isEven(45));
  printf("\nremainderThree tests\n");
  remainderThree(31);
  remainderThree(44);
  remainderThree(45);
  printf("\nnumberSize tests\n");
  numberSize(45);
  numberSize(-20);
  numberSize(100);

  /* Recursion */
  printf("\nTesting downByFour\n");
  downByFour(12);
  printf("\n");
  downByFour(11);
  printf("\n");

  /* Testing 4.2 */
  bottlesOfBeer(4);
  //bottlesOfBeer(99); //Trust me: it works

  /* Testing 4.3 */
  //getDigit(); // Again--trust that it works

  /* Testing 4.4 */
  checkFermat(2, 4, 5, 3);
}
