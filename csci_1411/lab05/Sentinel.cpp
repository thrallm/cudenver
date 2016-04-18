// This program illustrates the use of a sentinel in a while loop.
// The user is asked for monthly rainfall totals until a sentinel
// value of -1 is entered. Then the total rainfall is displayed

// Mason Thrall

#include <iostream>
using namespace std;

int main()
{
	// Fill in the code to define and initialize to 1 the variable month 
	float total = 0, rain;
	int month = 1;
	const int SENTINAL = -1;

	cout << "Enter the total rainfall for month " << month << endl;
	cout << "Enter -1 when you are finished" << endl;
	// Fill in the code to read in the value for rain
	cin >> rain;
	
	// Fill in the code to start a while loop that iterates 
	// while rain does not equal -1
	while (rain != SENTINAL) {
		// Fill in the code to update total by adding it to rain
		total += rain;
		// Fill in the code to increment month by one
		month++;
		
		cout << "Enter the total rainfall in inches for month " << month << endl;
		cout << "Enter -1 when you are finished" << endl;
		// Fill in the code to read in the value for rain
		cin >> rain;	
	}

	if (month == 1)
		cout << "No data has been entered" << endl;
	else
		cout << "The total rainfall for the " << month - 1 
		     << " months is "<< total << " inches." << endl;
	
	return 0;	
}
//
// Exercise 4: Code is completed.
//
// Exercise 5: The program seems to work well with reasonable numerical input. Starting
// with -1 directly closes the program as expected. Entering 0 works as expected.
// I think the only values which should be avoided are non-numeric or
// values too large for the float type.
//
// Exercise 6: The purpose of the indicated code is to notify the user they didn't
// enter data if the month is 1. Since the month var is initialized at 1, then if
// it is still 1 at the end of the program, it means the user exited the loop on the
// first iteration.
//
