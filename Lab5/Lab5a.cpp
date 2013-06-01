/* Program: CS 115 Lab 5a
   Author: Cory Bekker
   Description: This program will ask the user for a numerical value
      and do some calculations based on it.
*/
#include <iostream>
using namespace std;
 
int main () {
  int inputVal = 1;  // Value input by the user
  int Counter = 1;   // Loop counter
  int Total = 0;     // Running total
 
  /* Prompt for numeric value */
  cout << "Enter a numeric value: ";
  cin >> inputVal;
   
  /* Loop as long as the value of Counter <= inputVal */
  while (Counter <= inputVal) {
    Total = Total + Counter;  // Update the value of Total by
    // adding the value of Counter
    Counter++;                // Add 1 to the value of Counter
  }
   
  /* Print the final value of Total */
  cout << "The total is " << Total << "." << endl;
  
  return 0;
}
