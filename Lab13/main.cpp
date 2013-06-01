// Course and Lab: Lab12, computer science 115
// Name:Cory Bekker
/* Code to sort a list of students read from a text file */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "student.h"

using namespace std;

// The maximum # of students we can handle (might have fewer)
const int MAX=20;

// The file to read student info from
const string filename="lab12.txt";

/*{
  string name;    // student's name
  int score1, score2, score3; // grades on 3 exams
  float average;  // average exam grade
  }; */

int InputStudentData(Student students[]);
void Swap (Student& a, Student& b); 
void Sort (int size, Student students[]);
float Calculate (int num, Student students[]);
void PrintStudents (int num, Student students[]);

int main () 

{

  Student roster[MAX];         // an array of up to MAX Students
  int     num_students = 0;    // the number of array elements we're actually 
                               // using
 float overall_average = 0;   // overall average across all of the students

   // Read student info from file and save the number of students in a variable
  num_students = InputStudentData(roster);

  // Sort the list of students
  Sort (num_students, roster);

  // Compute the overall exam average across all of the students
  overall_average = Calculate (num_students, roster);

  // Print out the list of students
  PrintStudents(num_students, roster);

  // Print out the overall average
  cout << setw(12) << "Average:" 
       << setw(8) << overall_average << endl;
  return 0;

}
/* Function: InputStudentData 
 * Parameters: An array of students
 * Reads data from the file into the array of students
 */

int InputStudentData(Student students[]) 

{
  int num_read = 0;   // # of students we've read so far
  string tmp_name;    // temp variable for student's name 
                      // -- we'll copy this into the array
  ifstream inFile;    // variable for reading the student info from a file
  int ARRAY[NUM_TESTS];

  inFile.open (filename.c_str());

  if (inFile.fail()) 

    {
      cout << "File " << filename << " could not be opened.\n";
    }

  // While we can read a student from the file AND
  // we have read fewer than MAX students into the array
  while (inFile >> tmp_name && num_read < MAX) 
    {

      students[num_read].SetName(tmp_name); // Fill in first student name

       // Input the 3 test scores into student's array entry

      for(int i=0; i<3; i++)
	{
	  inFile>>ARRAY[i];
	}

      students[num_read].SetScores(ARRAY);

      // Set average for current student
      /* students[num_read].average = (students[num_read].score1 +
	 students[num_read].score2 + students[num_read].score3) / 3.0;*/

       // Increment count of students read from file
      num_read++;
    }
  return num_read;
}
 
/* Function: Swap
 * Parameters: Two students (passed by reference)
x * Swaps the values of the two students 
 */

void Swap (Student& a, Student& b) 
{
  Student t = a;
  a = b;
  b = t;
}

/* Function: Sort 
 * Parameters: An array of students, the size of the array
 * Sorts the two students (by what?)
 */

void Sort (int size, Student students[]) 
{
  // If we go through an iteration
  // without swapping two students,
  // we are done sorting
  bool swapped=true;

   for (int i = 0; i < size and swapped == true; i++) 
    {
      swapped = false;
      for (int j = 1; j < size - i; j++) 
        {
	  if (students[j].GetName() < students[j-1].GetName()) 
            {
	      swap (students[j], students[j-1]);

	      swapped = true;
            }
        }
    }
}

float Calculate (int size, Student students[]) 
{
  float sum =0;
  
    for (int i=0; i<size; i++)
      {
	sum += students[i].GetAvgScore();
      }

    float avg = sum/size; 

  return avg;
}

void PrintStudents (int size, Student students[]) 
{
  for (int i=0; i<size; i++)
    {
      students[i].Print();
    }
}
