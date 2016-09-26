/* 
 * File:   Position.h
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 21 / abril / 2016, 12:23
 */

#ifndef POSITION_H
#define POSITION_H

template <class E> class Position {
    public:
        Position (const E& element, Position<E>* const parentAux);
        virtual ~Position() {};
        const E getElement() const;
        Position<E>* const parent() const;
        Position<E>* const right() const;
        Position<E>* const left() const;
        bool isRoot() const;
        bool isExternal() const;
        void setRight(Position<E>* const rightAux);
        void setLeft(Position<E>* const leftAux);
        void setParent(Position<E>* const parentAux);
    
        private:
            Position<E>* leftP;
            Position<E>* rightP;
            Position<E>* parentP;
            E elementP;
};

/**
 * Default constructor for TAD Position. It initializes the node with no children
 * but it needs the value of the node and the parent.
 * 
 * @param element
 * @param parentAux
 */
template <class E> Position <E>::Position(const E& element, Position<E>* const parentAux) {
    this->elementP = element;
    this->leftP = 0;
    this->rightP = 0;
    setParent(parentAux);
}

/**
 * Returns the value of the node.
 * 
 * @return the value of the node
 */
template <class E> const E Position <E>::getElement() const {
    return this->elementP;
}

/**
 * Returns the parant of the node.
 * 
 * @return the parent of the node
 */
template <class E> Position<E>* const Position <E>::parent() const {
    return this->parentP;
}

/**
 * Returns the right child of the node.
 * 
 * @return the right child of the node
 */
template <class E> Position<E>* const Position <E>::right() const {
    return this->rightP;
}

/**
 * Returns the left child of the node.
 * 
 * @return the left child of the node
 */
template <class E> Position<E>* const Position <E>::left() const {
    return this->leftP;
}

/**
 * Returns if the node is the root or not (of the tree)
 * 
 * @return true if only if the node has no parent (is root)
 */
template <class E> bool Position<E>::isRoot() const {
    return (this->parent() == 0);
}

/**
 * Returns if the node is external or not (in the tree)
 * 
 * @return true if only if the node has no children (is external)
 */
template <class E> bool Position<E>::isExternal() const {
    return (this->left() == 0 && this->right() == 0);
}

/**
 * Sets the right child of the node with a given one (as a pointer).
 * 
 * @param rightAux
 */
template <class E> void Position<E>::setRight(Position<E>* const rightAux) {
    this->rightP = rightAux;
}

/**
 * Sets the left child of the node with a given one (as a pointer).
 * 
 * @param leftAux
 */
template <class E> void Position<E>::setLeft(Position<E>* const leftAux) {
    this->leftP = leftAux;
}

/**
 * Changes the parent of the node with a given one (as a pointer).
 * 
 * @param parentAux
 */
template <class E> void Position<E>::setParent(Position<E>* const parentAux) {
    this->parentP = parentAux;
}

#endif /* POSITION_H */

