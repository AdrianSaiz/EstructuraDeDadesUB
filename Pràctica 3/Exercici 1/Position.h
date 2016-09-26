/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Position.h
 * Author: orabasal15.alumnes
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

template <class E> Position <E>::Position(const E& element, Position<E>* const parentAux) {
    this->elementP = element;
    this->leftP = 0;
    this->rightP = 0;
    setParent(parentAux);
}

template <class E> const E Position <E>::getElement() const {
    return this->elementP;
}

template <class E> Position<E>* const Position <E>::parent() const {
    return this->parentP;
}

template <class E> Position<E>* const Position <E>::right() const {
    return this->rightP;
}

template <class E> Position<E>* const Position <E>::left() const {
    return this->leftP;
}

template <class E> bool Position<E>::isRoot() const {
    return (this->parent() == 0);
}

template <class E> bool Position<E>::isExternal() const {
    return (this->right() == 0 && this->right() == 0);
}

template <class E> void Position<E>::setRight(Position<E>* const rightAux) {
    this->rightP = rightAux;
}

template <class E> void Position<E>::setLeft(Position<E>* const leftAux) {
    this->leftP = leftAux;
}

template <class E> void Position<E>::setParent(Position<E>* const parentAux) {
    this->parentP = parentAux;
}

#endif /* POSITION_H */

