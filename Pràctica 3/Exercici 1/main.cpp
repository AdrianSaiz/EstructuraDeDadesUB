/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: orabasal15.alumnes
 *
 * Created on 21 / abril / 2016, 12:23
 */

#include <cstdlib>
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

/*
 * 
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
    arbre->printPreorder();
    cout << "kk" << endl;
    arbre->printPostorder();
    cout << "kk" << endl;
    arbre->printInorder();
    cout << "kk" << endl;
    cout << arbre->height() << endl;
    cout << "kk" << endl;
    cout << arbre->root()->getElement() << endl; 
    cout << "kk2" << endl;
    cout << arbre->search(8) << endl;
    cout << "kk" << endl;
    cout << arbre->search(3) << endl;
    cout << "kk" << endl;
    cout << arbre->search(7) << endl;
    cout << "kk" << endl;
    cout << arbre->search(24) << endl;
    return 0;
}

