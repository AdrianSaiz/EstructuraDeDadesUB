/* 
 * File:   ArrayQueue.h
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 10 / març / 2016, 12:13
 */

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

class ArrayQueue {
public:
    ArrayQueue(int const &maxSize); // constructor
    virtual ~ArrayQueue(); // destructor
    //Check methods
    int size(); // return the size
    bool full(); // return TRUE if the queue is full
    bool empty(); // return TRUE if the queue is empty
    //Set methods
    void enqueue(int const &item); // introduce an element in the queue
    int dequeue(); // return the first element of queue
    void print(); //Prints all the content of the queue
private:
    int sizeController;
    int max_size;
    int sentinella;
    int* queueArray;
    int first(); //Returns the first element of the queue
};

#endif /* ARRAYQUEUE_H */

