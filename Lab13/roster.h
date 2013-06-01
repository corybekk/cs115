// Name: Cory Bekker
// Course: Computer Science 115
// Lab#: Lab13

#include <string>
const int NUM_TESTS=3;
using namespace std;


/* Class for a single student */
class Student 

{
 public:
  Student(); // default constructor
  Student(const Student& s); // copy constructor

  /* Methods for setting and accessing the student's name */
  void SetName(string name_to_use);
 string GetName();

  /* Methods for setting and accessing the student's test scores */
  void SetScores(int scores_to_use[]);
  int  GetSingleScore(int index);

  /* Method for accessing the student's average score */
  float GetAvgScore();

   /* Method for print the student's name and scores */
  void Print();

 private:

  string name;
  int   scores[NUM_TESTS];
  float average;
};

const int MAX_STUDENTS=20;

using namespace std;

/* Class for a roster of students */
class Roster {
 public:
  Roster(); // default constructor
  bool AddStudent(string name_to_use, int scores_to_use[]);
  void Print();
  void Sort();
  float GetOverallAverage();
 private:
  Student students[MAX_STUDENTS];
  int num_students;
};

/* Helper function -- doesn't need internal access */
void Swap(Student& a, Student& b);

