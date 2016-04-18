// This program demonstrates the use of dynamic variables
// Mason Thrall

#include <iostream>
using namespace std;

const int MAXNAME = 10;

int main(){
	int pos;
	char *name;
	int *one;
	int *two;
	int *three;
	int result;

	//  Fill in code to allocate the integer variable one here
	one = new int;
	//  Fill in code to allocate the integer variable two here
	two = new int;
	//  Fill in code to allocate the integer variable three here
	three = new int;
	//  Fill in code to allocate the character array pointed by name
	name = new char[MAXNAME];

	cout << "Enter your last name with exactly 10 characters." << endl;
	cout << "If your name has < 10 characters, repeat last letter. " << endl
	     << "Blanks at the end do not count." << endl;
   
	for(pos = 0; pos < MAXNAME; pos++){
		cin >> *(name + pos);
		// cin >> name[pos];
		// Fill in code to read a character into the name array
        	// WITHOUT USING a bracketed subscript
	}
	cout << "Hi ";
	for ( pos = 0;  pos < MAXNAME;  pos++){
   		//cout << *(name + pos);
		cout << name[pos];
		// Fill in code to a print a character from the name array
                // WITHOUT USING a bracketed subscript
	}
  
	cout << endl << "Enter three integer numbers separated by blanks" << endl;

	// Fill in code to input three numbers and store them in the
	// dynamic variables pointed to by pointers one, two, and three.
	// You are working only with pointer variables
	cin >> *one >> *two >> *three;

	//echo print
	cout << "The three numbers are " << endl;

	// Fill in code to output those numbers
	cout << *one << " " << *two << " " << *three << endl;

	result = *one + *two + *three;
	// Fill in code to calculate the sum of the three numbers
	cout << "The sum of the three values is " << result << endl;
	// Fill in code to deallocate one, two, three and name
	delete one;
	delete two;
	delete three;
	delete name;
	
	return 0;
}
// Exercise 1: Program is complete.
// Exercise 2: The bracket subscript is unnecessary since an array variable is a beginning memory address,
// and an array is a sequence of contiguous memory locations. Since they are contiguous memory locations, 
// it is possible to do pointer arithmatic to access the locations in sequence. Since the array is defined
// as an array of chars, which are each two bytes, *(name + 2) indicates moving over two locations of two bytes,
// thus 4 bytes over. Using name[pos] works for both input and output because it also tells the program to get the
// value of the next memory location in the array.
