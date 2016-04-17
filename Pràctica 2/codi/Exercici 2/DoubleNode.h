/* 
 * File:   DoubleNode.h
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 10 de abril de 2016, 20:32
 */

#ifndef DOUBLENODE_H
#define DOUBLENODE_H

template <class E> class DoubleNode {
    public:
        //Gestors
        DoubleNode(E elem); //Constructor amb una refèrencia de l'element.
        ~DoubleNode(); //Destructor
        //Consultors
        DoubleNode<E>* getNext() const; //Retorna un punter al següent node.
        DoubleNode<E>* getPrev() const; //Retorna un punter al node anterior.
        E getElement() const; //Retorna una referència a l'element que guarda el node
        //Modificadors
        void setNext(DoubleNode<E>* nextNode); //Canvia el punter double node següent al que apunta .
        void setPrev(DoubleNode<E>* prevNode); //Canvia el punter double node anterior al què apunta.
        void setElem(E newElem); //Canvia l'element del Node.
    private:
        E elem;
        DoubleNode<E>* prev;
        DoubleNode<E>* next;
};

/*||||||||||||||||||||||||
  |                      |
  |        Gestors       |
  |                      |
  ||||||||||||||||||||||||*/

template<class E> DoubleNode<E>::DoubleNode(E elem) {
    this->elem = elem;
    next = 0; //Valor per defecte que no apunta a res
    prev = 0; //Valor per defecte que no apunta a res
}
template<class E> DoubleNode<E>::~DoubleNode() {
    //No fa res, els elements declarats com no punters els gestiona C++ i els punters no es tenen que eliminar.
}
/*||||||||||||||||||||||||
  |                      |
  |      Consultors      |
  |                      |
  ||||||||||||||||||||||||*/
template<class E> E DoubleNode<E>::getElement() const {
    return elem;
}
template<class E> DoubleNode<E>* DoubleNode<E>::getNext() const {
    return next;
}
template<class E> DoubleNode<E>* DoubleNode<E>::getPrev() const {
    return prev;
}
/*||||||||||||||||||||||||
  |                      |
  |     Modificadors     |
  |                      |
  ||||||||||||||||||||||||*/
template<class E> void DoubleNode<E>::setNext(DoubleNode<E>* nextNode) {
    next = nextNode; //Punter igual a la direcció de memòria a la qual apunta nextNode
}
template<class E> void DoubleNode<E>::setPrev(DoubleNode<E>* prevNode) {
    prev = prevNode; //Punter igual a la direcció de memòria a la qual apunta prevNode
}
template<class E> void DoubleNode<E>::setElem(E newElem) {
    elem = newElem;
}
#endif /* DOUBLENODE_H */

