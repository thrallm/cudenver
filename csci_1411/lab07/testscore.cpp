// This program will read in a group of test scores( positive integers from 1 to 100)
// from the keyboard and then calculates and outputs  the average score
// as well as the highest and lowest score. There will be a maximum of 100 scores.
// Mason Thrall

#include <iostream>
#include <fstream>
using namespace std;

typedef int GradeType[100];  // declares a new data type: 
                             // an integer array of 100 elements

float findAverage (const GradeType, int);  // finds average of all grades
int findHighest (const GradeType, int);  // finds highest of all grades
int findLowest  (const GradeType, int);  // finds lowest of all grades

int main()
{
	GradeType grades;	// the array holding the grades.
	int numberOfGrades;	// the number of grades read.
	int pos;		// index to the array.
	float avgOfGrades;	// contains the average of the grades.
	int highestGrade;	// contains the highest grade.
	int lowestGrade;	// contains the lowest grade.
	ifstream gradeFile;

	pos = 0;
	gradeFile.open("gradfile.txt"); // open the file
	while(!gradeFile.eof()){
		gradeFile >> grades[pos]; // read file line into array
		pos++;
	}
	gradeFile.close(); // dont forget to close the file

	numberOfGrades = pos;  // Fill blank with appropriate identifier
	// call to the function to find average
	avgOfGrades = findAverage(grades, numberOfGrades);
	cout << endl << "The average of all the grades is " << avgOfGrades << endl;
	//  Fill in the call to the function that calculates highest grade
	highestGrade = findHighest(grades, numberOfGrades);
	cout << endl << "The highest grade is " << highestGrade << endl;
	// Fill in the call to the function that calculates lowest grade
	lowestGrade = findLowest(grades, numberOfGrades);
	// Fill in code to write the lowest to the screen
	cout << endl << "The lowest grade is " << lowestGrade << endl;

	return 0;
}

//****************************************************************************
//                                 findAverage
//
// task:          This function receives an array of integers and its size.
//                It finds and returns the average of the numbers in the array
// data in:       array of floating point numbers
// data returned: avarage of the numbers in the array
//
//****************************************************************************

float findAverage (const GradeType array, int size)
{
	float sum = 0;   // holds the sum of all the numbers	
	for (int pos = 0; pos < size; pos++)
		sum = sum + array[pos];
	return (sum / size);  //returns the average  
}

//****************************************************************************
//                                 findHighest
//
// task:          This function receives an array of integers and its size.
//                It finds and returns the highest value of the numbers in
//                the array
// data in:       array of floating point numbers
// data returned: highest value of the numbers in the array
//
//****************************************************************************

int findHighest (const GradeType array, int size)
{
	int highest = 0;
	// Fill in the code for this function
	for (int pos = 0; pos < size; pos++)
		array[pos] > highest ? highest = array[pos] : highest = highest;	
	return highest;
}

//****************************************************************************
//                                 findLowest
//
// task:          This function receives an array of integers and its size.
//                It finds and returns the lowest value of the numbers in 
//                the array
// data in:       array of floating point numbers
// data returned: lowest value of the numbers in the array
//
//****************************************************************************

int findLowest (const GradeType array, int size)
{
	// Fill in the code for this function
	int lowest = array[0];
	for (int pos = 0; pos < size; pos++)
		array[pos] < lowest ? lowest = array[pos] : lowest = lowest;
	return lowest;
}
//
// Exercise 1: Program is completed.
//
// Exercise 2: 
//
// When running with the specified input, the output is:
// The average of all the grades is 67.5
//
// The highest grade is 90
//
// The lowest grade is 45
//
// Exercise 3: The program is modified to use the gradfile.txt
