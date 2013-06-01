/* Project:
 * Author:
 * Date:
 * Description:
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX_GRADES = 50;

/* Class: 
 * Description:
*/
class Grade
{
    public:
	Grade();
	bool Read (istream & input);
	void Print (ostream & output);
	char GetType ();
	float GetEarnedScore ();
	float GetPossibleScore ();
	string GetDate ();
	string GetName ();
    private:
	char atype;
	float earned;
	float possible;
	string date;
	string name;
};

/* Class: 
 * Description:
*/
class Course
{
    public:
	Course ();
	bool AddGrade (Grade to_be_added);
	void PrintReport (ostream & output);
	void Sort ();
	float GetLabHomeworkPercent ();
	float GetProjectPercent ();
	float GetQuizTestPercent ();
	float GetOverallPercent ();
	string GetGrade ();
    private:
	int num_grades;
	Grade grades [MAX_GRADES];
};

/* Function: main 
 * Parameters: a count of the number of arguments on the command line
 * 	and a list of the arguments on the command line
 * Description: this is the main function for the program. It will
 * 	- check to make sure the command line contains 2 arguments
 * 	- use the second argument to open an input file
 * 	- read the grades from the file and add them to a course
 *	- sort the grades in the course
 *	- print a report for the course
*/
int main (int argc, char * argv [])
{
	ifstream inFile;
	Grade oneGrade;
	Course oneCourse;

	// if the file name has not been provided on the command line, exit
	if (argc < 2)
	{
		cout << "Usage: " << argv[0] << " <filename>\n";
		exit (1);
	}

	// open the file using the file name provided on the command line
	inFile.open(argv[1]);

	// if the file cannot be opened, exit
	if (inFile.fail())
	{
		cout << "File: " << argv[1] << " not found\n";
		exit (2);
	}
	
	// read one grade at a time from the file and add it to the course
	while (oneGrade.Read(inFile) == true)
	{
		oneCourse.AddGrade(oneGrade);
	}
	
	// call the Sort function to sort the grades in the course
	oneCourse.Sort();

	// call the PrintReport function to print the grades for the course
	oneCourse.PrintReport(cout);

	// end the program
	return 0;
} 

/* Function: 
 * Parameters:
 * Description:
*/
Grade::Grade()
{
}

/* Function: 
 * Parameters:
 * Description:
*/
bool Grade::Read (istream & input)
{
	return false; // dummy return for stub
}

/* Function: 
 * Parameters:
 * Description:
*/
void Grade::Print (ostream & output)
{
}

/* Function: 
 * Parameters:
 * Description:
*/
char Grade::GetType ()
{
	return ' '; // dummy return for stub
}

/* Function: 
 * Parameters:
 * Description:
*/
float Grade::GetEarnedScore ()
{
	return 0; // dummy return for stub
}

/* Function: 
 * Parameters:
 * Description:
*/
float Grade::GetPossibleScore ()
{
	return 0; // dummy return for stub
}

/* Function: 
 * Parameters:
 * Description:
*/
string Grade::GetDate ()
{
	return ""; // dummy return for stub
}

/* Function: 
 * Parameters:
 * Description:
*/
string Grade::GetName ()
{
	return ""; // dummy return for stub
}

/* Function: 
 * Parameters:
 * Description:
*/
Course::Course ()
{
}

/* Function: 
 * Parameters:
 * Description:
*/
bool Course::AddGrade (Grade to_be_added)
{
	return false; // dummy return for stub
}

/* Function: 
 * Parameters:
 * Description:
*/
void Course::PrintReport (ostream & output)
{
}

/* Function: 
 * Parameters:
 * Description:
*/
void Swap (Grade & G1, Grade & G2)
{
}

/* Function: 
 * Parameters:
 * Description:
*/
void Course::Sort ()
{
}

/* Function: 
 * Parameters:
 * Description:
*/
float Course::GetLabHomeworkPercent ()
{
	return 0.0; // dummy return for stub
}

/* Function: 
 * Parameters:
 * Description:
*/
float Course::GetProjectPercent ()
{
	return 0.0; // dummy return for stub
}

/* Function: 
 * Parameters:
 * Description:
*/
float Course::GetQuizTestPercent ()
{
	return 0.0; // dummy return for stub
}

/* Function: 
 * Parameters:
 * Description:
*/
float Course::GetOverallPercent ()
{
	return 0.0; // dummy return for stub
}

/* Function: 
 * Parameters:
 * Description:
*/
string Course::GetGrade ()
{
	return "unknown"; // dummy return for stub
}
