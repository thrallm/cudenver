// This program finds the average time spent programming by a student
// each day over a three day period.

// Mason Thrall

#include <iostream>
using namespace std;

int main()
{
	int weekendLength;
	int numStudents;
	float numHoursProgramming, totalProgramming, averageProgramming; // vars for programming
	float numHoursBiology, totalBiology, averageBiology; // vars for biology
	int student, day = 0;     // these are the counters for the loops

	cout << "This program will find the average number of hours a day" 
	     << " that a student spent programming and studying "
	     << "biology over a long weekend\n\n";
	cout << "How many students are there ?" << endl;
	cin >> numStudents; 
	cout << "How many days long is the weekend?" << endl;
	cin >> weekendLength;
       
	for( student = 1; student <= numStudents; student++){
		totalProgramming = 0;
		totalBiology = 0;
		for(day = 1; day <= weekendLength; day++){
			cout << "Please enter the number of hours worked on programming by student " 
			     << student << " on day " << day << "." << endl;
			cin >> numHoursProgramming;
			cout << "Please enter the number of hours worked on biology by student "
                             << student << " on day " << day << "." << endl;
                        cin >> numHoursBiology;
			totalBiology += numHoursBiology;
			totalProgramming += numHoursProgramming;
		}
		averageProgramming = totalProgramming / weekendLength;
		averageBiology = totalBiology / weekendLength;
		cout << endl;
		cout << "The average number of hours per day spent programming by "
		     << "student " << student << " is " << averageProgramming << endl;
		cout << "The average number of hours per day spent studying biology by "
                     << "student " << student << " is " << averageBiology << endl;
		if (averageProgramming > averageBiology)
			cout << "Student " << student << " studied programming on average more.\n";
		else if (averageBiology > averageProgramming)
			cout << "Student " << student << " studied biology on average more.\n";
		else
			cout << "Student " << student << " studied both subjects the same.\n";
	}
	return 0;	
}
//
// Exercise 1: Code is modified to get the weekend length in days from the user.
//
// Exercise 2: Code is modified to collect and calculate results for biology as well. This should
// probably be made into a function because the calculations for each class are the same and the 
// current version of this code uses too many variables.
