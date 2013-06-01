/* Program: CS 115 Lab 6b

   Author: Cory Bekker

   Description: This program walks through nested for-loops.

*/

#include <iostream>

using namespace std;

 

int main () {

  int i, j;        // Loop counters

  int line = 1;    // Line counter

   

  for (i = 1; i <= 5; i++) {

    for (j = 1; j <= 2; j++) {

      cout << "Line " << line++

	   << ":\ti = " << i

	   << "\tj = " << j << endl;

    } // end j loop

  } // end i loop

  return 0;

}
