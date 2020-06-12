/** Chapter 9 Notes/Exercises: Structures **/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define true 1;
#define false 0;

// Example of a struct--usually defined after #includes before primary code
typedef struct {
  double x; // x attribute
  double y; // y attribute
} Point; // Name of specific struct

// Making a struct to represent a rectangle
typedef struct {
  double width; // Rectangle width
  double height; // Rectangle height
  Point botLeft; // Bottom leftmost point
} Rectangle;

/**
Notes
- Compound type: data types made up of smaller pieces
  - Ex: strings, which are comprised of an array of chars
- Possible to create our own compound types using typedef struct
- Passing a structure in as a parameter for a function uses call-by-value
  - A copy w/ same initial value is passed into the function
- Actually changing the parameter requires explicitly passing parameter by reference
- Advantages/disadvantages of passing structures by reference:
  - Allows for modification of the original structure
  - Faster (doesn't require copying over the entire structure)
  - Less "safe": may make modifications without being aware of them
- When passing struct or call-by-reference as parameter:
  - Make sure to use & operator to give pointer, and not the object itself
  - Make sure to use * operator to refer to the pointer in parameter
  - Within function, * operator can give value-at-address
- typedef struct can only contain 1 array/datatype of non-fixed size
  - Can use * (pointer-notation) unlimitedly--also affects strings
- Cannot use variables defined in a typedef struct syntax to define other variables
  - Say, an int length variable is defined in struct. It can't be used to give
    an array in that same struct a size
**/

// Function that takes Point_t type as input
void printCoordinates(Point pt) {
  printf("X coordinate: %f\n", pt.x);
  printf("Y coordinate: %f\n", pt.y);
}

// Function that finds distance b/w 2 point objects
double distance(Point pt1, Point pt2) {
  return sqrt(pow(pt1.x-pt2.x, 2) + pow(pt1.y-pt2.y, 2));
}

// Not passing struct as reference --> No modification of original value
void fakeChangePoint(Point pt) {
  pt.x += 1;
  pt.y += 1;
  printCoordinates(pt);
}

// Passing pointer to Point object --> original value of struct is changed
void realChangePoint(Point *pt) {
  // Accessing struct attributes via point requires -> "pointing-to" operator
  // Replaces the . "field-selection operator" normally used
  pt->x = pt->x + 1;
  pt->y = pt->y - 1;
}

// Function to find the area of a rectangle
// Convention dictates passing by reference for struct's
double rectangleArea(Rectangle *r) {
  return r->width * r->height;
}

// Function to find perimeter of a rectangle
double rectanglePerimeter(Rectangle *r) {
  return 2 * (r->width + r->height);
}

// Function that prints all the points of the rectangle
void printAllPoints(Rectangle *r) {
  printf("Bottom left: (%0.2f, %0.2f)\n", r->botLeft.x, r->botLeft.y);
  printf("Bottom right: (%0.2f, %0.2f)\n", r->botLeft.x + r->width, r->botLeft.y);
  printf("Top left: (%0.2f, %0.2f)\n", r->botLeft.x, r->botLeft.y + r->height);
  printf("Right top: (%0.2f, %0.2f)\n", r->botLeft.x + r->width, r->botLeft.y + r->height);
}

// Function that returns a struct--return point at center of a rectangle
Point rectangleCenter(Rectangle *r) {
  double x = r->botLeft.x + r->width/2;
  double y = r->botLeft.y + r->height/2;
  Point center = {x, y};
  return center;
}

// Function that changes the values of integers using pass by reference
// Integers can also be called by reference
void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

/** Note: these exercises will be my *own* creations b/c the book's are not
    comprehensive in the slightest. **/

/**
Exercise 9.1
Create a struct to represent a circle.
Then, create functions to do the following:
 --> Find the area
 --> Find the circumfrence
 --> Compare equality b/w 2 circle objects
**/

// Structure to represent a circle: just need its radius
typedef struct {
  double radius;
} Circle;

// Function to compute area of a circle
double circleArea(Circle *c) {
  return acos(-1) * pow(c->radius, 2); // acos(-1) = pi
}

// Function to compute the circumfrence of a circle
double circleCircumfrence(Circle *c) {
  return 2 * acos(-1) * c->radius;
}

// Function to compare whether 2 circles are the "same" using radius
int equalCircles(Circle *c1, Circle *c2) {
  if (c1->radius == c2->radius) {
    return true;
  }
  return false;
}


