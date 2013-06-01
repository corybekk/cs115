/* Program: CS 115 Lab 5e
   Author: Cory Bekker
   Description: Asks the user for a sequence of numeric values and prints the values entered.
*/
#include <iostream>
using namespace std;
 
int main () {

  int inputVal = 1;  // Current value entered by user
  int Counter = 0;   // Number of values entered by user
 
  cout << "Enter a numeric value: ";
  cin >> inputVal;

  do {
    cout << "The input value is " << inputVal << "." << endl;
    Counter++;
    cin >> inputVal;
  } while (inputVal > 0);
 
 
  cout << Counter << " values were entered.\n";
  return 0;
}
