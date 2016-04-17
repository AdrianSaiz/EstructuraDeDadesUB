/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: orabasal15.alumnes
 *
 * Created on 31 / març / 2016, 12:18
 */

#ifndef NODE_H
#define NODE_H

template <class E> class Node {
public:
    Node(const E& element);
    virtual ~Node();
    Node <E>* getNext() const;
    void setNext(Node* next);
    const E& getElement() const;
private:
    E element;
    Node* next;
};

/**
 * Constructor for Node by default. The node has two
 * fields:  the element passed by parameter and a pointer.
 * @param element
 */
template <class E> Node <E>::Node(const E& element) {
    this-> element = element;
    this-> next = 0;
}

/**
 * Default destructor for Node. 
 */
template <class E> Node <E>::~Node() {
    this-> setNext(0);
    delete next;
}

/**
 * Return the element of the node.
 * @return const E& Node the element which the node has.
 */
template <class E> const E& Node <E>::getElement() const {
    return this-> element;
}

/**
 * Set the pointer of the node to another Node of the same type of this.
 * @param next the node which the actual node will point.
 */
template <class E> void Node <E>::setNext(Node<E>* next) {
    this-> next = next;
}

/**
 * Get the element which the node points to.
 * @return Node <E>* the node which the node points.
 */
template <class E> Node <E>* Node <E>::getNext() const {
    return this-> next;
}

#endif /* NODE_H */