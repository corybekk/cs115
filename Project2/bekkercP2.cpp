// File :
// Project : CS 115 Project 2 - Hangman
// Author : Cory Bekker
// Date : Fall 2010
// Description : Allows a person to play a game of Hangman.


#include <iostream>

using namespace std;

const int MAX_MISSES = 10;  // constant to hold maximum number of misses
string GetSecretWord ();   // Prototype for function to get a secret word
void Display (int misses); // Prototype for function to display the gallows                                                                                                        

int main () {

  int misses;
  string word;
  string response;

  cout << endl;
  cout << " The main goal of Hangman is to find the missing word.";
  cout << " The player(you) will have 10 guesses to find the missing word.";
  cout << " Each time the player picks the correct letter, it will be inserted";
  cout << " into one of the blank lines. If the player chooses the wrong letter";
  cout << " then another piece of the hangman will appear." << endl;

  cout << endl;
  cout << endl;
  cout << " Welcome...." << endl << endl;
  cout << " Are you ready to play? (yes or no)" << ' ';
  cin >> response;

  for(int i = 0; i < response.size(); i++)
    {
      response[i] = toupper(response[i]); //makes anything entered a capital
    }
 



  while (response == "YES")
    {
      int misses = 0;
      string blanks;
      char guess;
      string bad;
     
      word = GetSecretWord();

      for ( int i=1; i <= word.size(); i++)
	{
	  blanks += '_';
	}

      int good = word.size();


      while (good > 0 && misses < MAX_MISSES)
	{
	  Display (misses);
      
	  for (int i = 0; i < blanks.size(); i++)
	    {
	     
	     cout <<  blanks[i] << ' ';
	 
	    }

	 

	  cout << endl << endl;
	  cout << " You have guesed:\n";
	  cout << ' ' << bad << endl;
	  cout << " What letter do you choose?" << ' '<< endl;	 
	  cout << ' ';
	  cin >> guess;
	
	  guess = toupper (guess);

	  bool found = false;

	  for (int i=0; i < word .size(); i++)
	    {
	      if (word[i] == guess)
		{
		  good--;
		  found = true;
		  blanks[i] = guess;
		}
	    }
	  if (found == false)
	    {
	      misses++;
	      bad += guess;
	    }                
	}
    
      if (misses == MAX_MISSES){
	cout << " YOU LOST! the word was:" <<' '<< word << endl << endl;
      }
      else {
	cout << " YOU WIN!!!!!!! the word was:" << ' ' << word << endl;
      }
     
      cout << " Would you like to play again? (yes or no)" << ' ';
     
      cin >> response;

      for (int i = 0; i < response.size(); i++)
	{
	  response[i] = toupper(response[i]);

	}
      cout << " Goodbye....." << endl;

    }



  return 0;

}








#include <ctime>
#include <fstream>
#include <cstdlib>

string GetSecretWord ()
// This function will get a word from the secret word file                                                                                                                         
{
  // Declare and open the file of secret words                                                                                                                                     
  ifstream file ("/home/faculty/tiawatts/cs115pickup/p2words.txt");
  // Declare a varaible to hold the number of words                                                                                                                                
  int numwords = 1;
  // Declare a varaible to hold a random number                                                                                                                                    
  int whichword = 0;
  // Declare a variable to hold the selected word                                                                                                                                  
  string word = "RANDOM";
  // Initialize the random number generator                                                                                                                                        
  srand (time (NULL));
  // Read in the number of words                                                                                                                                                   
  file >> numwords;
  // Calculate a random number >= 0 amd < the number of words                                                                                                                      
  whichword = rand() % numwords;
  // Loop to read the file                                                                                                                                                         
  do
    {
      // Read a word from the file                                                                                                                                           
      file >> word;
      // Decrement the counter                                                                                                                                               
      whichword--;
      // Stop reading when the counter hits 0                                                                                                                                
    } while (whichword > 0);
  // Close the file                                                                                                                                                          
  file.close();
  // Return the selected word                                                                                                                                                
  return word;
}

void Display (int misses)
// This function will print the hangman gallows                                                                                                                                    
{
  // Declare and initialize the display                                                                                                                                            
  string display [] = {"       |------|       ",
                       "       |      |       ",
                       "       O      |       ",
                       "      /|\\     |       ",
                       "       |      |       ",
                       "      / \\     |       ",
                       "     /   \\    |       ",
                       "              |       ",
                       "            -----     ",
		       "            |   |     ",
                       "          ---------   ",
                       "          |       |   "};

  // Block out the parts of the display that are not needed                                                                                                                        
  if (misses < 1)
    display [2][7] = ' ';
  if (misses < 2)
    display [3][7] = ' ';
  if (misses < 3)
    display [3][6] = ' ';
  if (misses < 4)
    display [3][8] = ' ';
  if (misses < 5)
    display [4][7] = ' ';
  if (misses < 6)
    display [5][6] = ' ';
  if (misses < 7)
    display [5][8] = ' ';
  if (misses < 8)
    display [6][5] = ' ';
  if (misses < 9)
    display [6][9] = ' ';
  // Print the lines of the display                                                                                                                                                
  for (int i = 0; i < 12; i++)
    cout << display[i] << endl;
}







