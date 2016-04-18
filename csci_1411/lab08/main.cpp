// Accept an array of ints from the user.
// Sort it, search it, and compute the mean. Display results.
// Author: Mason Thrall, mason.thrall@ucdenver.edu 
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
using namespace std;

const int MAX_SIZE = 50;
typedef int IntArray[MAX_SIZE];

int collectInput(IntArray, int);
void displayArray(IntArray, int);
void selectionSort(IntArray, int);
int binarySearch(IntArray, int, int);
float computeMean(IntArray, int);

int main() {
	IntArray iarray;
	int cmax = 0, val, fIndex;
	cmax = collectInput(iarray, MAX_SIZE);
	cout << "Original Array:\n";
	displayArray(iarray, cmax);
	selectionSort(iarray, cmax);
	cout << "Sorted Array:\n";
	displayArray(iarray, cmax);
	cout << "What do you want to search for?\n";
	cin >> val;
	fIndex = binarySearch(iarray, cmax, val);
	if(fIndex != -1)
		cout << val << " found at index " << fIndex << "\n";
	else
		cout << val << " not found!\n";
	cout << "The size of the list is " << cmax + 1 << endl;
	cout << "The mean of the values entered is: ";
	cout << fixed;
	cout << computeMean(iarray, cmax) << "\n";
	cout << "Goodbye!\n";
	return 0;
}
//**************************************************
// collectInput
//
// Collect input from the user and fill the IntArray.
// Return the size of the filled portion of the array.
//**************************************************
int collectInput(IntArray iarray, int max){
	int cmax = 0;
	string temp;
	for(int i = 0; i < max; i++){
		cout << "Please enter a number or N to stop\n";
		cout << max - i << " spots are left in the array\n";
		cin >> temp;
		if(tolower(temp[0]) == 'n') break;
		iarray[i] = atoi(temp.c_str());
		cmax = i;
	}
	cout << "Finished entering numbers\n";
	return cmax;
}
//**************************************************
// displayArray
//
// Print out the array to the monitor.
//**************************************************
void displayArray(IntArray iarray, int max){
	for(int i = 0; i < max+1; i++){
		cout << iarray[i] << "\n";
	}
}
//**************************************************
// selectionSort
//
// Sort the array using selection sort.
//**************************************************
void selectionSort(IntArray iarray, int max){
	int lowest = iarray[0];
	for(int i = 0; i < max+1; i++){
		for(int j = i; j < max+1; j++){
			if(iarray[j] < iarray[i]){
				int temp = iarray[i];
				iarray[i] = iarray[j];
				iarray[j] = temp;
			}
		}
	}
}
//**************************************************
// binarySearch
//
// Search the array using binary search.
//**************************************************
int binarySearch(IntArray iarray, int max, int val){
	int first = 0, last = max, middle;
	while(first < last){
		middle = first + (last - first)/2;
		if(iarray[middle] == val)
			return middle;
		else if(iarray[middle] > val)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return -1;
}
//**************************************************
// computeMean
//
// Compute the mean of the values of the array.
// Return the mean as a float.
//**************************************************
float computeMean(IntArray iarray, int max){
	int total = 0;
	float mean;
        for(int i = 0; i <= max; i++){
                total += iarray[i];
        }	
	mean = static_cast<float>(total) / (max + 1);
	return mean;
}

