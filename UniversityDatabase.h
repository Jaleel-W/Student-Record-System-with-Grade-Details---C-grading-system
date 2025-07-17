//Author Jaleel Williamson
#ifndef UNIVERSITY_DATABASE_H
#define UNIVERSITY_DATABASE_H

#include "Person.h"
#include "Student.h"
#include "Faculty.h"

class UniversityDatabase {
private:
    MyVector<Person*> people;

public:
    ~UniversityDatabase() {
        for (int i = 0; i < people.getSize(); ++i) {
            delete people[i];
        }
    }

    void addPerson(Person* person) {
        people.push_back(person);
    }

    Person* findPersonById(int id) const {
        for (int i = 0; i < people.getSize(); ++i) {
            if (people[i]->getId() == id) {
                return people[i];
            }
        }
        return nullptr;
    }

    Student* findStudentById(int id) const {
        return dynamic_cast<Student*>(findPersonById(id));
    }

    Faculty* findFacultyById(int id) const {
        return dynamic_cast<Faculty*>(findPersonById(id));
    }

    void displayAllPeopleInfo() const {
        for (int i = 0; i < people.getSize(); ++i) {
            people[i]->displayInfo();
            std::cout << "------------------------\n";
        }
    }
};

#endif
