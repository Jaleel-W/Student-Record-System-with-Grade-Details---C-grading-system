//Author Jaleel Williamson
#ifndef MYVECTOR_H
#define MYVECTOR_H

template <typename T>
class MyVector {
private:
    T* data = nullptr;
    int size = 0;
    int capacity = 0;

    void resize() {
        capacity = capacity ? capacity * 2 : 1;
        T* newData = new T[capacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    ~MyVector() { delete[] data; }

    void push_back(const T& value) {
        if (size == capacity) resize();
        data[size++] = value;
    }

    const T& operator[](int index) const { 
        return data[index]; 
    }

    int getSize() const { return size; }
};

#endif
