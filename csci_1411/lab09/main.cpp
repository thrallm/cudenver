// CSCI 1411-003 Lab09 - 9.4 option 1
// Author: Mason Thrall, mason.thrall@ucdenver.edu 
#include <iostream>
using namespace std;

// prototypes
void sort(float*, int);
void swapFloats(float&, float&);
void printScores(float*, int);

int main() {
	float *scores; // to hold dynamic array
	int numScores;
	float total;
	float average;

	cout << "Please input the number of scores\n";
	cin >> numScores;
	cin.ignore();
	scores = new float[numScores];

	// loop up to numScores and input to the array.
	for(int i = 0; i < numScores; i++){
		cout << "Please enter a score\n";
		cin >> scores[i];
		total += scores[i];
	}
	average = total / numScores;
	cout << "The average of the scores is " << average << endl;
	cout << "Here are the scores in ascending order\n";
	sort(scores, numScores);
	printScores(scores, numScores);
	delete [] scores;
	return 0;
}
//****************************************************
// sort()
// bubble sort a dynamic float array
//****************************************************
void sort(float* a, int size){
	bool swap;
	do{
		swap = false;
		for(int i = 0; i < size - 1; i++){
			if(a[i] > a[i + 1]){
				swapFloats(a[i], a[i + 1]);
				swap = true;
			}
		}	
	}while(swap);
}
//****************************************************
// printScores()
// print out a dynamic float array one elem per line
//****************************************************
void printScores(float* a, int size){
	for(int i = 0; i < size; i++){
		cout << a[i] << endl;
	}
}
//****************************************************
// swapFloats()
// Swap values in a and b
//****************************************************
void swapFloats(float& a, float& b){
	float temp = a;
	a = b;
	b = temp;
}
