//Author Jaleel Williamson
//
//
#include <iostream>
#include "UniversityDatabase.h"

// Main Function
// Main Function
int main() {
    UniversityDatabase universityDatabase;
    int id = 100;

    while (true) {
        std::cout << "Menu Options:" << std::endl;
        std::cout << "1- Add Student" << std::endl;
        std::cout << "2- Add Faculty Member" << std::endl;
        std::cout << "3- Add Grades for a Student" << std::endl;
        std::cout << "4- Add Courses for a Faculty Member" << std::endl;
        std::cout << "5- Add Contact Info for a Person" << std::endl;
        std::cout << "6- Display All People" << std::endl;
        std::cout << "7- Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Add Student
                std::string firstName, lastName;
                std::cout << "Enter student first name: ";
                std::cin >> firstName;
                std::cout << "Enter student last name: ";
                std::cin >> lastName;

                Student* student = new Student(firstName, lastName, id++);
                universityDatabase.addPerson(student);
                break;
            }
            case 2: {
                // Add Faculty Member
                std::string firstName, lastName, department;
                std::cout << "Enter faculty first name: ";
                std::cin >> firstName;
                std::cout << "Enter faculty last name: ";
                std::cin >> lastName;
                std::cout << "Enter faculty department: ";
                std::cin >> department;

                Faculty* faculty = new Faculty(firstName, lastName, id++, department);
                universityDatabase.addPerson(faculty);
                break;
            }
            case 3: {
                // Add Grades for a Student
                int studentId;
                std::cout << "Enter student ID: ";
                std::cin >> studentId;

                Student* student = universityDatabase.findStudentById(studentId);
                if (student) {
                    std::string course;
                    char grade;

                    std::cout << "Enter course for the student: ";
                    std::cin >> course;
                    std::cout << "Enter grade for the course: ";
                    std::cin >> grade;

                    student->addGrade(course, grade);
                } else {
                    std::cout << "Student not found." << std::endl;
                }
                break;
            }
            case 4: {
                // Add Courses for a Faculty Member
                int facultyId;
                std::cout << "Enter faculty ID: ";
                std::cin >> facultyId;

                Faculty* faculty = universityDatabase.findFacultyById(facultyId);
                if (faculty) {
                    std::string courseId, description;

                    std::cout << "Enter course ID for the faculty: ";
                    std::cin >> courseId;
                    std::cout << "Enter course description: ";
                    std::cin >> description;

                    faculty->addCourse(courseId, description);
                } else {
                    std::cout << "Faculty member not found." << std::endl;
                }
                break;
            }
            case 5: {
                // Add Contact Info for a Person
                int personId;
                std::cout << "Enter person ID: ";
                std::cin >> personId;

                Person* person = universityDatabase.findPersonById(personId);
                if (person) {
                    std::string key, value;
                    std::cout << "Enter contact information key: ";
                    std::cin >> key;
                    std::cout << "Enter contact information value: ";
                    std::cin >> value;
                    person->addContactInfo(key, value);
                } else {
                    std::cout << "Person not found." << std::endl;
                }
                break;
            }
            case 6: {
                // Display All People
                universityDatabase.displayAllPeopleInfo();
                break;
            }
            case 7: {
                // Exit
                return 0;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
    }

    return 0;
}
