/* Program: CS 115 Lab 5b
   Author: cory bekker
   Description: Asks the user for a sequence of 5 numeric values and   
   tells whether each number is even or odd.
*/
#include <iostream>
using namespace std;
 
int main () {
  int inputVal = 1; // Value from the user
  int Counter = 1;  // Loop counter
 
  /* Loop as long as Counter <= 5 */
  while (Counter <= 5) {
   
    /* Prompt the user to enter a value */
    cout << "Enter a numeric value: ";
    cin >> inputVal;
      
    /* Print whether that value is even or odd */
    if (inputVal % 2) {
      cout << inputVal << " is odd./n";
    }
    else {
      cout << inputVal << " is even./n";
    }
      
    Counter++; // Update the value of Counter
  } // end of loop
   
  return 0;
}
