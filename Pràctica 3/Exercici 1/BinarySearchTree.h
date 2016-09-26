/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinarySearchTree.h
 * Author: orabasal15.alumnes
 *
 * Created on 21 / abril / 2016, 13:02
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>

#include "Position.h"

template <class E> class BinarySearchTree {
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        const int size() const;
        const int height() const;
        bool empty() const;
        const Position<E>* root() const;
        void insert (const E& element);
        bool search (const E& element) const;
        void printPreorder() const;
        void printPostorder() const;
        void printInorder() const;
    
    private:
        void preorder(const Position<E>* elem) const;
        void postorder(const Position<E>* elem) const;
        void inorder(const Position<E>* elem) const;
        Position<E>* rootB;
        int sizeB;
        int heightB;
};


using namespace std;

template <class E> BinarySearchTree <E>::BinarySearchTree() {
    this->rootB = 0;
    this->sizeB = 0;
    this->heightB = 0;
}

template <class E> BinarySearchTree <E>::~BinarySearchTree() {
    delete this->rootB;
}

template <class E> const int BinarySearchTree <E>::size() const {
    return this->sizeB;
}
template <class E> const Position<E>* BinarySearchTree<E>::root() const {
    return this->rootB;
}

template <class E> const int BinarySearchTree <E>::height() const {
    return this->heightB;
}

template <class E> bool BinarySearchTree <E>::empty() const {
    bool trobat  = (this->size() == 0);
}

template <class E> void BinarySearchTree <E>::insert(const E& element) {
    if (this->empty())  {
        this->rootB = new Position<E>(element, 0); 
        sizeB++;
    }
    else {
        Position <E>* nou;
        Position <E>* guia = this->rootB;
        heightB = 0;
        while(guia->getElement() != element) {
            if(guia->getElement() > element) {
                if (!guia->left() == 0) guia = guia->left(); 
                else {
                    nou = new Position<E>(element, guia);
                    guia->setLeft(nou);
                    guia = nou;
                    sizeB++;
                }
                heightB++;
            }
            else {
                if (!guia->right() == 0) guia = guia->right(); 
                else {
                    nou = new Position<E>(element, guia);
                    guia->setRight(nou);
                    guia = nou;
                    sizeB++;
                }
                heightB++;
            }
        }
    }
}

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

template <class E> void BinarySearchTree <E>::printPreorder() const {
    this->preorder (this->rootB);
}

template <class E> void BinarySearchTree <E>::printPostorder() const {
    this->postorder (this->rootB);
}

template <class E> void BinarySearchTree <E>::printInorder() const {
    this->inorder (this->rootB);
}

template <class E> void BinarySearchTree <E>::preorder(const Position<E>* elem) const {
    cout << elem->getElement() << endl;
    if (!elem->isExternal()) {
        if(elem->left() != 0) preorder (elem->left());
        if(elem->right() != 0) preorder (elem->right());
    }
}

template <class E> void BinarySearchTree <E>::postorder(const Position<E>* elem) const {
    if (!elem->isExternal()) {
        if(elem->left() != 0) postorder (elem->left());
        if(elem->right() != 0)postorder (elem->right());
    }
    cout << elem->getElement() << endl;
}

template <class E> void BinarySearchTree <E>::inorder(const Position<E>* elem) const {
    if (!elem->isExternal() && elem->left() != 0) {
        inorder (elem->left());
    }
    cout << elem->getElement() << endl;
    if (!elem->isExternal() && elem->right() != 0) {
        inorder (elem->right());
    }
}

#endif /* BINARYSEARCHTREE_H */

