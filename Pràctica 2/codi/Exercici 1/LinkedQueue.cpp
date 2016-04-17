/* 
 * File:   LinkedQueue.cpp
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 * 
 * Created on 31 / març / 2016
 */

#include "LinkedQueue.h"
#include "Node.h"
#include <stdexcept>
#include <iostream>

using namespace std;
/*
 * Default contructor for LinkedQueue.
 */
LinkedQueue::LinkedQueue() {
    this-> t = 0;
}

/**
 * Default duplicator contructor for LinkedQueue.
 * @param orig
 */
LinkedQueue::LinkedQueue(const LinkedQueue& orig) {
}

/**
 * Default destructor for LinkedQueue
 */
LinkedQueue::~LinkedQueue() {
    if (!this-> empty()) {
        Node<int>* it = this-> head;
        while(it != this->rear) { 
            it = it->getNext();
            delete this-> head;
            this-> head = it;
        }
        delete it;
    }
    delete this-> head;
    delete this-> rear;
}

/**
 * Returns the number of elements defined in the queue
 * 
 * @return int which represents the size of the queue
 */
int LinkedQueue::size() const {
    return this-> t;
}

/**
 * Returns if the stack is empty or not
 * 
 * @return true if only if the queue is empty
 */
bool LinkedQueue::empty() const {
    return (this-> size() == 0);
}

/**
 * Returns the first element of the queue (the first element in).
 * 
 * @return int which represents the first element of the queue.
 */
int LinkedQueue::first() const {
    if (this-> empty()) {
        throw new out_of_range ("The Queue is empty");
    }
    else {
        return this-> head-> getElement();
    }
}

/**
 * Prints the elements defined in the table. The order of
 * the elements shown is from the first to the last element in.
 */
void LinkedQueue::show() const {
    if (!this-> empty()) {
        Node<int>* it = this-> head;
        while(it != this->rear) {
            cout << it->getElement() << endl; 
            it = it->getNext();
        }
        //Now we print rear
        cout << it->getElement() << endl;
    }
}

/**
 * Insert the given element to the bottom of the queue.
 * 
 * @param value - int that will be put in.
 */
void LinkedQueue::enqueue(int value) {
    Node <int>* node = new Node <int> (value);
    if(this-> empty()) {
        this-> head = node;
    }
    else {
        this-> rear-> setNext(node);
    }
    this-> rear = node;
    this-> t++;
}


/**
 * Deletes the first element of the stack (the last one in) and returns it.
 * 
 * @returns the first integer in that will be removed
 */
void LinkedQueue::dequeue() {
    if (this-> empty()) {
        throw new out_of_range ("The Queue is empty");
    }
    else {
        Node <int>* node = new Node <int> (0);
        node->setNext(this-> head-> getNext());
        delete this->head;
        this-> head = node->getNext();
        delete node;
        this-> t--;
    }
}