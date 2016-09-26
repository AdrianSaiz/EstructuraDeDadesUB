/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkHashEntry.h
 * Author: rballeba50.alumnes
 *
 * Created on 26 / maig / 2016, 12:32
 */

#ifndef LINKEDHASHENTRY_H
#define LINKEDHASHENTRY_H
#include <vector>
#include <iostream>

template <class K, class E> // K és el tipus de la Key, E és el tipus de les values
class LinkedHashEntry {
private:
    K key;
    std::vector<std::pair<E, E>> values;
    LinkedHashEntry* next;
public:
    
    /**
    * Default constructor for TAD LinkedHashEntry. It initializes the key value of the node
    * with no occurrences and sets the pointer to another node to null.
    * 
    * @param key
    */
    LinkedHashEntry(K key) {
        this->key = key;
        next = 0;
    }
    
    /**
     * Destructor for LinkedHashEntry, it deletes the next node if exists
     */
    ~LinkedHashEntry() {
        if (next != 0) {
            delete next;
        }
    }
    
    /**
    * Returns the key of the node.
    * 
    * @return the key of the node
    */
    K getKey() {
        return this->key;
    }
    
    /**
    * Gets a vector of pair with the occurrences of this node (of this key)
    * 
    * @return vector of pair with the occurrences
    */
    std::vector<std::pair<E, E>>& getValue() {
        return values;
    }
    
    /**
    * Sets a new occurrence of the key by giving the two needing parameters
    * 
    * @param line
    * @param wordNumber
    */
    void setValue(const E& line, const E& wordNumber) {
        values.push_back(std::make_pair(line, wordNumber));
    }
    
    /**
     * It returns the next element in the list (that means the next element in the
     * same position in the HashMap).
     * 
     * @return pointer to the next element
     */
    LinkedHashEntry *getNext() {
    return next;
    }
    
    /**
     * Sets the next element by giving a pointer to it
     * @param next
     */
    void setNext(LinkedHashEntry *next) {
    this->next = next;
    }
    
    /**
     * It prints the information contained by the position (All elements from vector and the key).
     */
    void toString() const {
        std::cout << "\nKey:" << this->key << "  Values:";
        for(typename std::vector<std::pair<E,E>>::const_iterator it = values.begin(); it!= values.end(); it++) {
            std::cout << "(" << it->first << "," << it->second << ") ";
        }
    }
};

#endif /* LINKEDHASHENTRY_H */

