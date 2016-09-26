/* 
 * File:   HashMap.h
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 15 / may / 2016, 12:23
 */

#ifndef HASHMAP_H
#define HASHMAP_H
#include <string>
#include "LinkedHashEntry.h"

template <class E, class N> class HashMap {
    public:
        const static int MAX_TABLE = 20123;
        const int POL = 617;
        HashMap();
        virtual ~HashMap();
        int getHashCode(std::string key) const;
        int getHashCode (int key) const;
        void put(const E& key, const N& line, const N& wordNumber);
        const bool get(const E& key) const;
        LinkedHashEntry <E,N>* getPosition(const E& element);
        int size;
        int celles;
        int colisioMax;
    private:
        LinkedHashEntry<E,N>* arrayElems[MAX_TABLE] = {};
            
};

/**
 * Default constructor for HashMap. It initilizes the size, the cells that have elements
 * and the maximum collision.
 */
template <class E, class N> HashMap<E, N>::HashMap() {
    size = 0;
    celles = 0;
    colisioMax = 0;
}

/**
 * Destructor for HashMap, it deletes all the nodes defined.
 */
template <class E, class N> HashMap<E, N>::~HashMap() {;
    for (int i = size; i >= 0; i--) {
        if (arrayElems[i] != 0) {
            delete arrayElems[i];
        }
    }
}

/**
 * Returns if the given key is arleady defined in the hash or not
 * 
 * @param key
 * @return true if only if the element is defined in the hash
 */
template <class E, class N> const bool HashMap<E, N>::get(const E& key) const {   
    bool found = arrayElems[getHashCode(key)] != 0;
    if (found) {
        LinkedHashEntry<E,N>* aux = arrayElems[getHashCode(key)];
        found = false;
        while (aux != 0 && !found) {
            if(aux->getKey() != key) found = true;
            else aux = aux->getNext();
        }
        if (found) aux->toString();
    }
    return found;
}

/**
 * Returns the hasCode of the given key if that key is a string
 * 
 * @param key
 * @return int with the hash code where the node with that key has to be located
 */
template <class E, class N> int HashMap<E, N>::getHashCode(std::string key) const {
    int polynomial = 0;
    for (int i=0; i<key.length(); ++i) {
        //Per a evitar caràcters extranys.
        if((int)key[i] > 0) polynomial += key[i]*(POL^i);
    }
    return polynomial%MAX_TABLE;
}

/**
 * Returns the hasCode of the given key if that key is an integer
 * 
 * @param key
 * @return int with the hash code where the node with that key has to be located
 */
template <class E, class N> int HashMap<E, N>::getHashCode(int key) const {
    return key%MAX_TABLE;
}

/**
 * Inserts a node which will represent the given element. Notice that there can't
 * be two equal nodes (with the same element) and that the nodes are inserted quite randomly.
 * 
 * @param element
 */
template <class E, class N> void HashMap<E, N>::put(const E& key, const N& line, const N& wordNumber) {
    int hashCode = getHashCode(key);
    bool found = arrayElems[hashCode] != 0;
    if (found) {
        int i = 0;
        LinkedHashEntry<E,N>* aux = arrayElems[hashCode];
        found = false;
        bool last = false;
        while (aux != 0 && !found && !last) {
            if (aux->getKey()== key) found = true;
            else if(aux->getNext() != 0) aux = aux->getNext();
            else last = true;
            i++;
        }
        if (!found) {
            LinkedHashEntry<E,N>* nou = new LinkedHashEntry<E,N> (key);
            aux->setNext(nou);
            size++;
            if (colisioMax < i) {
                colisioMax = i;
            }
            nou->setValue(line, wordNumber);
        }
        else aux->setValue(line, wordNumber);
    }
    else {
        arrayElems[hashCode] = new LinkedHashEntry<E,N> (key);
        arrayElems[hashCode]->setValue(line, wordNumber);
        size++;
        celles++;
    }
}

/**
 * If the element exists, it returns a pointer to it.
 * @param element Element to search.
 * @return const LinkedHashEntry <E,N>* 
 */
template<class E, class N> LinkedHashEntry <E,N>* HashMap <E, N>::getPosition(const E& element) {
    bool found = arrayElems[getHashCode(element)] != 0;
    if (found) {
        found = false;
        LinkedHashEntry<E,N>* aux = arrayElems[getHashCode(element)];
        while (aux != 0 && !found) {
            if(aux->getKey() == element) found = true;
            else aux = aux->getNext();
        }
        if (found) return aux;
    }
    return 0;
}
#endif /* HASHMAP_H */

