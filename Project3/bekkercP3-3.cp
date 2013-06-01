
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
void DetermineGrade(float GradePct);

//function to swap two integer values
void Swap (int & a, int & b);

// function to swap two string values
void Swap (string & a, string & b);

// Function to swat two character values
void Swap (char & a, char & b);

// Function to sort the parallel data arrays
void Sort (int numScores, char T[], int E[], int P[], string D[], string N[]);

//Function to print a formatted report of the assignments and percentage grades
void PrintReport (int numScores, char T[], int E[], int P[], string D[], string N[]);

//========================================================================================

int main() 

{

  ifstream inputFile;  // Variable for input file
  int numScores; //number of scores stored in the input file
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
    return 0;
  }

  // call function to sort the assignment data in the arrays.
  Sort(numScores, LH_type, earned, possible, date, name);
  // Call function to print formatted report of the data in the arrays. 
  PrintReport(numScores, LH_type, earned, possible, date, name);
  // Close the input file.
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

  cout<<"Enter the file name " << endl;

  cin >> inFileName;

  input.open(inFileName.c_str());// this opens up the file.

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
  float possible; // possible points available
  float earned;// points earned
  float LH_earned=0;// Total points earned for all assignments
  float LH_possible=0;// Total points possible for all assignments
  float P_earned=0;// Points earned on a single assignment
  float P_possible=0;// Points possible on a single assignment
  float QE_earned=0;// Quizes and exames earned
  float QE_possible=0;// Quizes and exames points possible
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
  else if (T[i] == 'Q' || T[i] == 'T')
    {
      QE_earned += E[i];
      QE_possible += P[i];

    }
    }

  LH_percent = 100.0 * LH_earned/LH_possible;// calculates Labs and Homeworks percent
  P_percent = 100.0 * P_earned/P_possible;
  QE_percent = 100 * QE_earned/QE_possible;

  /*  cout << "Your Lab and Homework percent is " << LH_percent << "%\n";// prints out the precentage of homework
  cout << "Your Project percent is " << P_percent << "%\n";
  cout << "Your Quiz and Exam percent is " << QE_percent << "%\n";

  percent = 0.2 * LH_percent + 0.3 * P_percent + 0.5 * QE_percent;// calculates overal percent of the three
      
  return percent;*/

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
//============================================================================================
//function to swap two integer values
void Swap (int & a, int & b)
{
  int temp = a;
  a = b;
  b = temp;
}

//===========================================================================================
// function to swap two string values
void Swap (string & a, string & b)
{
  string temp = a;
  a = b;
  b = temp;
}

//==========================================================================================
// Function to swat two character values
void Swap (char & a, char & b)
{
  char temp = a;
  a = b;
  b = temp;
}

//==========================================================================================
// Function to sort the parallel data arrays
void Sort (int numScores, char T[], int E[], int P[], string D[], string N[])
{
  for (int i=0; i< numScores-1; i++)
    {
      for (int j=1; j< numScores-i; j++)
	{
	  // checks if each number is smaller than the other
	  if ((T[j] < T[j-1]) ||((T[j] == T[j-1]) && (D[j] < D[j-1])))
	    {
	      Swap (T[j], T[j-1]);// tells it to swap array numbers 
	      Swap (E[j], E[j-1]);
	      Swap (P[j], P[j-1]);
	      Swap (D[j], D[j-1]);
	      Swap (N[j], N[j-1]);
	    }
	}
    }
}

