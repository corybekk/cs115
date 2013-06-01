/* Program: CS 115 Lab 7b
   Author: Cory Bekker
   Description: This program uses nested loops.
*/
#include <iostream>
using namespace std;
 
int main () {
  int i, j;        // Loop counters
  int total = 0;
 
  for (i = 1; i <= 2; i++) {
    for (j = 8; j >= 5; j--) {
         
      // Put some blank lines here
      total = i+j;
         
    }
  }
  cout << "Total = " << total << endl;
  return 0;
}
