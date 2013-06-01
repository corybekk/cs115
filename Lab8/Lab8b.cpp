/* Program: CS 115 Lab 8b

   Author: cory

   Description: This program reads a line of text from a file.

*/

#include <iostream>

#include <fstream>

#include <string>

using namespace std;

 

int main () {

  string dude;   

  ifstream cory;     // Variable for reading from a file

  string firstWord;    // Will contain first word of file

  string restOfLine;   // Will contain rest of first line of file

   

  // Open test.txt and associate it with the variable inFile

  cout << "enter a file name ";
  cin >> dude;

  cory.open (dude.c_str());

   

  // Did it work?

  if (cory.fail()) {

    cout << "Could not open input file.\n";

    return 0;

  }

   

  cory >> firstWord;   // Read the first string of inFile into a variable

  getline(cory, restOfLine);  // Read the rest of the line from inFile into restOfLine

   

  // Close the input file

  cory.close();

   

  // Print the results

  cout << "The first word of the file is: " << firstWord << endl;

  cout << "The rest of the first line is:\n";

  cout << restOfLine << endl;

   

  return 0;

}
