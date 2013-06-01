/* Program: CS 115 Lab 4g

   Author: cory b

   Description: This program will determine whether two numeric values are positive.

*/

#include <iostream>

using namespace std;

 

int main () {

  int  x, y; // Variables for the user's input

   

  // Get the user's input

  cout << "Enter two numeric values x and y: ";

  cin >> x >> y;

   

  if (x > 0) {

    if (y > 0) {

      cout << " Both are positive" << endl;

    }

    else {

      cout << " x is positive" << endl; 

    }

  }

  else {

    if (y > 0) {

      cout << " y is positive" << endl;

    }

    else {

      cout << "neither are positive" << endl;

    }

  }

  return 0;

}
