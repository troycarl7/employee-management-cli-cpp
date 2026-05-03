#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include "Employee.h"
using namespace std;



int main()
{
    string x;
    
    vector<Employee> e;
    e.push_back(Employee ("John", "Doe", 1000, 2, 1020));
    e.push_back(Employee("Marie", "Florence", 2000, 5, 2100));
    e.push_back(Employee("Joseph", "Trent", 1500, 10, 1650));
    e.push_back(Employee("Peter", "Rock", 1000, 7, 1070));
    e.push_back(Employee("Paul", "Tarsus", 1300, 1, 1313));
    e.push_back(Employee("Elliott", "James", 3000, 15, 3450));
    e.push_back(Employee("Thomas", "Aquinas", 2500, 10, 2750));
    e.push_back(Employee("Andrea", "Petros", 5000, 1, 5050));
    e.push_back(Employee("Jude", "Simon", 7000, 12, 7840));
    e.push_back(Employee("Timothy", "Petra", 2350, 6, 2491));
    e.push_back(Employee("Therese", "Avila", 1250, 19, 1487.50));

    do {
        do {

            cout << "\nWelcome to the MAIN MENU, please capitalize the first letter of every name." << endl;
            cout << "Option 1 -> Add employee\nOption 2 -> Delete employee\nOption 3 -> Search employee\n";
            cout << "Option 4 -> Look at the list of employee\nOption 5 -> Modify employee info\nOption 6 -> Exit\n";
            cout << "Select an option: ";
            cin >> x;
            if (x != "1" && x != "2" && x != "3" && x != "4" && x != "5" && x != "6")
                cout << "Invalid input, retry...\n";
            else {
                cout << "Valid input...\n";
                if (x == "1") cout << "\nAn employee will be added...\n\n";
                else if (x == "2") cout << "\nAn employee will be deleted...\n";

                else if (x == "6") { cout << "\nProgram exited..." << endl; return 0; }
                else if (x == "4") {
                    cout << "\nGenerating list..." << endl;
                    cout << "\nList of Employees:" << endl;
                    for (size_t i = 0; i < e.size(); ++i) {
                        cout << left << setw(15) << e[i].getLastName() << setw(15) << e[i].getFirstName() <<
                            setw(15) << e[i].getBaseSalary() << setw(8) << e[i].getBonus() << setw(15) << e[i].getSalary() << endl;

                    }
                    cout << "Coming back to MAIN MENU automatically..." << endl;
                }
                else if (x == "5") {

                }
            }
        } while (x != "1" && x != "2" && x != "3" && x != "4" && x != "5" && x != "6");

        int s = stoi(x);
        switch (s) {
        case 1: {
            int choice = 0;
            do {
                string first, last;
                double month, bonus, finalS;

                cout << "Enter the first name of the employee: ";
                cin >> first;
                cout << "Enter the last name of the employee: ";
                cin >> last;
                cout << "Enter the monthly salary: ";
                cin >> month;
                cout << "Enter the bonus %: ";
                cin >> bonus;
                finalS = month * (bonus / 100) + month;
                Employee a(first, last, month, bonus, finalS);
                e.push_back(a);
                cout << left << setw(15) << "Last Name" << setw(15) << "First name" << setw(15)
                    << "Base Salary" << setw(8) << "Bonus" << setw(15) << "Final Salary" << endl;
                for (size_t i = 0; i < e.size(); ++i) {
                    cout << setw(15) << e[i].getLastName() << setw(15) << e[i].getFirstName() <<
                        setw(15) << e[i].getBaseSalary() << setw(8) << e[i].getBonus() << setw(15) << e[i].getSalary() << endl;
                }


                do {
                    cout << "\n\nOption 1 -> Return to main menu" << endl << "Option 2 -> Add another employee" << endl
                        << "Option 3 -> Exit the program" << endl << "Select an option: "; cin >> choice;
                    if (choice != 1 && choice != 2 && choice != 3) cout << "Invalid input, retry..." << endl;
                } while (choice != 1 && choice != 2 && choice != 3);

                if (choice == 3)
                    return 0;
                else if (choice == 1) break;

            } while (choice == 2);
            break;
        }
        case 2: {
            int choice = 0;
            do {
                if (e.size() == 0) { cout << "No employees in the system. Returning to main menu..." << endl << endl; break; }

                cout << "\nAll employees in the system:" << endl << left << "     " << setw(15) << "Last Name" << setw(15) << "First name" << setw(15) <<
                    "Base Salary" << setw(8) << "Bonus" << setw(15) << "Final Salary" << endl;
                for (size_t i = 0; i < e.size(); ++i) {
                    if (i < 9) {
                        cout << i + 1 << ".   ";
                        cout << left << setw(15) << e[i].getLastName() << setw(15) << e[i].getFirstName() << setw(15)
                            << e[i].getBaseSalary() << setw(8) << e[i].getBonus() << setw(15) << e[i].getSalary() << endl;
                    }
                    else if (i < 99) {
                        cout << i + 1 << ".  ";
                        cout << left << setw(15) << e[i].getLastName() << setw(15) << e[i].getFirstName() << setw(15)
                            << e[i].getBaseSalary() << setw(8) << e[i].getBonus() << setw(15) << e[i].getSalary() << endl;
                    }
                    else {
                        cout << i + 1 << ". ";
                        cout << left << setw(15) << e[i].getLastName() << setw(15) << e[i].getFirstName() << setw(15)
                            << e[i].getBaseSalary() << setw(8) << e[i].getBonus() << setw(15) << e[i].getSalary() << endl;
                    }
                }
                do {
                    cout << "Which employee information do you want to delete? (Press 0 to cancel): ";
                    cin >> choice;
                    if (choice == 0) break;
                    else if (choice <= e.size()) {
                        e.erase(e.begin() + choice - 1);
                        cout << "Deleting employee...";
                        break;
                    }
                    else cout << "Invalid input, retry...\n";
                } while (choice > e.size());
                do {
                    cout << "\n\nOption 1 -> Return to main menu" << endl << "Option 2 -> Delete another employee" << endl
                        << "Option 3 -> Exit the program" << endl << "Select an option: "; cin >> choice;
                    if (choice != 1 && choice != 2 && choice != 3) cout << "Invalid input, retry..." << endl;
                } while (choice != 1 && choice != 2 && choice != 3);
                if (choice == 1) break;
                if (choice == 3) return 0;
            } while (choice == 2);

            break;
        }
        case 3: {
            int choice;
            do {
                string c;
                cout << "\n\nWho are you searching for: ";
                cin >> c;
                cout << "Searching...\n";
                int count = 0;
                vector<int> place;
                for (size_t i = 0; i < e.size(); ++i) {
                    string partF = e[i].getFirstName().substr(0, c.size());
                    string partL = e[i].getLastName().substr(0, c.size());
                    if (c == partF || c == partL) {
                        ++count;
                        place.push_back(i);
                    }
                }
                if (count != 0) {
                    cout << "\nThere is " << count << " match.\n";
                    cout << left << setw(15) << "Last Name" << setw(15) << "First name" << setw(15)
                        << "Base Salary" << setw(8) << "Bonus" << setw(15) << "Final Salary" << endl;
                    for (size_t i = 0; i < place.size(); ++i) {
                        cout << left << setw(15) << e[place[i]].getLastName() << setw(15) << e[place[i]].getFirstName() << setw(15)
                            << e[place[i]].getBaseSalary() << setw(8) << e[place[i]].getBonus() << setw(15) << e[place[i]].getSalary() << endl;
                    }
                }
                if (count == 0) cout << "No employees were found (Try to capitalize the first letter of the name)\n";

                do {
                    cout << "\nOption 1 -> Return to main menu" << endl << "Option 2 -> Search another employee" << endl
                        << "Option 3 -> Exit the program" << endl << "Select an option: "; cin >> choice;
                    if (choice != 1 && choice != 2 && choice != 3) cout << "Invalid input, retry..." << endl;
                } while (choice != 1 && choice != 2 && choice != 3);
                if (choice == 1) break;
                if (choice == 3) return 0;
            } while (choice == 2);

            break;
        }
        case 5: {
            int choice;
            do {
            do {
                if (e.size() == 0) { cout << "No employees in the system. Returning to main menu..." << endl << endl; break; }
                cout << "\nAll employees in the system:" << endl << left << "     " << setw(15) << "Last Name" << setw(15) << "First name" << setw(15) <<
                    "Base Salary" << setw(8) << "Bonus" << setw(15) << "Final Salary" << endl;
                for (size_t i = 0; i < e.size(); ++i) {
                    if (i < 9) {
                        cout << i + 1 << ".   ";
                        cout << left << setw(15) << e[i].getLastName() << setw(15) << e[i].getFirstName() << setw(15)
                            << e[i].getBaseSalary() << setw(8) << e[i].getBonus() << setw(15) << e[i].getSalary() << endl;
                    }
                    else if (i < 99) {
                        cout << i + 1 << ".  ";
                        cout << left << setw(15) << e[i].getLastName() << setw(15) << e[i].getFirstName() << setw(15)
                            << e[i].getBaseSalary() << setw(8) << e[i].getBonus() << setw(15) << e[i].getSalary() << endl;
                    }
                    else {
                        cout << i + 1 << ". ";
                        cout << left << setw(15) << e[i].getLastName() << setw(15) << e[i].getFirstName() << setw(15)
                            << e[i].getBaseSalary() << setw(8) << e[i].getBonus() << setw(15) << e[i].getSalary() << endl;
                    }
                }

                string option;
                
                    do {
                        cout << "\nWhich employee information do you want to modify? (Press 0 to cancel): ";
                        cin >> choice;

                        if (choice <= e.size() && choice >= 0) { break; }
                        else cout << "Invalid input, retry...\n";
                    } while (choice > e.size());
                    if (choice == 0) {
                        break;
                    }
                    if (choice != 0) {
                        cout << "Option 1 -> First Name\nOption 2 -> Last Name\nOption 3 -> Base Salary\nOption 4 -> Bonus\nOption 5 -> Cancel\nOption 6 -> MAIN MENU\n";
                        cout << "Select an option: ";
                        cin >> option;
                        string name;
                        double dollar;

                        if (option == "1") {
                            cout << "Enter the new First Name (Capitalize the first letter): ";
                            cin >> name; e[choice - 1].setFirstName(name);
                            cout << "\nNew info:\n";
                            cout << left << setw(15) << e[choice - 1].getLastName() << setw(15) << e[choice - 1].getFirstName() << setw(15)
                                << e[choice - 1].getBaseSalary() << setw(8) << e[choice - 1].getBonus() << setw(15) << e[choice - 1].getSalary() << endl;
                        }
                        else if (option == "2") {
                            cout << "Enter the new Last name (Capitalize the first letter): ";
                            cin >> name; e[choice - 1].setLastName(name);
                            cout << "\nNew info:\n";
                            cout << left << setw(15) << e[choice - 1].getLastName() << setw(15) << e[choice - 1].getFirstName() << setw(15)
                                << e[choice - 1].getBaseSalary() << setw(8) << e[choice - 1].getBonus() << setw(15) << e[choice - 1].getSalary() << endl; 
                        }
                        else if (option == "3") {
                            cout << "Enter the new Base Salary: ";
                            cin >> dollar; e[choice - 1].setBaseSalary(dollar);
                            cout << "\nNew info:\n";
                            cout << left << setw(15) << e[choice - 1].getLastName() << setw(15) << e[choice - 1].getFirstName() << setw(15)
                                << e[choice - 1].getBaseSalary() << setw(8) << e[choice - 1].getBonus()
                                << setw(15) << e[choice - 1].getSalary() << endl;
                            
                        }
                        else if (option == "4") {
                            cout << "Enter the new Bonus: ";
                            cin >> dollar; e[choice - 1].setBonus(dollar);
                            cout << "\nNew info:\n";
                            cout << left << setw(15) << e[choice - 1].getLastName() << setw(15) << e[choice - 1].getFirstName() << setw(15)
                                << e[choice - 1].getBaseSalary() << setw(8) << e[choice - 1].getBonus()
                                << setw(15) << e[choice - 1].getSalary() << endl;
                        }
                        else if (option == "6") {
                            break;
                        }
                        else cout << "\nInvalid input, retry...\n";
                    } while (option == "1" && option == "2" && option == "3" && option == "4" && option == "5");
                    if (option == "6") {
                        break;
                    }
                    else {
                        do {
                            cout << "\nOption 1 -> Return to main menu" << endl << "Option 2 -> Modify other options" << endl
                                << "Option 3 -> Exit the program" << endl << "Select an option: "; cin >> choice;
                            if (choice != 1 && choice != 2 && choice != 3) cout << "Invalid input, retry..." << endl;
                        } while (choice != 1 && choice != 2 && choice != 3);
                    }
                    if (choice == 1) { break; }
                    if (choice == 3) { cout << "Program exited..."; return 0; }
                } while (choice == 2);

            if (choice == 1)
                break;



            } while (true);
        }

        } 

    } while (true);
              return 0;
        }