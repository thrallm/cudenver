// This program will convert kilometers into miles.
// Mason Thrall

#include <iostream>
using namespace std;

int main()
{
	// Declare variables
	double kilometers;
	double miles;

	// Get the kilometer data from the user.
	cout << "How many kilometers were travelled?" << endl;	
	cin >> kilometers;

	// Convert kilometers to miles
	miles = kilometers * 0.621;
	
	// Display the converted data
	cout << "You travelled " << miles << " miles." << endl;
	
	// return 0 since main is an int function.
	return 0;
}
