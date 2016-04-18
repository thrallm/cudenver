// Assignment: Lab05 - question 7.4 option 1
// Author: Mason Thrall, mason.thrall@ucdenver.edu 
#include <iostream>
using namespace std;

// Constants
const int MIN_AGE = 0;
const int MAX_AGE = 100;
const int QUIT_CODE = -99;
// Array Types
typedef int AgesType[MAX_AGE];
//Function Prototypes
void getAges(AgesType);
void printAges(AgesType, int);
bool validInput(int, int, int);

// Global variables
AgesType ages; // global so it will be all zero

int main() {	
	getAges(ages);
	printAges(ages, MAX_AGE);
	return 0;
}

//*************************************************
// getAges
// Loop and ask for ages and increment ages array 
// at the appropriate index.
//*************************************************
void getAges(AgesType ages){
	int input = 0;
	while(input != QUIT_CODE){
		cout << "Please input an age from one to 100, put -99 to stop\n";
		cin >> input;
		if(validInput(input, MIN_AGE, MAX_AGE))
			ages[input]++;
		else
			cout << "Invalid input\n";
	}
}
//*************************************************
// printAges
// Loop through ages array and print the values.
//*************************************************
void printAges(AgesType ages, int arrayLen){
	for(int i = 0; i < arrayLen; i++){
		if(ages[i] > 0){
			cout << "The number of people " << i;
			cout << " years old is " << ages[i] << "\n";
		}
	}
}
//*************************************************
// bool validInput
// Return if input is valid for the age range.
//*************************************************
bool validInput(int input, int minAge, int maxAge){
	return input > minAge && input <= maxAge ? true : false;
}
