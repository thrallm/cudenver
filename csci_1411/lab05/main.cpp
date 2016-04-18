// Assignment: Lab 05 - question 5.6 - option 2
// Author: Mason Thrall, mason.thrall@ucdenver.edu 
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	// define constants
	const float GRAVITY = 9.8; // meters/second
	// declare vars
	int time;
	float height;
	float distance;
	// collect input
	cout << "This program will calculate how far a watermelon thrown"
	     << " off a bridge will fall per second." << endl;
	cout << "Please input the time the watermelon fell: " << endl;
	cin >> time;
	cout << "Please input the height of the bridge:" << endl;
	cin >> height;
	cout << "Time Falling (seconds)\tDistance Fallen (meters)" << endl;
	cout << "************************************************" << endl;
	// loop for each second
	// calculate the distance fallen
	// output the second and the distance fallen
	for (int t = 0; t <= time; t++){
		distance = 0.5 * GRAVITY * t * t;
		cout << t << "\t\t\t" << distance << endl;
	}
	//
	// check if distance fallen is > height
	// print warning if true
	if (distance > height){
		cout << "Warning-Bad Data: The distance fallen exceeds" 
		     << "the height of the bridge!" << endl;
	}
	return 0;
}
