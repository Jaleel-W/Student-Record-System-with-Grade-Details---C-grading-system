//Author Jaleel Williamson
//
//
#include <iostream>
#include "Pair.h"
#include "Person.h"


#ifndef STUDENT_H
#define STUDENT_H

// Student Class
class Student : public Person {
private:
    MyVector<Pair<std::string, char>> grades;

public:
    Student(const std::string& first, const std::string& last, int _id)
        : Person(first, last, _id) {}

    ~Student() {}

    void displayInfo() const override {
        std::cout << "Student: " << getFullName() << " (ID: " << getId() << ")" << std::endl;
        displayContactInfo();
        std::cout << "Average Grade: " << getAverageGrade() << std::endl;
    }

    std::string getRole() const override {
        return "Student";
    }

    void addGrade(const std::string& course, char grade) {
        grades.push_back(Pair<std::string, char>(course, grade));
    }

    double getAverageGrade() const {
        if (grades.getSize() == 0) {
            return 0.0;
        }

        double totalGrade = 0.0;
        for (int i = 0; i < grades.getSize(); ++i) {
            totalGrade += grades.retrieveInfoAtIndex(i).second;
        }

        return totalGrade / grades.getSize();
    }
};

#endif //STUDENT_H
