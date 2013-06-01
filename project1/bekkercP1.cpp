// Filename: bekkercP1.cpp
// Title: Project 1- Temperature Conversion Program
// Author: Cory Bekker
// Date: Fall 2010
/* Description: A program that converts a Fahrenheit temperature to Celsius or a Celsius temperature to Fahrenheit.*/ 

#include <iostream>
#include <string>

using namespace std;

int main ()

{
  float celsius;
  float fahrenheit;
  string request; 

  
  cout << "Temperature Conversion Program" << endl << endl;

  cout << "Enter F2C to convert  Fahrenheit to Celsius." << endl;
 
  cout << "Enter C2F to convert  Celsius to Fahrenheit." << endl << endl;

  cout << "Enter F2C or C2F" << endl;

  cout.setf (ios::fixed);
  cout.setf (ios::showpoint);
  cout.precision (1);




  cin >> request; 

  if (request == "F2C") 
    {
      cout << "Enter Fahrenheit temperature" << endl;
      cin >> fahrenheit;
      celsius =(5.0/9) * (fahrenheit - 32);
      cout << "The equivalent of " << fahrenheit 
	   << " degrees fahrenheit is " << celsius << " degrees Celsius." 
	   << endl;  
    } 
  else if (request == "C2F")
    {
      cout << "Enter Celsius temperature " << endl;
      cin >> celsius; 
      fahrenheit = celsius * 9.0/5 + 32;
      cout << "The equivalent of " << celsius << " degrees celsius is "
	   << fahrenheit << " degrees fahrenheit. "
	   << endl; 
    }

  else 
    {
      cout << request << " is an invalid option"
	   << endl;
    }
  return 0;
} 
