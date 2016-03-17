#include "ArrayStack.h"
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

ArrayStack::ArrayStack () {
   t = 0; //Initialize top Stack to 0 
  data = vector <char> (MAX_STACK);
}

ArrayStack::~ArrayStack() {  
}

bool ArrayStack::empty() {
    return (t);
}

bool ArrayStack::full() {
    return (t == MAX_STACK); //Actual size is t
}

void ArrayStack::pop() {
    if (!empty()) {
        data [t-1] = NULL;
        t--; 
    }
    else {
        throw out_of_range("The stack is empty");
    }
}

void ArrayStack::push(const char item) {
    if (!full()) {
        data[t] = item;
        t++;
    }
    else{
        throw out_of_range("The stack is full");
    }
}

char ArrayStack::top() {
    if (!empty()) {
        return data[t-1];
    }
    else {
        throw out_of_range("The stack is empty");
    }
}

void ArrayStack::print() {
    vector<char>::iterator it = data.begin();
    for(int i= 0 ; i < t; i++) {
        cout << *it << endl;
        it++;
    }
    //We print the last element
    cout << *it << endl;
}