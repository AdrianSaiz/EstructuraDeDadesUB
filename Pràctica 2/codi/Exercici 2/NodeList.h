/* 
 * File:   NodeList.h
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 * Created on 10 de abril de 2016, 20:52
 */

#ifndef NODELIST_H
#define NODELIST_H
#include "DoubleNode.h"
#include <iostream>
#include <stdexcept>

template <class E> class NodeList {
    public:
        //Gestors
        NodeList(); //Constructor
        ~NodeList(); //Destructors
        //Consultors
        bool empty() const; //Retorna true si està buit i false si tè com a mínim un element.
        int size() const; //Retorna la mida de la llista
        E get() const; //Retorna l'element del node
        void show() const; //Imprimeix tots els elements de la llista
        //Modificadors
        void insert(E elem);
        void remove();
        void modify(E elem);
        //Punt d'interés
        void begin(); //Va a l'inici de la llista
        bool end(); //Va al final de llista
        void next(); //Va al següent element de la llista
    private:
        DoubleNode<E>* head; //Per on comença la llista
        DoubleNode<E>* tail; //Per un acaba la llista
        DoubleNode<E>* puntInteres; // Punt d'interés.
        int length;
};
/*||||||||||||||||||||||||
  |                      |
  |        Gestors       |
  |                      |
  ||||||||||||||||||||||||*/
template <class E> NodeList<E>::NodeList() {
    DoubleNode<E>* ghostNodeStart = new DoubleNode<E>(0); //Node que no apunta a res.
    DoubleNode<E>* ghostNodeEnd = new DoubleNode<E>(0);
    ghostNodeStart->setNext(ghostNodeEnd);
    ghostNodeEnd->setNext(ghostNodeEnd);
    ghostNodeEnd->setPrev(ghostNodeStart);
    //Cal implementar direccions ghost Node
    head = ghostNodeStart;
    tail = ghostNodeEnd;
    puntInteres = ghostNodeEnd;
    length = 0;
}
template <class E> NodeList<E>::~NodeList() {
    delete head;
    delete tail;
    delete puntInteres;
    //Com els nodes els hem creat sense punters C++ gestiona la seva eliminació
}
/*||||||||||||||||||||||||
  |                      |
  |      Consultors      |
  |                      |
  ||||||||||||||||||||||||*/
template <class E> int NodeList<E>::size() const {
    return length;
}
template <class E> bool NodeList<E>::empty() const {
    return size() == 0;
}
template <class E> E NodeList<E>::get() const {
    if (empty()) throw new std::out_of_range("La llista està buida.");
    else return puntInteres->getElement();
}
template <class E> void NodeList<E>::show() const {
    if (empty()) throw new std::out_of_range("La llista està buida.");
    else {
        DoubleNode<E>* puntInteresAux = head->getNext(); // per retornar al punt interés una vegada s'hagi mostrat tot.
        while(puntInteresAux != tail) {
            std::cout << puntInteresAux->getElement() <<  "| ";
            puntInteresAux = puntInteresAux->getNext();
        }
        std::cout << std::endl;
    }
}
/*||||||||||||||||||||||||
  |                      |
  |     Modificadors     |
  |                      |
  ||||||||||||||||||||||||*/

template <class E> void NodeList<E>::insert(E elem) {
    DoubleNode<E>* newNode = new DoubleNode<E>(elem);
    newNode->setPrev(puntInteres->getPrev());
    newNode->getPrev()->setNext(newNode);
    newNode->setNext(puntInteres);
    puntInteres->setPrev(newNode);
    puntInteres = puntInteres->getNext()->getPrev();
    length++;
}

template <class E> void NodeList<E>::remove() {
    if (empty()) throw new std::out_of_range("No hi ha elements");
    else if(end()) throw new std::out_of_range("No pots eliminar l'últim element");
    else {
        puntInteres->getNext()->setPrev(puntInteres->getPrev());
        puntInteres = puntInteres->getNext();
        delete puntInteres->getPrev()->getNext();
        puntInteres->getPrev()->setNext(puntInteres);
        length--;
    }
}
template <class E> void NodeList<E>::modify(E elem) {
    puntInteres->setElem(elem);
}
/*||||||||||||||||||||||||
  |                      |
  |       P.Interés      |
  |                      |
  ||||||||||||||||||||||||*/
template <class E> void NodeList<E>::begin() {
    puntInteres = head->getNext();
}
template <class E> bool NodeList<E>::end() {
    return puntInteres == tail->getPrev();
}
template <class E> void NodeList<E>::next() {
    puntInteres = puntInteres->getNext();
}
#endif /* NODELIST_H */

