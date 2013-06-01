/* Program: CS 115 Lab 9b

   Author: Cory bekker

   Description: This program should initialize an array

        and then print its elements twice: once in order,

        and once in reverse order.

   This version of the program has a bug.

*/

#include <iostream>

using namespace std;

 

const int ARR_SIZE = 5;

 

void InitArray(int array[], int size);

void PrintArray(int array[], int a, int b);

int TotalArray(int array[], int A, int B);
 



int main() 

{

  int numbers[ARR_SIZE]= {1, 3, 5, 7, 9}; // Declare array of numbers

  /*  InitArray(numbers, ARR_SIZE);*/ // Call function to initialize array

 

  PrintArray(numbers, 0, ARR_SIZE-1); // Print array in order

  PrintArray(numbers, ARR_SIZE-1, 0); // Print array in reverse order

  cout << "The Total:" << TotalArray(numbers,0, ARR_SIZE-1) << endl;

 


  return 0;

}

 

/* Function: InitArray

   Parameters: an integer array (array)

      and the number of elements it contains (size).

   Return value: none

   Initializes all the elements of the array according to the    

   Following formula: element i = 1 + 2*i

*/

void InitArray(int array[], int size) 

{

  for (int i=0; i < size; i++) 

    {

      array[i] = 1 + 2 * i;

    }

}

 

/* Function: PrintArray

   Parameters:

      - an integer array (array)

      - the subscript to start printing at (a)

      - the subscript to stop printing at (b)

   Return value: none

   Should print all array elements with subscripts

      between a and b (inclusive)

   If a <= b, should print elements in ascending order

   Otherwise, should print elements in descending order

   

   NOTE: This is the description of what the function SHOULD

   do -- not necessarily what it's doing right now!

*/

void PrintArray(int array[], int a, int b) 

{

  cout << "Array of numbers:\n";

   

  // If a <= b, print in ascending order

  if (a <= b) 

    {

      // Loop 1

      for (int i=a; i <= b; i++) 

	{

	  cout << i << ": " << array[i] << '\t';

	}

    }

  // Otherwise, print in descending order

  else 

    {

      // Loop 2

      for (int i=a; i >= b; i--) 

	{

	  cout << i << ": " << array[i] << '\t';

	}

    }

  cout << endl;

}


int TotalArray(int array[], int A, int B)
{
int total = 0;

for (int i=A; i <= B; i++)

  {

    total += array[i];

  }
return total;

}
