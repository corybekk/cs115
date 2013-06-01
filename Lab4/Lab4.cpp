/* Program: CS 115 Lab 4b

   Author: Cory Bekker

   Description: This program will ask the user for a numerical value

      and tell the user whether it is positive or negative.

*/

#include <iostream>

using namespace std;

 

int main () {

  /* Declare variables */

  int inputVal = 1;  // This variable will hold the user's input; initialize to 1

 

  /* Prompt the user and read the user's input */

  cout << "Enter a numeric value: ";

  cin >> inputVal;

 

  /* Print whether the user's input is positive or negative */

  if (inputVal < 0) {

    cout << "The value is negative." << endl;

  }

  if (inputVal > 0) {

    cout << "The value is positive." << endl;

  }

  if (inputVal == 0) {

    cout << "the value is zero. " << endl;   
  }



  return 0;

}