/**
Exercise 9.2
Create a struct to represent a person with the following attributes:
  - First name, last name, age, birthday
  - Identity: Create a function to print out a person's "information"
  - Happy birthday: Create a function to advance a person's birthday
  - Is it birthday?: Create a function that checks whether or not the given date
    for a person's name is their given BDAY
**/

// struct for a basic person's attributes
typedef struct {
  char *firstName;
  char *lastName;
  int age;
  char *birthday;
} Person;

// Function that prints out the identifying information about a person
void identity(Person *p) {
  printf("Name: %s %s\n", p->firstName, p->lastName);
  printf("Age: %i\n", p->age);
  printf("Birthday: %s\n", p->birthday);
}

// Function that checks whether or not it's a person's BDAY
int isBDAY(Person *p, char bday[]) {
  if (strcmp(p->birthday, bday) == 0) {
    return true;
  }
  return false;
}

// Given a date and a person, advance their age if it's their birthday
void happyBirthday(Person *p, char date[]) {
  if (isBDAY(p, date)) {
    p->age++;
  }
}



/**
Exercise 9.3
Create a struct to represent US cities and representative information
  - Attributes: name, population, state
  - Create a way to store new instances of the city struct
    - Create a function that prints out all the cities' information
    - Create a function that sorts the cities by population (descending)
**/

// Struct containing the information about a city
typedef struct {
  char *name;
  char *state;
  int population;
} City;

// Function to print city information for convenience
void printCityInfo(City c) {
  printf("Name: %s, ", c.name);
  printf("State: %s, ", c.state);
  printf("Population: %i\n", c.population);
}

// Cannot determine the length of an array--so it needs to be passed in
void sortCity(City *cities, int length) {
  for (int i = 0; i < length; i++) {
    int locMax = i;
    City cityMax = cities[i];
    for (int j = i; j < length; j++) {
      // printf("cities[j] pop: %i at %i\n", cities[j].population, j);
      // printf("cityMax pop: %i\n", cityMax.population);
      if (cities[j].population > cityMax.population) {
        cityMax = cities[j];
        locMax = j;
      }
    }
    // printf("MAX LOC: %i\n", locMax);
    City tempCity = cities[i];
    cities[i] = cityMax;
    cities[locMax] = tempCity;
  }
}



/**
Exercise 9.4
A teacher wants to digitize their gradebook (containing the results for the students'
homework, midterm1, midterm2, and final grade--weighted 10%, 20%, 20%, 50% respectively).
  - Create a struct to represent the student (name + performance)
  - Create a struct to represent the gradebook
  - Functions to find the top student + lowest student
  - Function that computes relevant statistics for the teacher: mean/median/standard deviation
**/

// struct to represent a student's information
typedef struct {
  char *name;
  double hwScore;
  double mt1;
  double mt2;
  double final;
} Student;

void printStudentInfo(Student s) {
  printf("Name: %s, ", s.name);
  printf("Homework: %0.2f, ", s.hwScore);
  printf("Midterm 1: %0.2f, ", s.mt1);
  printf("Midterm 2: %0.2f, ", s.mt2);
  printf("Final: %0.2f\n", s.final);
}

double calculateGrade(Student *s) {
  return 0.1 * s->hwScore + 0.2*s->mt1 + 0.2*s->mt2 + 0.5*s->final;
}

// struct to represent a compilation of all student information--TBC
/* Note to self: can a struct be used as an array of structs? */
typedef struct {
  int numStudents;
  Student *students;
} Gradebook;

// Calculate mean grade from the gradebook
double calculateMeanGrade(Gradebook *gradebook) {
  double totalGrade = 0;
  for (int i = 0; i < gradebook->numStudents; i++) {
    totalGrade += calculateGrade(&gradebook->students[i]);
  }
  return totalGrade/gradebook->numStudents;
}

// Calculate the standard deviation from the gradebook
double calculateStdDev(Gradebook *gradebook) {
  double stdDev = 0;
  double mean = calculateMeanGrade(gradebook);
  for (int i = 0; i < gradebook->numStudents; i++) {
    double studentGrade = calculateGrade(&gradebook->students[i]);
    stdDev += pow(studentGrade-mean, 2);
  }
  stdDev = sqrt(stdDev/gradebook->numStudents);
  return stdDev;
}

