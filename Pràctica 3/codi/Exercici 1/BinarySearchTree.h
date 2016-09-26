/* 
 * File:   BinarySearchTree.h
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 21 / abril / 2016, 12:23
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <stdexcept>
#include "Position.h"

using namespace std;

template <class E> class BinarySearchTree {
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        const int size() const {if (rootB == 0) return 0; else return size(rootB);};
        const int height() const {return this->height (this->rootB);};
        bool empty() const;
        const Position<E>* root() const;
        void insert (const E& element);
        bool search (const E& element) const;
        void printPreorder() const {if (this->empty()) cout << "Tree is empty" << endl;
                                    else this->printPreorder (this->rootB);};
        void printPostorder() const {if (this->empty()) cout << "Tree is empty" << endl;
                                    else this->printPostorder (this->rootB);};
        void printInorder() const {if (this->empty()) cout << "Tree is empty" << endl;
                                    else this->printInorder (this->rootB);};
    
    private:
        const int size(Position<E>* subArbre) const;
        void printPreorder(const Position<E>* elem) const;
        void printPostorder(const Position<E>* elem) const;
        void printInorder(const Position<E>* elem) const;
	const int height (Position<E>* node) const;
        Position<E>* rootB;
};

/**
 * Default constructor for TAD BinarySearchTree. It initilizes the tree with no members.
 */
template <class E> BinarySearchTree <E>::BinarySearchTree() {
    this->rootB = 0;
    this->heightB = 0;
}

/**
 * Default destructor for TAD BinarySearchTree. It deletes all tree nodes by deleting the root one.
 */
template <class E> BinarySearchTree <E>::~BinarySearchTree() {
    delete this->rootB;
}

/**
 * Returns the size of the tree (number of members).
 * 
 * @return int with the size of the tree
 */
template <class E> const int BinarySearchTree <E>::size(Position<E>* subArbre) const {
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
template <class E> const Position<E>* BinarySearchTree<E>::root() const {
    if (this->empty()) throw new out_of_range ("Tree is empty");
    else return this->rootB;
}

/**
 * Returns the height of the tree.
 * 
 * @return int with the height of the tree
 */
template <class E> const int BinarySearchTree <E>::height() const {
    return this->heightB;
}

/**
 * Returns if the tree is empty or not (has no members)
 * 
 * @return true if only if the size of the tree is 0
 */
template <class E> bool BinarySearchTree <E>::empty() const {
    return (this->size() == 0);
}
/**
 * Returns the height of the tree.
 * 
 * @return int with the height of the tree
 */
template <class E> const int BinarySearchTree <E>::height(Position<E>* node) const {
    if (node->isExternal()) return 0;
    else if (node->left() != 0 && node->right() != 0) return (max(height(node->left()), height(node->right()))+1);
    else if (node->left() == 0) return height(node->right())+1;
    else return height(node->left())+1;
}
/**
 * Inserts a node which will represent the given element. Notice that there can't
 * be two equal nodes (with the same element) and that the nodes are inserted orderly.
 * 
 * @param element
 */
template <class E> void BinarySearchTree <E>::insert(const E& element) {
    if (this->empty())  {
        this->rootB = new Position<E>(element, 0); 
    }
    else {
        Position <E>* nou;
        Position <E>* guia = this->rootB;
        int i = 0;
        while(guia->getElement() != element) {
            if(guia->getElement() > element) {
                if (!guia->left() == 0) guia = guia->left(); 
                else {
                    nou = new Position<E>(element, guia);
                    guia->setLeft(nou);
                    guia = nou;
                }
            }
            else {
                if (!guia->right() == 0) guia = guia->right(); 
                else {
                    nou = new Position<E>(element, guia);
                    guia->setRight(nou);
                    guia = nou;
                }
            }
            i++;
        }
        if (i > this->heightB) this->heightB = i;
    }
}

/**
 * Returns if an element is in the tree or not.
 * 
 * @param element
 * @return true if only if the element is in tree.
 */
template <class E> bool BinarySearchTree <E>::search(const E& element) const {
    Position <E>* guia = this->rootB;
    bool trobat = guia->getElement() == element;
    bool final = false;
        while(!trobat && !final) {
            if (guia->getElement() == element) trobat = true;
            else if(guia->getElement() > element) {
                if (!guia->left() == 0) guia = guia->left(); 
                else final = true;
            }
            else {
                if (!guia->right() == 0) guia = guia->right(); 
                else final = true;
            }
        }
    return trobat;
}

/**
 * Auxiliary function that alows to print the tree in a preorder way by using recoursivity.
 * 
 * @param elem
 */
template <class E> void BinarySearchTree <E>::printPreorder(const Position<E>* elem) const {
    cout << elem->getElement() << endl;
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
template <class E> void BinarySearchTree <E>::printPostorder(const Position<E>* elem) const {
    if (!elem->isExternal()) {
        if(elem->left() != 0) printPostorder (elem->left());
        if(elem->right() != 0)printPostorder (elem->right());
    }
    cout << elem->getElement() << endl;
}

/**
 * Auxiliary function that alows to print the tree in an inorder way by using recoursivity.
 * 
 * @param elem
 */
template <class E> void BinarySearchTree <E>::printInorder(const Position<E>* elem) const {
    if (!elem->isExternal() && elem->left() != 0) {
        printInorder (elem->left());
    }
    cout << elem->getElement() << endl;
    if (!elem->isExternal() && elem->right() != 0) {
        printInorder (elem->right());
    }
}

#endif /* BINARYSEARCHTREE_H */

