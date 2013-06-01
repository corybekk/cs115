/* Program: CS 115 Lab 8f

   Author: cory

   Description: This program computes a person's percent score over 

                    a number of variable-point assignments.  It reads

                    the earned score and total possible score for 

                    each assignment from a file.  The file must be 

                    formatted in a specific way.*/

#include <iostream>

#include <fstream>

using namespace std;

 

int InputNumScores(ifstream& input);

float ComputePctScore(ifstream& input, int numScores);

 

int main() 

{

  ifstream inputFile;  // Variable for input file

  int numScores;   // Number of scores stored in the input file

 

  // Call a function to open the input file 

  numScores = InputNumScores(inputFile); 

   

  // If there was an error reading the file, output a message and 

  // exit.

  if (numScores == -1) 

    {

      cout << "Could not read input file\n";

      return 0;

    }

   

  // Call a function to read the scores from the file and compute

  // the overall percentage score.

  cout << "Your percent is "

       << ComputePctScore(inputFile, numScores) << "%\n";

 

  // Close the input file

  inputFile.close();

  return 0;

}

 

/* Function: InputNumScores

 * Parameters: ifstream variable to use for open file. This variable should

 *    not currently be associated with any open files.

 * Return value: 0 if it successfully opens the file

 *    Returns -1 if it could not open the file.

 */

int InputNumScores(ifstream& input) 

{

  int numScores;

  string filename;

  cout << "Enter the filename: ";

  cin >> filename;

 
  input.open(filename.c_str());


  if (input.fail()) 

    {

      return -1;

    }

  return 0;

}

 

/* Function: ComputePctScore

 * Parameters:

 *    1. ifstream variable for input file.  This variable needs to

 *       be associated with an open file.

 *    2. the number of scores in the input file

 * Return value: the overall percent score

 */

float ComputePctScore(ifstream& input, int numScores) {

  int total_earned=0;    // Total points earned for all assignments

  int total_possible=0;  // Total points possible for all 

  // assignments

  int earned;            // Points earned on a single assignment

  int possible;          // Points possible on a single assignment

  float pct;             // Overall percent score

 

  // Read in lines from the file until nothing is left to read. 

  while (input >> earned >> possible) 

    {

      total_earned += earned;

      total_possible += possible;

    }

   

  pct = 100.0 * total_earned/total_possible;

  return pct;

}
