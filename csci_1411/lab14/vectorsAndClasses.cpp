// This program demonstrates the use of vectors with classes, defines
// operator functions, uses the pointer defererencing (->) operator.
// Compiles on CSE Grid using --std=c++11
// Mason Thrall

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Employee
{
public:
	Employee();
	// mutators
	void setName(string& _name) { name = _name; }
	void setID(string _id) { id = _id; }
	void setSupervisorName(string _name) { supervisor->setName(_name); }
	void setSupervisorID(string _id) { supervisor->setID(_id); }
	void setSupervisor(Employee *_supervisor) { supervisor = _supervisor; }
	// accessors
	string getName() { return name; }
	string getID() { return id; }
	string getSupervisorName() { return supervisor->name; }
	string getSupervisorID() { return supervisor->id; }
	// operators (friends so they can use private)
	friend ostream& operator<< (ostream& _out, Employee& _employee);
private:
	string name;
	string id;
	Employee* supervisor;
};

// default constructor
Employee::Employee() {
	name = "";
	id = -1;
	supervisor = nullptr;
};

ostream& operator<< (ostream& _out, Employee& _employee) {
	_out << "Name: " << _employee.getName() << '\n';
	_out << "ID: " << _employee.getID() << '\n';
	_out << "Supervisor Name: " << _employee.getSupervisorName() << '\n';
	return _out;
}

void inputEmployee(Employee& _employee) {
	string employeeName, supervisorName, id;
	Employee *sPtr = new Employee;

	cout << "Employee Name: ";
	getline(cin, employeeName);
	_employee.setName(employeeName);
	cout << "Employee ID: ";
	getline(cin, id);
	_employee.setID(id);
	cout << "Supervisor Name: ";
	getline(cin, supervisorName);
	_employee.setSupervisor(sPtr);
	_employee.setSupervisorName(supervisorName);
}

void printVector(ostream& _out, vector<Employee>& _employeeVector) {
	for (size_t i = 0; i < _employeeVector.size(); i++) {
		_out << _employeeVector[i] << '\n' << '\n';
	}
}

int main() {
	vector <int> intVector;
	vector <Employee> employeeVector;
	Employee employee1;
	char menu = 'z';

	ifstream infile("input.txt");
	ofstream outfile("output.txt");

	while (menu != 'e') {
		cout << "a. add employee" << endl;
		cout << "b. print all employees to screen" << endl;
		cout << "c. print all employees to file" << endl;
		cout << "e. exit" << endl;
		cin >> menu;
		cin.ignore();
		switch (tolower(menu)) {
		case 'a':
			// add employee
			inputEmployee(employee1);
			employeeVector.push_back(employee1);
			break;
		case 'b':
			// print to monitor
			printVector(cout, employeeVector);
			break;
		case 'c':
			// print to file (doesn't work, not sure why)
			printVector(outfile, employeeVector);
			break;
		case 'e':
			exit(0);
			break;
		default:
			break;
		}
		outfile.close();
	}

	return 0;
}