/* Program: CS 115 Lab 6e

 *    Author: cory bekker

 *       Description: This program manipulates string objects.

 *       */

#include <iostream>

#include <algorithm>

using namespace std;

 

int main ()

{

  string s1, s2, s3;

 

  cout << "Enter a string of characters: ";

  getline (cin, s1);

  cout << "Enter another string of characters: ";

  getline (cin, s2);

  s3 = s1 + s2;

  cout << "The concatenation of your strings is: " << s3 << endl;

 

  sort (s3.begin(), s3.end());

 

  cout << "The letters in your strings are: ";

  for (int i = 0; i < s3.size(); i++)

    {

      cout << s3[i] << ' ';

    }

  cout << endl;

 
  cout << "The letters in your strings are: ";

  cout << s3[0];

  for (int i = 1; i < s3.size(); i++)

    {

      if (s3[i] != s3[i-1])

	cout << ' ' << s3[i];

    }

  cout << endl;

  s3 = s1 + ' ' + s2;

  string s4;

  for (int i = s3.size() - 1; i >= 0; i--)

    {

      s4 += s3[i];

    }
  cout << "The new string is:" << s4 << endl;

  
  for (int i = s3.size() - 1; i >= 0; i--)

  cout << s3[i] << ' ';

  cout << endl;

  return 0;

}
