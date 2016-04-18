////////////////////////////////////////////////////////////////
// CSCI 1411-003, lab10.5, exercise 1
// Write a program to accept input of a word, then
// determine if it is a palindrome, and let the user know.
// Author: Mason Thrall, mason.thrall@ucdenver.edu
////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
using namespace std;

const short MAXSIZE = 50;

bool checkPanindrome(char[], int);

int main() {
	char word[MAXSIZE];
	int wordlen;

	cout << "Please enter a word up to " << MAXSIZE << " characters long.\n";
	cout << "This program will let you know if it is a palindrome.\n";
	cin.getline(word, MAXSIZE);
	cout << "You picked " << word << endl;
	wordlen = strlen(word);
	if (checkPanindrome(word, wordlen)) {
		cout << word << " is a palindrome!\n";
	}
	else {
		cout << word << " is not a palindrome :(\n";
	}
	return 0;
}
//**********************************************************************************
//checkPalindrome
//
// This checks every letter, when you only actually need to check half of them.
// Inefficient, yes, but it is not a very long word or a frequently used program.
//**********************************************************************************
bool checkPanindrome(char word[], int len) {
	short matchCount = 0;
	for (int i = 0; i < len; i++) {
		cout << word[i] << " vs. " << word[len - i - 1] << "\n";
		if (word[i] == word[len - i - 1]) {
			matchCount++;
		}
	}
	return matchCount == len ? true : false;
}
