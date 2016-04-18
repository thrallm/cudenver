// This program performs a linear search on an integer array

// Mason Thrall

#include<iostream>
using namespace std;

int searchList(int[], int, int); // function prototype
const int SIZE = 8;
const int EXIT_CODE=-99;

int main(){
	int numList[SIZE] = {3, 6, -19, 5, 5, 0, -2, 99};
	int found;
	int numToFind; 

	do{
		cout << "Enter an integer to search for (" << EXIT_CODE << " to quit):" << endl;
		cin >> numToFind;
		if(numToFind != EXIT_CODE){
			found = searchList(numList, SIZE, numToFind);
			if (found == -1)
				cout << "The integer " << numToFind
             			     << " was not found in the list" << endl;
			else
				cout << "The integer " << numToFind <<" is in the " << found + 1
		     		     << " position of the list" << endl;
		}
	} while (numToFind != EXIT_CODE);
	cout << "Goodbye!\n";
	return 0;

}


//*******************************************************************
//                      searchList
//
// task:	  This searches an array for a particular value
// data in:       List of values in an array, the number of 
//                elements in the array, and the value searched for
//                in the array
// data returned: Position in the array of the value or -1 if value
//                not found
//
//*******************************************************************

int searchList( int List[], int numElems, int value){
	for (int count = 0; count <= numElems; count++){
		if (List[count] == value){
                	// each array entry is checked to see if it contains
	        	// the desired value.
			return count; 
			// if the desired value is found, the array subscript
			// count is returned to indicate the location in the array
		}
	}
	return -1;	// if the value is not found, -1 is returned
}
// Exercise 1: Program is rewritten to work with an array of ints. If you search for 5,
// which is in the array twice, then only the first occurance of 5 is found.
//
// Exercise 2: Code is modified to repeatedly ask.  I chose a post-test loop since I want
// it to run at least once.
