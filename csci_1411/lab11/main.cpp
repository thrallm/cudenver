// CSCI 1411-003
// Lab 11
// Question 11.5
// Option 1
// Author: Mason Thrall, mason.thrall@ucdenver.edu 
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Point {
	float x, y;
};

struct Circle {
	Point center;
	float radius;
	float area; 
	float circumference;
	float distance_from_origin;
};

const float PI = 3.14159;
const int SIZE = 6;

// prototypes
void computeArea(Circle &c);
void computeCircumference(Circle &c);
void computeOriginDist(Circle &c);
void printCircleInfo(Circle c);
int findClosestToOrigin(Circle circles[], int size);

int main() {
	Circle circles[SIZE];
	cout << setprecision(2) << fixed << showpoint;
	cout << "Please enter circle info below:\n";
	for(int i = 0; i < SIZE; i++) {
		cout << "What is the radius for circle #" << i + 1 << " ";
		cin >> circles[i].radius;
		cout << "What is the x coordinate for circle #" << i + 1 << " ";
		cin >> circles[i].center.x;
		cout << "What is the y coordinate for circle #" << i + 1 << " ";
		cin >> circles[i].center.y;
		computeArea(circles[i]);
		computeCircumference(circles[i]);
		computeOriginDist(circles[i]);
	}
	cout << "Circle info entered:\n";
	for(int i = 0; i < SIZE; i++) {
		cout << "Circle #" << i + 1<< endl;
		printCircleInfo(circles[i]);
	}
	int closest = findClosestToOrigin(circles, SIZE);
	cout << "The closest circle to the origin is ";
	cout << "circle #" << closest + 1 << endl;
	return 0;
}

//***********************************
// computeArea
// Compute the area of the circle
// and put it in the area member var.
//***********************************
void computeArea(Circle &c) {
	c.area = PI * pow(c.radius, 2);
}

//***********************************
// computeCircumference
// Compute the circumference of the circle
// and put it in the circumference member var.
//***********************************
void computeCircumference(Circle &c) {
	c.circumference = 2 * PI * c.radius;
}

//***********************************
// computeOriginDist
// Compute the distance from the circle center
// to the origin and put it in the 
// distance_from_origin member var.
//***********************************
void computeOriginDist(Circle &c) {
	c.distance_from_origin = sqrt(pow(c.center.x, 2.0) + pow(c.center.y, 2.0));
}

//***********************************
// printCircleInfo
// Print info about the circle to cout.
//***********************************
void printCircleInfo(Circle c){
	cout << "The area is " << c.area << endl;
	cout << "The circumference is " << c.circumference << endl;
	cout << "The distance from the origin is " << c.distance_from_origin << endl;
}
//***********************************
// findClosestToOrigin
// Compare distance_from_origin for all
// circles.
// return the index of the smallest.
//***********************************
int findClosestToOrigin(Circle circles[], int size) {
	int smallestI = 0;
	float smallest = circles[0].distance_from_origin;
	for(int i = 1; i < size; i++) {
		if(circles[i].distance_from_origin < smallest) {
			smallest = circles[i].distance_from_origin;
			smallestI = i;
		}
	}
	return smallestI;
}
