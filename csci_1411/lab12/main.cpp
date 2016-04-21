// Mason Thrall
// CSCI 1411
// Lab 12
// Question 12.5

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

const int NAME_SIZE = 15;
const int ADDRESS_SIZE = 30;
const int CITY_SIZE = 20;
const int STATE_SIZE = 5;
const int MAXSIZE = 20;
char IN_DAT[NAME_SIZE] = "in.dat";
char OUT_TXT[NAME_SIZE] = "out.txt";
struct PersonInfo
{
	char first_name[NAME_SIZE + 1];
	char last_name[NAME_SIZE + 1];
	char street[ADDRESS_SIZE + 1];
	char city[CITY_SIZE + 1];
	char state[STATE_SIZE + 1];
	long zip;
};
// prototypes
void inputData(PersonInfo &b);
void outputTextFile(ofstream& o, PersonInfo b[], int size);

int main() {
	fstream indata;
	ofstream outdata;
	char choice;
	int size = 0;
	PersonInfo people[MAXSIZE];
	PersonInfo people2[MAXSIZE];
	// input
	for (int i = 0; i < MAXSIZE; i++) {
	   inputData(people[i]);
	   cout << "Enter another person? (Y|N)\n";
	   cin.get(choice);
	   cin.ignore(100, '\n');
	   size++;
	   if(toupper(choice) != 'Y') {
		   break;
	   }
	}
	cout << "Thats all the data\n";
	indata.open(IN_DAT, ios::out | ios::binary);
	indata.write(reinterpret_cast<char *>(people), sizeof(people));
	indata.close();
	// read bin file
	indata.open(IN_DAT, ios::in | ios::binary);
	indata.read(reinterpret_cast<char *>(people2), sizeof(people2));
	indata.close();
	// write text file
	outdata.open(OUT_TXT);
	outdata << left << fixed << setprecision(2);
	outputTextFile(outdata, people2, size);
	return 0;
}

void outputTextFile(ofstream& o, PersonInfo b[], int size){
	o << setw(20) << "First Name" << setw(10) << "Last Name" 
	  << setw(20) << "Street" << setw(10) << "City" 
	  << setw(20) << "State" << setw(10) << "Zip" << endl << endl;
	for (int i = 0; i < size; i++) {
		o << setw(20) << b[i].first_name << setw(10) << b[i].last_name 
		  << setw(20) << b[i].street << setw(10) << b[i].city 
		  << setw(20) << b[i].state << setw(10) << b[i].zip << endl;
	}
}

void inputData(PersonInfo &b){
	cout << "Enter the following information" << endl;
	cout << "First name: ";
	cin.getline(b.first_name, NAME_SIZE);
	cout << "Last name: ";
	cin.getline(b.last_name, NAME_SIZE);
	cout << "Street: ";
	cin.getline(b.street, ADDRESS_SIZE);
	cout << "City: ";
	cin.getline(b.city, CITY_SIZE);
	cout << "State: ";
	cin.getline(b.state, STATE_SIZE);
	cout << "Zip: ";
	cin >> b.zip;
	cin.ignore(100, '\n');
	cin.clear();
}
