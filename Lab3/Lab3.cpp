/* Program: CS 115 Lab 3

   Author: cory bekker

   Description: This program will compute the area of a square given the side length.

*/

 

#include <iostream>

#include <cmath>

using namespace std;

 

const float pi = 3.14159;

 

int main () {

  float inVal = 1;  // Value input by the user; initialize to 1
  float circle;
  float sqArea;     // Area of a square with side length=inVal
  float cube;
  float sphere;
  float triangle;

  // Prompt the user for the side of the square


 

  cout << "Enter a numeric value: ";

  cin >> inVal;
  cout.setf (ios::fixed);
  cout.setf (ios::showpoint);
  cout.precision (2);

   

  // Compute the area of the square

  sqArea = inVal * inVal;
   
  
  // Print the area of the square

  cout << "The area of a square with side length "

       << inVal << " is " << sqArea

       << "." << endl;
  
  // compute area of the circle

  circle = pi * inVal * inVal;
  
  // print the area of the circle

  cout << "The area of a circle with radius length "
      
       << inVal << " is " << circle

       << "." << endl;
 

 
  // compute volume of the cube

  cube = inVal * inVal * inVal;

  // print the volume of the cube

  cout << "The volume of the cube with side length "
      
       << inVal << " is " << cube

       << "." << endl;

  // compute volume of the sphere

  sphere = (4.0/3.0) * pi * inVal * inVal * inVal;

  // print the volume of the sphere

    cout << "The volume of the sphere with radius length "

	 << inVal << " is " << sphere

	 << "." << endl;

  // compute area of triangle

    triangle = inVal * inVal * (sqrt (3)) / 4; 

  // print the area of the triangle 

      cout << "The area of the triangle with side length "

	    << inVal << " is " << triangle

	    << "." << endl;

  return 0;

}




