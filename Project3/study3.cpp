#include <iostream>
using namespace std;

int main (){

  float total =0;                         // line 1
  float value [3];                        // line 2
  int ctr =0;                           // line 3

  cout << "Enter 3 numeric values: ";   // line 4

  while (ctr < 3)                      // line 5
    {
      cin>> value[ctr];                 // line 6
      total = total + value[ctr];       // line 7
      ctr++;                            // line 8
    }
 
  cout << total / 3 << endl;            // line 9

  return 0;
}
