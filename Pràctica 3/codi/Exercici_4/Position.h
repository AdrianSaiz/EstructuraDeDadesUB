/* 
 * File:   Position.h
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 21 / abril / 2016, 12:23
 */

#ifndef POSITION_H
#define POSITION_H

#include <vector>

using namespace std;

template <class E, class N> class Position {
    public:
        Position (const E& element, Position <E, N>* const parentAux);
        virtual ~Position() {};
        const E getElement() const;
        void toString() const;
        const int balanceFactor() const;
        const int getHeight() const;
        const vector<pair<N, N>> getValues() const;
        Position <E, N>* const parent() const;
        Position <E, N>* const right() const;
        Position <E, N>* const left() const;
        bool isRoot() const;
        bool isExternal() const;
        void setOcurrence(const N& numLinia, const N& numParaula);
        void setHeight (const int& height);
        void setRight(Position<E, N>* const rightAux);
        void setLeft(Position<E, N>* const leftAux);
        void setParent(Position<E, N>* const parentAux);
    
        private:
            Position<E, N>* leftP;
            Position<E,N>* rightP;
            Position<E, N>* parentP;
            E key;
            vector<pair<N,N>> values;
            int height;
};

/**
 * Default constructor for TAD Position. It initializes the node with no children
 * but it needs the value of the node and the parent.
 * 
 * @param element
 * @param parentAux
 */
template <class E, class N> Position <E, N>::Position(const E& element, Position<E, N>* const parentAux) {
    this->key = element;
    this->leftP = 0;
    this->rightP = 0;
    this->height = 1;
    setParent(parentAux);
}

/**
 * Returns the value of the node.
 * 
 * @return the value of the node
 */
template <class E, class N> const E Position <E,N>::getElement() const {
    return this->key;
}
/**
 * It prints the information contained by the position (All elements from vector and the key).
 */
template <class E, class N> void Position<E,N>::toString() const {
    cout << this->getElement() << "[";
    for(typename vector<pair<N,N>>::const_iterator it = values.begin(); it != values.end(); ++it) {
        cout << "(" << (*it).first << ", " << (*it).second << ")";
    }
    cout << "]";
}
template <class E, class N> const vector<pair<N, N>> Position<E, N>::getValues() const {
    return this->values;
}
/**
 * Return the height of the node.
 */
template <class E, class N> const int Position<E, N>:: getHeight() const {
    return this->height;
}
/**
 * Returns the parant of the node.
 * 
 * @return the parent of the node
 */
template <class E, class N> Position<E, N>* const Position<E, N>::parent() const {
    return this->parentP;
}

/**
 * Returns the right child of the node.
 * 
 * @return the right child of the node
 */
template <class E, class N> Position<E, N>* const Position<E, N>::right() const {
    return this->rightP;
}

/**
 * Returns the left child of the node.
 * 
 * @return the left child of the node
 */
template <class E, class N> Position<E, N>* const Position<E, N>::left() const {
    return this->leftP;
}

/**
 * Returns if the node is the root or not (of the tree)
 * 
 * @return true if only if the node has no parent (is root)
 */
template <class E, class N> bool Position<E, N>::isRoot() const {
    return (this->parent() == 0);
}

/**
 * Returns if the node is external or not (in the tree)
 * 
 * @return true if only if the node has no children (is external)
 */
template <class E, class N> bool Position<E, N>::isExternal() const {
    return (this->left() == 0 && this->right() == 0);
}
template <class E, class N> void Position<E, N>::setOcurrence(const N& numLinia, const N& numParaula) {
    values.push_back(make_pair(numLinia, numParaula));
}
/**
 * Sets the height of the node with a given one (as a integer)
 * 
 * @param heightLeft
 */
template <class E, class N> void Position <E, N>::setHeight(const int& height) {
    this->height = height;
}

/**
 * Sets the right child of the node with a given one (as a pointer).
 * 
 * @param rightAux
 */
template <class E, class N> void Position<E, N>::setRight(Position<E, N>* const rightAux) {
    this->rightP = rightAux;
}

/**
 * Sets the left child of the node with a given one (as a pointer).
 * 
 * @param leftAux
 */
template <class E, class N> void Position<E, N>::setLeft(Position<E, N>* const leftAux) {
    this->leftP = leftAux;
}

/**
 * Changes the parent of the node with a given one (as a pointer).
 * 
 * @param parentAux
 */
template <class E, class N> void Position<E, N>::setParent(Position<E, N>* const parentAux) {
    this->parentP = parentAux;
}

#endif /* POSITION_H */

