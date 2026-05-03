# employee-management-cli-cpp
Employee Management System in C++  A command-line employee management system built in C++ using object-oriented programming. The program allows users to add, delete, search, display, and modify employee information through an interactive menu.

### Employee.h
Defines the `Employee` class interface.  
It contains the employee attributes and declares the constructors, destructor, getters, and setters used to manage employee data.

The class stores:
- First name
- Last name
- Monthly salary
- Bonus percentage
- Final salary

### Employee.cpp
Implements the functions declared in `Employee.h`.

This file handles:
- Constructor initialization
- Copy constructor behavior
- Getter functions
- Setter functions
- Automatic recalculation of final salary when salary or bonus is modified

### main.cpp
Contains the main program logic and user interface.

The program uses a `vector<Employee>` to store multiple employee objects dynamically. Users can interact with the system through a menu to:

- Add new employees
- Delete existing employees
- Search employees by first or last name
- Display the full employee list
- Modify employee information
- Exit the program

Concepts Demonstrated

- Object-oriented programming
- Classes and objects
- Header and implementation file separation
- Constructors and copy constructors
- Getters and setters
- Vectors
- String handling
- Menu-based program flow
- Input validation
