//  This program prints "You Pass" if a student's average is 
//  60 or higher and prints "You Fail" otherwise
// name: Mason Thrall

#include <iostream>
using namespace std;

int main()
{

	float average;    // holds the grade average

	cout << "Input your average:" << endl;
	cin >> average;

	if (average > 100)
		cout << "Invalid Data" << endl;
	else if (average >= 90)
		cout << "You got an A" << endl;
	else if (average >= 80)
		cout << "You got a B" << endl;
	else if (average >= 60)
		cout << "You Pass" << endl;
	else if (average >= 0)
		cout << "You fail" << endl;
	else
		cout << "Negative input!" << endl;

	return 0;	
}

// Exercise 1:
// If you input 60, then the program doesn't return pass or fail. This is because the
// first if statement uses > instead of >=, which would allow 60 to be considered a pass.
//
// Exercise 2:
// The program is modifed to use a single if/else statement.
//
// Exercise 3:
// If -12 is entered, then the else case is triggered since it doesn't match any of the categories.
// This could be avoided by grouping the negative case with the > 100 case in the invalid data condition like:
// if (average > 100 || average < 0).
//
