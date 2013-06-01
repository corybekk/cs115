// Program: Lab 2

// Author: cory

// Description: This program will be used to test input and

//   output for different variable types.

 

#include <iostream>

#include <string>

using namespace std;

 

int main () {

  // Declare variables of different types

  int ival = 0;

  float fval = 0.0;

  char cval = '?';

  string sval = "???";

    

  // Prompt the user

  cout << "Enter some data: ";

    

  // Read the user's input into the different variables --

  // first the int, then the float, then the char, then the string

  cin >> sval >> cval >> fval >> ival;

    

  // Read the values back out

  cout << "The integer value is " << ival << endl;

  cout << "The float value is " << fval << endl;

  cout << "The char value is " << cval << endl;

  cout << "The string value is " << sval << endl;

    

  // And report the value of cin.fail()

  cout << "The value of cin.fail() is " << cin.fail() << endl;

  return 0;

}
