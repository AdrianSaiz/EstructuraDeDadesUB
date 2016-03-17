/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayQueue.cpp
 * Author: rballeba50.alumnes
 * 
 * Created on 17 / març / 2016, 12:37
 */

#include "ArrayQueue.h"
#include <stdexcept>
#include <iostream>

using namespace std;

ArrayQueue::ArrayQueue(int const &maxSize) {
    this ->sizeController = 0; 
    this->max_size = maxSize;
    queueArray = new int[maxSize];
    this->sentinella = 0;
}

ArrayQueue::~ArrayQueue() {
}

int ArrayQueue::size() {
    return this->sizeController;
}

bool ArrayQueue::empty() {
    return this->size() == 0;
}

bool ArrayQueue::full () {
    return (this->size() == this->max_size);
}

int ArrayQueue::first() {
    if (this->empty()){
        throw out_of_range ("The queue is empty");
    }
    else {
        return this->queueArray[sentinella];
    }
}

void ArrayQueue::enqueue(const int& item) {
    if (!full()) {
        this-> queueArray[(this->size() + this->sentinella)%this->max_size] = item;
        sizeController++;
    }
    else {
        throw out_of_range ("The queue is full");
    }
}

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

void ArrayQueue:: print() {
    for(int i = 0; i<this->size(); i++) {
        cout << this->queueArray[(this->sentinella + i)%this->max_size] << endl;
    }
}