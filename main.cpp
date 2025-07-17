//Author Jaleel Williamson
#include "UniversityDatabase.h"
#include <iostream>
#include <limits>
#include <cctype>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    UniversityDatabase db;
    int id = 100;

    while (true) {
        std::cout << "\nUniversity Database System\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Add Faculty\n";
        std::cout << "3. Add Student Grade\n";
        std::cout << "4. Add Faculty Course\n";
        std::cout << "5. Add Contact Info\n";
        std::cout << "6. Display All Records\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter choice: ";

        int choice;
        if (!(std::cin >> choice)) {
            clearInputBuffer();
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                std::string last, first;
                std::cout << "Enter last name: ";
                std::cin >> last;
                std::cout << "Enter first name: ";
                std::cin >> first;
                db.addPerson(new Student(last, first, id++));
                std::cout << "Student added successfully.\n";
                break;
            }
            
            case 2: {
                std::string last, first, dept;
                std::cout << "Enter last name: ";
                std::cin >> last;
                std::cout << "Enter first name: ";
                std::cin >> first;
                std::cout << "Enter department: ";
                std::cin >> dept;
                db.addPerson(new Faculty(last, first, id++, dept));
                std::cout << "Faculty added successfully.\n";
                break;
            }
            
            case 3: {
                int sid;
                std::cout << "Enter student ID: ";
                if (!(std::cin >> sid)) {
                    clearInputBuffer();
                    std::cout << "Invalid ID format.\n";
                    break;
                }
                
                if (Student* s = db.findStudentById(sid)) {
                    std::string course;
                    char grade;
                    std::cout << "Enter course name: ";
                    std::cin >> course;
                    std::cout << "Enter grade (A-F): ";
                    std::cin >> grade;
                    
                    if (!std::isalpha(grade)) {
                        std::cout << "Invalid grade format.\n";
                    } else {
                        s->addGrade(course, grade);
                        std::cout << "Grade added successfully.\n";
                    }
                } else {
                    std::cout << "Student not found.\n";
                }
                break;
            }
            
            case 4: {
                int fid;
                std::cout << "Enter faculty ID: ";
                if (!(std::cin >> fid)) {
                    clearInputBuffer();
                    std::cout << "Invalid ID format.\n";
                    break;
                }
                
                if (Faculty* f = db.findFacultyById(fid)) {
                    std::string course, desc;
                    std::cout << "Enter course name: ";
                    std::cin >> course;
                    std::cout << "Enter course description: ";
                    clearInputBuffer();
                    std::getline(std::cin, desc);
                    f->addCourse(course, desc);
                    std::cout << "Course added successfully.\n";
                } else {
                    std::cout << "Faculty not found.\n";
                }
                break;
            }
            
            case 5: {
                int pid;
                std::cout << "Enter person ID: ";
                if (!(std::cin >> pid)) {
                    clearInputBuffer();
                    std::cout << "Invalid ID format.\n";
                    break;
                }
                
                if (Person* p = db.findPersonById(pid)) {
                    std::string type, value;
                    std::cout << "Contact type (Email/Phone): ";
                    std::cin >> type;
                    std::cout << "Contact value: ";
                    std::cin >> value;
                    p->addContactInfo(type, value);
                    std::cout << "Contact added successfully.\n";
                } else {
                    std::cout << "Person not found.\n";
                }
                break;
            }
            
            case 6: {
                db.displayAllPeopleInfo();
                break;
            }
            
            case 7: {
                return 0;
            }
            
            default: {
                std::cout << "Invalid choice. Try again.\n";
                clearInputBuffer();
            }
        }
    }
}
