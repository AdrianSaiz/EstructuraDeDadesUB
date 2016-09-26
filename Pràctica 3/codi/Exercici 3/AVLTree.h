/* 
 * File:   AVLTree.h
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 21 / abril / 2016, 12:23
 */

#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include <stdexcept>
#include <cmath> 
#include "Position.h"

using namespace std;

template <class E> class AVLTree{
    public:
        AVLTree();
        ~AVLTree();
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
        Position<E>* nodeDesb(Position<E>* nodeInserted) const;
        void rebalance(Position<E>* treeToRebalance); 
        void leftRotation(Position<E>* nodeToRebalanceSon);
        void rightRotation(Position<E>* nodeToRebalanceSon);
        Position<E>* rootB;
};

/**
 * Default constructor for TAD AVLTree. It initilizes the tree with no members.
 */
template <class E> AVLTree<E>::AVLTree() {
    this->rootB = 0;
}

/**
 * Default destructor for TAD AVLTree. It deletes all tree nodes by deleting the root one.
 */
template <class E> AVLTree<E>::~AVLTree() {
    delete this->rootB;
}

/**
 * Returns the size of the tree (number of members).
 * 
 * @return int with the size of the tree
 */
template <class E> const int AVLTree<E>::size(Position<E>* subArbre) const {
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
template <class E> const Position<E>* AVLTree<E>::root() const {
    if (this->empty()) throw new out_of_range ("Tree is empty");
    else return this->rootB;
}

/**
 * Returns if the tree is empty or not (has no members)
 * 
 * @return true if only if the size of the tree is 0
 */
template <class E> bool AVLTree<E>::empty() const {
    return (this->size() == 0);
}

/**
 * Inserts a node which will represent the given element. Notice that there can't
 * be two equal nodes (with the same element) and that the nodes are inserted orderly.
 * 
 * @param element
 */
template <class E> void AVLTree<E>::insert(const E& element) {
    if (this->empty())  {
        this->rootB = new Position<E>(element, 0); 
    }
    else {
        Position <E>* nou;
        Position <E>* guia = this->rootB;
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
                if (guia->right() != 0) guia = guia->right(); 
                else {
                    nou = new Position<E>(element, guia);
                    guia->setRight(nou);
                    guia = nou;
                }
            }
        }
        guia = nodeDesb(guia); //Hem insertat guia, comprobem si s'ha desbalancejat
        if(guia != 0) rebalance(guia); //Crida a desbalanceig
    }
}

/**
 * Returns if an element is in the tree or not.
 * 
 * @param element
 * @return true if only if the element is in tree.
 */
