// This program demonstrates the use of pointer variables
// It finds the area of a rectangle given length and width
// It prints the length and width in ascending order 

// Mason Thrall

#include <iostream>
using namespace std;

int main(){

	int length;		// holds length
	int width;		// holds width
	int area;		// holds are	
	int *lengthPtr;	// int pointer which will be set to point to length
	int *widthPtr;   // int pointer which will be set to point to width

	cout << "Please input the length of the rectangle" << endl;
	cin >> length;
	cout << "Please input the width of the rectangle" << endl;
	cin >> width;

	// Fill in code to make lengthPtr point to length (hold its address)
	lengthPtr = &length;
	// Fill in code to make widthPtr point to width (hold its address) 
	widthPtr = &width;
   
	area = *lengthPtr * *widthPtr;
	cout << "The area is " << area << endl;

	if (*lengthPtr > *widthPtr)
  		cout << "The length is greater than the width" << endl;
	else if (*widthPtr > *lengthPtr)
  		cout << "The width is greater than the length" << endl;
	else 
  		cout << "The width and length are the same" << endl;

	return 0;
}
// Exercise 1: Program is completed.
// Exercise 2: The program returns:
// The area is 150
// The width is greater than the length
