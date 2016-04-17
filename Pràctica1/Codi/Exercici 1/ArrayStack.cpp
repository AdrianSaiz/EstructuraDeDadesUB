/* 
 * File:   ArrayStack.cpp
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 10 / març / 2016, 12:13
 */

#include "ArrayStack.h"
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

/**
 * Default contructor for ArrayStack, it initializes the size of the stack and
 * the vector container that will store the sequence of chars.
 */
ArrayStack::ArrayStack () {
  t = 0; //Initialize top Stack to 0 
  data = vector <char> (MAX_STACK); //Initilize the vector with a maximum of characters possible.
}

/**
 * Default destructor for ArrayStack.
 */
ArrayStack::~ArrayStack() {  
}

//Consultor methods

/**
 * Returns if the stack is empty or not
 * 
 * @return true if only if the stack is empty
 */
bool ArrayStack::empty() {
    return (t); //t == 0 returns true by default
}

/**
 * Returns if the stack is full or not.
 * 
 * @return true if only if the stack is full
 */
bool ArrayStack::full() {
    return (t == MAX_STACK); //Actual size is t
}

/**
 * Prints the characters defined in the table. The order of
 * the charachers shown is from the top to the first element in.
 */
void ArrayStack::print() {
    vector<char>::iterator it = data.begin(); //Iteration
    for(int i= 0 ; i < t; i++) {
        cout << *it << endl;
        it++;
    }
    //Prints the last element
    cout << *it << endl;
}

/**
 * Returns the top element of the stack (the first element in).
 * 
 * @return char which represents the top element of the stack.
 */
char ArrayStack::top() {
    if (!empty()) { //Chacks if the stack is empty
        return data[t-1];
    }
    else {
        throw out_of_range("The stack is empty"); //Throws if the stack is empty
    }
}

//Modifier methods

/**
 * Deletes the top element of the stack (the last one in).
 */
void ArrayStack::pop() {
    if (!empty()) { //Checks if the stack is empty
        t--; 
    }
    else {
        throw out_of_range("The stack is empty"); //Throws if the stack is empty
    }
}

/**
 * Insert the given element to the top of the Stack.
 * 
 * @param item - char that will be put in.
 */
void ArrayStack::push(const char item) {
    if (!full()) { //Checks if the stack is full
        data[t] = item;
        t++;
    }
    else{
        throw out_of_range("The stack is full"); //Throws if the stack is full
    }
}