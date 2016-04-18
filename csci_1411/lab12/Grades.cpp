// Mason Thrall
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

// This program reads records from a file.  The file contains the
// following: student's name, two test grades and final exam grade. 
// It then prints this information to the screen.

// global constants
const int NAMESIZE = 15;
const int MAXRECORDS = 50;
// prototypes, types, and structs
struct Grades
{
	char name[NAMESIZE + 1];
	int test1;
	int test2;
	int final;
	char letter;
};
typedef Grades gradeType[MAXRECORDS];    
void readIt(ifstream &inData, gradeType gradeRec, int &total);
void computeLetter(Grades &g);

int main() {
	ifstream indata;
	int numRecord;
	gradeType studentRecord;	
	indata.open("graderoll.dat");
	if(!indata) {
		cout << "Error opening file. \n";
		cout << "It may not exist where indicated" << endl;
		return 1;
	}
	readIt(indata, studentRecord, numRecord);
	// output the information 
    	for (int count = 0; count < numRecord; count++) {
	   cout << studentRecord[count].name << setw(10) 
		<< studentRecord[count].test1
		<< setw(10) << studentRecord[count].test2;
	   cout << setw(10) << studentRecord[count].final 
		<< setw(10) << studentRecord[count].letter << endl;
	}
	indata.close();
	return 0;
}
//**************************************************************
//					readIt
//
//  task: This procedure reads records into an array of 
//        records from an input file and keeps track of the 
//	  total number of records
//  data in:  data file containing information to be placed in
//            the array
//  data out: an array of records and the number of records
//
//**************************************************************
void readIt(ifstream &inData, gradeType gradeRec, int &total) {
   	total = 0;
   	inData.get(gradeRec[total].name, NAMESIZE);
   	while (inData) {
     		inData >> gradeRec[total].test1;
     		inData >> gradeRec[total].test2;
     		inData >> gradeRec[total].final;
		computeLetter(gradeRec[total]);
		total++;
     		// FILL IN THE CODE TO CONSUME THE END OF LINE
     		inData.ignore(100, '\n');
     		// FILL IN THE CODE TO READ name 
     		inData.get(gradeRec[total].name, NAMESIZE);
  	}
}
//**************************************************************
// computeLetter
//
// Calculates the letter grade for a Grades struct and inserts it
// back into the Grade struct letter member variable. The grades
// are weighted so that the tests are each worth 30% and the final
// is worth 40%.
//**************************************************************
void computeLetter(Grades &g){
	float temp = .3 * (g.test1 + g.test2) + .4 * g.final;
	if (temp >= 90 && temp <= 100)
		g.letter = 'A';
	else if (temp >= 80 && temp < 90)
		g.letter = 'B';
	else if (temp >= 70 && temp < 80)
		g.letter = 'C';
	else if (temp >= 60 && temp < 70)
		g.letter = 'D';
	else if (temp >= 0 && temp < 60)
		g.letter = 'F';
	else
		g.letter = '?';
}
// Exercise 1: Code is complete. The names occupy no more than 15 chars because the
// char array they are stored in (cstring) is 16 chars long (NAMESIZE + 1). This is 
// because the end of a cstring is the null character '\0'.
//
// Exercise 2:
