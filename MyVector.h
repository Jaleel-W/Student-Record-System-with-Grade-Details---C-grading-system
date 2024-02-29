//Author Jaleel Williamson
//
//
#include <vector>

#ifndef MYVECTOR_H
#define MYVECTOR_H

// MyVector Class
template <typename T>
class MyVector {
private:
    T* data;
    int size;
    int capacity;

public:
    MyVector() : data(nullptr), size(0), capacity(0) {}
    ~MyVector() { delete[] data; }

    void push_back(const T& value) {
        if (size == capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            T* newData = new T[capacity];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }

    T retrieveInfoAtIndex(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
    
    // Default return statement 
    return T();
}
    int getSize() const {
        return size;
    }
};

#endif //MYVECTOR_H