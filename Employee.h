#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <string>
using namespace std;

class Employee {
private:
	string firstName;
	string lastName;
	double monthlySalary;
	double bonus;
	double finalSalary;

public:
	
	Employee(const string& firstName, const string& lastName, double baseSalary, double bonus, double salary);
	Employee(const Employee& other);


	~Employee();

	string getFirstName() const;
	string getLastName() const;
	double getBaseSalary() const;
	double getBonus() const;
	double getSalary() const;

	void setFirstName(const string& f);
	void setLastName(const string& l);
	void setBaseSalary(double monthlySalary);
	void setBonus(double b);
};
#endif

