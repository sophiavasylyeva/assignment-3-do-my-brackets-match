// Implement a stack based on an array.

#ifndef DSStack_list_H
#define DSStack_list_H
#include "DSList.h"

template <typename Object> 
class DSStack_list{
    public:
       bool isEmpty();
       int getsize();
       void clear();
       void pop();
       Object top();
       void push(Object);
       Object peek();
    private:
        DSList<Object> stack;

};

template <typename Object> 
bool DSStack_list<Object>::isEmpty(){ //checks to see if vector is empty
    if(stack.getsize() == 0)
        return true;
    else    
        return false;
}

template <typename Object> 
int DSStack_list<Object>::getsize(){
    return stack.getsize();
}

    
template <typename Object> 
void DSStack_list<Object>::clear(){
    stack.clear();
}

template <typename Object> 
void DSStack_list<Object>::pop(){
    stack.pop_front();
}

template <typename Object> 
Object DSStack_list<Object>::top(){ //returns first element of vector, top of the stack
    return stack[0]; 
}

template <typename Object> 
void DSStack_list<Object>::push(Object val){
    stack.push_front(val); //adds object to the vector
}

template <typename Object> 
Object DSStack_list<Object>::peek(){
    return stack[0]; //return object on top of the stack
}

       
#endif

  

