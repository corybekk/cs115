/* Code to sort a list of students read from a text file */
#include <iostream>
#include <fstream>
#include <iomanip>
#include "roster.h"

using namespace std;

// The file to read student info from
const string filename="lab12.txt";

void InputStudentData(Roster& students);

int main () {

  Roster students;

  // Read student info from file and save the number of students in a variable
  InputStudentData(students);

  // Sort the list of students
  students.Sort();

  // Print out the list of students
  students.Print();

  // Print out the overall average
  cout << setw(12) << "Average:"
      << setw(8) << students.GetOverallAverage() << endl;

   return 0;

}
/* Function: InputStudentData
 * Parameters: A Roster
 * Reads data from the file into the array of students
 */
void InputStudentData(Roster& students) {

  string tmp_name;    // temp variable for student's name -- we'll copy this into the array
  ifstream inFile;    // variable for reading the student info from a file
  int scores[3];
  int num_read=0;

   inFile.open (filename.c_str());

  if (inFile.fail()) {

    cout << "File " << filename << " could not be opened.\n";

  }
   // While we can read a student from the file AND
   // we have read fewer than MAX students into the array
 while (inFile >> tmp_name and num_read < MAX_STUDENTS) {

     // Input the 3 test scores into student's array entry
    inFile >> scores[0];
    inFile >> scores[1];
    inFile >> scores[2];

    students.AddStudent(tmp_name, scores);

    // Increment count of students read from file
    num_read++;
  }
  inFile.close();
}
