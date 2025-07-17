//Author Jaleel Williamson
#ifndef PERSON_H
#define PERSON_H

#include "MyVector.h"
#include "Pair.h"
#include <iostream>

class Person {
protected:
    std::string lastName;
    std::string firstName;
    int id;
    MyVector<Pair<std::string, std::string>> contactInfo;

public:
    Person(const std::string& last, const std::string& first, int _id)
        : lastName(last), firstName(first), id(_id) {}
    
    virtual ~Person() = default;
    
    virtual void displayInfo() const = 0;
    virtual std::string getRole() const = 0;

    std::string getFullName() const { 
        return lastName + ", " + firstName; 
    }
    
    int getId() const { 
        return id; 
    }

    void addContactInfo(const std::string& key, const std::string& value) {
        contactInfo.push_back({key, value});
    }

    void displayContactInfo() const {
        for (int i = 0; i < contactInfo.getSize(); ++i) {
            const auto& info = contactInfo[i];
            std::cout << "  " << info.first << ": " << info.second << "\n";
        }
    }
};

#endif
