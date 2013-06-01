
/* Program: CS 115 Project 3-2
   Author: Cory Bekker
   Description: This program computes a person's percent score over a 
   number of variable-point assignments.  It reads the earned score and total possible score for each assignment from a file and prints out the precent and grade.  The file  must be formatted in a specific way.*/

#include <iostream>
#include <cstdlib> // allows exit
#include <iomanip> // allows setw
#include <fstream>

using namespace std;

const string inFileName = "scores1.in";

const int MAX = 100;

// Function to open file and read data into arrays.
// Will return number of assignments (-1 if the file cannot be read)
int InputScores(ifstream& input, char T[], int E[], int P[],string D[], string N[]);

// Function to print data from the arrays.
void PrintScores (int numScores, char T[], int E[], int P[], string D[], string N[]);

// Function to calculate and return the overall percentage score using the
// data in the arrays. Will also print the percentage score for each category.
float ComputePctScore(int numScores, char T[], int E[], int P[],string D[], string N[]);

// function used to determine the total grade
char DetermineGrade( int GradePct);
//========================================================================================

int main() 

{

  ifstream inputFile;  // Variable for input file
  int numScores;   // Number of scores stored in the input file
  float GradePct; // easier way to print the returned value of inputscores
  char LH_type [MAX]; // Array to hold assignment types
  int earned [MAX]; // Array to hold assignment earned scores
  int possible [MAX]; // Array to hold assignment possible scores
  string date [MAX]; // Array to hold assignment dates
  string name [MAX]; // Array to hold assignment nameschar atype [MAX]; 

  // Call a function to open the input file and the data into the arrays.
  numScores = InputScores(inputFile, LH_type, earned, possible, date, name);

  // If there was an error reading the file, output a message and exit.
  if (numScores == -1) 
  {
    cout << "Could not read input file\n";
    exit (1);
  }

  cout << "There are " << numScores << "assignments in the file\n";

  // Call function to print assignment data from the arrays.
  PrintScores(numScores, LH_type, earned, possible, date, name);

  // Call a function to read the scores from the file and computer
  // the overall percentage score.
  GradePct = ComputePctScore(numScores, LH_type, earned, possible, date, name);
  cout << "your percent is " << GradePct << "%\n";

  // Determines the overall grade of all the assignments together
  cout << "Your grade is "; 
  DetermineGrade(GradePct);

  // Close the input file
  inputFile.close();
  return 0;
}

//========================================================================================
/* Function: InputNumScores
 * Parameters: ifstream variable to use for open file. This variable should
 *    not currently be associated with any open files.
 * Return value: The first line of the input file, which should be
 *    the number of scores in the file if the file is correctly formatted.
 *    Returns -1 if it could not open the file.
 */
int InputScores (ifstream& input, char T[], int E[], int P[],string D[], string N[])
		   
{
  int numScores = 0;// the amount of assignments within the file
  string inFileName;// file name

  cout<<"Enter the file name ";

  cin >> inFileName;

  input.open(inFileName.c_str());

  if (input.fail()) // if the file entered is wrong fails to open.
    { 
      return -1;
    }


  while (input >> T[numScores] && numScores < MAX)// figures out how many assignments are in the file.
    {
      input >> E[numScores]; 
      input >> P[numScores];
      input >> D[numScores];
      getline (input, N[numScores]);
      numScores++;
    }

  return numScores;

}

//========================================================================================
/* Function: ComputePctScore
 * Parameters:
 *    1. ifstream variable for input file.  This variable needs to
 *       be associated with an open file.  The first line of the file
 *       (the number of scores) should already have been read.
 *    2. the number of scores in the input file
 * Return value: the overall percent score
 */

 float ComputePctScore(int numScores, char T[], int E[], int P[],string D[], string N[])

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
      
      // makes the file be read in a certain order
 
  if (T[i] == 'L' || T[i] == 'H') // catagorize what scores go where
    {
      LH_earned += E[i]; // totals up the earned list 
      LH_possible += P[i]; // totals up the possible list 

    }
  else if (T[i] == 'P')
    {
      P_earned += E[i];
      P_possible += P[i];

    }
  else if (T[i] == 'Q' || T[i] == 'E')
    {
      QE_earned += E[i];
      QE_possible += P[i];

    }
    }

  LH_percent = 100.0 * LH_earned/LH_possible;// calculates Labs and Homeworks percent
  P_percent = 100.0 * P_earned/P_possible;
  QE_percent = 100.0 * QE_earned/QE_possible;

  cout << "Your Lab and Homework percent is " << LH_percent << "%\n";// prints out the precentage of homework
  cout << "Your Project percent is " << P_percent << "%\n";
  cout << "Your Quiz and Exam percent is " << QE_percent << "%\n";

  percent = 0.2 * LH_percent + 0.3 * P_percent + 0.5 * QE_percent;// calculates overal percent of the three
      
  return percent;

}

//==============================================================================================
// Function to print data from the arrays.
void PrintScores (int numScores, char T[], int E[], int P[],string D[], string N[])
{
  for (int i = 0; i < numScores; i++)
    
    {
    cout << T[i];
    cout << setw(5)<< E[i];// prints the assignments inside the file onto the screen
    cout << setw(5)<< P[i];
    cout << setw(11)<< D[i];
    cout << setw(5)<< N[i];
    cout << endl;    
    }
}

//==============================================================================================
// Checks what GradePct falls into and then prints the grade. .
char DetermineGrade(int GradePct)
{
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
}
