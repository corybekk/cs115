#include <iostream>
 using namespace std;

int f1 (int a, int b);

int main ()
{

  int a[5] = {1,0,-4,-5,6};

    cin >> a[0];

 for (int i = 0; i < 5; i++)
{
  if (a[i] > 0)
cout << a(i) << "is a positive number" << endl;

 else if(a[i]<0)
cout << a[i] <<" is a negative number\n";

 else
cout << "The value is zero" << endl;
}

 cout << f1 (a[1], a[2]) << endl;

return 0;
}


int f1 (int a, int b)
{
int c = a * b + 7;
return c;
}
