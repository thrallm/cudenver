#include <fstream>
#include <iostream>
using namespace std;

// Mason Thrall

const short MAXNAME = 20;

int main()
{
	ifstream inData;
	inData.open("grades.txt");

	char name[MAXNAME + 1];  // holds student name
	float average;  // holds student average

	inData.get(name, MAXNAME + 1); // prime the read
	while(inData){
		inData >> average;
		// FILL IN THE CODE to print out name and 
		// student average
		cout << name << " has a(n) " << average << " average\n";

		// FILL IN THE CODE to complete the while 
		// loop so that the rest of the student
		// names and average are read in properly
		inData.ignore(100, '\n');
		inData.get(name, MAXNAME + 1);
	}

	return 0;
}
//
// Exercise 4: Complete.
