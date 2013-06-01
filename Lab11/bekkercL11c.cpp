/* Program: CS 115 Lab 11c
Author: cory bekker
Description: This program should use functions to initialize a 2-D 
             array and then print its elements twice: first by 
            row,and then by column.
*/
#include <iostream>
using namespace std;
 
// Define consts for the number of rows and the number of columns
// here (See step 1)
const int rows = 5; // shows the constant for how many rows there are.
const int cols = 7; // shows the constant for how many colums there are.
 
//Prototypes for functions
void InitArray (int B[][cols]); // prototype for the functions. 
void PrintByRows (int C[][cols]);
void PrintByColumns (int D[][cols]);
 
int main()
{
  // Declare array A here
  int A[rows][cols];
 
  // Call function to initialize array A here
  InitArray (A);
  cout << "The rows of the array:" << endl; 
  // Call function to print array A by rows
  PrintByRows (A);
  cout << "The columns of the array:" << endl; 
  // Call function to print array A by columns
  PrintByColumns (A);
 
  return 0;
}
 
// Implementations of functions
 
void InitArray (int B[][cols])
{
  for (int r = 0; r < rows; r++)// this function intializes the array to follow the equation 3 * r + c
    {
      for (int c = 0; c < cols; c++) 
	{
	  B[r][c] = 3 * r + c;// equation that shows what numbers are in the arrays.
	}
    }
}
void PrintByRows (int C[][cols])// this function prints the arrays rows first.. horizontal.
{
  for (int r = 0; r < rows; r++) 
    {
      for (int c = 0; c < cols; c++) 
	{
	  cout << C[r][c] << '\t'; // prints out the array numbers 
	}
      cout << endl;
    }
}
 
void PrintByColumns (int D[][cols])// this function prints the arrays colums... vertical.
{
  for (int c = 0; c < cols; c++)// reads the next c[] once the 2nd for loop fails   
    {
      for (int r = 0; r < rows; r++)// reads all the r[] until it fails and goes back to the first for 
	{
	  cout << D[r][c] << '\t';
	}
      cout << endl;
    }
}
