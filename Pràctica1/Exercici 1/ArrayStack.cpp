#include "ArrayStack.h"
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

ArrayStack::ArrayStack () {
   t = 0; //Initialize top Stack to 0
   data = std::vector <char> (MAX_STACK);
}

ArrayStack::~ArrayStack() {    
}

bool ArrayStack::empty() {
    return (data.empty());
}

bool ArrayStack::full() {
    return (data.size() == data.max_size());
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
        vector<char>::iterator it;
        it = data.begin();
        for(int i=0; i < t; i++) {
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
        data.back();
    }
    else {
        throw out_of_range("The stack is empty");
    }
}

void ArrayStack::print() {
    vector<char>::iterator it;
    it = data.begin();
    for (int i = 0; i<t ; i++) {
        it++;
        cout << *it << endl; 
    }
}