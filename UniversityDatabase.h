//Author Jaleel Williamson
//
//
#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include "MyVector.h"

#ifndef UNIVERSITY_DATABASE_H
#define UNIVERSITY_DATABASE_H

// UniversityDatabase Class
class UniversityDatabase {
private:
    MyVector<Person*> people;

public:
    ~UniversityDatabase() {
        for (int i = 0; i < people.getSize(); ++i) {
            delete people.retrieveInfoAtIndex(i);
        }
    }

    void addPerson(Person* person) {
        people.push_back(person);
    }

    Person* findPersonById(int id) const {
        for (int i = 0; i < people.getSize(); ++i) {
            if (people.retrieveInfoAtIndex(i)->getId() == id) {
                return people.retrieveInfoAtIndex(i);
            }
        }
        return nullptr;
    }

    Student* findStudentById(int id) const {
        Person* person = findPersonById(id);
        return dynamic_cast<Student*>(person);
    }

    Faculty* findFacultyById(int id) const {
        Person* person = findPersonById(id);
        return dynamic_cast<Faculty*>(person);
    }

    void displayAllPeopleInfo() const {
        for (int i = 0; i < people.getSize(); ++i) {
            people.retrieveInfoAtIndex(i)->displayInfo();
            std::cout << std::endl;
        }
    }
};

#endif // UNIVERSITY_DATABASE_H