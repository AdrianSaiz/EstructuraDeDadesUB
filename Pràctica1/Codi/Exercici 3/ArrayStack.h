/* 
 * File:   ArrayStack.h
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 10 / març / 2016, 12:13
 */

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <class E> class ArrayStack {
    enum { DEF_CAPACITY = 100};
public:
    ArrayStack(int cap = DEF_CAPACITY); // constructor
    ArrayStack(const ArrayStack& orig); // copy constructor
    virtual ~ArrayStack(); // destructor
    int size () const; // return the size
    bool empty() const; // return TRUE if the stack is empty
    bool full() const; // return TRUE if the stack is full
    const E& top() const; // return the top element of stack
    void push(const E& e); // introduce an element in the stack
    void pop(); // remove top element from the stack
    // ... housekeeping functions
    void print() const;
private:
    E* S;
    int capacity;
    int t;

};

/**
 * Default contructor for ArrayStack, it initializes the size of the stack,
 * the array that will store the sequence of elements and the maximum capacity of
 * the stack.
 */
template <class E> ArrayStack<E>::ArrayStack(int cap) {
    this-> capacity = cap;
    this-> S = new E [cap];
    this-> t = 0; //Initialize top Stack to 0 
}

/**
 * Constructor used to copy from an ArrayStack already defined.
 * 
 * @param orig
 */
template <class E> ArrayStack<E>::ArrayStack(const ArrayStack& orig) {
}

/**
 * Default destructor for ArrayStack.
 */
template <class E> ArrayStack<E>::~ArrayStack() {
}

//Consultor methods

/**
 * Returns if the stack is empty or not
 * 
 * @return true if only if the stack is empty
 */
template <class E> bool ArrayStack<E>::empty() const {
    return (this-> t == 0);
}

/**
 * Returns if the stack is full or not.
 * 
 * @return true if only if the stack is full
 */
template <class E> bool ArrayStack<E>::full() const {
    return (this-> t == this-> capacity);
}

/**
 * Prints the elements defined in the table. The order of
 * the elements shown is from the top to the first element in.
 */
template <class E> void ArrayStack<E>::print() const {
    for(int i = 0; i < this-> t; i++) {
        cout << this-> S [i] << endl;
    }
    
}

/**
 * Returns the top element of the stack (the first element in).
 * 
 * @return E& which represents the top element of the stack.
 */
template <class E> const E& ArrayStack<E>::top() const {
    if (this-> empty()) { //Checks if the stack is empty
        throw new out_of_range("The Stack is empty"); //Throws if the stack is empty
    }
    else {
        return this-> S [(this-> t)-1];
    }
}

/**
 * Returns the number of elements defined in the stack
 * 
 * @return int which represents the size of the stack
 */
template <class E> int ArrayStack<E>::size() const {
    return this-> t;
}

//Modifier methods

/**
 * Deletes the top element of the stack (the last one in).
 */
template <class E> void ArrayStack<E>::pop() {
    if (!this-> empty()) { //Checks if the stack is empty
        this-> t--;
    }
    else {
        throw new out_of_range ("The Stack is empty"); //Throws if the stack is empty
    }
}

/**
 * Insert the given element to the top of the Stack.
 * 
 * @param e - element (E&) that will be put in.
 */
template <class E> void ArrayStack<E>::push(const E& e) {
    if (!this-> full()) { //Checks if the stack is full
        this-> S [this-> t] = e;
        this-> t++;
    }
    else {
        throw new out_of_range ("The Stack is full"); //Throws if the stack is full
    }
}

#endif /* ARRAYSTACK_H */

