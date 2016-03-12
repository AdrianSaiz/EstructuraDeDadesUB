#include "ArrayStack.h"
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

ArrayStack::ArrayStack () {
   t = -1; //Initialize top Stack to -1
   data = std::vector <char> (MAX_STACK);
}

ArrayStack::~ArrayStack() {  
}

bool ArrayStack::empty() {
    return (t==-1);
}

bool ArrayStack::full() {
    return ((t+1) == data.max_size()); //Actual size is t+1
}

void ArrayStack::pop() {
    if (!empty()) {
        data.pop_back();
        t--; 
    }
    else {
        throw out_of_range("The stack is empty");
    }
}

void ArrayStack::push(const char item) {
    if (!full()) {
        vector<char>::iterator it = data.begin();
        for(int i= 0 ; i <= t; i++) {
            it++;
        }
            data.insert(it, item);
            t++;
    }
    else{
        throw out_of_range("The stack is full");
    }
}

char ArrayStack::top() {
    if (!empty()) {
        vector<char>::iterator it = data.begin();
        for(int i= 0 ; i < t; i++) {
            it++;
        }
        return *it;
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