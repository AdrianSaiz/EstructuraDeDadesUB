/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ruben
 *
 * Created on 10 de abril de 2016, 20:31
 */

#include <cstdlib>
#include "NodeList.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Esto es una prueba 
    NodeList<int> list;
    list.insert(1);
    list.show();
    list.insert(2);
    list.show();
    list.insert(3);
    list.show();
    list.insert(4);
    list.show();
    list.begin();
    list.remove();
    list.show();
    list.begin();
    list.next();
    list.remove();
    list.modify(5);
    cout<< list.get() <<endl;
    list.show();
    cout << "Tamaño " << list.size();
    return 0;
}

