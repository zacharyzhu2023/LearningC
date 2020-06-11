/** Chapter 8 Notes/Exercises: Strings **/

/**
Notes
- Strings in C are represented as an array of chars (terminated by \0 character)
- Food for thought: strings in C do not seem to use call by reference
  - That would mean: altering string in function doesn't alter original string
  - Also means: string's length is its intrinsic property
  - Final conclusion: not completely analogous to an array of chars
- C: one of few high level languages allowing for manipulating objects in memory
  - Direct manipulation requires knowing its loctation (address)
- Pointer variables: variables pointing to other objects in memory
  - int *i_p: creating a memory address variable
- char ex[7] = "hello" is same as: char ex[7] = {'h','e','l','l','o','\0','\0'}
  - Any character after the first \0 character is automatically ignored
- strncat(str1, str2, maxlen)
  - str1: string that str2 gets tacked onto
  - str2: string that gets added (str2's value after operation won't change)
  - maxlen: maximum # of characters that can be added onto str1
  - Note: str1 has to have enough "space" allocated to accommodate str2's characters
**/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define true 1;
#define false 0;


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

// Function traverses and prints string in reverse
void reversePrint(char s[]) {
  for (int i = strlen(s) - 1; i >= 0; i--) {
    printf("%c", s[i]);
  }
  printf("\n");
}

// Function that returns whether or not a char is present in a string
int findChar(char s[], char c) {
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == c) {
      return true;
    }
  }
  return false;
}

/**
Exercise 8.1
  A word is said to be “abecedarian” if the letters in the word appear
  in alphabetical order. For example, the following are all 6-letter English
  abecedarian words.
    Implement an algorithm to check whether a string is abecedarian.
**/
int isAbecedarian(char inp[]) {
  for (int i = 0; i < strlen(inp) - 1; i++) {
    if (!(isalpha(inp[i]))) {
      return false;
    } else if (inp[i + 1] < inp[i]) {
      return false;
    }
  }
  if (!isalpha(inp[strlen(inp) - 1])) {
    return false;
  }
  return true;
}

/**
Exercise 8.2
Write a function that creates a histogram for letters in a string.
Be sure to account for whether a letter is upper or lower case.
**/
void letterHistogram(char inp[]) {
  int letterHist[26];
  for (int i = 0; i < 26; i++) {
    letterHist[i] = 0;
  }
  for (int i = 0; i < strlen(inp); i++) {
    if (isalpha(inp[i])) {
      int index = (int)tolower(inp[i]) - (int)'a';
      letterHist[index] ++;
    }
  }
  printf("Histogram for %s: ", inp);
  printArray(letterHist, 26);
}

/**
Exercise 8.3
A word is said to be a “doubloon” if every letter that appears in the
word appears exactly twice. Write a function to check whether or not a
string is a doubloon
**/
int isDoubloon(char inp[]) {
  for (int i = 0; i < strlen(inp); i++) {
    if (!isalpha(inp[i])) {
      return false;
    }
  }
  int letterHist[26];
  for (int i = 0; i < 26; i++) {
    letterHist[i] = 0;
  }
  for (int i = 0; i < strlen(inp); i++) {
    int index = (int)tolower(inp[i]) - (int)'a';
    letterHist[index] ++;
  }
  for (int i = 0; i < 26; i++) {
    if (letterHist[i] != 0 && letterHist[i] != 2) {
      return false;
    }
  }
  return true;
}
/**
Exercise 8.4
Implement a circular caesar cipher function for a string.
**/
void caesarCipher(char inp[], int shift) {
  char shifted[strlen(inp)];
  for (int i = 0; i < strlen(inp); i++) {
    if (!isalpha(inp[i])) {
      printf("Invalid input\n");
      return;
    } else if (islower(inp[i])) {
      int index = (int)inp[i] - (int)'a';
      index += shift;
      index = index % 26;
      shifted[i] = (char) (index + (int) 'a');
    } else {
      int index = (int)inp[i] - (int)'A';
      index += shift;
      index = index % 26;
      shifted[i] = (char) (index + (int) 'A');
    }
  }
  printf("Cipher of %s by %i: %s\n", inp, 2, shifted);
}