//=========================================================================================
//Function to print a formatted report of the assignments and percentage grades
void PrintReport (int numScores, char T[], int E[], int P[], string D[], string N[])
{

  float possible; // possible points available
  float earned;// points earned
  float LH_earned=0;// Total points earned for all assignments
  float LH_possible=0;// Total points possible for all assignments
  float P_earned=0;// Points earned on a single assignment
  float P_possible=0;// Points possible on a single assignment
  float QE_earned=0;// Quizes and exames earned
  float QE_possible=0;// Quizes and exames points possible
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
      else if (T[i] == 'Q' || T[i] == 'T')
	{
	  QE_earned += E[i];
	  QE_possible += P[i];

	}
    }

  LH_percent = 100.0 * LH_earned/LH_possible;// calculates Labs and Homeworks percent
  P_percent = 100.0 * P_earned/P_possible;
  QE_percent = 100 * QE_earned/QE_possible;
  percent = 0.2 * LH_percent + 0.3 * P_percent + 0.5 * QE_percent;//calculates total % 


  cout <<"Type";// prints out the heading for each score, date, and name. 
  cout << setw(10)<<" Earned";
  cout << setw(10)<<" Possible";
  cout << setw(1)<<" Date";
  cout << setw(27)<<" Assignment Name";
  cout << endl;

  for(int i=0; i<numScores; i++)// goes through each assignment 
    {
      if(T[i] == 'L')// prints out all labs in the file.
	{
	  cout << T[i]<< '\t'; // prints the TYPE, for instance, LAB
	  cout << E[i]<< '\t'; // prints out points earned in lab
	  cout << P[i]<< '\t'; // prints possible points of lab
	  cout <<' '<< D[i]<< '\t'; // prints out date
	  cout << N[i]<< endl;// prints out name of project
	}
    }
  cout << setw(10)<< LH_earned;//prints out the earned points.
  cout << setw(8)<< LH_possible<< endl;// prints out the possible points
  cout << "Your Lab and Homework percent is" <<' '<<LH_percent<<'%'<< endl; 
  cout << endl; 

  cout <<"Type";
  cout << setw(10)<<" Earned";
  cout << setw(10)<<" Possible";
  cout << setw(1)<<" Date";
  cout << setw(27)<<" Assignment Name";
  cout << endl;


  for(int i=0; i<numScores; i++)
    {
      if(T[i] == 'P')
	{
	  cout << T[i]<< '\t';
	  cout << E[i]<< '\t';
	  cout << P[i]<< '\t';
	  cout <<' '<< D[i]<< '\t';
	  cout << N[i]<< endl;
	}
    }
  cout << setw(10)<<P_earned;
  cout<< setw(8)<<P_possible<< endl;
  cout << "Your Project percent is" <<' '<<P_percent<<'%'<< endl;
  cout << endl;

  cout <<"Type";
  cout << setw(10)<<" Earned";
  cout << setw(10)<<" Possible";
  cout << setw(1)<<" Date";
  cout << setw(27)<<" Assignment Name";
  cout << endl;

  for(int i=0; i<numScores; i++)
    {
      if(T[i] == 'Q' || T[i] == 'T')
	{
	  cout << T[i]<< '\t';
	  cout << E[i]<< '\t';
	  cout << P[i]<< '\t';
	  cout <<' '<< D[i]<< '\t';
	  cout << N[i]<< endl;
	}
    
    }
  cout << setw(10)<<QE_earned;
  cout<< setw(8)<<QE_possible<< endl;
  cout << "Your Quiz and Exam percent is"<<' '<<QE_percent<<'%'<< endl;
  cout << endl;

  cout << "Your Overall percent is "
       << percent << '%'<<endl;// prints the total percent.
  cout << "Your grade is ";

  if (percent >= 90)// checks what grade and then prints it.
    {
      cout << 'A';
    }
  if (percent >= 80 and percent <= 89)
    {
      cout << 'B';
    }
  if (percent >= 70 and percent <= 79)
    {
      cout << 'C';
    }
  if (percent >= 60 and percent <= 69)
    {
      cout << 'D';
    }
  if (percent < 60)
    {
      cout << 'F';
    }

  cout << endl;
}




//=======================================================================================
 void DetermineGrade(float GradePct)
 {
cout << "Your percent is "
<< GradePct << '%'<<endl;
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
 }
