/** Chapter 7 Notes/Exercises: Arrays **/

/**
Notes
- Array: set of values with identifiable values referenced by index
  - Can have arrays of ints/doubles
- C does not have a built-in operation to check the length of an array
- Cannot have an array as return type
- Cannot find the size of an array passed into a function
- Deterministic program: does the same thing every time
- C uses call by value evaluation fo expressions
  - Passing a value into function copies that value from where it was originally called
- Passing an array into the function operates by: call by reference
  - C generates a reference to original array (so affecting the array in function
    will change the original array)
- rand() will generate same "random" values each time
  - Uses the same starting seed when program is run
  - Ease of debug, but has predictability when generating "random"
- srand() function will allow for a different seed to be used
- Initializing an array in a local function results in garbage values
**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define true 1;
#define false 0;

/** Different formats to take array as parameter
1. void func(int * param) --"pointer" as input
2. void func(int param[10]) --Fixed sized array
3. void func(int param[]) --Array of an arbitrary size
**/

// Function that takes the sum of elements of an array
int sumElements(int arr[4]) {
  // Finding the length of an array
  int total = 0;
  for (int i = 0; i < 4; i++) {
    total += arr[i];
  }
  return total;
}

// Function that generates pseudorandom #'s from 0-n
int randomNum(int n) {
  int randInt = rand();
  return randInt % n;
}

// Function to generate random float from 0-1
double randomFloat() {
  return (double) rand()/RAND_MAX;
}

// Function that assigns values of an array from 0-999
void randomizeArray(int arr[], int length) {
  for (int i = 0; i < length; i++) {
    arr[i] = randomNum(1000);
  }
}

// Function that prints out an array
void printArray(int arr[], int length) {
  printf("[");
  for (int i = 0; i < length; i++) {
    if (i != length - 1) {
      printf("%i, ", arr[i]);
    } else {
      printf("%i]\n", arr[i]);
    }
  }
}

/**
Exercise 7.1
Write a function that prints out the digits of a number in reverse
**/

void reverseInt(int x) {
  printf("Reversed: ");
  for (int i = x; i > 0; i = i/10) {
    printf("%i", i % 10);
  }
  printf("\n");
}

/**
Exercise 7.2
Write a function that takes an array as an argument, its length, and the maximum
value an integer can take in that array and output an array corresponding to number
of occurrences of each element
([1, 1, 3, 4, 5, 5, 5], max of 6) --> [0, 2, 0, 1, 1, 3, 0]
**/
void histogram(int arr[], int length, int maximum) {
  int hist[maximum + 1];
  for (int i = 0; i <= maximum; i++) {
    hist[i] = 0;
  }
  for (int i = 0; i < length; i++) {
    hist[arr[i]] ++;
  }
  printf("Histogrammed array: ");
  printArray(hist, maximum + 1);
}

/**
Exercise 7.3
One not-very-efficient way to sort the elements of an array is to find the largest element
and swap it with the first element, then find the second-largest element and swap it
with the second, and so on. Implement this algorithm
**/
void sortArray(int arr[], int length) {
  for (int i = 0; i < length; i++) {
    int indexLargest = i;
    int largestElem = arr[i];
    for (int j = i; j < length; j++) {
      if (arr[j] > largestElem) {
        largestElem = arr[j];
        indexLargest = j;
      }
    }
    int temp = arr[i];
    arr[i] = largestElem;
    arr[indexLargest] = temp;
  }
  printf("Sorted: ");
  printArray(arr, length);
}

/**
Exercise 7.4
Merge 2 sorted int arrays and print the result
([11, 9, 4, 4, 1], [10, 6, 4, 2]) --> [11, 10, 9, 6, 4, 4, 4, 2]
**/
void mergeArrays(int arr1[], int length1, int arr2[], int length2) {
  int mergedArr[length1 + length2];
  int index1 = 0;
  int index2 = 0;
  while (index1 < length1 || index2 < length2) {
    if (index1 >= length1 || (index2 < length2 && arr2[index2] >= arr1[index1])) {
      mergedArr[index1 + index2] = arr2[index2];
      index2++;
    } else {
      mergedArr[index1 + index2] = arr1[index1];
      index1++;
    }
  }
  printf("Merged Array: ");
  printArray(mergedArr, length1 + length2);
}

int main() {
  /** Syntax for arrays **/
  int c[4]; // Initialize an array of 4 integers named c
  // Accessing/assigning elements of an array
  for (int i = 0; i < 4; i++) {
    printf("%i ", c[i]);
  }
  printf("\n");
  c[0] = 1;
  c[1] = 5;
  c[2] = 3;
  c[3] = 2;
  for (int i = 0; i < 4; i++) {
    printf("%i ", c[i]);
  }
  printf("\n");

  int newArr[10];
  // Syntax for finding the length of an array
  printf("Length of array: %ld\n", sizeof(newArr) / sizeof(newArr[0]));

  // Testing sumElements
  int inp[] = {1, 5, 3, 7};
  printf("Sum of array [1,5,3,7] is: %i\n", sumElements(inp));

  // Generating pseudorandom numbers (of ALL possible integers in C)
  for (int i = 0; i < 5; i++) {
    int x = rand();
    printf("Random integer: %i\n", x);
  }

  // Generating pseudorandom numbers in a range (from 0-n)
  int n = 20;
  for (int i = 0; i < 5; i++) {
    printf("Random integer from 0-%i: %i\n", n-1, randomNum(n));
  }

  // Testing generation of random floats (0 to 1)
  for (int i = 0; i < 5; i++) {
    printf("Random float from 0 to 1: %f\n", randomFloat());
  }

  // Testing randomizing and assigning values to an array
  int arr1[10];
  int arr2[6];
  int arr3[8];
  randomizeArray(arr1, 10);
  randomizeArray(arr2, 6);
  randomizeArray(arr3, 8);
  printArray(arr1, 10);
  printArray(arr2, 6);
  printArray(arr3, 8);

  // Testing srand(int x) function
  srand(10); // Changing the seed "changes" the pseudorandom #'s
  for (int i = 0; i < 5; i++) {
    printf("srand gives us: %i\n", rand());
  }

  // Testing 7.1
  reverseInt(754);
  reverseInt(8822);
  reverseInt(70);
  // Testing 7.2
  int t1[] = {1, 1, 3, 4, 5, 5, 5};
  int t2[] = {0, 0, 1, 4};
  int t3[] = {0, 1, 2, 3, 4, 5, 6};
  histogram(t1, 7, 6);
  histogram(t2, 4, 4);
  histogram(t3, 7, 6);
  // Testing 7.3
  sortArray(t1, 7);
  sortArray(t2, 4);
  sortArray(t3, 7);
  // Testing 7.4
  mergeArrays(t1, 7, t2, 4);
  mergeArrays(t1, 7, t3, 7);
  mergeArrays(t2, 4, t3, 7);

}