/**
Exercise 8.5
Write a function that determines whether a given word can be created from a given string,
using all the original characters a maximum of one time. Assume upper and lower case letters
can be used interchangably.
("yoodle", "odo")--> true
("thehehaiaasbne", "zee") --> false
**/
int formWord(char inp1[], char inp2[]) {
  // Check to make sure both inputs are valid
  for (int i = 0; i < strlen(inp1); i++) {
    if (!isalpha(inp1[i])) {
      return false;
    }
  }
  for (int i = 0; i < strlen(inp2); i++) {
    if (!isalpha(inp2[i])) {
      return false;
    }
  }

  // Generate the histogram of characters for inp1 and inp2
  int hist1[26];
  int hist2[26];
  for (int i = 0; i < 26; i++) {
    hist1[i] = 0;
    hist2[i] = 0;
  }
  for (int i = 0; i < strlen(inp1); i++) {
    int index = (int)tolower(inp1[i]) - (int)'a';
    hist1[index]++;
  }
  for (int i = 0; i < strlen(inp2); i++) {
    int index = (int)tolower(inp2[i]) - (int)'a';
    hist2[index]++;
  }
  for (int i = 0; i < 26; i++) {
    if (hist1[i] < hist2[i]) {
      return false;
    }
  }
  return true;
}

/**
Exercise 8.6
Modify the algorithm from 8.5 to account for the possibility for "wild cards": characters
that can represent any value. Assume that space represents a wild card.
**/
int formWordWild(char inp1[], char inp2[]) {
  // Check to make sure both inputs are valid
  int numSpaces = 0;
  for (int i = 0; i < strlen(inp1); i++) {
    if (inp1[i] == ' ') {
      numSpaces += 1;
    } else if (!isalpha(inp1[i])) {
      return false;
    }
  }
  for (int i = 0; i < strlen(inp2); i++) {
    if (!isalpha(inp2[i])) {
      return false;
    }
  }

  // Generate the histogram of characters for inp1 and inp2
  int hist1[26];
  int hist2[26];
  for (int i = 0; i < 26; i++) {
    hist1[i] = numSpaces;
    hist2[i] = 0;
  }
  for (int i = 0; i < strlen(inp1); i++) {
    int index = (int)tolower(inp1[i]) - (int)'a';
    hist1[index]++;
  }
  for (int i = 0; i < strlen(inp2); i++) {
    int index = (int)tolower(inp2[i]) - (int)'a';
    hist2[index]++;
  }
  for (int i = 0; i < 26; i++) {
    if (hist1[i] < hist2[i]) {
      return false;
    }
  }
  return true;
}

// Function that gets integer user input, checking for validity
void intInput() {
  // Check for success getting user input for an integer
  int success, x;
  char ch;
  printf("Enter an integer: ");
  success = scanf("%i", &x);
  // Successful scans yield a value of 1
  while (success != 1) {
    printf("No number was entered. Try again: ");
    while ((ch = getchar()) != '\n' && ch != EOF); // Empty the buffer
    success = scanf("%i", &x);
  }
  printf("Your integer is: %i\n", x);
}

// Function to take string input
void stringInput() {
  char inp[80]; // Make sure enough space is allocated
  printf("Please enter a string: ");
  scanf("%s", inp);
  printf("Your string is: %s\n", inp); // Will only print out the string before reaching SPACE char
}

