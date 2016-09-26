/* 
 * File:   Position.h
 * Author: Rubén Ballester Bautista / Oriol Rabasseda Alcaide
 * 
 * Created on 15 / may / 2016, 12:28
 */

#ifndef POSITION_H
#define POSITION_H

#include <vector>
#include <string>

using namespace std;

template <class E, class N> class Position {
    public:
        Position(E key);
        virtual ~Position() {};
        const E& getKey() const;
        void newValue(const N& first, const N& second);
        void toString() const;
        const vector<pair<N,N>> getValues() const;
    private:
        E key;
        vector<pair<N, N>> values;
};

/**
 * Default constructor for TAD Position. It initializes the key value of the node
 * with no occurrences.
 * 
 * @param key
 */
template <class E, class N>  Position<E, N>::Position(E key) {
    this->key = key;
}

/**
 * Returns the key of the node.
 * 
 * @return the key of the node
 */
template <class E, class N> const E& Position<E,N>::getKey() const {
    return this->key;
}

/**
 * Sets a new occurrence of the key by giving the two needing parameters
 * 
 * @param first
 * @param second
 */
template <class E, class N> void Position<E, N>::newValue(const N& first, const N& second) {
    values.push_back(make_pair(first, second));
}

/**
 * It prints the information contained by the position (All elements from vector and the key).
 */
template <class E, class N> void Position<E, N>::toString() const {
    cout << "\nKey:" << this->key << "  Values:";
    for(typename vector<pair<N,N>>::const_iterator it = values.begin(); it!= values.end(); it++) {
        cout << "(" << it->first << "," << it->second << ") ";
    }
}

/**
 * Gets a vector of pair with the occurrences of this node (of this key)
 * 
 * @return vector of pair with the occurrences
 */
template <class E, class N> const vector<pair<N,N>> Position<E, N>::getValues() const {
    return values;
}

#endif /* POSITION_H */