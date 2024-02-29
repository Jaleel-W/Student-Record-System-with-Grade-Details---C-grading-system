//Author Jaleel Williamson
//
//
#include <iostream>
#include "Pair.h"
#include "Person.h"
#include "MyVector.h"

#ifndef FACULTY_H
#define FACULTY_H

// Faculty Class
class Faculty : public Person {
private:
    MyVector<Pair<std::string, std::string>> courseInfo;
    std::string department;

public:
    Faculty(const std::string& first, const std::string& last, int _id, const std::string& dept)
        : Person(first, last, _id), department(dept) {}

    ~Faculty() {}

    void displayInfo() const override {
        std::cout << "Faculty: " << getFullName() << " (ID: " << getId() << ")" << std::endl;
        std::cout << "Department: " << department << std::endl;
        displayContactInfo();
        displayCourseInfo();
    }

    std::string getRole() const override {
        return "Faculty";
    }

    void addCourse(const std::string& courseId, const std::string& description) {
        courseInfo.push_back(Pair<std::string, std::string>(courseId, description));
    }

    void displayCourseInfo() const {
        std::cout << "Courses: " << std::endl;
        for (int i = 0; i < courseInfo.getSize(); ++i) {
            Pair<std::string, std::string> info = courseInfo.retrieveInfoAtIndex(i);
            std::cout << info.first << ": " << info.second << std::endl;
        }
    }
};

#endif // FACULTY_H