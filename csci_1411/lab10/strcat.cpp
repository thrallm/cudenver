// Strcat, from CSCI 1411-003 lab 10.4
// Author: Mason Thrall, mason.thrall@ucdenver.edu 
#include <iostream>
#include <cstring>
using namespace std;

int main() {

	char string1[20] ="Total Eclipse ";
	char string2[11] = "of the Sun";
	
	cout << string1 << endl;	
	cout << string2 << endl;
	strcat(string1,string2);
	cout << string1 << endl;

	return 0;
}
//
// Exercise 1: Outputs:
// Total Eclipse
// of the Sun
// Total Eclipse of the Sun
//
// Exercise 2: The altered program with a shorter string1 looks like:
// Total Eclipse
// of the Sun
// Total Eclipse of the Sun
//
// It wrote past the end of the array, but the computer allowed it...