// Find the worst performing student
Student worstStudent(Gradebook *gradebook) {
  double worstScore;
  Student worstStudent = gradebook->students[0];
  worstScore = calculateGrade(&worstStudent);
  for (int i = 0; i < gradebook->numStudents; i++) {
    double score = calculateGrade(&gradebook->students[i]);
    if (score < worstScore) {
      worstScore = score;
      worstStudent = gradebook->students[i];
    }
  }
  return worstStudent;
}

// Find the highest performing student
Student bestStudent(Gradebook *gradebook) {
  double bestScore;
  Student bestStudent = gradebook->students[0];
  bestScore = calculateGrade(&bestStudent);
  for (int i = 0; i < gradebook->numStudents; i++) {
    double score = calculateGrade(&gradebook->students[i]);
    if (score > bestScore) {
      bestScore = score;
      bestStudent = gradebook->students[i];
    }
  }
  return bestStudent;
}

int main() {

  // Creating an instance of our struct
  Point point1;
  point1.x = 5.0; // Dot notation assigns attributes to our object
  point1.y = 6.0;

  // Accessing attributes of struct
  printf("X coordinate: %f\n", point1.x);
  printf("Y coordinate: %f\n", point1.y);

  // Alternate initialization--Both are VALID
  Point point2 = {3.0, 3.5};
  Point point3;
  point3 = (Point) {7.5, 1.5}; // Requires typecasting
  /**
  INVALID WAY
  Point samplePoint;
  samplePoint = {3.0, 3.5};
  **/

  // Testing printCoordinates function
  printCoordinates(point1);
  printCoordinates(point2);
  printCoordinates(point3);

  // Testing distance function
  printf("Distance from (%f, %f) to (%f, %f) is: %f\n",
    point1.x, point1.y, point2.x, point2.y, distance(point1, point2));
  printf("Distance from (%f, %f) to (%f, %f) is: %f\n",
    point3.x, point3.y, point1.x, point1.y, distance(point3, point1));
  printf("Distance from (%f, %f) to (%f, %f) is: %f\n",
    point2.x, point2.y, point3.x, point3.y, distance(point2, point3));

  // Illustrating call-by-value w/ Point structure
  fakeChangePoint(point1);
  printCoordinates(point1); // x & y attributes were not affected by function above
  realChangePoint(&point1); // Use the address of operator (&) to obtain pointer
  printCoordinates(point1); // Shows we've got a lasting change

  // Testing rectangle functions
  Rectangle r1 = {4.0, 8.0, point1};
  printf("Area of r1 is: %0.1f\n", rectangleArea(&r1)); // 0.1 limits digits after decimal point to 1
  printf("Perimeter of r1 is: %0.1f\n", rectanglePerimeter(&r1));
  printAllPoints(&r1);

  // Alternative way to declare Rectangle object
  Rectangle r2 = {6.0, 3.0, {5.0, -1.0}}; // Point + Rectangle are declared simultaneously
  printAllPoints(&r2);

  // Testing center
  Point p1 = rectangleCenter(&r1); // Again, make sure to pass in address (as pointer)
  Point p2 = rectangleCenter(&r2);
  printf("Center of r1: (%0.2f, %0.2f)\n", p1.x, p1.y);
  printf("Center of r2: (%0.2f, %0.2f)\n", p2.x, p2.y);

  // Testing swap: call by reference w/ integers
  int x = 10;
  int y = 5;
  printf("(x, y) is: (%i, %i)\n", x, y);
  swap(&x, &y);
  printf("(x, y) now is: (%i, %i)\n", x, y);

  // Testing 9.1
  printf("\n\nEXERCISES\n");
  Circle c1 = {4.0};
  Circle c2 = (Circle){1.0};
  Circle c3;
  c3.radius = 6.0;
  Circle c4 = {6.0};
  printf("Area of c1 is: %f\n", circleArea(&c1));
  printf("Area of c2 is: %f\n", circleArea(&c2));
  printf("Area of c3 is: %f\n", circleArea(&c3));
  printf("Circumfrence of c1 is: %f\n", circleCircumfrence(&c1));
  printf("Circumfrence of c2 is: %f\n", circleCircumfrence(&c2));
  printf("Circumfrence of c3 is: %f\n", circleCircumfrence(&c3));
  printf("Circle c1 == Circle c2? %i\n", equalCircles(&c1, &c2));
  printf("Circle c3 == Circle c4? %i\n", equalCircles(&c3, &c4));
  printf("Circle c1 == Circle c1? %i\n", equalCircles(&c1, &c1));

  // Testing 9.2
  Person person1 = {"Adam", "Smith", 25, "October 1"};
  Person person2 = {"Stacy", "Adams", 77, "June 22"};
  Person person3 = {"Jessie", "Zheng", 14, "January 13"};
  Person person4 = {"Mo", "Ishmael", 19, "February 5"};
  identity(&person1);
  identity(&person2);
  identity(&person3);
  printf("Is October 1 person1's BDAY? %i\n", isBDAY(&person1, "October 1"));
  printf("Is October 2 person1's BDAY? %i\n", isBDAY(&person1, "October 2"));
  printf("%s %s is %i years old. It is %s. ", person2.firstName, person2.lastName,
          person2.age, "June 22");
  happyBirthday(&person2, "June 22");
  printf("%s %s is now %i years old. \n", person2.firstName, person2.lastName,
          person2.age);
  printf("%s %s is %i years old. It is %s. ",
          person2.firstName, person2.lastName, person2.age, "January 1");
  happyBirthday(&person2, "January 1");
  printf("%s %s is now %i years old. \n",
          person2.firstName, person2.lastName, person2.age);

  // Testing 9.3
  int MAX_CAPACITY = 10;
  City SanDiego = {"San Diego", "CA", 1300000};
  City NYC = {"NYC", "NY", 8500000};
  City LA = {"LA", "CA", 3700000};
  City Chicago = {"Chicago", "IL", 2400000};
  City Atlanta = {"Atlanta", "GA", 2100000};
  City Houston = {"Houston", "TX", 1100000};
  City SF = {"SF", "CA", 1500000};
  // Representing the cities in an array
  City cities[MAX_CAPACITY];
  cities[0] = SanDiego;
  cities[1] = NYC;
  cities[2] = LA;
  cities[3] = Chicago;
  cities[4] = Atlanta;
  cities[5] = Houston;
  cities[6] = SF;
  printf("Cities pre-sort\n");
  for (int i = 0; i < 7; i++) {
    printCityInfo(cities[i]);
  }
  // printf("%s\n", cities[0].name); // Correctly identifies city as San Diego
  // printf("%s\n", cities[5].name); // By default, array value is null
  printf("Cities post-sort\n");
  sortCity(cities, 7);
  for (int i = 0; i < 7; i++) {
    printCityInfo(cities[i]);
  }

  // Testing 9.4
  Student st0 = {"Sally", 100.0, 95.0, 92.0, 80.0};
  Student st1 = {"George", 95.0, 80.0, 72.0, 85.0};
  Student st2 = {"Anne", 98.0, 99.0, 97.0, 94.0};
  Student st3 = {"Michael", 100.0, 40.0, 36.0, 50.0};
  Student st4 = {"Jason", 85.0, 75.0, 82.0, 88.0};
  Student st5 = {"Blake", 93.0, 92.0, 88.0, 88.0};
  int maxClassSize = 6;
  Student students[maxClassSize];
  students[0] = st0;
  students[1] = st1;
  students[2] = st2;
  students[3] = st3;
  students[4] = st4;
  students[5] = st5;
  Gradebook gradebook = {6, students};
  //printf("%s", gradebook.students[0].name);
  for (int i = 0; i < maxClassSize; i++) {
      printStudentInfo(gradebook.students[i]);
      printf("Overall grade for %s is: %0.2f\n", gradebook.students[i].name,
              calculateGrade(&gradebook.students[i]));
  }
  printf("\nOVERALL STUDENT STATS\n");
  printf("Mean grade for all students is: %0.3f\n", calculateMeanGrade(&gradebook));
  printf("Standard deviation: %0.3f\n", calculateStdDev(&gradebook));
  printf("Best student: ");
  printStudentInfo(bestStudent(&gradebook));
  printf("Worst student: ");
  printStudentInfo(worstStudent(&gradebook));

}

/**
Note to self: research malloc/alloc
- Other stuff to look into:
  - What does ** notation mean?
    - Ex: int **num
  - Representing linked lists/trees
  - Representing other "data types" in C
  - struct vs. typedef struct
  - sizeof(array)--working with dynamically vs. statically typed arrays
**/
