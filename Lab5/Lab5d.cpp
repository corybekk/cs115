/* Program: CS 115 Lab 5d
   Author: Cory Bekker
   Description: Asks the user for a sequence of numeric values and 
                prints the values entered.
*/
#include <iostream>
using namespace std;
 
int main () {
  int inputVal = 1;  // Current value entered by user
  int Counter = 0;   // Number of values entered by user
 
  /* Prompt the user for the first value */
  cout << "Enter a numeric value: ";
  cin >> inputVal;
   
  /* Loop as long as the user's input is greater than 0 */
  while (inputVal > 0) {
    cout << "The input value is " << inputVal << "." << endl; 
    // Print the user's input
    Counter++;       // Update the value of Counter
    cin >> inputVal; // Get the next input
  }
   
  /* Print the final value of Counter */
  cout << Counter << " values were entered.\n";
 
  return 0;
}
