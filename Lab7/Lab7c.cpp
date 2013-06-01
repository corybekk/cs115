/* Program: CS 115 Lab 7c
   Author: cory bekker
   Description: This program walks through nested for-loops.
*/
#include <iostream>
using namespace std;
 
void PrintHello(char x) {
  cout << "Hello\n";             // Line A
  cout << "My input was " << x << endl;
}

 
float GimmePi(int radius) {
  cout << "Hi from GimmePi\n";   // Line B
  float returnValue = radius* radius* 3.14159;   // Line C
  return returnValue;
}

int Gimme5(int input ) 
{
  cout << "executing Gimme5\n";
  int returnValue = 5 + input;
  return returnValue;
}

 
int main( ) {
  int value2; 
 float Value1;                  // Line D
  cout << "calling PrintHello\n";
  PrintHello('a');
  cout << "calling GimmePi\n";   // Line E
  Value1 = GimmePi(4);
  cout << "result of GimmePi: " << Value1 << endl;
  value2 = Gimme5(Value1); 
    cout << "result of Gimme5:" << value2 << endl;

  return 0;                      // Line F
}