int main() {
  // String basics
  char str1[] = "One string method";
  char str2[] = {'A', 'n', 'o', 't', 'h', 'e', 'r', '\0'}; // Make sure to include terminator character
  printf("First string: %s\n", str1);
  printf("Second string: %s\n", str2);
  printf("Indexing a string: %c, %c, %c\n", str1[0], str1[6], str2[5]);
  printf("Length of str1: %lu\n", strlen(str1)); // Length of string

  // Testing reversePrint
  char RP1[] = "The first string";
  char RP2[] = "Second string";
  reversePrint(RP1);
  reversePrint(RP2);
  printf("%s contains %c? %i\n", RP1, 't', findChar(RP1, 't'));
  printf("%s contains %c? %i\n", RP2, '5', findChar(RP2, '5'));

  // Working with pointers
  int number = 10; // Arbitrary number
  int *i_p;
  i_p = &number;
  printf("Original location: %p\n", i_p); // %p: printing address
  printf("Original *i_p value: %i\n", *i_p); // * is content-of operation
  printf("Location from number: %p\n", &number); // & gets the memory address
  printf("Value from number: %i\n", number);
  *i_p = *i_p + 4; // Changing the value associated w/ the memory address affects intrinsic variable value
  printf("Changed *i_p location: %p\n", i_p);
  printf("Changed *i_p value: %i\n", *i_p);
  printf("Location from number: %p\n", &number);
  printf("Value from number: %i\n", number);
  i_p += 2;
  printf("Changed i_p location: %p\n", i_p); // i_p is associated with a new value/address
  printf("Changed i_p value: %i\n", *i_p);
  printf("Location from number: %p\n", &number);
  printf("Value from number: %i\n", number);

  // String concactenation
  char sample1[50] = "A series of characters.";
  char sample2[] = " New sequence of things";
  strncat(sample1, sample2, strlen(sample2));
  printf("Cocactenated string: %s\n", sample1);

  // String copy
  char copyEx1[8];
  strncpy(copyEx1, "testers", 8); // Extra +1 is to accommodate \0 character
  printf("Copying full string: %s\n", copyEx1);
  char copyEx2[6];
  strncpy(copyEx2, "Tata for now", 4);
  copyEx2[4] = '\0'; // Make sure to add in final \0 character when copying only part of string
  printf("Copying part string: %s\n", copyEx2);

  // String comparison: strcmp
  printf("Comparison 1: %i\n", strcmp("one", "two")); // -1: first string < second
  printf("Comparison 2: %i\n", strcmp("one", "one")); // 0: first string == second
  printf("Comparison 3: %i\n", strcmp("two", "one")); // 1: first string > second

  // Character classifications
  char letter = 'g';
  char digit = '5';
  char space = ' ';
  char upper = 'E';
  printf("Checking %c is letter: %i\n", letter, isalpha(letter));
  printf("Checking %c is number: %i\n", digit, isdigit(digit));
  printf("Checking %c is space: %i\n", space, isspace(space));
  printf("Checking %c is uppercase: %i\n", upper, isupper(upper));
  printf("Convert %c to lower: %c\n", letter, toupper(letter));
  printf("curiosity: %c\n", letter); // letter retains its original value
  printf("Convert %c to lower: %c\n", digit, tolower(digit)); // char is unmodified if not uppercase letter

  // User input

  /**
  Syntax to get an integer
  int x;
  printf("Enter an integer: ");
  scanf("%i", &x);
  printf("Your integer is: %i\n", x);
  **/

  // intInput(); // Get integer as input
  // stringInput(); // Get string as input


  printf("\n\n\n\nEXERCISES\n");
  char s1[] = "testing";
  char s2[] = "appall";
  char s3[] = "Anna";
  char s4[] = "Abba";
  char s5[] = "dehors";
  char s6[] = "of2f";
  char s7[] = "yyz";
  // Testing 8.1
  printf("%s is abecedarian: %i\n", s1, isAbecedarian(s1)); // 0
  printf("%s is abecedarian: %i\n", s2, isAbecedarian(s2)); // 0
  printf("%s is abecedarian: %i\n", s5, isAbecedarian(s5)); // 1
  printf("%s is abecedarian: %i\n", s6, isAbecedarian(s6)); // 0
  // Testing 8.2
  letterHistogram(s1);
  letterHistogram(s2);
  letterHistogram(s6);
  // Testing 8.3
  printf("%s is doubloon: %i\n", s1, isDoubloon(s1)); // 0
  printf("%s is doubloon: %i\n", s2, isDoubloon(s2)); // 1
  printf("%s is doubloon: %i\n", s5, isDoubloon(s5)); // 0
  printf("%s is doubloon: %i\n", s6, isDoubloon(s6)); // 0
  printf("%s is doubloon: %i\n", s4, isDoubloon(s4)); // 1
  // Testing 8.4
  caesarCipher(s4, 2); // Cddc
  caesarCipher(s4, 1); // Bccb
  caesarCipher(s7, 10); // iij
  // Testing 8.5
  char cSet1[] = "aabbccdd";
  char cSet2[] = "bac";
  char cSet3[] = "bae";
  char cSet4[] = "abcdh  ";
  char cSet5[] = "btu";
  char cSet6[] = "bttt";
  char cSet7[] = "abbttta";
  printf("%s can form %s: %i\n", cSet1, cSet2, formWord(cSet1, cSet2)); // 1
  printf("%s can form %s: %i\n", cSet1, cSet3, formWord(cSet1, cSet3)); // 0
  printf("%s can form %s: %i\n", cSet6, cSet7, formWord(cSet6, cSet7)); // 0
  printf("%s can form %s: %i\n", cSet7, cSet6, formWord(cSet7, cSet6)); // 1
  // Testing 8.6
  printf("%s can form %s: %i\n", cSet4, cSet5, formWordWild(cSet4, cSet5)); // 1
  printf("%s can form  %s: %i\n", cSet4, cSet6, formWordWild(cSet4, cSet6)); // 0
  printf("%s can form %s: %i\n", cSet1, cSet2, formWordWild(cSet1, cSet2)); // 1
  printf("%s can form %s: %i\n", cSet1, cSet3, formWordWild(cSet1, cSet3)); // 0

}
