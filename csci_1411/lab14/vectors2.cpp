// This program demonstrates the use of vectors with classes, defines
// operator functions, uses the pointer defererencing (->) operator.
// Compiles on CSE Grid using --std=c++11
// Mason Thrall

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// prototypes
class Employee;
ostream& operator<< (ostream& _out, Employee& _employee);
istream& operator>> (istream& _in, Employee& _employee);
void inputEmployee(Employee& _employee);
void printVector(ostream& _out, vector<Employee>& _employeeVector);
void readFromFile(istream& _in, vector<Employee>& _employeeVector);

class Employee {
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
	friend istream& operator>> (istream& _in, Employee& _employee);
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
	_out << "Name: " << _employee.name << '\n';
	_out << "ID: " << _employee.id << '\n';
	_out << "Supervisor Name: " << _employee.supervisor->name << '\n';
	_out << "Supervisor ID: " << _employee.supervisor->id << '\n';
	return _out;
}

istream& operator>> (istream& _in, Employee& _employee) {
	string temp;
	Employee *sPtr = new Employee;
	getline(_in, temp);
	_employee.name = temp;
	getline(_in, temp);
	_employee.id = temp;
	getline(_in, temp);
	_employee.supervisor = sPtr;
	_employee.supervisor->name = temp;
	getline(_in, temp);
	_employee.supervisor->id = temp;
	return _in;
}

void inputEmployee(Employee& _employee) {
	string employeeName, supervisorName, id, supervisorID;
	Employee *sPtr = new Employee;

	cout << "Employee Name: ";
	getline(cin, employeeName);
	_employee.setName(employeeName);
	cout << "Employee ID: ";
	getline(cin, id);
	_employee.setID(id);
	cout << "Supervisor Name: ";
	getline(cin, supervisorName);
	cout << "Supervisor ID: ";
	getline(cin, supervisorID);
	_employee.setSupervisor(sPtr);
	_employee.setSupervisorName(supervisorName);
	_employee.setSupervisorID(supervisorID);
}

void printVector(ostream& _out, vector<Employee>& _employeeVector) {
	for (size_t i = 0; i < _employeeVector.size(); i++) {
		_out << _employeeVector[i] << '\n' << '\n';
	}
}

void readFromFile(istream& _in, vector<Employee>& _employeeVector) {
	Employee *ePtr = nullptr;
	ePtr = new Employee;
	char c = _in.peek();
	while (c != EOF) {
		_in >> *ePtr;
		_employeeVector.push_back(*ePtr);
		c = _in.peek();
	}
	delete ePtr;
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
		cout << "d. read from file" << endl;
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
		case 'd':
			// read from file
			readFromFile(infile, employeeVector);
			break;
		case 'e':
			//exit(0);
			break;
		default:
			break;
		}
		outfile.close();
	}

	return 0;
}