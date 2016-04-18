/*
Class: CSCI 1411-003
Name: Mason Thrall
Date: 02/04/2016
Assignment: Lab 3.5
Assignment Choice: Option 1
*/
#include <iostream> // for input and output
#include <iomanip> // to format the float decimal points.
using namespace std;

int main()
{
	// declare the variables
	int firstGrade, secondGrade, thirdGrade;
	double averageGrade;
	
	// set formatting options
	cout <<  fixed << setprecision(2) << showpoint;
	// collect the input
	cout << "Please input the first grade: " << endl;
	cin >> firstGrade;
        cout << "Please input the second grade: " << endl;
	cin >> secondGrade;
        cout << "Please input the third grade: " << endl;
	cin >> thirdGrade;
	// Compute the averageGrade.
	averageGrade = (firstGrade + secondGrade + thirdGrade)/3.0;
	// display the average grade
	cout << "The average of the three grades is : " << averageGrade << endl; 

	return 0;
}
