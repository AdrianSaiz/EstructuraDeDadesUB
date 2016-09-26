/* 
 * File:   main.cpp
 * Author: Rubén Ballester Bautista | Oriol Rabasseda Alcaide
 *
 * Created on 21 / abril / 2016, 12:23
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "AVLTree.h"

using namespace std;

/**
 * Main with some tests to show that the TAD AVLTree is working correctly.
 */
int main(int argc, char** argv) {
    AVLTree<int>* arbre = new AVLTree<int>();
    arbre->insert(8);
    arbre->insert(9);
    arbre->insert(10);
    arbre->insert(2);
    arbre->insert(1);
    arbre->insert(5);
    arbre->insert(3);
    arbre->insert(6);
    arbre->insert(4);
    arbre->insert(7);
    arbre->insert(11);
    arbre->insert(12);
    arbre->printPreorder();
    delete arbre;
    return 0;
}