template <class E> bool AVLTree<E>::search(const E& element) const {
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
template <class E> void AVLTree<E>::printPreorder(const Position<E>* elem) const {
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
template <class E> void AVLTree<E>::printPostorder(const Position<E>* elem) const {
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
template <class E> void AVLTree<E>::printInorder(const Position<E>* elem) const {
    if (!elem->isExternal() && elem->left() != 0) {
        printInorder (elem->left());
    }
    cout << elem->getElement() << endl;
    if (!elem->isExternal() && elem->right() != 0) {
        printInorder (elem->right());
    }
}

/**
 * Returns the height of the tree.
 * 
 * @return int with the height of a given node
 */
template <class E> const int AVLTree<E>::height(Position<E>* node) const {
    return node->getHeight();
}
/**
 * It returns the first subtree that has a bad balance factor.
 * @return 
 */
template<class E> Position<E>* AVLTree<E>::nodeDesb(Position<E>* nodeInserted) const {
    int balanceFactor = 0; 
    int heightLeft = 0;
    int heightRight = 0;
    Position<E>* nodeSon = nodeInserted;
    while(nodeSon != this->rootB && balanceFactor < 2) {
        heightLeft = (nodeSon->parent()->left() != 0)? nodeSon->parent()->left()->getHeight():0;
        heightRight = (nodeSon->parent()->right() != 0)? nodeSon->parent()->right()->getHeight():0;
        balanceFactor = abs(heightLeft - heightRight);
        nodeSon->parent()->setHeight(max(nodeSon->parent()->getHeight(), nodeSon->getHeight() + 1)); //Actualitzem la mida del pare si cal
        /*----------------------------*/
        nodeSon = nodeSon->parent();
    }
    if(balanceFactor >= 2) return nodeSon;
    else return 0;
}
template<class E> void AVLTree<E>::rebalance(Position<E>* treeToRebalance) {
    int heightLeft = 0;
    int heightRight = 0;
    heightLeft = (treeToRebalance->left() != 0)? treeToRebalance->left()->getHeight():0;
    heightRight = (treeToRebalance->right() != 0)? treeToRebalance->right()->getHeight():0;
    //1)Comprovem si es cas intern o extern.
    if(heightLeft > heightRight) {
        //1.2) En cas que la altura del node fill esquerre sigui major que la del node fill dret.
        heightLeft = (treeToRebalance->left()->left() != 0)? treeToRebalance->left()->left()->getHeight():0;
        heightRight = (treeToRebalance->left()->right() != 0)? treeToRebalance->left()->right()->getHeight():0;
        if(heightLeft > heightRight) {
            //2.1)Cas extern esquerra
            rightRotation(treeToRebalance->left());
        }
        else {
            //2.2)Cas intern esquerra
            leftRotation(treeToRebalance->left()->right());
            rightRotation(treeToRebalance->left());
        }
    }
    else {
        heightLeft = (treeToRebalance->right()->left() != 0)? treeToRebalance->right()->left()->getHeight():0;
        heightRight = (treeToRebalance->right()->right() != 0)? treeToRebalance->right()->right()->getHeight():0;
        //1.2)En cas que la altura del node fill dret sigui major que la del node fill esquerre.
        if(heightLeft > heightRight) {
            //2.3)Cas intern dreta
            rightRotation(treeToRebalance->right()->left());
            leftRotation(treeToRebalance->right());
        }
        else {
            //2.4)Cas extern dreta
            leftRotation(treeToRebalance->right());
        }
    }
}
/**
 * Right rotation between the node passed by parameter and her parent
 * @param nodeToRebalanceSon
 */
template <class E> void AVLTree<E>::rightRotation(Position<E>* nodeToRebalanceSon) {
    Position<E>* nodeParent = nodeToRebalanceSon->parent();
    Position<E>* nodeParentParent = nodeParent->parent(); 
    Position<E>* nodeSon = nodeToRebalanceSon;
    //1) Convertimos al padre del padre en el padre del hijo
    if(nodeParentParent != 0) {
        if(nodeParentParent->left() == nodeParent) nodeParentParent->setLeft(nodeSon); //Era el hijo izquierdo
        else nodeParentParent->setRight(nodeSon); // Era el hijo derecho
        nodeSon->setParent(nodeParentParent);
    }
    else {
      //Ara el fill serà el nou root
      nodeSon->setParent(0);
      this->rootB = nodeSon;
    } 
    if(nodeSon->right() != 0) {
    //2) Convertimos el hijo derecho del hijo en hijo izquierdo del padre
    nodeSon->right()->setParent(nodeParent);
    nodeParent->setLeft(nodeSon->right()); 
    }
    else nodeParent->setLeft(0); //No tindrà res
    //Mantienen la misma altura por ahora
    //3) Ahora realizamos el giro
    nodeParent->setParent(nodeSon); //Ahora el padre es el hijo
    nodeSon->setRight(nodeParent);
    //4)Seteamos las nuevas alturas
    nodeParent->setHeight(max(((nodeParent->left() != 0)? nodeParent->left()->getHeight(): 0),((nodeParent->right() != 0)? nodeParent->right()->getHeight():0)) + 1);
    nodeSon->setHeight(max(((nodeSon->left() != 0)? nodeSon->left()->getHeight(): 0),((nodeSon->right() != 0)? nodeSon->right()->getHeight():0)) + 1);
}
/**
 * Left rotation between the node passed by parameter and her parent
 * @param nodeToRebalanceSon
 */
template<class E> void AVLTree<E>::leftRotation(Position<E>* nodeToRebalanceSon) {
    Position<E>* nodeParent = nodeToRebalanceSon->parent();
    Position<E>* nodeParentParent = nodeParent->parent(); 
    Position<E>* nodeSon = nodeToRebalanceSon;
    //1) Convertimos al padre del padre en el padre del hijo
    if(nodeParentParent != 0) {
        if(nodeParentParent->left() == nodeParent) nodeParentParent->setLeft(nodeSon); //Era el hijo izquierdo
        else nodeParentParent->setRight(nodeSon); // Era el hijo derecho
        nodeSon->setParent(nodeParentParent);
    }
    else {
      //Ara el fill serà el nou root
      nodeSon->setParent(0);
      this->rootB = nodeSon;
    } 
    //2) Convertimos el hijo izquierdo del hijo en hijo derecho del padre en caso de que el hijo izquierdo exista
    if(nodeSon->left() != 0) {
        nodeSon->left()->setParent(nodeParent);
        nodeParent->setRight(nodeSon->left()); 
    }
    else nodeParent->setRight(0); //No tindrà res
    //Mantienen la misma altura por ahora
    //3) Ahora realizamos el giro
    nodeParent->setParent(nodeSon); //Ahora el padre es el hijo
    nodeSon->setLeft(nodeParent);
    //4)Seteamos las nuevas alturas
    nodeParent->setHeight(max(((nodeParent->left() != 0)? nodeParent->left()->getHeight(): 0),((nodeParent->right() != 0)? nodeParent->right()->getHeight():0)) + 1);
    nodeSon->setHeight(max(((nodeSon->left() != 0)? nodeSon->left()->getHeight(): 0),((nodeSon->right() != 0)? nodeSon->right()->getHeight():0)) + 1);
}
#endif /* AVLTREE_H */


