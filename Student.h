//Author Jaleel Williamson
#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <cctype>

class Student : public Person {
private:
    MyVector<Pair<std::string, char>> grades;

    double convertGrade(char g) const {
        switch (std::toupper(g)) {
            case 'A': return 4.0;
            case 'B': return 3.0;
            case 'C': return 2.0;
            case 'D': return 1.0;
            default: return 0.0;
        }
    }

public:
    Student(const std::string& last, const std::string& first, int _id)
        : Person(last, first, _id) {}

    void displayInfo() const override {
        std::cout << "Student: " << getFullName() << " (ID: " << id << ")\n";
        displayContactInfo();
        if (grades.getSize() > 0) {
            std::cout << "  Grades:\n";
            for (int i = 0; i < grades.getSize(); ++i) {
                const auto& g = grades[i];
                std::cout << "    " << g.first << ": " << g.second << "\n";
            }
            std::cout << "  Average Grade: " << getAverageGrade() << "\n";
        }
    }

    std::string getRole() const override { 
        return "Student"; 
    }

    void addGrade(const std::string& course, char grade) {
        grades.push_back({course, static_cast<char>(std::toupper(grade))});
    }

    double getAverageGrade() const {
        if (grades.getSize() == 0) return 0.0;
        
        double total = 0.0;
        for (int i = 0; i < grades.getSize(); ++i) {
            total += convertGrade(grades[i].second);
        }
        return total / grades.getSize();
    }
};

#endif
