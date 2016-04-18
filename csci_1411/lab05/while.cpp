// Mason Thrall

#include <iostream>
using namespace std;

int main()
{
	char letter = 'a';

	do {
           cout << "Please enter a letter (entering x will quit)" << endl; 
           cin >> letter;
           cout << "The letter you entered is " << letter << endl;
	} while (letter != 'x');

	return 0;	
}
//
// Exercise 1: The program is not user friendly because it doesnt tell you
// about the option 'x' which will exit the program.
//
// Exercise 2: I put a note that x will quit in the instructions.
//
// Exercise 3: Adding the quit instruction to the code does not affect how it is 
// run when it is switched to a do-while loop. It is just more clear how to use it.
// Since do-while is a post test loop, then do-while would work once even if 
// the initial value of letter was 'x'.
//
