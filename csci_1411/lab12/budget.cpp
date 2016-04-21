// Mason Thrall
// This program reads in from the keyboard a record of financial information
// consisting of a person's name, income, rent, food cost, utilities and
// miscellaneous expenses.  It then determines the net money
// (income minus all expenses)and places that information in a record
// which is then written to an output file.

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

const int NAMESIZE = 15;
const int MAXSIZE = 10;
struct Budget  //declare a structure to hold name and financial information
{
	char name[NAMESIZE + 1];
	float income;       // person's monthly income
	float rent;         // person's monthly rent
	float food;         // person's monthly food bill
	float utilities;    // person's monthly utility bill
	float miscell;      // person's other bills
	float net;          // person's net money after bills are paid
};
// prototypes
void inputData(Budget &b);
void outputTextFile(ofstream& o, Budget b[], int size);

int main() {
	fstream indata;
	ofstream outdata;
	char choice;
	int size = 0;
	Budget people[MAXSIZE];
	Budget people2[MAXSIZE];
	// input
	for (int i = 0; i < MAXSIZE; i++) {
	   inputData(people[i]);
	   people[i].net = people[i].income - people[i].rent - people[i].food - people[i].utilities - people[i].miscell;
	   cout << "Enter another person? (Y|N)\n";
	   cin.get(choice);
	   cin.ignore();
	   size++;
	   if(toupper(choice) != 'Y') {
		   break;
	   }
	}
	cout << "Thats all the data\n";
	// write bin file
	indata.open("income.dat", ios::out | ios::binary);
	indata.write(reinterpret_cast<char *>(people), sizeof(people));
	indata.close();
	// read bin file
	indata.open("income.dat", ios::in | ios::binary);
	indata.read(reinterpret_cast<char *>(people2), sizeof(people2));
	indata.close();
	// write text file
	outdata.open("student.out");
	outdata << left << fixed << setprecision(2);
	outputTextFile(outdata, people2, size);
	return 0;
}

void outputTextFile(ofstream& o, Budget b[], int size){
	o << setw(20) << "Name" << setw(10) << "Income" << setw(10) << "Rent"
	  << setw(10) << "Food" << setw(15) << "Utilities" << setw(15)
	  << "Miscellaneous" << setw(10) << "Net Money" << endl << endl;
	for (int i = 0; i < size; i++) {
		o << setw(20) << b[i].name << setw(10) << b[i].income << setw(10) << b[i].rent
		  << setw(10) << b[i].food << setw(15) << b[i].utilities << setw(15)
		  << b[i].miscell << setw(10) << b[i].net << endl;
	}
}

void inputData(Budget &b){
	cout << "Enter the following information" << endl;
	cout << "Person's name: ";
	cin.getline(b.name, NAMESIZE);
	cout << "Income :";
	cin >> b.income;
	cout << "Rent :";
	cin >> b.rent;
	cout << "Food :";
	cin >> b.food;
	cout << "Utilities :";
	cin >> b.utilities;
	cout << "Miscellaneous :";
	cin >> b.miscell;
	cin.ignore();
}
// Exercise 1: Program is complete.
// Exercise 2: Program is modified to accept an array of Budget structures.
