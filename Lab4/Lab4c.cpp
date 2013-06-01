/* Program: CS 115 Lab 4c

   Author: Cory Bekker

   Description: This program will ask the user for a numerical value

      and tell the user whether it is positive or negative.

*/

#include <iostream>

using namespace std;

 

int main () {

  /* Declare variables */

  float Val = 1;  // This variable will hold the user's input; initialize to 1

 

  /* Prompt the user and read the user's input */

  cout << "Enter a numeric value: ";

  cin >> Val;

 

  /* Modify the user's input:

      If it is negative, multiply it by 3 and print the new value.

      If it is positive, divide it by 3 and print the new value.

  */

  if (Val < 0) {

    cout << "The old value is " << Val << '.' << endl;

    Val += 3;

    cout << "The new value is " << Val << '.' << endl;

  }

 else if (Val > 0) {

    cout << "The old value is " << Val << '.' << endl;

    Val -= 3;

    cout << "The new value is " << Val << '.' << endl;

  }

 else{// (Val == 0) {

    cout << "The old value is " << Val << "."  << endl;

    Val +=2;

   cout << "The new value is " << Val << "." << endl;   

  }

  return 0;

}
