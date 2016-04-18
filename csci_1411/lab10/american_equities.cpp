// This program tests a password for the American Equities
// web page to see if the format is correct

// Mason Thrall

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std; 

// constants

const int PWLEN = 10;
const int PWLETTERS = 4;
const int PWDIGITS = 6;
const char PWEXAMPLE[11] = "hellot1232";


//function prototypes 

bool testPassWord(char[]);  
int countLetters(char*);
int countDigits(char*);

int main(){
	char passWord[20];  
	
	cout << "Enter a password consisting of exactly " << PWLETTERS << " "
	     << "lower case letters and " << PWDIGITS << " digits:" << endl;
	cin.getline(passWord,20);

	if (testPassWord(passWord))
		cout << "Please wait - your password is being verified" << endl;
	else {
		cout << "Invalid password. Please enter a password "
		     << "with exactly " << PWLETTERS << " lower case letters and " 
		     << PWDIGITS << " digits" << endl
		     << "For example, " << PWEXAMPLE << " is valid" << endl;
	}


	// FILL IN THE CODE THAT WILL CALL countLetters and 
	// countDigits and will print to the screen both the number of
	// letters and digits contained in the password.  
	cout << "The number of lower case Letters is " << countLetters(passWord) << endl;
	cout << "The number of digits is " << countDigits(passWord) << endl;

	return 0;
}


//**************************************************************
//                       testPassWord
//
// task:			determines if the word contained in the
//				    character array passed to it, contains
//					exactly 5 letters and 3 digits.
// data in:			a word contained in a character array
// data returned:   true if the word contains 5 letters & 3
//					digits, false otherwise
//
//**************************************************************
bool testPassWord(char custPass[])
{
	int numLetters, numDigits, length;

	length = strlen(custPass);
    	numLetters = countLetters(custPass);
	numDigits = countDigits(custPass);
	if (numLetters == PWLETTERS && numDigits == PWDIGITS && length == PWLEN )
		return true;
	else
		return false;
}


// the next 2 functions are from Sample Program 10.5
//**************************************************************
//                       countLetters
//
// task:			counts the number of letters (both
//                  capital and lower case in the string
// data in:			a string 
// data returned:   the number of letters in the string
//
//**************************************************************
int countLetters(char *strPtr){
	int occurs = 0;

	while(*strPtr != '\0'){
		if (isalpha(*strPtr) && islower(*strPtr))
			occurs++;
		strPtr++;
	}
	return occurs;
}

//**************************************************************
//                       countDigits
//
// task:			counts the number of digitts in the string
// data in:			a string 
// data returned:   the number of digits in the string
//
//**************************************************************
int countDigits(char *strPtr){  
	int occurs = 0;

	while(*strPtr != '\0'){
		if (isdigit(*strPtr))  // isdigit determines if
			               // the character is a digit
			occurs++;
		strPtr++;
	}

	return occurs;
}
//
// Exercise 1: Code is filled in.
//
// Exercise 2: The program is modified to expect a password of 10 characters with 
// 6 being digits and 4 being letters.
//
// Exercise 3: The program is adjusted to only allow lower case letters.
