/* Program: CS 115 Lab 5g
   Author: Cory Bekker
   Description: Runs through a bunch of for-loops to demonstrate how they work.
*/
#include <iostream>
using namespace std;
 
int main () {
  int ctr;
  for (ctr = 1; ctr <= 3; ctr++) {
    cout << "The value of ctr is " << ctr << "." << endl;
  }
  for (ctr = 0; ctr < 3; ctr++) {
    cout << "The value of ctr is " << ctr << "." << endl;
  }
  for (ctr = 3; ctr > 0; ctr--) {
    cout << "The value of ctr is " << ctr << "." << endl;         
  }
  for (ctr = 0; ctr <= 3; ctr = ctr + 2) {
    cout << "The value of ctr is " << ctr << "." << endl;
  }
 
  return 0;
}
