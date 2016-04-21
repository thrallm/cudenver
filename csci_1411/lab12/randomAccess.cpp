// Mason Thrall
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main()
{
	fstream inFile("proverb.txt", ios::in);
	long offset;
	char ch;
	char more;

	do
	{
		//  Fill in the code to write to the screen
		//  the current read position (with label)
		cout << "Current read position is: ";
		cout << inFile.tellg() << endl;
		cout << "Enter an offset from the current read position: ";
		cin >> offset;

		//  Fill in the code to move the read position "offset" bytes
		//  from the current read position.
		inFile.seekg(offset, ios::cur);

		//  Fill in the code to get one byte of information from the file
		//  and place it in the variable "ch".
		inFile.get(ch);

		cout << "The character read is "  << ch << endl;
		cout << "If you would like to input another offset enter a Y" << endl;

		cin >> more;

		//  Fill in the code to clear the eof flag.

	} while (toupper(more) == 'Y');

	inFile.close();
	return 0;
}
// Exercise 1: Program completed.
// Exercise 2: Once you read past the EOF, then the seekp cant get a new value, so it returns the old one again.
// To get another letter using seekp, you would need to use clear() on the inFile.
