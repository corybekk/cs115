/* Program: CS 115 Lab 5a
   Author: Cory Bekker
   Description: This program will ask the user for a numerical value
      and do some calculations based on it.
*/
#include <iostream>
using namespace std;
 
int main (){ 


  int inputVal = 1;  // Value input by the user
  int Counter = 1;   // Loop counter
  int Total = 0;     // Running total
 
 
  cout << "Enter a numeric value: ";
  cin >> inputVal;

  while (Counter <= inputVal)

    {  
    
    if (Counter %2) { 
   
   cout << Counter << " is odd.\n";
   Total = Total - Counter;
}

  else {
  
  cout << Counter << " is even.\n";
  Total = Total + Counter;  
  }
   Counter++;                

  
 } 
  
  cout << "The total is " << Total << "." << endl;
  
  return 0;
}

