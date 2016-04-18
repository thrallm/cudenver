// This program illustrates the use of the Switch statement.
// name: Mason Thrall

#include <iostream>
using namespace std;

int main()
{
	char grade;
	bool logicType;

	cout << "Do you want to use the switch? (1 for yes and 0 for no)" << endl;
        cin >> logicType;
	cin.ignore(); // to skip the \n from the previous cin since using cin.get().
	cout << "What grade did you earn in Programming I? (A, B, C, D, or F)" << endl;
	cin.get(grade);

	if ( logicType ) {
		cout << ".....Using the switch method....." << endl;	
		switch( grade ) {
			case 'A':
				cout << "an A - excellent work !" << endl;
				break;
			case 'B':
				cout << "you got a B - good job" << endl;
				break;
			case 'C':  
				cout << "earning a C is satisfactory" << endl;
				break;
			case 'D':
				cout << "while D is passing, there is a problem" << endl;
				break;
       			case 'F':
				cout << "you failed - better luck next time" << endl;
				break;
       			default:
				cout << "You did not enter an A, B, C, D, or F" << endl;
		}
	} else {
		cout << ".....Using the if/else if/else method....." << endl;	
		if ( grade == 'A' )
			cout << "an A - excellent work !" << endl;
		else if ( grade == 'B' )
			cout << "you got a B - good job" << endl;
		else if ( grade == 'C' )
			cout << "earning a C is satisfactory" << endl;
		else if ( grade == 'D' )
			cout << "while D is passing, there is a problem" << endl;
		else if ( grade == 'F' )
			cout << "you failed - better luck next time" << endl;
		else
			cout << "You did not enter an A, B, C, D, or F" << endl;
	}
	
	switch( grade <= 'D' ) {
                case true:
                        cout << "YOU PASSED!" << endl;
                        break;
                case false:
                        cout << "YOU FAILED!" << endl;
                        break;
        }

	return 0;
}

// Exercise 1:
// Removing all the break statements makes the program execute all of the cases after the
// case which it matches instead of only the intended case.
//
// Exercise 2:
// Pass/Fail switch statement is added.
//
// Exercise 3:
// The trailing else in the else/else if/else version correspinds to the 
// default case in the switch statement.
