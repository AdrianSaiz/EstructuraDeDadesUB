/* 
 * File:   MinHeap.h
 * Author: Rubén Ballester Bautista / Oriol Rabasseda Alcaide
 * 
 * Created on 15 / may / 2016, 12:28
 */

#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <string>
#include <iostream>
#include "Position.h"
#include <stdexcept>
#include <math.h> 

using namespace std;

template <class E, class N> class MinHeap {
    public:
        MinHeap() {};
        virtual ~MinHeap();
        const int size() const {return this->vectorElems.size();};
        const bool empty() const {return size() == 0;};
        void insert(const E& key, const N& first, const N& second);
        const E& min() const;
        const Position <E,N>* getPosition(const E& element);
        const vector<pair<N, N>> minValues()const ;
        void removeMin();
        void printHeap();
        int height() {return (int)(log2(vectorElems.size()))+ 1;};
    private:
        vector<Position<E, N>*> vectorElems;
        void upHeap();
        void downHeap();
        void swap (int pos1, int pos2);
};


/**
 * Destructor for MinHeap, it deletes all the nodes defined. Because the vector 
 * will be deleted automatically.
 */
template <class E, class N> MinHeap<E, N>::~MinHeap() {
    int i = vectorElems.size() - 1;
    for (i; i >= 0; i--) {
        if(vectorElems[i] != 0) delete vectorElems[i];
    }
}

/**
 * Inserts a node which will represent the given element. Notice that there can't
 * be two equal nodes (with the same element) and that the nodes are inserted quite orderly.
 * 
 * @param element
 */
template <class E, class N> void MinHeap<E, N>::insert(const E& key, const N& first, const N& second) {
    if (empty()) {
        vectorElems.push_back(new Position<E, N>(key));
        vectorElems[0]->newValue(first, second);
    }
    else {
        bool found = false;
        int i = 0;
        while (!found && i < vectorElems.size()) {
            found = vectorElems.at(i)->getKey() == key;
            i++;
        }
        if (!found) {
            vectorElems.push_back(new Position<E, N>(key));
            vectorElems[vectorElems.size()-1]->newValue(first, second);
            upHeap();
        }
        else {
            vectorElems[i-1]->newValue(first, second);
        }
    }
}

/**
 * It reestructures the heap after inserting an element in order to mantain the order.
 */
template<class E, class N> void MinHeap<E, N>::upHeap() {
    bool found = false;
    int positionToUpHeap = vectorElems.size() - 1;
    while(positionToUpHeap != 0 && !found) {
        if(vectorElems[(positionToUpHeap - 1)/2]->getKey() > vectorElems[positionToUpHeap]->getKey()) {
            swap (positionToUpHeap, (positionToUpHeap  - 1)/2);
            positionToUpHeap = (positionToUpHeap - 1)/2;
        }
        else found = true;
    }
}

/**
 * Swaps the position in the heap between 2 given positions in the vector.
 * 
 * @param pos1
 * @param pos2
 */
template<class E, class N> void MinHeap<E, N>::swap(int pos1, int pos2) {
    Position<E, N>* positionAux = vectorElems[pos1];
    vectorElems[pos1] = vectorElems[pos2];
    vectorElems[pos2] = positionAux;
}

/**
 * Returns the minumum element of the heap (always corresponding to the first in the
 * vector)
 * 
 * @return minimum element in the heap 
 */
template <class E, class N> const E& MinHeap<E, N>::min() const {
    if (empty()) throw new out_of_range("Heap buit");
    return vectorElems[0]->getKey();
}

/**
 * Returns a vector if pair with the occurrences of the minimum key in the heap.
 * 
 * @return 
 */
template <class E, class N> const vector<pair<N, N>> MinHeap<E, N>::minValues() const {
    if (empty()) throw new out_of_range("Heap buit");
    return vectorElems[0].getValues();
}

/**
 * Deletes the minimum element of the heap (always corresponding to the first one
 * in the vector).
 */
template <class E, class N> void MinHeap<E, N>::removeMin() {
    if(empty()) throw new out_of_range("Heap buit");
    Position<E, N>* positionAux = vectorElems[0];
    vectorElems[0] = vectorElems[vectorElems.size()-1];
    vectorElems[vectorElems.size()-1] = positionAux;
    vectorElems.pop_back();
    downHeap();
}

/**
 * It restructures the heap after deleting an element (specifically for deleting the minumum one).
 */
template <class E, class N> void MinHeap<E, N>::downHeap() {
    int i = 0;
    bool found = false;
    while(i < vectorElems.size() && !found) {
        if (2*i+2 >= vectorElems.size() && 2*i+1 >= vectorElems.size()) {
            found = true;
        }
        else if (2*i+2 >= vectorElems.size()) {
            if (vectorElems[i]->getKey() > vectorElems[2*i+1]->getKey()) {
                swap (2*i+1, i);
                i = 2*i+1;
            }
            else {
                found = true;
            }
        }
        else if (2*i+1 >= vectorElems.size()) {
            if (vectorElems[i]->getKey() > vectorElems[2*i+2]->getKey()) {
                swap (2*i+2, i);
                i = 2*i+2;
            }
            else {
                found = true;
            }
        }
        else {
            if (vectorElems[2*i+2]->getKey() > vectorElems[2*i+1]->getKey()) {
                if (vectorElems[i]->getKey() > vectorElems[2*i+1]->getKey()) {
                    swap (2*i+1, i);
                    i = 2*i+1;
                }
                else {
                    found = true;
                }
            }
            else {
                if (vectorElems[i]->getKey() > vectorElems[2*i+2]->getKey()) {
                    swap (2*i+2, i);
                    i = 2*i+2;
                }
                else {
                    found = true;
                }
            }
        }
    }
}

/**
 * Prints the heap how it is structured inside the vector (the floors of the heap
 * have always bigger keys that the ones which are above).
 */
template <class E, class N> void MinHeap<E, N>::printHeap() {
    Position<E, N>* posAux;
    for (typename vector<Position<E,N>*>::iterator it = vectorElems.begin() ; it != vectorElems.end(); ++it) {
        posAux = *it;
        posAux->toString();
    }
}

/**
 * If the element exists, it returns a pointer to it.
 * @param element Element to search.
 * @return const Position <E,N>* 
 */
template<class E, class N> const Position <E,N>* MinHeap<E, N>::getPosition(const E& element) {
    bool found = false;
    int i = 0;
    while (!found && i < vectorElems.size()) {
        found = vectorElems.at(i)->getKey() == element;
        i++;
    }
    if (!found) return nullptr;
    else return vectorElems.at(i-1);
}
#endif /* MINHEAP_H */

