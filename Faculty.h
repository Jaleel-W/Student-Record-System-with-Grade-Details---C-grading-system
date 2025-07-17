//Author Jaleel Williamson
#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"

class Faculty : public Person {
private:
    MyVector<Pair<std::string, std::string>> courses;
    std::string department;

public:
    Faculty(const std::string& last, const std::string& first, int _id, const std::string& dept)
        : Person(last, first, _id), department(dept) {}

    void displayInfo() const override {
        std::cout << "Faculty: " << getFullName() << " (ID: " << id << ")\n";
        std::cout << "  Department: " << department << "\n";
        displayContactInfo();
        if (courses.getSize() > 0) {
            std::cout << "  Courses:\n";
            for (int i = 0; i < courses.getSize(); ++i) {
                const auto& c = courses[i];
                std::cout << "    " << c.first << ": " << c.second << "\n";
            }
        }
    }

    std::string getRole() const override { 
        return "Faculty"; 
    }

    void addCourse(const std::string& course, const std::string& description) {
        courses.push_back({course, description});
    }
};

#endif
