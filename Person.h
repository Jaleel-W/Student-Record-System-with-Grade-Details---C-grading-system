//Author Jaleel Williamson
//
//
#include <iostream>
#include "Pair.h"
#include "MyVector.h"

#ifndef PERSON_H
#define PERSON_H


// Person Class (Abstract)
class Person {
private:
    MyVector<Pair<std::string, std::string>> contactInfo;
    std::string firstName;
    std::string lastName;
    int id;

public:
    Person(const std::string& first, const std::string& last, int _id)
        : firstName(first), lastName(last), id(_id) {}

    virtual ~Person() {}

    virtual void displayInfo() const = 0;
    virtual std::string getRole() const = 0;

    std::string getFullName() const {
        return firstName + " " + lastName;
    }

    int getId() const {
        return id;
    }

    void addContactInfo(const std::string& key, const std::string& value) {
        contactInfo.push_back(Pair<std::string, std::string>(key, value));
    }

    void updateContactInfo(const MyVector<Pair<std::string, std::string>>& newInfo) {
        // Update contact information as needed
        // This is a simplified implementation
        // You may want to implement logic to merge or replace existing information
    }

    void displayContactInfo() const {
        for (int i = 0; i < contactInfo.getSize(); ++i) {
            Pair<std::string, std::string> info = contactInfo.retrieveInfoAtIndex(i);
            std::cout << info.first << ": " << info.second << std::endl;
        }
    }
};

#endif //PERSON_H
