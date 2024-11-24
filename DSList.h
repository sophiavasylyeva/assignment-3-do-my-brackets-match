#ifndef DSList_H
#define DSList_H
#include <iostream>

/**
 * @brief Singly-linked list that uses positions and has a stack interface
 *
 * Implement all described functions and provide a test program using CATCH2
 * 
 * @tparam Object 
 */
template <typename Object>
class DSList
{
private:
   /**
     * @brief The nested Node data structure
     * 
     * struct is in C++ a class with all public members
     */
    struct Node
    {
        Object data;
        Node *next;
        Node *prev;

        Node(const Object &d = Object{}, Node *n = nullptr, Node *p = nullptr)
            : data{d}, next{n}, prev{p} {};
    };
    
    Node *head;
    int size;
    Node *tail;

public:

// You need to implement at least:
// Default constructor
// Rule-of-3
// size
// is the list empty?
// clear the whole list
// find an element with a specific value (and return the position. First element in list is pos 0). Not found returns -1.
// insert at the beginning of the list (push_front).
// insert at the end of the list (push_back).
// remove the first element(pop_front)
// remove the last element (pop_back)

    DSList();
    DSList(const DSList &);
    ~DSList();
    DSList &operator=(const DSList &);
    Object &operator[](int);
    int getsize();
    bool isEmpty();
    void clear();
    int findByValue(const Object &);
    void push_front(const Object &);
    void push_back(const Object &);
    void pop_front();
    void pop_back();
    void insert(const Object &, int);

};

template <typename Object> 
DSList<Object>::DSList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename Object> 
DSList<Object>::DSList(const DSList &copy){ //copy constructor for a double linked list 
    if(copy.size() == 0){
        head == nullptr;
        tail = nullptr;
        size = 0;
    }
    else{
        head = new Node(copy.head->data);
        Node* iterator = copy.head->next;
        tail = head;
        while(iterator!=nullptr){
            tail->next = new Node(iterator->data);
            tail->next->prev = tail;
            tail = tail->next;
            iterator = iterator->next;
        }
        size = copy.size();
    }
}

template <typename Object> 
DSList<Object>::~DSList(){
    clear();
}

template <typename Object> 
DSList<Object>& DSList<Object>::operator=(const DSList &o){ //assignment operator constructor 
    this.clear();
    if(o.size() == 0){
        head == nullptr;
        tail = nullptr;
        size = 0;
    }
    else{
        head = new Node(o.head->data);
        Node* iterator = o.hear->next;
        tail = head;
        while(iterator!=nullptr){
            tail->next = new Node(iterator->data);
            tail->next->prev = tail;
            tail = tail->next;
            iterator = iterator->next;
        }
        size = o.size();
    }
    return *this;
}

template <typename Object> 
Object& DSList<Object>::operator[](int index){
    if(index < 0 || index >= size){
        std::cerr << "out of bounds error" << std::endl; //tests if index in the list is out of bounds 
        exit(1);
    }
    if(index == size-1)
        return tail->data; //returns last index of list and assigns it to tail
    Node* iterator = head;
    for(int i = 0; i < index; i++){
        iterator = iterator->next;
    }
    return iterator->data;
}


template <typename Object> 
int DSList<Object>::getsize(){
    return size;
}

template <typename Object> 
bool DSList<Object>::isEmpty(){
    if(size == 0)
        return true;
    else    
        return false;
}

template <typename Object> 
void DSList<Object>::clear(){
    Node* iterator = head;
    while(iterator!=nullptr){
        Node*temp = iterator->next;
        delete iterator;
        iterator = temp;
    }
    size = 0; //deletes data from linked list and reassigns head and tail to nullptr because it is now empty
    head = nullptr;
    tail = nullptr;
}

template <typename Object> 
int DSList<Object>::findByValue(const Object &data){
    Node* iterator = head;
    while(iterator!=nullptr){
        int i = 0;
        if(iterator->data == data)
            return i; //returns data at index of list 
        iterator = iterator->next;
        i++; 
    }
    return -1;
}

template <typename Object> 
void DSList<Object>::push_front(const Object &o){
    head->prev = new Node(o);
    head->prev->next = head;
    head = head->prev;
    size++; //adds object to front of list and reassigns head of list
}

template <typename Object> 
void DSList<Object>::push_back(const Object &obj){
    tail->next = new Node(obj);
    tail->next->prev = tail;
    tail = tail->next;
    size++; //adds object to end of list and reassigns tail of list
}

template <typename Object> 
void DSList<Object>::pop_front(){
    head = head->next;
    delete head->prev;
    size--;
}

template <typename Object> 
void DSList<Object>::pop_back(){
    tail = tail->prev;
    delete tail->next;
    size--;
}

template <typename Object> 
void DSList<Object>::insert(const Object &obj, int index){ //inserts obejct at an index in list 
    if(index < 0 || index > size){
        std::cerr << "out of bounds error" << std::endl; //if index doesn't exist, throws out of bounds error
        exit(1);
    }
    if(index==0)
        push_front(index); 
    else if(index == size)
        push_back(index); //if index is head or tail, it is added on list
    else{
        Node* iterator = head;
        for(int i = 0; i < index; i++){
            iterator=iterator->next;
        }
        Node* temp = new Node(obj);
        temp->next = iterator;
        temp->prev = iterator->prev;
        iterator->prev->next = temp;
        iterator->prev = temp;
        size++; //otherwise, inserted at index and head and tail is reassigned
    }
}

#endif
