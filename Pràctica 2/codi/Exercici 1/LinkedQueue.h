/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedQueue.h
 * Author: orabasal15.alumnes
 *
 * Created on 31 / març / 2016, 12:35
 */

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "Node.h"

class LinkedQueue {
public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue& orig);
    virtual ~LinkedQueue();
    bool empty() const;
    int first() const;
    int size() const;
    void show() const;
    void enqueue (int value);
    void dequeue();
private:
    int t;
    Node<int>* head; //Apunta a la cabeza
    Node<int>* rear; //Apunta al final
};

#endif /* LINKEDQUEUE_H */

