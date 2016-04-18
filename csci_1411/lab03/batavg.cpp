// This program will determine the batting average of a player. 
// The number of hits and at bats are set internally in the program.

// name: Mason Thrall

#include <iostream>
using namespace std;


const int AT_BAT = 421;
const int HITS = 123;

int main()
{
	float batAvg;
	batAvg = static_cast<float>(HITS) / AT_BAT; // an assignment statement
	cout << "The batting average is " << batAvg << endl; // output the result

	return 0;
}

/*
Exercise 1:
The batting average in the initial program is 0.

Exercise 2:
After changing batAvg to a float, the output is still 0.

Exercise 3:
Using static_cast<float> to force one of the division operands to be a float,
this allows the output to also be a float.
*/
