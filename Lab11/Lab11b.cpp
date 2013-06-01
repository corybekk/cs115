/* Program: CS 115 Lab 11b
   Author: cory bekker
   Description: This program should initialize a 2-D array
        and then print its elements twice: first by row, 
        and then by column.
*/
#include <iostream>
using namespace std;
 
// Define consts for the number of rows and the number of columns 
// here (See step 1)
 
const int rows = 4;
const int cols = 3;

int main() 
{
  int A[rows][cols];

  for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++) 
	{
	  A[r][c] = 3 * r + c;
	}
    }

  cout << "The rows of the array:\n";

  for (int r = 0; r < rows; r++) 
    {
      for (int c = 0; c < cols; c++) 
	{
	  cout << A[r][c] << '\t';
	}
      cout << endl;
    }

  cout << endl;
   
  cout << "The columns of the array:\n";

  for (int c = 0; c < cols; c++) 
    {
      for (int r = 0; r < rows; r++) 
	{
	  cout << A[r][c] << '\t';
	}
      cout << endl;
    }

  cout << endl;
   
  return 0;
}
