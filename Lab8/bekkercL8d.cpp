
   /* Program: CS 115 Lab 8d

   Author: Cory

   Description: This program reads questions from an input file and quizzes the user.

   */

#include <iostream>

#include <fstream>

#include <string>

#include <cstdlib>

   using namespace std;

 

void OpenInputFile(ifstream& infile);

bool AskQuestion(ifstream& input);

bool PrintQuestion(ifstream& input);

void CheckAnswer(char answer, char guess);

 

int main () 

{

  ifstream input;          // Variable for reading input file

  OpenInputFile(input);    // Open the input file

  AskQuestion(input);      // Ask one quiz question to the user

  bool more = true;

  while (more == true){ 

    more = AskQuestion(input);
      }


  input.close();

  return 0;

}

 

/* Function: OpenInputFile

 * 

 * Opens the file problems.in and associates it with an ifstream variable.

 * Prints an error message and exits the program if file cannot be opened.

 * 

 * Parameters:

 *   - ifstream variable to use for the open file. This variable should

 *    not currently be associated with any open files.

 * 

 */

void OpenInputFile(ifstream& infile) 

{

  infile.open("problems.in");

  if (infile.fail())    {

    cout << "Could not open problems.in\n";

    exit(1);

  }

}

 

/* Function: AskQuestion

 * Parameters: ifstream variable associated with problems.in

 *

 * Reads one question and its multiple answer choices from the file,

 *   gets the user's answer, and compares the user's answer to 

 *   the correct answer.

 *

 * Return value: true if input file could be read, false otherwise.

 */

bool AskQuestion(ifstream& input){

  string line;             // line of input file

  char   answer, guess;    // correct answer and user's guess

 

  // If we couldn't read a question

  if (!PrintQuestion(input))   {

    return false;

  }

   

  // Get the answer from the file

  input >> answer;

  getline(input, line);

 

  // Get the user's guess

  cout << "Enter the correct answer: ";

  cin >> guess;

  CheckAnswer(answer, guess);

 

  return true;

}

 

/* Function: PrintQuestion

 * Parameters: ifstream variable associated with problems.in

 *

 * Reads and prints 5 lines of the file: one for the question and 

 *    4 for the multiple-choice selections.

 *

 * Return value: true if input file could be read, false otherwise.

 */

bool PrintQuestion(ifstream& input)

{

  string line; // line of the input file

 

  getline(input, line);

 

  // Return if input file could not be read

  if (input.fail())   

    {

      return false;

    }

   

  // Print out the question and the 4 answer choices

  cout << line << endl;

 

  for (int i=0; i<4; i++)   

    {

      getline(input, line);

      cout << line << endl;

    }

  return true;

}

 

/* Function: CheckAnswer

 * Parameters: the correct answer and the user's guess

 * Prints a congratulatory message if the user's guess matches the correct answer.

 * Otherwise, prints a message correcting the user.

 */

void CheckAnswer(char answer, char guess) 

{

  if (guess == answer)   

    {

      cout << "Correct!\n";

    }

  else   

    {

      cout << "Incorrect. The correct answer is " 

	   << answer << ".\n";

    }

}
