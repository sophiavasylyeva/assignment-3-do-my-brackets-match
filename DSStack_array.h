// Implement a stack based on an array.

// Implement a stack based on an array.

#ifndef DSStack_array_H
#define DSStack_array_H

template <typename Object> 
class DSStack_array{
    public:
       DSStack_array();
       DSStack_array(const DSStack_array &);
       ~DSStack_array();
       DSStack_array &operator=(const DSStack_array &);
       Object &operator[](const int);
       bool isEmpty() const;
       int getSize() const;
       void clear();
       void pop();
       const Object& top() const;
       void push(const Object &);
       const Object& peek() const;
    private:
        Object* stack;
        int capacity;
        int size;
        int len;

};

template <typename Object> 
DSStack_array<Object>::DSStack_array(){
    len = 0;
    size = 0;
    capacity = 10;
    stack = new Object[capacity];

}

template <typename Object>
DSStack_array<Object>::DSStack_array(const DSStack_array &o) { //copy constructor
    len = o.len;
    capacity = o.capacity;
    stack = new Object[capacity];
    for (int i = 0; i < len; i++) {
        stack[i] = o.stack[i];
    }
}

template <typename Object> 
DSStack_array<Object>::~DSStack_array(){
    delete[] stack;
}

template <typename Object>
DSStack_array<Object> &DSStack_array<Object>::operator=(const DSStack_array &o) { //assignment operator
    if (this != &o) {
        delete[] stack;
        len = o.len;
        capacity = o.capacity;
        stack = new Object[capacity];
        for (int i = 0; i < len; i++) {
            stack[i] = o.stack[i];
        }
    }
    return *this;
}

template <typename Object>
Object &DSStack_array<Object>::operator[](const int x) {
    return stack[x];
}

template <typename Object> 
bool DSStack_array<Object>::isEmpty() const{ //checks to see if vector is empty
    
//return size == 0;
    if(size == 0)
        return true;
    else    
        return false;
 }

template <typename Object> 
int DSStack_array<Object>::getSize() const{
    return size;
    //return stack.getSize();
}

    
template <typename Object> 
void DSStack_array<Object>::clear(){
   delete[] stack;
   capacity = 10;
   size = 0;
   stack = new Object[capacity];
   // stack.clear();
}

template <typename Object> 
void DSStack_array<Object>::pop(){
    if(!isEmpty())
        --size;
    //stack.pop_front();
}

template <typename Object> 
const Object& DSStack_array<Object>::top() const{ //returns first element of vector, top of the stack
   if(!isEmpty())
        return stack[size - 1];
   // return stack[0]; 
}

template <typename Object> 
void DSStack_array<Object>::push(const Object& val){
    if(size == capacity){            //adds object to the vector
        capacity *= 2;
        Object *stackNew = new Object[capacity];
        for(int i = 0; i < size; i++){
            stackNew[i] = stack[i];
        }
        delete[] stack;
        stack = stackNew;
    }
    stack[size++] = val;
}


template <typename Object> 
const Object& DSStack_array<Object>::peek() const{
    return top(); //return object on top of the stack
}

       
#endif

  

