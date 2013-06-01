/* Program: CS 115 Lab 5f
   Author: cory bekker
   Description: Asks the user for a numeric value until the user enters a valid number.
*/
#include <iostream>
using namespace std;
 
int main () 
{
  int inputVal = 1;

  cout << "Enter a numeric value: ";
  cin >> inputVal;
   
  while (cin.fail()) 

{
      cin.clear();     
      cout << "cin.fail = " << cin.fail() << endl;
      string restOfLine;
      getline (cin, restOfLine);
      cout << "restOfLine = " << restOfLine << endl;
      cout << "Try again." << endl;
      cin >> inputVal;
    }
  cout << "You entered " << inputVal << "." << endl;
 
  return 0;
}
