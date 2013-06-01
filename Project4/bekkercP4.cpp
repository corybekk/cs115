/* Project: Project4
 * Author: Cory Bekker
 * Date:December 02,2010
 * Description: A puzzle game where the player must get all numbers in ascending order.
*/

#include <iostream>
#include <cstdlib>
#include <iomanip> // alows setw

using namespace std;

const int SIZE = 4;


class Puzzle
{
    public:
	Puzzle();
        void PrintDirections ();
	void Initialize ();
	void Scramble ();
	void Print ();
	bool Move (char direction);
	bool IsDone ();
    private:
	int Tiles [SIZE][SIZE];
	int ShouldBe [SIZE][SIZE];
	int BlankRow, BlankCol;
};


/* Function: main 
 * Parameters: none
 * Description: this is the main function for the program. It will
*/
int main ()
{
  Puzzle puzzle;// class
  puzzle.PrintDirections();//calls PrintDirections, and prints directions
  puzzle.Scramble();//calls Scramble, which scrambles the numbers
  while (puzzle.IsDone() == false)// stays false until the game is won
	{
	  puzzle.Print();//prints the game

		cout << "Which direction would you like to move? ";
		char direction; // W A S D input
		cin >> direction;
		if (puzzle.Move(direction) == false) //if the puzzle moves out of bounds
		{
			cout << "Invalid move - please try again\n";
		}

	}
	puzzle.Print();
	cout << "Congratulations!" << endl;
	return 0;
}

//================================================================ 
 
/* Function: puzzle 
 * Parameters:None
 * Description:This constructor function should initialize the puzzle by calling the
Initialize function.
*/
Puzzle::Puzzle()
{
  Initialize(); // starts the game by intializing it.
}
//================================================================
/* Function:PrintDirections
 * Parameters:None
 * Description:This function should print (to cout) directions for
playing the puzzle.
*/
void Puzzle::PrintDirections ()
{
  cout << endl;
  cout <<"The goal of the puzzle is to get all the numbers\n";
  cout <<"in ascending order from left to right. Use the\n";
  cout <<"A S D W keys to move the numbers around and press enter.\n";
  cout <<"Also try to get the blank square in the bottom right corner."<< endl;
  cout << endl;
}
//===============================================================
/* Function:Initialize
 * Parameters:non
 * Description:This function should Initialize the puzzle by setting the
values in the Tiles and ShouldBe arrays to 1 to SIZE*SIZE as illustrated above.
The SIZE*SIZE value will be used to indicate the position of the empty space.
The BlankRow and BlankCol variables should be initialized to SIZE-1.
*/
void Puzzle::Initialize ()
{

  int numPosition =1;
  BlankRow = SIZE-1;
  BlankCol = SIZE-1;

  for(int i=0; i<SIZE; i++)// makes it count all the positions in the 2d array
    {
      for (int j=0; j<SIZE; j++)
	{
	  Tiles[i][j]= numPosition;// makes each position have a number
	  ShouldBe[i][j] = numPosition;
	  numPosition++;
	}
    }
}
//==============================================================
/* Function: Swap
 * Parameters: int a and b are the paramenters. they swap the Tiles[][] positions
 * Description: This function swaps two variables. 
*/
void Swap (int & a, int & b)
{
  int t= a; // swaps two variables
  a = b;
  b = t;
}
//==============================================================
/* Function:Scramble 
 * Parameters:None
 * Description:This function should call the Move function repeatedly to
move the numbers stored in the Tiles array.
*/
void Puzzle::Scramble ()
{
  srand(time(NULL));// allows for srand, which picks random numbers
 
  int Random =0;
  for (int i =0; i< 10000; i++)// 10,000 times to guarrantee full scramble
	{
	  Random = 1+ rand() % 4;// picks a number 1-4 randomly 10,000 times
	  if(Random == 1 )// if the number is 1, then it will swap two positions in the Move function
	    Move ('d');   // this connects it to the move function 'd'
	  if(Random == 2)
	    Move ('s');
	  if(Random == 3)
	    Move ('a');
	  if(Random == 4)
	    Move ('w');
	}
}

//=============================================================
/* Function: Print
 * Parameters:none
 * Description:This function should print (to cout) the values stored in the
Tiles array in a nicely formatted manner.
*/
void Puzzle::Print ()
{
  {
    cout << "+------+------+------+------+" << endl; // makes the top line of the game
    for(int i = 0; i < SIZE; i++)
      {
	cout << "|      |      |      |      |" << endl; // makes the column lines
	cout << "|";
	        for (int j = 0; j < SIZE; j++) 
	       {
		 if(Tiles[i][j] == SIZE*SIZE)// makes blank spot on game
		   {
		     cout << "      |";
		   }
		 else
		   {
		     cout << setw(4) <<Tiles[i][j] << setw(3) << "|"; // Sets the numbers 4 spaces
		   }
	       }
	cout << endl;
	cout << "|      |      |      |      |" << endl;
	cout << "+------+------+------+------+" << endl; // makes bottom line
      }
  }
}
//=============================================================
/* Function: Move
 * Parameters:char direction, which is W A S D 
 * Description:This function will call the Swap function to
move a tile adjacent to the blank space in the provided direction. If a tile can be
moved, the function will return true. If not, it will return false.
*/
bool Puzzle::Move (char direction)
{
 
  if( direction == 'w' and  BlankRow +1 < SIZE)
    {   
      Swap(Tiles[BlankRow][BlankCol], Tiles[BlankRow +1][BlankCol]);// swaps down
      BlankRow++;// keeps track of the empty space
      return true;// return true making the move valid    
    }
     
  else if( direction == 's' and BlankRow-1 >= 0)
    {
      Swap(Tiles[BlankRow][BlankCol], Tiles[BlankRow-1][BlankCol]);// swaps up
	     BlankRow--;
	     return true;    
    }
	
  else if( direction == 'd' and BlankCol-1 >= 0)
    {  
      Swap(Tiles[BlankRow][BlankCol], Tiles[BlankRow][BlankCol-1]);// swaps left
	     BlankCol--;
	     return true;    
    }   	   
	   
  else if( direction == 'a' and  BlankCol+1 < SIZE)
    {    
      Swap(Tiles[BlankRow][BlankCol], Tiles[BlankRow][BlankCol+1]);// swaps right
	     BlankCol++;
	     return true;      
    }		  
  	        
	return false; // return false if move is invalid
	   
}	  

//============================================================
/* Function: IsDone
 * Parameters: none
 * Description:This function will return true if all of the tiles are in the
correct spaces; otherwise it will return false. The easiest way to determine if all lf
the tiles are in the correct spaces is to check if every element in the Tiles array
matches the corresponding elelemnt in the ShouldBe array.
*/
bool Puzzle::IsDone ()
{
  for(int Row=0; Row<SIZE; Row++)// goes through the whole grid
    {
      for(int Col=0; Col<SIZE; Col++)
	{
	  if(ShouldBe[Row][Col] != Tiles[Row][Col])// checks if each position matches 
	    {                                      //the correct number for game over.
		     return false;
		   }
	}
    }
  return true;
}
  
