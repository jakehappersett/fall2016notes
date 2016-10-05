#include <iostream>
#include <stdio.h>

using namespace std;

const int SALARY = 0;
const int HOURLY = 1;

class employee
{
	char firstname[50];
	char lastname[50];
	int employeetype;
	double  compensation;

	public: 
	employee();
	void addEmployee();
	void displayEmployee();
};

employee::employee()
{
	cout << "in constructor" << endl;
	employeetype = SALARY;
	compensation = 0.0;
}

void employee::addEmployee()
{
	cout << "enter first name" << endl;
	gets(firstname);
	cout << enter lastname << endl;
	gets(lastname);
	cout << "enter employee type 0 = salary, 1 = hourly" << endl;	
	cin >> employeetype;
	cout << "enter compensation" << endl;
	cin >> compensation;
}
void employee::displayEmployee()
{
	cout << firstname << " " << lastname << " " << endl;
	if (employeetype == SALARY)
		cout << "salaried ";
	else 
		cout << "hourly ";
	cout << compensation << endl;
}

int main()
{
	employee myEmployee;

	myEmployee.addEmployee();
	myEmployee.displayEmployee();
	return 0;
}
