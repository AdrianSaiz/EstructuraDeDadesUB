/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayQueue.h
 * Author: rballeba50.alumnes
 *
 * Created on 17 / març / 2016, 12:37
 */

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

class ArrayQueue {
public:
    ArrayQueue(int const &maxSize);
    virtual ~ArrayQueue();
    //Check methods
    int size();
    bool full();
    bool empty();
    //Set methods
    void enqueue(int const &item);
    int dequeue();
    void print();
private:
    int sizeController;
    int max_size;
    int sentinella;
    int* queueArray;
    int first();
};

#endif /* ARRAYQUEUE_H */

