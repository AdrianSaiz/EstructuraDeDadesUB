/* 
 * File:   BinarySearchTree.h
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 21 / abril / 2016, 12:23
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <string>
#include <stdexcept>
#include "Position.h"

using namespace std;

template <class E, class N> class BinarySearchTree {
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        const int size() const {if (rootB == 0) return 0; else return size(rootB);};
        const int height() const {return this->height (this->rootB);};
        bool empty() const;
        const Position <E, N>* root() const;
        void insert (const E& element, const N& numLinia, const N& numParaula);
        bool search (const E& element) const;
        const Position <E,N>* getPosition(const E& element);
        void printPreorder() const {if (this->empty()) cout << "Tree is empty" << endl;
                                    else this->printPreorder (this->rootB);};
        void printPostorder() const {if (this->empty()) cout << "Tree is empty" << endl;
                                    else this->printPostorder (this->rootB);};
        void printInorder() const {if (this->empty()) cout << "Tree is empty" << endl;
                                    else this->printInorder (this->rootB);};
    
    private:
        const int size(Position <E, N>* subArbre) const;
        void printPreorder(const Position <E, N>* elem) const;
        void printPostorder(const Position <E, N>* elem) const;
        void printInorder(const Position <E, N>* elem) const;
        const int height (Position<E, N>* node) const;
        Position <E, N>* rootB;
        
};

/**
 * Default constructor for TAD BinarySearchTree. It initilizes the tree with no members.
 */
template <class E, class N> BinarySearchTree <E, N>::BinarySearchTree() {
    this->rootB = 0;
}

/**
 * Default destructor for TAD BinarySearchTree. It deletes all tree nodes by deleting the root one.
 */
template <class E, class N> BinarySearchTree <E, N>::~BinarySearchTree() {
    delete this->rootB;
}

/**
 * Returns the size of the tree (number of members).
 * 
 * @return int with the size of the tree
 */
template <class E, class N> const int BinarySearchTree <E, N>::size(Position <E, N>* subArbre) const {
    if(subArbre->isExternal()) return 1;
    else if(subArbre->left() != 0 && subArbre->right() != 0) return size (subArbre->left()) + size(subArbre->right()) + 1;
    else if(subArbre->right() != 0) return size (subArbre->right()) + 1;
    else return size (subArbre->left()) + 1;
}


/**
 * Returns a pointer to the root Position node.
 * 
 * @return a pointer to the root Position node
 */
template <class E, class N> const Position <E, N>* BinarySearchTree<E, N>::root() const {
    if (this->empty()) throw out_of_range ("Tree is empty");
    else return this->rootB;
}

/**
 * Returns the height of the tree.
 * 
 * @return int with the height of the tree
 */
template <class E, class N> const int BinarySearchTree <E, N>::height(Position<E, N>* node) const {
    if (node->isExternal()) return 0;
    else if (node->left() != 0 && node->right() != 0) return (max(height(node->left()), height(node->right()))+1);
    else if (node->left() == 0) return height(node->right())+1;
    else return height(node->left())+1;
}

/**
 * Returns if the tree is empty or not (has no members)
 * 
 * @return true if only if the size of the tree is 0
 */
template <class E, class N> bool BinarySearchTree <E, N>::empty() const {
    return (this->size() == 0);
}

/**
 * Inserts a node which will represent the given element. Notice that there can't
 * be two equal nodes (with the same element) and that the nodes are inserted orderly.
 * 
 * @param element
 */
template <class E, class N> void BinarySearchTree <E, N>::insert(const E& element, const N& numLinia, const N& numParaula) {
    if (this->empty())  {
        this->rootB = new Position <E, N>(element, 0); 
        this->rootB->setOcurrence(numLinia, numParaula);
    }
    else {
        Position <E, N>* nou;
        Position <E, N>* guia = this->rootB;
        while(guia->getElement() != element) {
            if(guia->getElement() > element) {
                if (guia->left() != 0) guia = guia->left(); 
                else {
                    nou = new Position <E, N>(element, guia);
                    guia->setLeft(nou);
                    guia = nou;
                }
            }
            else {
                if (guia->right() != 0) guia = guia->right(); 
                else {
                    nou = new Position <E, N>(element, guia);
                    guia->setRight(nou);
                    guia = nou;
                }
            }
        }
        guia->setOcurrence(numLinia, numParaula);
    }
}

/**
 * Returns if an element is in the tree or not.
 * 
 * @param element
 * @return true if only if the element is in tree.
 */
template <class E, class N> bool BinarySearchTree <E, N>::search(const E& element) const {
    Position <E, N>* guia = this->rootB;
    bool trobat = guia->getElement() == element;
    bool finalC = false;
        while(!trobat && !finalC) {
            if (guia->getElement() == element) trobat = true;
            else if(guia->getElement() > element) {
                if (!guia->left() == 0) guia = guia->left(); 
                else finalC = true;
            }
            else {
                if (!guia->right() == 0) guia = guia->right(); 
                else finalC = true;
            }
        }
    return trobat;
}
/**
 * If the element exists, it returns a pointer to it.
 * @param element Element to search.
 * @return const Position <E,N>* 
 */
template<class E, class N> const Position <E,N>* BinarySearchTree<E, N>::getPosition(const E& element) {
    Position <E, N>* guia = this->rootB;
    bool trobat = guia->getElement() == element;
    bool finalC = false;
        while(!trobat && !finalC) {
            if (guia->getElement() == element) trobat = true;
            else if(guia->getElement() > element) {
                if (!guia->left() == 0) guia = guia->left(); 
                else finalC = true;
            }
            else {
                if (!guia->right() == 0) guia = guia->right(); 
                else finalC = true;
            }
        }
    if (!trobat) return nullptr;
    else return guia;
}
/**
 * Auxiliary function that alows to print the tree in a preorder way by using recoursivity.
 * 
 * @param elem
 */
template <class E, class N> void BinarySearchTree <E, N>::printPreorder(const Position <E, N>* elem) const {
    elem->toString(); 
    cout << endl;
    if (!elem->isExternal()) {
        if(elem->left() != 0) printPreorder (elem->left());
        if(elem->right() != 0) printPreorder (elem->right());
    }
}

/**
 * Auxiliary function that alows to print the tree in a postorder way by using recoursivity.
 * 
 * @param elem
 */
template <class E, class N> void BinarySearchTree <E, N>::printPostorder(const Position <E, N>* elem) const {
    if (!elem->isExternal()) {
        if(elem->left() != 0) printPostorder (elem->left());
        if(elem->right() != 0)printPostorder (elem->right());
    }
    elem->toString(); 
    cout << endl;
}

/**
 * Auxiliary function that alows to print the tree in an inorder way by using recoursivity.
 * 
 * @param elem
 */
template <class E, class N> void BinarySearchTree <E, N>::printInorder(const Position <E, N>* elem) const {
    if (!elem->isExternal() && elem->left() != 0) {
        printInorder (elem->left());
    }
    elem->toString(); 
    cout << endl;
    if (!elem->isExternal() && elem->right() != 0) {
        printInorder (elem->right());
    }
}
#endif /* BINARYSEARCHTREE_H */

