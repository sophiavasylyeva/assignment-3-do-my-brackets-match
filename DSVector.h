
#ifndef DSVector_H
#define DSVector_H
#include <iostream>

template <typename Object>
class DSVector {
   public:
    DSVector();
    DSVector(const DSVector &);
    ~DSVector();
    DSVector &operator=(const DSVector &);
    Object &operator[](const int);
    void push_back(const Object &);
    void push_front(const Object &);
    // void insert(const Object &, int);
    int getSize();
    void pop_back();
    void pop_front();
    void clear();
    // void removeByIndex(int);
    // void removeByValue(const Object &);
    int findByValue(const Object &);

   private:
    void resize();
    int len;
    Object *array;
    int capacity;
};

template <typename Object>
DSVector<Object>::DSVector() { //initializes all private variables
    len = 0;
    capacity = 10;
    array = new Object[capacity];
}

template <typename Object>
DSVector<Object>::DSVector(const DSVector &o) { //copy constructor
    len = o.len;
    capacity = o.capacity;
    array = new Object[capacity];
    for (int i = 0; i < len; i++) {
        array[i] = o.array[i];
    }
}

template <typename Object>
DSVector<Object>::~DSVector() { //destructor
    delete[] array;
}

template <typename Object>
DSVector<Object> &DSVector<Object>::operator=(const DSVector &o) { //assignment operator
    if (this != &o) {
        delete[] array;
        len = o.len;
        capacity = o.capacity;
        array = new Object[capacity];
        for (int i = 0; i < len; i++) {
            array[i] = o.array[i];
        }
    }
    return *this;
}

template <typename Object>
Object &DSVector<Object>::operator[](const int x) {
    return array[x];
}

template <typename Object>
void DSVector<Object>::push_front(const Object &o) {
    if (len == capacity) {
        capacity * 2;
    }

    Object *temp = new Object[capacity]; //creates temp object and iterates through array to push object to front of array and reassigns object
    temp[0] = o;
    for (int i = 0; i < len; i++) {
        temp[i + 1] = array[i];
    }
    delete[] array;
    array = temp;
    len++;
}

template <typename Object>
void DSVector<Object>::push_back(const Object &o) {
    if (len == capacity)
        resize();
    
    array[len] = o;
    len++;
}

template <typename Object>
int DSVector<Object>::getSize() { //returns size of array
    return len;
}

template <typename Object>
void DSVector<Object>::pop_back() {
    if (len == 0) {
        std::cerr << "empty vector" << std::endl;
    }
    len--; //decrements array size because object is deleted
}

template <typename Object>
void DSVector<Object>::pop_front() {
    for (int i = 1; i < len; i++)
        array[i - 1] = array[i];
    len--;
}

template <typename Object>
void DSVector<Object>::clear() {
    delete[] array;
    len = 0;
    capacity = 10;
    array = new Object[capacity]; //clears contents of array and recreates new array
}

template <typename Object>
void DSVector<Object>::resize() {
    capacity *= 2;
    Object *temp = new Object[capacity];
    for (int i = 0; i < len; i++)
        temp[i] = array[i];
    delete[] array;
    array = temp; //doubles capacity of array, makes temporary array to reassign, deletes old array and reassigns to new, resized array
}

template <typename Object>
int DSVector<Object>::findByValue(const Object &o) {
    for (int i = 0; i < len; i++) {
        if (array[i] == o)
            return i; //finds value in the array and returns it
    }
    return -1;
}

#endif
