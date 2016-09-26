/* 
 * File:   OrderedList.h
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 17 de abril de 2016, 17:42
 */
#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

#include "NodeList.h"

template <class E> class OrderedList : public NodeList<E> {
    public:
        //Constructor & Destructor
        OrderedList() : NodeList <E> () {};
        ~OrderedList();
        //Modificadors
        void insert(E elem);
};
template<class E> OrderedList<E>::~OrderedList() {}
template<class E> void OrderedList<E>:: insert(E elem) {
    DoubleNode<E>* puntInteresAux = NodeList<E>::puntInteres; // Punt d'interés.
    bool trobat = false;
    NodeList<E>::begin();
    if(NodeList<E>::empty()) NodeList<E>::insert(elem);
    while(!trobat && !NodeList<E>::end()) {
        if(NodeList<E>::get() >= elem) trobat = true;
        else NodeList<E>::next();
    }
    NodeList<E>::insert(elem);
    NodeList<E>::puntInteres = puntInteresAux;
}
#endif /* ORDEREDLIST_H */

