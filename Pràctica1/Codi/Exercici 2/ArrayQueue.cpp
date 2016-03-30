/* 
 * File:   ArrayQueue.cpp
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 10 / març / 2016, 12:13
 */
#include "ArrayQueue.h"
#include <stdexcept>
#include <iostream>

using namespace std;

/*
 * Default contructor for ArrayQueue, it initializes the size of the stack,
 * the array that will store the sequence of elements, the maximum capacity of
 * the stack and the position of the first element (the structure of the TAD is 
 * a circular array).
 * 
 * @param maxSize
 */

ArrayQueue::ArrayQueue(int const &maxSize) {
    this ->sizeController = 0; 
    this->max_size = maxSize;
    queueArray = new int[maxSize];
    this->sentinella = 0;
}

/**
 * Default destructor for ArrayQueue.
 */
ArrayQueue::~ArrayQueue() {
}

//Consultor methods

/**
 * Returns the number of elements defined in the queue
 * 
 * @return int which represents the size of the queue
 */
int ArrayQueue::size() {
    return this->sizeController;
}

/**
 * Returns if the stack is empty or not
 * 
 * @return true if only if the queue is empty
 */
bool ArrayQueue::empty() {
    return this->size() == 0;
}

/**
 * Returns if the stack is full or not.
 * 
 * @return true if only if the queue is full
 */
bool ArrayQueue::full () {
    return (this->size() == this->max_size);
}

/**
 * Prints the elements defined in the table. The order of
 * the elements shown is from the first to the last element in.
 */
void ArrayQueue:: print() {
    for(int i = 0; i<this->size(); i++) {
        cout << this->queueArray[(this->sentinella + i)%this->max_size] << endl;
    }
}

/**
 * Returns the first integer of the queue (the first element in).
 * 
 * @return int which represents the first element of the queue.
 */
int ArrayQueue::first() {
    if (this->empty()){
        throw out_of_range ("The queue is empty");
    }
    else {
        return this->queueArray[sentinella];
    }
}

//Modifier methods

/**
 * Insert the given element to the bottom of the queue.
 * 
 * @param item - int that will be put in.
 */
void ArrayQueue::enqueue(const int& item) {
    if (!full()) {
        this-> queueArray[(this->size() + this->sentinella)%this->max_size] = item;
        sizeController++;
    }
    else {
        throw out_of_range ("The queue is full");
    }
}

/**
 * Deletes the first element of the stack (the last one in) and returns it.
 * 
 * @returns the first integer in that will be removed
 */
int ArrayQueue::dequeue() {
    if (this->empty()){
        throw out_of_range ("The queue is empty");
    }
    else {
        int varAux = first();
        this-> queueArray [this->sentinella] = 0;
        this->sentinella = (this->sentinella + 1)% this->max_size;
        sizeController--;
        return varAux;
    }
}