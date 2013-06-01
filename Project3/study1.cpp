#include <iostream>
using namespace std;
void swap (int a, int b);
void swap (float & a, float & b);
int main ()
{
  int w = 5, x = 7;
  float y = 3.2, z = 2.3;
  swap (w, x);
  cout << w << ' ' << x << endl;
  swap (y, z);
  cout << y << ' ' << z << endl;
  return 0;
}
void swap (int a, int b)
{
  int t = a;
  a = b;
  b = t;
}
void swap (float & a, float & b)
{
  int t = a;
  a = b;
  b = t;
}
