
   /* Program: CS 115 Lab 8d

   Author: Cory

   Description: This program reads questions from an input file and quizzes the user.

   */

#include <iostream>

#include <fstream>

#include <string>

#include <cstdlib>

   using namespace std;

const int MAX_QUESTIONS = 10;

int ReadQuestions (ifstream & infile, string Q[], string A[], string B[], string C[], string D[], char R[]); 
void OpenInputFile(ifstream& infile);
void PrintQuestion(string Question, string aAnswer, string bAnswer, string cAnswer,

		   string dAnswer);
bool AskQuestion(string Q[], string A[], string B[], string C[], string D[], char R[]);
bool CheckAnswer(char answer, char guess);

int main () 

{
  int correct = 0;
  ifstream input;                      // Variable for reading input file
  string Questions [MAX_QUESTIONS];    // Array to hold questions
  string aAnswers [MAX_QUESTIONS];     // Array to hold a. answers
  string bAnswers [MAX_QUESTIONS];     // Array to hold b. answers
  string cAnswers [MAX_QUESTIONS];     // Array to hold c. answers
  string dAnswers [MAX_QUESTIONS];     // Array to hold d. answers
  char Right [MAX_QUESTIONS];          // Array to hold correct answers to the questions
 int number = 0;                      // Variable to hold the number of questions

  OpenInputFile(input);                // Open the input file

   // Read all of the questions from the input file into
  // the arrays and store the number of questions in number

  number = ReadQuestions (input, Questions, aAnswers, bAnswers, cAnswers, dAnswers, Right);

  // Ask one quiz question and increment correct if it the user answers it correctly

  if (AskQuestion(Questions, aAnswers, bAnswers, cAnswers, dAnswers, Right))

    correct++;          // Ask one quiz questions until AskQuestion returns false.

  cout << "you have got" << ' ' << correct << ' ' << "answers correct"<< endl;
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
bool AskQuestion(string Q[], string A[], string B[], string C[], string D[], char R[])
{
  static int Qnum = -1;    // index of question to be asked
  char guess = ' ';        // the user's guess
 bool correct = false;    // will hold return value of CheckAnswer

  Qnum++;                  // get the index of the next question

   // Call PrintQuestion to print the selected question and its answers
  PrintQuestion (Q[Qnum], A[Qnum], B[Qnum], C[Qnum], D[Qnum]);

  // Get the user's guess
  cout << "Enter the correct answer: ";
  cin >> guess;

  // Call CheckAnswer to see if the user's guess is correct
  correct = CheckAnswer(R[Qnum], guess);
  return correct;
}
/* Function: PrintQuestion
 * Parameters: ifstream variable associated with problems.in
 *
 * Reads and prints 5 lines of the file: one for the question and 
 *    4 for the multiple-choice selections.
 *
 * Return value: true if input file could be read, false otherwise.
 */
void PrintQuestion(string Question, string aAnswer, string bAnswer, string cAnswer, string dAnswer)
{
  cout <<Question<< endl;
  cout <<aAnswer<< endl;
  cout <<bAnswer<< endl;
  cout <<cAnswer<< endl;
  cout <<dAnswer<< endl;
  /*
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
  */
}
/* Function: CheckAnswer
 * Parameters: the correct answer and the user's guess
 * Prints a congratulatory message if the user's guess matches the correct answer.
 * Otherwise, prints a message correcting the user.
 */

bool CheckAnswer(char answer, char guess) 
{
  if (guess == answer)   
    {
      cout << "Correct!\n";
      return true;    
    }

  else   
    {
      cout << "Incorrect. The correct answer is " 
	   << answer << ".\n";
    
  return false;
    }
}

/* Function: ReadQuestions

 * Parameters: ifstream variable associated with problems.txt
*   arrays in wich to store the components of the trivia questions.
 *      the questions will be read into the array: string Q[]
 *      the a. answers will be read into the array: string A[]
 *      the b. answers will be read into the array: string []
 *      the c. answers will be read into the array: string C[]
 *      the d. answers will be read into the array: string D[]
 *      the correct ansers will be read int the array: car R[]
 *
 * Reads all of the questions and their multiple choice answers from the file
 *      and stores them into the arrays.
 * Return value: returns the number of questions read from the file.
 */

int ReadQuestions(ifstream& infile, string Q[], string A[],

		  string B[], string C[], string D[], char R[])
{
  int count = 0;  // Variable to hold count of questions; initially 0

   while (getline (infile, Q[count]))  // Read the question line until it fails

    {
      string rest_of_line;

      getline (infile, A[count]); // Read the a. answer for the question
      getline (infile, B[count]); // Read the b. answer for the question
      getline (infile, C[count]); // Read the c. answer for the question
      getline (infile, D[count]); // Read the d. answer for the question
      infile >> R[count];     // Read the correct answer for the question
      getline (infile, rest_of_line); // Read the rest of the correct answer line
      count++;
    }
  return count;
}
