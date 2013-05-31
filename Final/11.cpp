#include <iostream>
using namespace std;

void Swap (int & a, int & b); 

int main () 
{

int A[5] = {2, 3, 5, 7, 11}; 
 
for (int i = 1; i < 5; i++) 
   
 Swap (A[i], A[i-1]); 
  
for (int i = 0; i < 5; i++) 
   
 cout << "A[" << i << "] = " << A[i] << endl; 
  
return 0; 
 
}

void Swap (int & a, int & b)

{
 int t = a; a = b; b = t; 
}
