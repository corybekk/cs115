/* Program: CS 115 Lab 10d
   Author: Cory Bekker
   Description: This program will initialize and print an array.
*/

#include <iostream>
using namespace std;

const int ARR_SIZE = 10;
const int LAST_SUBSCRIPT = (ARR_SIZE-1); // Subscript of the last element

void InitArray(int array[], int size);
void PrintArray(int array[], int size);
void Swap(int & a, int & b);

int main() 
{
  int numbers[ARR_SIZE]; // Declare array of numbers
  InitArray(numbers, ARR_SIZE); // Initialize array
  PrintArray(numbers, ARR_SIZE); // Print array
  Swap(numbers[0], numbers[1]);
  PrintArray(numbers, ARR_SIZE); // Print array again
  return 0;
}
/* Function: Swap
 * Parameters: Two integers
 * Swaps the values of the two integers
 * THIS CODE IS WRONG!!!
 */
void Swap(int & a, int & b) 
{
  b = a;
  a = b;
}

/* Function: InitArray
   Parameters: an integer array (array)
      and the number of elements it contains (size).
   Return value: none
   Initializes all the elements of the array according to the following
      formula: element i = 3*i-1
*/
void InitArray(int array[], int size) 
{
  for (int i = 0; i < size; i++) {
    array[i] = 3 * i - 1;
  }
}
/* Function: PrintArray
   Parameters:
      - an integer array (array)
      - the number of elements it contains (size)
   Return value: none
   Should print all array elements with subscripts
      between 0 and (size-1), inclusive
*/
void PrintArray(int array[], int size) 
{
  cout << "Array of numbers:\n";
 
  for (int i=0; i < size; i++) 
    {
      cout << i << ": " << array[i] << '\t';
    }
  cout << endl;
}
