//Name: Cory Bekker
//Course: Computer Science 115
//Lab#: Lab13

#include <iostream>
#include <iomanip>
#include "student.h"

using namespace std;

/* Default constructor for Student
 *
 * Creates a new Student
 * Sets name to the empty string and all scores to 0
 */

Student::Student() 
{
  name = "";
  for (int i=0; i < NUM_TESTS; i++) 
    {
      scores[i] = 0;
    }
  average = 0;
}

//=========================================================================
/* Copy constructor for Student
 *
 * Defines how to make a copy of a Student
 * 
 */

Student::Student(const Student& s) 
{
  name = s.name;

  for (int i=0; i < NUM_TESTS; i++) 
    {
      scores[i] = s.scores[i];
    }

  average = s.average;
}
//======================================================================
/* SetName
 *
 * Parameter: name_to_use
 * Initializes the Student's name to name_to_use
 */

void Student::SetName(string name_to_use) 
{
  name = name_to_use;
}
//====================================================================
/* GetName
 * Returns the Student's name
 */
string Student::GetName() 
{ 
  return name; 
}
//===================================================================
/* SetScores
 *
 * Parameters: an integer array containing the student's scores
 * Sets the student's cores and average
 */

void Student::SetScores(int scores_to_use[]) 
{
  float total = 0;

  for (int i=0; i < NUM_TESTS; i++) 

    {
      scores[i] = scores_to_use[i];
      total += scores[i];
    }

  average = total/NUM_TESTS;
}
//==================================================================
/* GetSingleScore
 *
 * Parameters: index of the score to get (a number between 0 and  NUM_TESTS-1)
 * Returns: the corresponding score (scores[index]) or -1 if index is invalid
 */

int Student::GetSingleScore(int index) 
{

  if (index < 0 or index >= NUM_TESTS) 
    {
      return -1;
    }

    return scores[index];
    }
//==================================================================
   /* GetAvgScore
   *
   * Returns the student's test average
   */

  float Student::GetAvgScore() 
  { 
    return average; 
  }
//=================================================================
  /* Print
   *
   * Print the student's name and scores, separated by tabs
   */

  void Student::Print() 
  {
    cout << setw(10) << name << '\t';

    for (int i=0; i < NUM_TESTS; i++) 

      {
	cout << scores[i] << '\t';
      }

    cout << average << endl;
  }
