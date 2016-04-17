/* 
 * File:   ArrayQueue.h
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 10 / març / 2016, 12:13
 */

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <vector>

class ArrayStack {
    
private:
    int MAX_STACK = 100;
    std::vector <char> data;
    int t; //top of the stack

public:
    ArrayStack(); // constructor
    ~ArrayStack(); // destructor
    bool empty(); // return TRUE if the stack is empty
    bool full(); // return TRUE if the stack is full
    void push (const char item);
    
    //Introduce an element to the stack, and it returns an exception
    //if it hasn't been possible
    
    void pop ();
    
    //Remove an element from the stack, and it returns an exception
    //if it hasn't been possible
    
    char top ();
    
    //Returns the top element of the stack, and it returns an exception
    //if it hasn't been possible
    
    void print (); //Prints all the content of the stack
};

#endif /* ARRAYSTACK_H */

