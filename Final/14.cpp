#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS =4; // dont forget to declare this
const int COLS =5;

bool MatchingRow (int N[][COLS], int rows, int cols);

int main(){

  int M[ROWS][COLS];

  for (int r = 0; r < ROWS; r++)
    {
      for (int c = 0; c < COLS; c++)
	{
	  M[r][c] = 1;
	}
    }


  for (int r = 1; r < ROWS; r++)
    { 
   for (int c = 1; c < COLS; c++)
      {      
	M[r][c] = M[r-1][c] + M[r][c-1];
	cout <<setw(10)<< M[r][c] << ' ';
      }
  cout << endl;
    }

  if (MatchingRow (M,ROWS,COLS))
    {
      cout << "There is a matching row in the array.\n";
    }

  return 0;

}

bool MatchingRow (int N[][COLS], int rows, int cols)
{
} 
  
 
    
      
