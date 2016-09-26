/* 
 * File:   main.cpp
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 21 / abril / 2016, 12:23
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "BinarySearchTree.h"

using namespace std;

/**
 * Main with some tests to show that the TAD BinarySearchTree is working correctly.
 */
int main(int argc, char** argv) {
    BinarySearchTree<int>* arbre = new BinarySearchTree<int>();
    arbre->insert(3);
    arbre->insert(5);
    arbre->insert(1);
    arbre->insert(2);
    arbre->insert(4);
    arbre->insert(4);
    arbre->insert(7);
    arbre->insert(9);
    arbre->insert(0);
    arbre->printPreorder();
    cout << "kk" << endl;
    arbre->printPostorder();
    cout << "kk" << endl;
    arbre->printInorder();
    cout << "kk" << endl;
    cout << arbre->height() << endl;
    cout << "kk" << endl;
    cout << arbre->root()->getElement() << endl; 
    cout << "kk" << endl;
    cout << arbre->search(8) << endl;
    cout << "kk" << endl;
    cout << arbre->search(3) << endl;
    cout << "kk" << endl;
    cout << arbre->search(7) << endl;
    cout << "kk" << endl;
    cout << arbre->search(24) << endl;
    cout << "kk" << endl;
    cout << arbre->size() << endl;
    delete arbre;
    return 0;
}

