/* Program: CS 115 Lab 5h
   Author: Cory Bekker
   Description: Prints a pattern of numbers.
*/
#include <iostream>
using namespace std;
 
int main () {

  int i, j; // Loop counters

      for (i = 1; i <= 4 ; i++) {

	for (j = 0; j < i ; j++) { 
	  
	  cout << i << ',' << j << '\t';
	}

	cout << endl;  
}
        
  return 0;
}
