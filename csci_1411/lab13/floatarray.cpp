// Mason Thrall
// This program reads floating point data from a data file and places those
// values into the private data member called values (a floating point array)
// of the FloatList class. Those values are then printed to the screen.
// The input is done by a member function called GetList. The output 
// is done by a member function called PrintList.  The amount of data read in
// is stored in the private data member called length.  The member function
// GetList is called first so that length can be initialized to zero.

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_LENGTH = 50; // MAX_LENGTH contains the maximum length of our list
class FloatList {
public:
	void getList(ifstream&);   // Member function that gets data from a file
	void printList() const;    // Member function that prints data from that
							   // file to the screen.
	FloatList();               // constructor that sets length to 0.  
	~FloatList();			   // destructor
	float findAverageTemp();

private:
	int length;                // Holds the number of elements in the array
	float values[MAX_LENGTH];  // The array of values

};

int main() {
	ifstream tempData;   // Defines a data file
						 // Fill in the code to define an object called list of the class FloatList
	FloatList list;

	cout << fixed << showpoint;
	cout << setprecision(2);

	tempData.open("temperatures.txt");


	// Fill in the code that calls the getList function.
	list.getList(tempData);
	// Fill in the code that calls the printList function.
	list.printList();
	cout << "The average temperature is ";
	cout << list.findAverageTemp() << endl;
	return 0;
}

FloatList::FloatList() {
	// Fill in the code to complete this constructor that
	// sets the private data member length to 0
	length = 0;
}

// Fill in the entire code for the  getList function
// The getList function reads the data values from a data file
// into the values array of the class FloatList
void FloatList::getList(ifstream& strm) {
	while(strm && length < MAX_LENGTH) {
		strm >> values[length];
		length++;
	}
}

// Fill in the entire code for the  printList function
// The printList function prints to the screen the data in 
// the values array of the class FloatList
void FloatList::printList() const {
	for (int i = 0; i < length - 1; i++) {
		cout << values[i] << endl;
	}
}

// Fill in the code for the implementation of the destructor
FloatList::~FloatList() {
	cout << "FloatList destroyed!\n";
}
float FloatList::findAverageTemp() {
	float sum = 0.0;
	for (int i = 0; i < length - 1; i++) {
		sum += values[i];
	}
	return (sum / (length - 1));
}
// Exersize 1: printList() has a const after it since it shouldn't to modify any member variables.
// So to be safe, it is made a const so it would be impossible to make a mistake and make it modify a member var.
// Exersize 2: Code is complete.
// Exersize 3: Code for findAverageTemp() is added.