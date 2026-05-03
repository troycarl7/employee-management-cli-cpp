using namespace std;
#include <iostream>
#include <string>
#include "Employee.h"



Employee::Employee(const string& firstName, const string& lastName, double salary, double b, double finalSalary) :firstName(firstName), lastName(lastName), monthlySalary(salary > 0 ? salary : 0),
bonus(b > 0 ? b : 0), finalSalary(monthlySalary* (bonus/100) + monthlySalary) {}
Employee::Employee(const Employee& other) : firstName(other.firstName), lastName(other.lastName), monthlySalary(other.monthlySalary), bonus(other.bonus), finalSalary(other.finalSalary)
{}


Employee::~Employee() {};

string Employee::getFirstName() const
{
	return firstName;
}

string Employee::getLastName() const
{
	return lastName;
}

double Employee::getBaseSalary() const
{
	return monthlySalary;
}

double Employee::getBonus() const {
	return bonus;
}

double Employee::getSalary() const {
	return finalSalary;
}

void Employee::setFirstName(const string& f) {
	firstName = f;
}

void Employee::setLastName(const string& l) {
	lastName = l;
}

void Employee::setBonus(double b) {
	bonus = (b > 0) ? b : 0;
	finalSalary = monthlySalary * (bonus/100) + monthlySalary;
}

void Employee::setBaseSalary(double salary)
{
	monthlySalary = (salary > 0) ? salary : 0;
	finalSalary = monthlySalary * (bonus/100) + monthlySalary;
}
