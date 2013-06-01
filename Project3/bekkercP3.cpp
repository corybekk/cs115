/* Program: CS 115 Project 3

   Author: Cory Bekker

   Description: This program computes a person's percent score over a 

      number of variable-point assignments.  It reads the earned score and 

      total possible score for each assignment from a file and prints out the precent and grade.  The file

      must be formatted in a specific way.

*/

#include <iostream>

#include <fstream>

using namespace std;

 

const string inFileName = "scores1.in";

 
int InputNumScores(ifstream& input);

float ComputePctScore(ifstream& input, int numScores);

 

int main() 

{

  ifstream inputFile;  // Variable for input file

  int numScores;   // Number of scores stored in the input file

  float GradePct;

  // Call a function to open the input file and read the first line,

  // which contains the number of scores to read

  numScores = InputNumScores(inputFile); 

   

  // If there was an error reading the file, output a message and exit.

  if (numScores == -1) {

    cout << "Could not read input file\n";

    return 0;

  }

   

  // Call a function to read the scores from the file and computer

  // the overall percentage score.
  GradePct = ComputePctScore(inputFile, numScores);// changes the long function to GradePct to make it easier

  cout << "Your percent is "
       << GradePct << endl;
  cout << "Your grade is ";

  if (GradePct >= 90)// checks what grade
    {
      cout << 'A';
    }
  if (GradePct >= 80 and GradePct <= 89)
    {
      cout << 'B';
    }
  if (GradePct >= 70 and GradePct <= 79)
    {
      cout << 'C';
    }
  if (GradePct >= 60 and GradePct <= 69)
    {
      cout << 'D';
    }
  if (GradePct < 60)
    {
      cout << 'F';
    }

  cout << endl;
     

  // Close the input file

  inputFile.close();

  return 0;

}

 

/* Function: InputNumScores

 * Parameters: ifstream variable to use for open file. This variable should

 *    not currently be associated with any open files.

 * Return value: The first line of the input file, which should be

 *    the number of scores in the file if the file is correctly formatted.

 *    Returns -1 if it could not open the file.

 */

int InputNumScores(ifstream& input) 

{

  int numScores;

  string inFileName;

  cout<<"Enter the file name ";

  cin >> inFileName;



  input.open(inFileName.c_str());

  input >> numScores;

  if (input.fail()) // if the file entered is wrong fails to open.

    {

      return -1;

    }

  return numScores;

  }

 

/* Function: ComputePctScore

 * Parameters:

 *    1. ifstream variable for input file.  This variable needs to

 *       be associated with an open file.  The first line of the file

 *       (the number of scores) should already have been read.

 *    2. the number of scores in the input file

 * Return value: the overall percent score

 */

float ComputePctScore(ifstream& input, int numScores) 

{
  int possible; // possible points available
  int earned;// points earned
  int LH_earned=0;// Total points earned for all assignments
  int LH_possible=0;// Total points possible for all assignments
  int P_earned=0;// Points earned on a single assignment
  int P_possible=0;// Points possible on a single assignment
  int QE_earned=0;// Quizes and exames earned
  int QE_possible=0;// Quizes and exames points possible
  float percent;// Overall percent score
  char LH_type;// the catagory type... test, homework, projects ... ect.
  float LH_percent;// percent of Labs and homework
  float P_percent; // percent of projects
  float QE_percent;// percent of Quizes and exams






  for (int i=0; i < numScores; i++) // reads all text in a file 
    {
      
      input >> LH_type >> earned >> possible; // makes the file be read in a certain order
 
  if (LH_type == 'L' || LH_type == 'H') // catagorize what scores go where
    {
      LH_earned += earned; // totals up the earned list 
      LH_possible += possible; // totals up the possible list 

    }
  else if (LH_type == 'P')
    {
      P_earned += earned;
      P_possible += possible;

    }
  else if (LH_type == 'Q' || LH_type == 'E')
    {
      QE_earned += earned;
      QE_possible += possible;

    }

  LH_percent = 100.0 * LH_earned/LH_possible;

  P_percent = 100.0 * P_earned/P_possible;

  QE_percent = 100.0 * QE_earned/QE_possible;

 percent = 0.2 * LH_percent + 0.3 * P_percent + 0.5 * QE_percent;

    }  


  
return percent;

}
