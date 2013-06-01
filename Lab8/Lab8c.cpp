/* Program: CS 115 Lab 8c

   Author: cory

   Description: This program writes the user's input to a file.

*/

#include <iostream>

#include <fstream>

#include <string>

using namespace std;

 

int main () {

   

  ofstream outFile;     // Variable for writing to a file

  string line;          // Read a line of user's input

   

  // Open test.txt and associate it with the variable outFile

  outFile.open("test.txt");

   

  // Did it work?

  if (outFile.fail()) {

    cout << "Could not open output file.\n";

    return 0;

  }

   

  do {

    /* Prompt for the user's input and write to to the file */

        

    cout << "Type a line of text:\n";

    getline(cin, line);

    outFile << line << "\n";

        

  } while (line.length() != 0);

   

  // Close the output file

  outFile.close();

   

  return 0;

}
